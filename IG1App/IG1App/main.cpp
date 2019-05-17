//#include <Windows.h>
//#include <gl/GL.h>    // OpenGL
//#include <gl/GLU.h>   // OpenGL Utility Library
//#include <GL/glut.h>  // OpenGL Utility Toolkit

#include <GL/freeglut.h>  // Free OpenGL Utility Toolkit for creating windows, initializing OpenGL contexts, and handling input events
#include <glm.hpp>  // OpenGL Mathematics. A C++ mathematics library for graphics programming 

#include "Viewport.h"
#include "Camera.h"
#include "Scene.h"

#include <iostream>

using namespace std;

//---------- Global variables -------------------------------------------------------------

// Viewport position and size

Viewport* viewPort = new Viewport(800, 600);  
Viewport* viewPort2 = new Viewport(800, 600);

//Viewport viewPort(800, 600);

// Camera position, view volume and projection
Camera* camera = new Camera(viewPort);    
Camera* camera2 = new Camera(viewPort2);

//Camera camera(&viewPort);

// Graphics objects of the scene
Scene scene;   
Scene scene2;

GLuint last_updated_tick = 0;

bool animacion = true;
bool baldosas = false;
bool twoPorts = false;
bool luz = true;
bool minero = true;
bool dron = true;

GLfloat apagado[] = { 0.0 ,0.0 ,0.0 ,1.0 };
GLfloat encendido[] = { 0.5, 0.5, 0.5, 1.0 };//{ 1.0, 1.0, 1.0, 1.0 }; // {0.5, 0.5, 0.5, 1.0} Debería ser esta

//Declarar dos variables para guardar las coordenadas de ratón
glm::dvec2 mCoord;
int mBot = 0;

int CLIENT_WIDTH = 800;
int CLIENT_HEIGHT = 600;
//----------- Callbacks ----------------------------------------------------

void display();
void resize(int newWidth, int newHeight);
void key(unsigned char key, int x, int y);
void specialKey(int key, int x, int y);
void update();
void embaldosar(int nCol);

//Añado callbacks de las diapositivas de cámara (17)
//Se genera cuando se presiona o se suelta el botón del ratón
//(button) y recoge en coordenadas de ventana (x,y) el momento en que
//el estado (state) del botón cambió y pasó a estar pulsado o soltado
void mouse(int button, int state, int x, int y);

//Se genera cuando un botón del ratón se encuentra pulsado y recoge,
//en coordenadas de la ventana (x,y) el lugar donde se soltó.
void motion(int x, int y);

void mouseWheel(int n, int d, int x, int y);
//-------------------------------------------------------------------------

int main(int argc, char *argv[])
{
	cout << "Starting console..." << '\n';

	// Initialization
	glutInit(&argc, argv);

	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);  // GLUT_CORE_PROFILE
	glutInitContextFlags(GLUT_DEBUG);   // GLUT_FORWARD_COMPATIBLE
 
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS); 
  
	//glutInitWindowSize(800, 600);   // window size
	glutInitWindowSize(CLIENT_WIDTH, CLIENT_HEIGHT);
	//glutInitWindowPosition (140, 140);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH /*| GLUT_STENCIL*/); // RGBA colors, double buffer, depth buffer and stencil buffer   
  
	int win = glutCreateWindow("IG1App");  // window's identifier
  
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutSpecialFunc(specialKey);
	glutDisplayFunc(display);
	glutIdleFunc(update);
	//Registramos los nuevos eventos de raton (diap. 18 camara)
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutMouseWheelFunc(mouseWheel);

	cout << glGetString(GL_VERSION) << '\n';
	cout << glGetString(GL_VENDOR) << '\n';

	// after creating the context
	camera->set3D();
	scene.init();
	scene2.init2();
	camera2->set3D();
  
	glutMainLoop(); 
    
	//cin.ignore(INT_MAX, '\n');  cin.get();  
	glutDestroyWindow(win);  // Destroy the context 
 
	return 0;
}
//-------------------------------------------------------------------------

void display()   // double buffering
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   
  
	if (twoPorts) {

		GLdouble ancho = glutGet(GLUT_WINDOW_WIDTH);

		GLdouble SVAratio = (camera->getxRight() - camera->getxLeft()) / (camera->getyTop() - camera->getyBot());
		GLdouble w = (GLdouble)ancho / (GLdouble)2;
		GLdouble h = w / SVAratio;

		Viewport * vp1 = new Viewport(w, h);
		vp1->uploadPos((GLint)0, (GLint)h/2);
		vp1->upload();
		camera->setVP(vp1);
		camera->uploadPM();
		scene.render(camera->getViewMat());

		Viewport * vp2 = new Viewport(w, h);
		vp2->uploadPos((GLint)w, (GLint)h/2);
		vp2->upload();
		camera2->setVP(vp2);
		camera2->uploadPM();
		scene2.render(camera2->getViewMat());

	}
	else {
		if (baldosas) {
			embaldosar(2);
		}
		else {
			Viewport* vp = new Viewport(CLIENT_WIDTH, CLIENT_HEIGHT);
			vp->upload();
			camera->setVP(vp);
			scene.render(camera->getViewMat());
		}
	}
    
	glutSwapBuffers();  
}
//-------------------------------------------------------------------------

