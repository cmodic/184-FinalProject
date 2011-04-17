#ifndef VERTEX_H_
#define VERTEX_H_

#include "global.h"

class Vertex {
public:
	Vertex();
	Vertex(vec3 p, double a = 0.0);
	Vertex(double x, double y, double z, double a = 0.0);
	
	vec3 getPos();
	double getAzimuth();
	
	void setPos(vec3 p);
	void setAzimuth(double a);
	
	
private:
	vec3 pos;
	double azimuth;
};

#endif