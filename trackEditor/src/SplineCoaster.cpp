#include "SplineCoaster.h"

#include "global.h"

#include <fstream>

namespace {
    // Used to advance the rotation minimizing frame forward
    // formula from [wang et al. 07]
    inline vec3 advanceFrame(const vec3 &xi, const vec3 &xi1,
                                const vec3 &ti, const vec3 &si, const vec3 &ri,
                                  const vec3 &ti1) {
        vec3 v1 = xi1 - xi;
        double c1 = v1 * v1;
        vec3 riL = ri - (2/c1)*(v1*ri)*v1;
        vec3 tiL = ti - (2/c1)*(v1*ti)*v1;
        vec3 v2 = ti1 - tiL;
        double c2 = v2 * v2;
        return riL - (2/c2)*(v2*riL)*v2;
    }
}


SplinePoint SplinePoint::sampleBSpline(vector<SplinePoint*>& cps, double t, bool closed, int degree)
{
    if (cps.empty()) {
        UCBPrint("sampleBSpline", "need at least one control point");
        return SplinePoint();
    }


    // get into 0,1 range
    if (t > 1.0 || t < 0.0)
        t = fmod(t, 1.0);
    if (t < 0.0)
        t += 1.0;
    
    // adjust degree down as needed to get a curve, if too few control points and not on closed loop
    int numCPs = int(closed ? cps.size() + degree : cps.size());
    if (degree >= numCPs)
        degree = numCPs - 1;

    // rescale t to minSupport,maxSupport range
    double minSupport = degree;
    double maxSupport = numCPs;
    t = (1-t)*minSupport + t*maxSupport;

    // 'recursive' form of b-spline is done iteratively here
    SplinePoint *bases = new SplinePoint[degree+1];
    int k = (int)t;

    for (int i = 0; i <= degree; ++i) {
        bases[i] = *cps[(k - degree + i) % cps.size()];
    }

    for (int power = 1; power <= degree; ++power) {
        for (int i = 0; i <= degree - power; ++i) {
            int knot = k - degree + power + i;
            double u_i = (double)knot;
            double u_ipr1 = double(knot + degree - power + 1);
            double a = (t - u_i) / (u_ipr1 - u_i);
            bases[i] = SplinePoint::lerp(a, bases[i], bases[i+1]);
        }
    }

    SplinePoint result = bases[0];

    delete [] bases;

    return result;
}

SplineCoaster::SplineCoaster(string filename) : globalTwist(0), globalAzimuth(0), hasDL(false) {
    ifstream f(filename.c_str());
    if (!f) {
        UCBPrint("SplineCoaster", "Couldn't load file " << filename);
        return;
    }
    //skeleton = new SweepSkeleton(filename);
    string line;
    while (getline(f,line)) {
        stringstream linestream(line);
        string op;
        linestream >> op;
        if (op.empty() || op[0] == '#') // comments are marked by # at the start of a line
            continue;
        if (op == "p") { // p marks profile points (2d cross section vertices)
            vec2 v;
            linestream >> v;
            profile.push_back(v);
        } else if (op == "v") { // v marks bspline control points with optional azimuth info
            vec3 v;
            linestream >> v;
            double az;
            if (linestream >> az) {
                bsplinePts.push_back(new SplinePoint(v, az));
            } else {
                bsplinePts.push_back(new SplinePoint(v));
            }
        } else if (op == "twist") {
            linestream >> globalTwist;
        } else if (op == "azimuth") {
            linestream >> globalAzimuth;
        }
    }
    profile.push_back(vec2(-2, -1));
    profile.push_back(vec2(2, -1));
    profile.push_back(vec2(2, -3));
    profile.push_back(vec2(-2, -3));
    
}

// clean up memory (helper for the big render function)
void SplineCoaster::freePolyline(vector<SplinePoint*> &pts) {
    for(vector<SplinePoint*>::iterator it = pts.begin(); it != pts.end(); ++it)
        delete *it;
}

// create a polyline that samples the curve (helper for the big render function)
void SplineCoaster::createPolyline(vector<SplinePoint*> &polyline, int totalSamples) {
    if (totalSamples == 0)
        return; // ... no samples is easy!

    vec3 lastGood;
    for (int i = 0; i < totalSamples + 3; i++) {
        int loc = i % totalSamples;
        double t = loc / double(totalSamples);
        SplinePoint sp = SplinePoint::sampleBSpline(bsplinePts, t);
        if (!polyline.empty() && (sp.point - lastGood).length2() < .0001) {
            continue; // wait for the samples to get a bit further apart ... !
        } else {
            polyline.push_back(new SplinePoint(sp));
            lastGood = sp.point;
        }
    }
}

