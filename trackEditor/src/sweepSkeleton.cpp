#include "sweepSkeleton.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

SweepSkeleton::SweepSkeleton(string filename) : savecount(0) {
    ifstream f(filename.c_str());
    if (!f) {
        UCBPrint("SplineCoaster", "Couldn't load file " << filename);
        return;
    }
    string line;
    while (getline(f,line)) {
        stringstream linestream(line);
        string op;
        linestream >> op;
        if (op.empty() || op[0] == '#') // comments are marked by # at the start of a line
            continue;
        if (op == "p") { // p marks profile points (2d cross section vertices)
            continue;
        } else if (op == "v") { // v marks bspline control points with optional azimuth info
            vec3 v;
            linestream >> v;
            double az;
            if (linestream >> az) {
                _vertices.push_back(new Vertex(v, az));
            } else {
                _vertices.push_back(new Vertex(v));
            }
        } else if (op == "twist") {
            linestream >> globalTwist;
        } else if (op == "azimuth") {
            linestream >> globalAzimuth;
        }
    }
}

void SweepSkeleton::render() {
    

    glDisable(GL_LIGHTING); // just draw plain colored lines
    //glDisable(GL_DEPTH_TEST); // make it show through the mesh

    
    glColor3d(1,0,0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    for (size_t i = 0; i < _vertices.size(); i++) {
        vec3 posn = _vertices[i]->getPos();
        glVertex3dv(&posn[0]);
    }
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    for (size_t i = 0; i < _vertices.size(); i++) {
        glVertex3dv(&_vertices[i]->getPos()[0]);
    }
    glEnd();

    glEnable(GL_LIGHTING);
    //glEnable(GL_DEPTH_TEST);
}

int SweepSkeleton::pickJoint(double &depth, vec2 mouse, double selectionRadius) {
    double modelview[16], projection[16];
    int viewport[4];

    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    mouse[1] = viewport[3] - mouse[1];

    int bestJoint = -1;
    double bestDist = selectionRadius*selectionRadius;
    for (size_t i = 0; i < _vertices.size(); ++i) {
        vec3 p = _vertices[i]->getPos();
        vec2 s;
        double sz;
        gluProject(p[0], p[1], p[2], 
            modelview, projection, viewport, 
            &s[0], &s[1], &sz);
        vec2 diff = mouse - s;
        
        if (diff.length2() <= bestDist) {
            bestDist = diff.length2();
            bestJoint = int(i);
            depth = sz;
        }
    }
    return bestJoint;
}

vec3 SweepSkeleton::getPos(vec2 mouse, double depth) {
    double modelview[16], projection[16];
    int viewport[4];

    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    mouse[1] = viewport[3] - mouse[1];

    double x,y,z;
    gluUnProject(mouse[0], mouse[1], depth, 
                 modelview, projection, viewport,
                 &x, &y, &z);
    return vec3(x,y,z);
}

void SweepSkeleton::writeAsTRK() {
 	//std::stringstream filename(stringstream::in | stringstream::out);
 	savecount++;
 	string filename = "outputTrack.trk" ;
 	const char * c = filename.c_str();
 	ofstream output(c, ios::out);
 	output << "azimuth " << globalAzimuth << "\n";
 	output << "twist " << globalTwist << "\n";
 	for (int i =0; i< _vertices.size(); ++i) {
 		vec3 pos = _vertices[i]->getPos();
 		double az = _vertices[i]->getAzimuth();
 		output << "v " << pos[0] << " " << pos[1] << " " << pos[2] << " " << az << "\n";
 	}
 	
}

void SweepSkeleton::addVertex(int v, vec3 p, double a) {
	if (v+1 >= _vertices.size()) {
		_vertices.push_back(new Vertex(p, a));
		return;
	} 
	Vertex *temp = _vertices[v+1];
	Vertex *temp2;
	_vertices[v+1] = new Vertex(p, a);
	for (int i = v+2; i < _vertices.size();++i) {
		temp2 = _vertices[i];
		_vertices[i] = temp;
		temp = temp2;
	}
	_vertices.push_back(temp);
}

void SweepSkeleton::moveVertex(int v, vec3 p) {
	_vertices[v]->setPos(p);
}

void SweepSkeleton::removeVertex(int v) {
	_vertices.erase(_vertices.begin()+v);
}

void SweepSkeleton::changeAzimuth(int v, double a) {
	_vertices[v]->setAzimuth(a);
}

void SweepSkeleton::setGlobalTwist(double t) {
	globalTwist = t;
}

void SweepSkeleton::setGlobalAzimuth(double a) {
	globalAzimuth = a;
}