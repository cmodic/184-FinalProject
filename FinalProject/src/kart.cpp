#include "kart.h"
#include "models.h"
#include "main.h"
#include "mesh.h"

Kart::Kart():
pos(vec2(0,0)), 
	maxSpeed(.06), 
	maxAcceleration(.025),
	maxDeceleration(.5),
	currentSpeed(0),  
	turningSpeed(.05),
	lateralAdjustment(20),
	forwardDirection(vec2(0,1)) {

		model = new Mesh();
		model->loadFile("kart.obj");
		model->loadTextures("rainbow_t.png","squarebump.png");
		model->computeVertexNormals();
}

Kart::~Kart() {

}

void Kart::draw(Shader* s) {
	/*
	for (int i = 0; i < numKartFaces; i++) {    
		glBegin(GL_TRIANGLES);    
			for (int j = 0; j < 3; ++j) {
				glNormal3fv(KartNorms[KartFaces[i][j*2+1] - 1]);
				glVertex3fv(KartVerts[KartFaces[i][j*2] - 1]);
			}
		glEnd(); 
	}
	*/
	glPushMatrix();
		glTranslatef(0,.25,0);
		glScalef(.25,.25,.25);
		model->draw(*s);
	glPopMatrix();
}

void Kart::update(double timePassedSeconds) {
	if (gasOn) {
		currentSpeed += timePassedSeconds * maxAcceleration;
		currentSpeed = min(currentSpeed, maxSpeed);
	} else {
		currentSpeed -= timePassedSeconds * maxDeceleration;
		currentSpeed = max(currentSpeed, 0.0);
	}

	vec2 movementVector = currentSpeed * timePassedSeconds * forwardDirection.normalize();
	movementVector[0] *= lateralAdjustment;

	pos += movementVector;

	if (pos[0] < -.9) {
		pos[0] = -.9;
	} else if (pos[0] > .9) {
		pos[0] = .9;
	}

	if (pos[1] >= 1.0) {
		pos[1] -= 1.0;
	}
}

void Kart::turnLeft() {
	double rotationAngle = turningSpeed;
	double newLateralDir = cos(rotationAngle) * forwardDirection[0] - sin(rotationAngle) * forwardDirection[1];
	double newForwardDir = sin(rotationAngle) * forwardDirection[0] + cos(rotationAngle) * forwardDirection[1];

	forwardDirection = vec2(newLateralDir, newForwardDir);
}

void Kart::turnRight() {
	double rotationAngle = -turningSpeed;
	double newLateralDir = cos(rotationAngle) * forwardDirection[0] - sin(rotationAngle) * forwardDirection[1];
	double newForwardDir = sin(rotationAngle) * forwardDirection[0] + cos(rotationAngle) * forwardDirection[1];

	forwardDirection = vec2(newLateralDir, newForwardDir);
}

double Kart::getRotation() {
	double sign = 1.0;
	if (forwardDirection[0] >= 0.0) {
		sign *= -1;
	}
	return sign * acos(vec2(0,1) * forwardDirection.normalize()); 
}

bool Kart::collidedWithCrate(Crate *c) {
	vec2 cratePos = c->getPos();
	return (abs(pos[0] - cratePos[0]) < .15 && abs(pos[1] - cratePos[1]) < .01);
}