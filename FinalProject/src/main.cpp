#include "main.h"
#include "kart.h"
#include "crate.h"
#include <time.h>
#include <list>
using namespace std;


//****************************************************
// Some Classes
//****************************************************
class Viewport {
public:
    Viewport(): mousePos(0.0,0.0) { orientation = identity3D(); };
	int w, h; // width and height
	vec2 mousePos;
    mat4 orientation;
};

//****************************************************
// Global Variables
//****************************************************
Viewport viewport;
UCB::ImageSaver * imgSaver;
int frameCount = 0;
Sweep *sweep;
Mesh *mesh;
Shader *shade;

Shader *kartShader;
Kart* player;
list<Crate*> crates;
void render();
int V_OTS = 0;
int V_FP = 1;
int V_TP = 2;
int VIEWMODE = V_OTS; 
int numModes = 3;

// A simple helper function to load a mat4 into opengl
void applyMat4(mat4 &mat) {
    double glmat[16];
    int k = 0;
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            glmat[k++] = mat[j][i];
        }
    }
    glMultMatrixd(glmat);
}


void checkCrateCollisions() {
	for(list<Crate*>::iterator it = crates.begin(); it != crates.end(); ++it) {
		if (player->collidedWithCrate(*it)) {
			crates.erase(it);
			checkCrateCollisions();
			return;
		}
	}
}

//-------------------------------------------------------------------------------
/// You will be calling all of your drawing-related code from this function.
/// Nowhere else in your code should you use glBegin(...) and glEnd() except code
/// called from this method.
///
/// To force a redraw of the screen (eg. after mouse events or the like) simply call
/// glutPostRedisplay();
void display() {
	//Clear Buffers
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);					// indicate we are specifying camera transformations
	glLoadIdentity();							// make sure transformation is "zero'd"
	
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	double timePassedSeconds = 1.0 / 30.0;
	
	player->update(timePassedSeconds);
	checkCrateCollisions();

	for(list<Crate*>::iterator it = crates.begin(); it != crates.end(); ++it) {
		(*it)->update(timePassedSeconds);
	}

	render();

	glutSwapBuffers();

}

void render() {

	double cartForwardComponent = player->getPosition()[1];
	double cartLateralComponent = player->getPosition()[0];

	vec3 cartPos = sweep->sample(cartForwardComponent).point;
	vec3 forwardPos = sweep->sampleForward(cartForwardComponent);
	vec3 upPos = sweep->sampleUp(cartForwardComponent,.001);
	vec3 sidePos = forwardPos ^ upPos;

	cartPos += sidePos.normalize() * sweep->getCrossSectionWidth() * cartLateralComponent;

	vec3 front = cartPos + forwardPos;
	vec3 top = cartPos + upPos;
	vec3 renderPos = cartPos;

	bool renderCar = true;
	
	//SETS UP THE CAMERA
	if (VIEWMODE == V_OTS) {
		vec3 cameraEye = renderPos + 3 * upPos - 45 * forwardPos;
		vec3 cameraCenter = renderPos + 10 * forwardPos + upPos;
		gluLookAt(cameraEye[0], cameraEye[1], cameraEye[2], cameraCenter[0], cameraCenter[1], cameraCenter[2], upPos[0],upPos[1],upPos[2]);
	} else {
		glTranslatef(0,0,-20);
		applyMat4(viewport.orientation);
	}
	//END CAMERA SETUP

	//RENDER THE TRACK
	sweep->renderWithDisplayList(*shade,100,1,3);
	
	//DRAW CRATES
	for (list<Crate*>::iterator it = crates.begin(); it != crates.end(); ++it) {
		Crate *c = *it;
		double crateForwardComponent = c->getPos()[1];
		double crateLateralComponent = c->getPos()[0];
	
		vec3 cratePos = sweep->sample(crateForwardComponent).point;
		vec3 crateForwardPos = sweep->sampleForward(crateForwardComponent);
		vec3 crateUpPos = sweep->sampleUp(crateForwardComponent,.001);
		vec3 crateSidePos = crateForwardPos ^ crateUpPos;

		cratePos += crateSidePos.normalize() * sweep->getCrossSectionWidth() * crateLateralComponent;
		
		vec3 cf = crateForwardPos.normalize();
		vec3 cu = crateUpPos.normalize();
		vec3 cs = cf ^ cu;

		mat4 cm = mat4(
			vec4(cs[0], cs[1], cs[2], 0.0),
			vec4(cu[0], cu[1], cu[2], 0.0),
			vec4(-cf[0], -cf[1], -cf[2], 0.0),
			vec4(0, 0, 0, 1)
		);

		glPushMatrix();
			glTranslated(cratePos[0], cratePos[1], cratePos[2]);
			applyMat4(cm);
			glDisable(GL_BLEND);
			c->draw(shade);
		glPopMatrix();
	}

	vec3 f = forwardPos.normalize();
	vec3 u = upPos.normalize();
	vec3 s = f ^ u;

	mat4 m = mat4(
		vec4(s[0], s[1], s[2], 0.0),
		vec4(u[0], u[1], u[2], 0.0),
		vec4(-f[0], -f[1], -f[2], 0.0),
		vec4(0, 0, 0, 1)
	);

	if (renderCar) {
		glPushMatrix();
			glTranslated(cartPos[0], cartPos[1], cartPos[2]);
			applyMat4(m);
			glRotatef(player->getRotation() * 180.0 / M_PI,0,1,0);
			glDisable(GL_BLEND);
			player->draw(shade);
		glPopMatrix();
	}
}