void update()
{

	bool need_redisplay = true;
	GLuint tiempo = glutGet(GLUT_ELAPSED_TIME)- last_updated_tick;

	if (animacion == true && tiempo > 50 ) {
		if (twoPorts) {
			scene2.update(glutGet(GLUT_ELAPSED_TIME) - last_updated_tick);
		}
		scene.update(glutGet(GLUT_ELAPSED_TIME) - last_updated_tick);
		last_updated_tick = glutGet(GLUT_ELAPSED_TIME);
	}
	
	if(need_redisplay)
		glutPostRedisplay();

}

void embaldosar(int nCol)
{
	GLdouble SVAratio = (camera->getxRight() - camera->getxLeft()) / (camera->getyTop() - camera->getyBot());
	GLdouble w = (GLdouble)CLIENT_WIDTH / (GLdouble)nCol;
	GLdouble h = w / SVAratio;
	
	for (GLint c = 0; c < nCol; c++) {
		GLdouble currentH = 0;
		while ((currentH + h) <= CLIENT_HEIGHT) {
			Viewport* vp = new Viewport((GLint)w, (GLint)h);
			vp->uploadPos((GLint)(c*w), (GLint)currentH);
			vp->upload();
			camera->setVP(vp);
			scene.render(camera->getViewMat());
			currentH += h;
		} //del while
	} // del for
}

void resize(int newWidth, int newHeight)
{
	CLIENT_WIDTH = newWidth;
	CLIENT_HEIGHT = newHeight;
	// Resize Viewport 
	viewPort->uploadSize(newWidth, newHeight);  
	if (twoPorts) {
		viewPort2->uploadSize(newWidth, newHeight);
	}
  
	// Resize Scene Visible Area 
	camera->uploadSize(viewPort->getW(), viewPort->getH());    // scale unchanged
	if (twoPorts) {
		camera2->uploadSize(viewPort2->getW(), viewPort2->getH());
	}
}
//-------------------------------------------------------------------------

void key(unsigned char key, int x, int y)
{
	bool need_redisplay = true;

	switch (key) {
		case 27:  // Escape key 
			glutLeaveMainLoop();  // Freeglut's sentence for stopping glut's main loop 
			break;
		case '+': 
			if (twoPorts) {
				camera2->uploadScale(+0.01);   // zoom in  (increases the scale)
			}
			camera->uploadScale(+0.01);   // zoom in  (increases the scale)
			break;
		case '-':
			if (twoPorts) {
				camera2->uploadScale(-0.01);
			}
			camera->uploadScale(-0.01);   // zoom out (decreases the scale)
			break;
		case 'l':
			if (twoPorts) {
				camera2->set3D();
			}
			camera->set3D(); 
			break;
		case 'o':
			if (twoPorts) {
				camera2->set2D();
			}
			camera->set2D();
			break;
		case 'u':
			if (twoPorts) {
				scene2.update();
			}
			scene.update();
			break;
		case 'U': {
			if (animacion == true)
				animacion = false;
			else
				animacion = true;
			break;
		}
		case 'p': {
			if (twoPorts) {
				if (camera2->getOrto() == true) {
					camera2->setOrto(false);
				}
				else {
					camera2->setOrto(true);
				}
				camera2->uploadPM();
			}
			if (camera->getOrto() == true) {
				camera->setOrto(false);
			}
			else {
				camera->setOrto(true);
			}
			camera->uploadPM();
			break;
		}
		case '1':
			luz = !luz;
			scene.setLuzDireccion(luz);
			break;
		case '2':
			minero = !minero;
			scene.setLuzMinero(minero);
			break;
		case '3':
			if (dron)
			{
				dron = false;
				scene.move(9);
			}
			else {
				dron = true;
				scene.move(8); //true arriba
			}
			break;
		/*case '3':
			if (dron) {
				dron = false;
				glDisable(GL_LIGHT1);
			}
			else {
				dron = true;
				glEnable(GL_LIGHT1);
			}
			break;*/
		/*case '2':
			scene.~Scene();
			scene.cambiar2D();
			break;
		case '3':
			scene.~Scene();
			scene.cambiar3D();
			break;
		*/
		case 'c':
			if (twoPorts) {
				camera2->setCenital();
			}
			camera->setCenital();
			break;
		case 'h':
			if (baldosas == true) {
				baldosas = false;
			}
			else baldosas = true;
			break;
		case 'j':
			if (twoPorts == true) {
				twoPorts = false;
			}
			else twoPorts = true;
			break;
		case 'k':
			if (twoPorts) {
				camera2->yaw(1);
			}
			break;
		case 'm':
			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, encendido);
			break;
		case 'n':
			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, apagado);
			break;
		default:
			need_redisplay = false;
			break;
	} //switch

	if (need_redisplay)
		glutPostRedisplay();
}
//-------------------------------------------------------------------------

