#ifndef SWEEPSKELETON_H_
#define SWEEPSKELETON_H_


#include <cmath>
#include <vector>

#include "algebra3.h"
#include "Vertex.h"

using namespace std;


class SweepSkeleton {

public:
	SweepSkeleton(string filename);
	
	
	
	void render();
	
	int pickJoint(double &depth, vec2 mouse, double selectionRadius = 10.0);
	
	vec3 getPos(vec2 mouse, double depth);
	
	void writeAsTRK();
	
	void moveVertex(int v, vec3 p);
	void addVertex(int v, vec3 p, double a= 0.0);
	void removeVertex(int v);
	void changeAzimuth(int v, double a);
	void setGlobalTwist(double t);
	void setGlobalAzimuth(double a);
	
private:
	int savecount;
	vector<Vertex*> _vertices;
	double globalTwist;
	double globalAzimuth;
};
#endif