// render supporting pillars for the coaster (helper for the big render function)
void SplineCoaster::renderSupports(int supportsPerPt, double supportSize, double groundY) {
    int totalSupports = (int) bsplinePts.size() * supportsPerPt;
    glColor3f(0,0,1); // blue supports ...
    for (int i = 0; i < totalSupports; i++) {
        int loc = i % totalSupports;
        double t = loc / double(totalSupports);
        SplinePoint sp = SplinePoint::sampleBSpline(bsplinePts, t);
        if (sp.point[1] < groundY) continue; // don't add supports if we're underground
        vec3 upCurve = sampleUp(t, .1);
        if (upCurve * vec3(0,1,0) < .3) continue; // don't add supports if we're upside-down
        vec3 pos = sp.point;
        vec3 right(1,0,0);
        vec3 fwd(0,0,1);
        glBegin(GL_QUAD_STRIP);
        for (double circ = 0; circ <= 2 * M_PI + .05; circ += .1) {
            vec3 n = right * cos(circ) + fwd * sin(circ);
            vec3 p = pos + n * supportSize;
            glNormal3f(n[0],n[1],n[2]);
            glVertex3d(p[0],p[1]-1,p[2]);
            glVertex3d(p[0],groundY,p[2]);
        }
        glEnd();
    }
}

// sample the curve at a point
SplinePoint SplineCoaster::sample(double t) {
    return SplinePoint::sampleBSpline(bsplinePts, t);
}
// get the forward direction
vec3 SplineCoaster::sampleForward(double t, double step) {
    return sample(t+step).point - sample(t).point;
}
vec3 SplineCoaster::sampleUp(double t, double step) {
        t = fmod(t, 1.0);
        if (t < 0.0) t+=1.0;
        vec3 up = getFirstUp();
        vec3 lastpos = sample(0).point;
        vec3 lastdir = sampleForward(0).normalize();
        vec3 dir = lastdir;
        vec3 pos = lastpos;
        for (double st = step; st <= t + step*.5; st+=step) {
            double tt = min(st, t);
            dir = sampleForward(tt);
            dir.normalize();
            pos = sample(tt).point;
            vec3 right = lastdir ^ up;
            right.normalize();
            up = advanceFrame(lastpos, pos, lastdir, right, up, dir);
            right = dir ^ up;
            up = right ^ dir;
            up.normalize();
            lastpos = pos; lastdir = dir;
        }

        
        // orthonormalize the frame
        dir = sampleForward(t).normalize();
        vec3 right = dir^up;
        up = right^dir;
        up.normalize();

        
        orientVectorInFrame(-dir, fmod(t,1.0), sample(t).azimuth, up);

        
        return up;
    }


// rotates a vector according to the global azimuth, local azimuth, twist, direction, and location on curve
void SplineCoaster::orientVectorInFrame(const vec3 &dir, double percent, double localAz, vec3 &inFrame) {
    double rot = globalAzimuth + globalTwist * percent + localAz;
    inFrame = rotation3D(dir, rot) * inFrame;
}

vec3 SplineCoaster::getFirstUp() {
    vec3 leg1 = sampleForward(0).normalize();
    vec3 leg2 = sampleForward(0,-.001).normalize();
    vec3 up = leg1+leg2; // start with the frenet frame
    if (up.length2() < .0001) { // if that doesn't work, try something else
        up = leg1 ^ vec3(0,1,0);
        if (up.length2() < .0001) {
            up = leg1 ^ vec3(.1,1,0);
        }
    }
    up.normalize();
    return up;
}