void specialKey(int key, int x, int y)
{
	bool need_redisplay = true;

	switch (key) {
		case GLUT_KEY_RIGHT:
			//camera.pitch(1);   // rotate 1 on the X axis
			scene.move(GLUT_KEY_RIGHT);
			break;
		case GLUT_KEY_LEFT:
			//camera.yaw(1);     // rotate 1 on the Y axis 
			scene.move(GLUT_KEY_LEFT);
			break;
		case GLUT_KEY_UP:
			//camera.roll(1);    // rotate 1 on the Z axis
			scene.move(GLUT_KEY_UP); //true arriba
			break;
		case GLUT_KEY_DOWN:
			//camera.roll(-1);   // rotate -1 on the Z axis
			scene.move(GLUT_KEY_DOWN); // false abajo
			break;
		default:
			need_redisplay = false;
			break;
	}//switch

	if (need_redisplay)
		glutPostRedisplay();
}
//-------------------------------------------------------------------------

void mouse(int button, int state, int x, int y) {
	mBot = button;
	mCoord = glm::dvec2(x, y);

	//la variable y se refiere a coordenadas de ventana y esta tiene 
	//origen en la esquina superior izquierda, mientras que en el 
	//puerto de vista el origen está en la esquina inferior izquierda.
	//El paso de una a otra es:
	
	// y(viewPort) = glutGet(GLUT_WINDOW_HEIGHT) - y ;
}

void motion(int x, int y) {
	// GLUT_LEFT_BUTTON / GLUT_RIGHT_BUTTON botones del ratón
	// GLUT_UP / GLUT_DOWN estado del boton (soltado o pulsado)
	//Guardamos mCoord cuando se pulsó el botón
	glm::dvec2 mp = mCoord;
	mCoord = glm::dvec2(x, y);

	if (twoPorts) {

		bool izquierda = false;
	
		mp = mCoord - mp;

		if (mCoord.x < CLIENT_WIDTH / 2) {
			izquierda = true;
		}
		else {
			izquierda = false;
		}

	
		if (mBot == GLUT_LEFT_BUTTON) {
			if(izquierda) camera->orbit(mp.x * 0.5, mp.y);
			else camera2->orbit(mp.x * 0.5, mp.y);
		}
		else if (mBot == GLUT_RIGHT_BUTTON) {
			if (izquierda) {
				camera->moveUD(mp.y);
				camera->moveLR(-mp.x);
			}
			else {
				camera2->moveUD(mp.y);
				camera2->moveLR(-mp.x);
			}
			
		}
		glutPostRedisplay();

	}
	else {
		// Calcular el desplazamiento habido
		mp = mCoord - mp;

		if (mBot == GLUT_LEFT_BUTTON)
		{
			//Recuerda que mp.x son radianes. Reducelos a tu gusto
			camera->orbit(mp.x*0.5, mp.y);
		}
		else if (mBot == GLUT_RIGHT_BUTTON)
		{
			camera->moveUD(mp.y);
			camera->moveLR(-mp.x);
		}

		glutPostRedisplay();
	}

	
}

void mouseWheel(int n, int d, int x, int y)
{
	//Se identifica cuántes de las teclas posibles
	// GLUT_ACTIVE_CTRL/ALT/_SHIFT están pulsadas
	int m = glutGetModifiers();

	if (m == 0) //Si ninguna tecla pulsada,
	{
		//desplazar en la dirección de vista d

		if (d == 1)
		{
			camera->moveFB(10);
			if (twoPorts) camera2->moveFB(10);
		}
		else
		{
			camera->moveFB(-10);
			if (twoPorts) camera2->moveFB(-10);
		}
	}
	else if (m == GLUT_ACTIVE_CTRL)
	{
		glm::dvec2 mp = mCoord;
		mCoord = glm::dvec2(x, y);

		bool izquierda = false;

		if (mCoord.x < CLIENT_WIDTH / 2) {
			izquierda = true;
		}
		else {
			izquierda = false;
		}

		if (d == 1)
		{
			if (twoPorts) {
				if (izquierda) camera->uploadScale(0.1);
				else camera2->uploadScale(0.1);
			}
			else {
				camera->uploadScale(0.1);
			}

		}
		else
		{
			if (twoPorts) {
				if (izquierda) camera->uploadScale(-0.1);
				else camera2->uploadScale(-0.1);
			}
			else
			{
				camera->uploadScale(-0.1);
			}
		}

		glutPostRedisplay();
	}
}