#include "crate.h"


Crate::Crate(vec2 initialPosition):rotationRate(M_PI / 3.0),currentRotation(0) {
	pos = initialPosition;
	model = new Mesh();
	model->loadFile("itemCrate.obj");
	model->loadTextures("rainbow_t.png","squarebump.png");
}

void Crate::update(double timePassedSeconds) {
	currentRotation += rotationRate * timePassedSeconds;
	if (currentRotation > M_PI * 2) {
		currentRotation -= M_PI * 2;
	}
	
}

void Crate::draw(Shader* s) {
	glPushMatrix();
		glTranslatef(0,.2,0);
		glRotatef(currentRotation * 180.0 / M_PI,0,1,0); //SPIN!
		glRotatef(30, 0,0,1); //TILT THE CRATE
		glScalef(.2,.2,.2);
		model->draw(*s);
	glPopMatrix();
}