// sweep the cross section along the curve (helper for the big render function)
void SplineCoaster::renderSweep(vector<SplinePoint*> &polyline, double crossSectionScale) {
    SplinePoint* pts[3]; // pts[1] is us, pts[0] and pts[3] surround us
    vector<vec2> & crossSection = profile;
    int size = (int) polyline.size();
    vec3 * newSlice = new vec3[crossSection.size()];
    vec3 * oldSlice = new vec3[crossSection.size()];
    vec3 oldDir, right;
    bool firstDir = true;
    for (int i = 1; i < size-1; i++) {
        double percent = double(i % size) / (double(size-3));
        for (int c = -1; c <= 1; c++) { // populate local pts
            pts[c+1] = polyline[ (i + size + c) %  size ];
        }

		vec3 leg1 = (pts[0]->point - pts[1]->point).normalize();
        vec3 leg2 = (pts[2]->point - pts[1]->point).normalize();
        vec3 dir = (leg2 - leg1);
        if (dir.length2() < .0001)
            dir = pts[2]->point - pts[1]->point;
		dir.normalize();
        
        vec3 up;
        if (firstDir) { // first time around use a special routine to find the up dir
            up = getFirstUp();
            firstDir = false;
        }
        else { // after the first frame, advance with the rotation minimizing frame
            up = advanceFrame(pts[0]->point, pts[1]->point,
                        oldDir, right, up, dir);
        }
        right = dir ^ up;
        up = right ^ dir;
        up.normalize(); right.normalize();
        oldDir = dir;

        double rot = globalAzimuth + globalTwist * percent + pts[1]->azimuth;

        vec3 bisect = leg1 + leg2;
        double len = bisect.length();
        bool scaleSect = false;
        double scaleTrans = 0;
        if (len > .0001) { // only scale if not going straight already
            scaleSect = true;
            bisect = bisect/len;
            double dot = -leg1*leg2;
            double angle = acos(CLAMP(dot,-1.0,1.0));
            double scale = 1.0 / MAX(cos(.5*angle ),.1);
            scaleTrans = scale - 1.0;
		}

        double s = crossSectionScale;
        int ind = 0;
        for (vector<vec2>::iterator it = crossSection.begin(); it != crossSection.end(); ++it, ++ind) {
            vec2 pos2d = rotation2D(vec2(0,0),rot) * (*it);
            vec3 pt = right * pos2d[0] * s + up * pos2d[1] * s;
            if (scaleSect) {
                pt = pt + scaleTrans * (pt * bisect) * bisect;
            }
            newSlice[ind] = pts[1]->point + pt;
        }

        if (i > 1) {
            glBegin(GL_QUADS);
            for (int v = 0; v < (int) crossSection.size(); v++) {
                int vn = (v + 1) % int(crossSection.size());
                glColor3f(v%4!=0,v%4!=1,v%4!=2);
				vec3 n = (newSlice[v] - oldSlice[v])^(newSlice[vn] - oldSlice[v]);
				n.normalize();
				glNormal3dv(&n[0]);
                glVertex3dv(&oldSlice[v][0]);
                glVertex3dv(&newSlice[v][0]);
                glVertex3dv(&newSlice[vn][0]);
                glVertex3dv(&oldSlice[vn][0]);
            }
            glEnd();
        }

        // swap new and old lists
        vec3 *temp = newSlice;
        newSlice = oldSlice;
        oldSlice = temp;
    }
    delete [] newSlice;
    delete [] oldSlice;
}

// the big render function
void SplineCoaster::render(int samplesPerPt, double crossSectionScale, int supportsPerPt, double supportSize, double groundY) {
    int totalSamples = (int) bsplinePts.size() * samplesPerPt;

    vector<SplinePoint*> polyline;
    createPolyline(polyline, totalSamples);

    int size = (int) polyline.size();
    if (size < 2) { // a polyline with only one point is pretty lame!
        freePolyline(polyline);
        cout << "not enough curve to sweep ..." << endl;
        return;
    }

    //renderSupports(supportsPerPt, supportSize, groundY);
    renderSweep(polyline, crossSectionScale);
    //skeleton->render();

    freePolyline(polyline);
}
void SplineCoaster::moveVertex(int v, vec3 pos) {
	bsplinePts[v]->point = pos;
}

void SplineCoaster::addVertex(int v, vec3 p, double a) {
	if (v+1 >= bsplinePts.size()) {
		bsplinePts.push_back(new SplinePoint(p, a));
		return;
	} 
	SplinePoint *temp = bsplinePts[v+1];
	SplinePoint *temp2;
	bsplinePts[v+1] = new SplinePoint(p, a);
	for (int i = v+2; i < bsplinePts.size();++i) {
		temp2 = bsplinePts[i];
		bsplinePts[i] = temp;
		temp = temp2;
	}
	bsplinePts.push_back(temp);
}

void SplineCoaster::removeVertex(int v) {
	bsplinePts.erase(bsplinePts.begin()+v);
}

void SplineCoaster::changeAzimuth(int v, double a) {
	bsplinePts[v]->azimuth = a;
}


void SplineCoaster::setGlobalTwist(double t) {
	globalTwist = t;
}

void SplineCoaster::setGlobalAzimuth(double a) {
	globalAzimuth = a;
}