//-------------------------------------------------------------------------------
/// \brief	Called when the screen gets resized.
/// This gives you the opportunity to set up all the relevant transforms.
///
void reshape(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, ((double)w / MAX(h, 1)), 1.0, 100.0);
	//glOrtho(-10,10,-10,10,1,100);

    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


//-------------------------------------------------------------------------------
/// Called to handle keyboard events.
void myKeyboardFunc (unsigned char key, int x, int y) {
	switch (key) {
		case 27:			// Escape key
			exit(0);
			break;
		case 'w':
			player->turnGasOn();
			break;
		case 'a':
			player->turnLeft();
			break;
		case 'd':
			player->turnRight();
			break;
        case 'S':
        case 's':
			player->turnGasOff();
            break;
        case 'T':
        case 't':
            shade->toggleTextureMap();
            sweep->clearDisplayList();
            break;
        case 'B':
        case 'b':
            shade->toggleBumpMap();
            sweep->clearDisplayList();
            break;
        case 'P':
        case 'p':
            shade->togglePhong();
            sweep->clearDisplayList();
            break;
		case 'v':
			VIEWMODE = (VIEWMODE + 1) % numModes;
	}
}

void myKeyboardUpFunc (unsigned char key, int x, int y) {
	switch (key) {
		case 'w':
			player->turnGasOff();
			break;
	}
}

//-------------------------------------------------------------------------------
/// Called whenever the mouse moves while a button is pressed
void myActiveMotionFunc(int x, int y) {

    // Rotate viewport orientation proportional to mouse motion
    vec2 newMouse = vec2((double)x / glutGet(GLUT_WINDOW_WIDTH),(double)y / glutGet(GLUT_WINDOW_HEIGHT));
    vec2 diff = (newMouse - viewport.mousePos);
    double len = diff.length();
    if (len > .001) {
        vec3 axis = vec3(diff[1]/len, diff[0]/len, 0);
        viewport.orientation = viewport.orientation * rotation3D(axis, -180 * len);
    }

    //Record the mouse location for drawing crosshairs
    viewport.mousePos = newMouse;

    //Force a redraw of the window.
    glutPostRedisplay();
}


//-------------------------------------------------------------------------------
/// Called whenever the mouse moves without any buttons pressed.
void myPassiveMotionFunc(int x, int y) {
    //Record the mouse location for drawing crosshairs
    viewport.mousePos = vec2((double)x / glutGet(GLUT_WINDOW_WIDTH),(double)y / glutGet(GLUT_WINDOW_HEIGHT));

    //Force a redraw of the window.
    glutPostRedisplay();
}

//-------------------------------------------------------------------------------
/// Called to update the screen at 30 fps.
void frameTimer(int value){

    frameCount++;
    glutPostRedisplay();
    glutTimerFunc(1000/30, frameTimer, 1);
}

void exitFreeimage(void) {
    FreeImage_DeInitialise();
}


//-------------------------------------------------------------------------------
/// Initialize the environment
int main(int argc,char** argv) {
	//Initialize OpenGL
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);

    FreeImage_Initialise();
    atexit(exitFreeimage);

	//Set up global variables
	viewport.w = 600;
	viewport.h = 600;

	if (argc < 2) {
	    cout << "USAGE: sweep sweep.trk" << endl;
	    return -1;
    }

	//Initialize the screen capture class to save BMP captures
	//in the current directory, with the prefix "sweep"
	imgSaver = new UCB::ImageSaver("./", "sweep");

	//Create OpenGL Window
	glutInitWindowSize(viewport.w,viewport.h);
	glutInitWindowPosition(0,0);
	glutCreateWindow("CS184 Framework");

	//Register event handlers with OpenGL.
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(myKeyboardFunc);
	glutKeyboardUpFunc(myKeyboardUpFunc);
	glutMotionFunc(myActiveMotionFunc);
	glutPassiveMotionFunc(myPassiveMotionFunc);
    frameTimer(0);

    // set some lights
    {
       float ambient[4] = { .1f, .1f, .1f, 1.f };
       float diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.f };
       float pos[4] = { 0, 0, 1, 0 };
       glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
       glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
       glLightfv(GL_LIGHT0, GL_POSITION, pos);
       glEnable(GL_LIGHT0);
    }
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glewInit();
	if (GLEW_ARB_vertex_shader && GLEW_ARB_fragment_shader)
		printf("Ready for GLSL\n");
	else {
		printf("No GLSL support\n");
		exit(1);
	}

    shade = new Shader("sweepShader.vert", "sweepShader.frag");

  
    // Create the coaster
    sweep = new Sweep(argv[1]);
    if (sweep->bad()) {
        cout << "Sweep file appears to not have a proper sweep in it" << endl;
        return -1;
    }

    mesh = new Mesh();
    mesh->loadFile("cyl_textured.obj");
    mesh->loadTextures("cylinder_tex.bmp", "cylinder_tex_bump.png");
    mesh->centerAndScale(3);
    // do two steps of subdivision by swapping through a temp mesh
    Mesh temp; mesh->subdivide(temp); temp.subdivide(*mesh);
    // recompute vertex normals
    mesh->computeVertexNormals();


	// NEW STUFF

	player = new Kart();
	player->turnGasOff();
	for (int i = 0; i < 5; i++) {
		crates.push_back(new Crate(vec2(-.8 + .3 * i, 0 + .2 * i)));
	}

	//END NEW STUFF

	//And Go!
	glutMainLoop();
}
