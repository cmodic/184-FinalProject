#include "main.h"

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
SplineCoaster *coaster;
SweepSkeleton *skeleton;
enum {VIEW_FIRSTPERSON, VIEW_THIRDPERSON, VIEW_MAX};
int viewMode = VIEW_THIRDPERSON;
 enum {MOVE_VERTEX, ADD_VERTEX, REMOVE_VERTEX, VERTEX_AZIMUTH, GLOBAL_AZIMUTH, GLOBAL_TWIST};
int editMode = MOVE_VERTEX;

int chosenVertex;
double chosenDepth;

void applyMat4(mat4 &m) {
	double glmat[16];
	int idx = 0;
	for (int j = 0; j < 4; j++) 
		for (int i = 0; i < 4; i++)
			glmat[idx++] = m[i][j];
	glMultMatrixd(glmat);
}


void printtext(int x, int y, string String) {
	glPushAttrib(GL_DEPTH_TEST);
	glDisable(GL_DEPTH_TEST);
	glRasterPos2i(x,y);
	for(int i=0; i<String.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, String[i]);
	}
	glPopAttrib();
}


void display() {

	//Clear Buffers
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);					// indicate we are specifying camera transformations
	glLoadIdentity();		// make sure transformation is "zero'd"
    
    glTranslatef(0,0,-20);
    
    char string[64];
    char string2[256];
    char string3[64];
    char string4[256];
    sprintf(string3, "Keyboard Options: ");
    sprintf(string4, "'m' - move vertices, 'v' - add vertices, 'r' - remove vertices, 'a' - vertex azimuth. 'g' - global azimuth, 't' - global twist");
    switch(editMode) {
    	case MOVE_VERTEX:
    		sprintf(string, "Current Mode: Move Vertices");
    		sprintf(string2, "click and drag vertices to move");
    		break;
    	case ADD_VERTEX:
    		sprintf(string, "Current Mode: Add Vertices");
    		sprintf(string2, "click existing vertex, then desired new vertex location to place a new vertex after the first");
    		break;
    	case REMOVE_VERTEX:
    		sprintf(string, "Current Mode: Remove Vertices");
    		sprintf(string2, "click existing vertex to remove it");
    		break;
    	case VERTEX_AZIMUTH:
    		sprintf(string, "Current Mode: Vertex Azimuth");
    		sprintf(string2, "click vertex then drag mouse left and right to adjust it's azimuth");
    		break;
    	case GLOBAL_AZIMUTH:
    		sprintf(string, "Current Mode: Global Azimuth");
    		sprintf(string2, "click and drag mouse to adjust global azimuth");
    		break;
    	case GLOBAL_TWIST:
    		sprintf(string, "Current Mode: Global Twist");
    		sprintf(string2, "click and drag mouse to adjust global twist");
    		break;
    	}
    	
    printtext(-8, 8,string);
    printtext(-8,7, string2);
    printtext(-8,-7, string3);
    printtext(-8,-8, string4);
    glBegin(GL_LINE_LOOP);
        	glVertex2f(5,-5);
        	glVertex2f(5,5);
        	glVertex2f(-5,5);
        	glVertex2f(-5,-5);
    glEnd();

       
        applyMat4(viewport.orientation);

        applyMat4(*(new mat4(vec4(0.5,0,0,0),vec4(0,0.5,0,0),vec4(0,0,0.5,0),vec4(0,0,0,1))));

    coaster->renderWithDisplayList(100,.3,3,.2,0);
    skeleton->render();


	//drawCart(1.0);
	//Now that we've drawn on the buffer, swap the drawing buffer and the displaying buffer.
	glutSwapBuffers();

}

