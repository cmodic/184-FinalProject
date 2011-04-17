#include "Vertex.h"

Vertex::Vertex(): pos(0.0,0.0,0.0), azimuth(0.0) {

}

Vertex::Vertex(vec3 p, double a): pos(p), azimuth(a) {

}

Vertex::Vertex(double x, double y, double z, double a): pos(x,y,z), azimuth(a) {

}

vec3 Vertex::getPos() {

	return pos;
	
}

void Vertex::setPos(vec3 p) {
	pos = p;
}

void Vertex::setAzimuth(double a) {
	azimuth = a;
}
double Vertex::getAzimuth() {
	return azimuth;
}