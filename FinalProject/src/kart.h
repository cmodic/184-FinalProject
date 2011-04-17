#ifndef KART_H
#define KART_H

#include "main.h"
#include "crate.h"

class Kart {
public:

	Kart();
	~Kart();

	void draw(Shader* s);
	void update(double timePassedSeconds);
	void turnGasOn() { gasOn = true; };
	void turnGasOff() { gasOn = false; };

	void turnLeft();
	void turnRight();

	vec2 getPosition() { return pos; } 
	double getRotation(); 
	bool collidedWithCrate(Crate *c);
	
private:
	const double maxSpeed;
	const double maxAcceleration;
	const double maxDeceleration;
	const double lateralAdjustment;

	double currentSpeed;
	
	double turningSpeed; //RADIANS
	
	bool gasOn;

	vec2 pos;
	vec2 forwardDirection;
	Mesh* model;

};

#endif