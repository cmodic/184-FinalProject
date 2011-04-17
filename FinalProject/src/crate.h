#ifndef CRATE_H
#define CRATE_H

#include "main.h"
#include "mesh.h"

class Crate {

public:
	Crate(vec2 initialPosition);
	void update(double timePassedSeconds);
	void draw(Shader* s);

	vec2 getPos() { return pos; }

private:
	const double rotationRate; // RADIANS

	vec2 pos;
	Mesh* model;
	double currentRotation; // RADIANS


};

#endif