void saveFrame(int value){
	if (value<0)
		return;


    imgSaver->saveFrame();
    glutTimerFunc(1000/30, saveFrame, value-1);
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

void myMouseFunc(int button, int state, int x, int y) {
	if(editMode == ADD_VERTEX) {
		if(chosenVertex != -1 && state==GLUT_DOWN) {
			vec3 target = skeleton->getPos(vec2(x,y), chosenDepth);
			skeleton->addVertex(chosenVertex, target);
			coaster->addVertex(chosenVertex, target);
			coaster->clearDisplayList();
			chosenVertex = -1;
		} else if(state==GLUT_DOWN) {
			chosenVertex = skeleton->pickJoint(chosenDepth, vec2(x,y));
		}
		
	} else if(editMode == REMOVE_VERTEX) {
		chosenVertex = skeleton->pickJoint(chosenDepth, vec2(x,y));
		if(chosenVertex != -1) {
			skeleton->removeVertex(chosenVertex);
			coaster->removeVertex(chosenVertex);
			coaster->clearDisplayList();
			chosenVertex = -1;
		} 
	} else {
		chosenVertex = skeleton->pickJoint(chosenDepth, vec2(x,y));
	}
	if(editMode == MOVE_VERTEX && state == GLUT_UP) {
		chosenVertex = -1;
	} else {
	
	}
}

//-------------------------------------------------------------------------------
/// Called to handle keyboard events.
void myKeyboardFunc (unsigned char key, int x, int y) {
	switch (key) {
		case 27:			// Escape key
			exit(0);
			break;
        case 'S':
        case 's':
    	    skeleton->writeAsTRK();
            break;
        case 'V':
        case 'v':
        	chosenVertex = -1;
        	editMode = ADD_VERTEX;
        	break;
        case 'M':
        case 'm':
        	chosenVertex = -1;
        	editMode = MOVE_VERTEX;
        	break;
        case 'R':
        case 'r':
        	chosenVertex = -1;
        	editMode = REMOVE_VERTEX;
        	break;
        case 'A':
        case 'a':
        	chosenVertex = -1;
        	editMode = VERTEX_AZIMUTH;
        	break;
        case 'G':
        case 'g':
        	chosenVertex = -1;
        	editMode = GLOBAL_AZIMUTH;
        	break;
        case 'T':
        case 't':
        	chosenVertex = -1;
        	editMode = GLOBAL_TWIST;
        	break;
	}
}

//-------------------------------------------------------------------------------
/// Called whenever the mouse moves while a button is pressed
void myActiveMotionFunc(int x, int y) {

    if(editMode == MOVE_VERTEX && chosenVertex != -1  ) {
    	vec3 target = skeleton->getPos(vec2(x,y), chosenDepth); 
    	skeleton->moveVertex(chosenVertex, target);
    	coaster->moveVertex(chosenVertex, target);
    	coaster->clearDisplayList();
    } else if(editMode==VERTEX_AZIMUTH && chosenVertex != -1) {
    	double azimuth = ((((double) x)/600.0)*2*360.0) - 2*180.0;
    	skeleton->changeAzimuth(chosenVertex, azimuth);
    	coaster->changeAzimuth(chosenVertex, azimuth);
    	coaster->clearDisplayList();
    } else if(editMode==GLOBAL_AZIMUTH) {
    	double azimuth = ((((double) x)/600.0)*360.0) - 180.0;
    	skeleton->setGlobalAzimuth(azimuth);
    	coaster->setGlobalAzimuth(azimuth);
    	coaster->clearDisplayList();
    } else if(editMode==GLOBAL_TWIST) {
    	double twist = ((((double) x)/600.0)*360.0) - 180.0;
    	skeleton->setGlobalTwist(twist);
    	coaster->setGlobalTwist(twist);
    	coaster->clearDisplayList();
    } else{
    
		// Rotate viewport orientation proportional to mouse motion
		vec2 newMouse = vec2((double)x / glutGet(GLUT_WINDOW_WIDTH),(double)y / glutGet(GLUT_WINDOW_HEIGHT));
		vec2 diff = (newMouse - viewport.mousePos);
		double len = diff.length();
		if (len > .001) {
			vec3 axis = vec3(diff[1]/len, diff[0]/len, 0);
			viewport.orientation = rotation3D(axis, 180 * len) * viewport.orientation;
		}
	
		//Record the mouse location for drawing crosshairs
		viewport.mousePos = newMouse;
	
		//Force a redraw of the window.
		glutPostRedisplay();
		
    }
}


//-------------------------------------------------------------------------------
/// Called whenever the mouse moves without any buttons pressed.
void myPassiveMotionFunc(int x, int y) {
    //Record the mouse location for drawing crosshairs
    viewport.mousePos = vec2((double)x / glutGet(GLUT_WINDOW_WIDTH),(double)y / glutGet(GLUT_WINDOW_HEIGHT));
	//chosenVertex = -1;
	
    //Force a redraw of the window.
    glutPostRedisplay();
}

//-------------------------------------------------------------------------------
/// Called to update the screen at 30 fps.
void frameTimer(int value) {
    frameCount++;
    glutPostRedisplay();
    glutTimerFunc(1000/30, frameTimer, 1);
}



//-------------------------------------------------------------------------------
/// Initialize the environment
int main(int argc,char** argv) {
	//Initialize OpenGL
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);

	//Set up global variables
	viewport.w = 600;
	viewport.h = 600;

	if (argc < 2) {
	    cout << "USAGE: coaster coaster.trk" << endl;
	    return -1;
    } else {
        // Create the coaster
        coaster = new SplineCoaster(argv[1]);
        if (coaster->bad()) {
            cout << "Coaster file appears to not have a proper coaster in it" << endl;
            return -1;
        }
        skeleton = new SweepSkeleton(argv[1]);
    }

	//Initialize the screen capture class to save BMP captures
	//in the current directory, with the prefix "coaster"
	imgSaver = new UCB::ImageSaver("./", "coaster");

	//Create OpenGL Window
	glutInitWindowSize(viewport.w,viewport.h);
	glutInitWindowPosition(0,0);
	glutCreateWindow("CS184 Framework");

	//Register event handlers with OpenGL.
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(myKeyboardFunc);
	glutMotionFunc(myActiveMotionFunc);
	glutPassiveMotionFunc(myPassiveMotionFunc);
	glutMouseFunc(myMouseFunc);
    frameTimer(0);

    glClearColor(1,1,1,0);

    // set some lights
    {
       float ambient[3] = { .1f, .1f, .1f };
       float diffuse[3] = { .2f, .5f, .5f };
       float pos[4] = { 0, 5, -5, 0 };
       glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
       glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
       glLightfv(GL_LIGHT1, GL_POSITION, pos);
       glEnable(GL_LIGHT1);
    }
    {
       float ambient[3] = { .1f, .1f, .1f };
       float diffuse[3] = { .5f, .2f, .5f };
       float pos[4] = { 5, 0, -5, 0 };
       glLightfv(GL_LIGHT2, GL_AMBIENT, ambient);
       glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse);
       glLightfv(GL_LIGHT2, GL_POSITION, pos);
       glEnable(GL_LIGHT2);
    }
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);


	//And Go!
	glutMainLoop();
}
