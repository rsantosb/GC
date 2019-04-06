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
Viewport viewPort(800, 600);   

// Camera position, view volume and projection
Camera camera(&viewPort);    

// Graphics objects of the scene
Scene scene;   

GLuint last_updated_tick = 0;

bool animacion = true;

//Declarar dos variables para guardar las coordenadas de ratón
glm::dvec2 mCoord;
int mBot = 0;

//----------- Callbacks ----------------------------------------------------

void display();
void resize(int newWidth, int newHeight);
void key(unsigned char key, int x, int y);
void specialKey(int key, int x, int y);
void update();

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
  
  glutInitWindowSize(800, 600);   // window size
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
  camera.set3D();
  scene.init();    
  
  glutMainLoop(); 
    
  //cin.ignore(INT_MAX, '\n');  cin.get();  
  glutDestroyWindow(win);  // Destroy the context 
 
  return 0;
}
//-------------------------------------------------------------------------

void display()   // double buffering
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   
  
  scene.render(camera.getViewMat());   
    
  glutSwapBuffers();  
}
//-------------------------------------------------------------------------

void update()
{

	bool need_redisplay = true;
	GLuint tiempo = glutGet(GLUT_ELAPSED_TIME)- last_updated_tick;

	if (animacion == true && tiempo > 50 ) {
		scene.update(glutGet(GLUT_ELAPSED_TIME) - last_updated_tick);
		last_updated_tick = glutGet(GLUT_ELAPSED_TIME);
	}
	
	if(need_redisplay)
		glutPostRedisplay();

}

void resize(int newWidth, int newHeight)
{
  // Resize Viewport 
  viewPort.uploadSize(newWidth, newHeight);  
  
  // Resize Scene Visible Area 
  camera.uploadSize(viewPort.getW(), viewPort.getH());    // scale unchanged
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
    camera.uploadScale(+0.01);   // zoom in  (increases the scale)
    break;
  case '-':
    camera.uploadScale(-0.01);   // zoom out (decreases the scale)
    break;
  case 'l':
	camera.set3D(); 
	break;
  case 'o':
	camera.set2D();
	break;
  case 'u':
    scene.update();
	break;
  case 'U': {
	  if (animacion == true)
		  animacion = false;
	  else
		  animacion = true;
	  break;
  }
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
	  camera.setCenital();
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
    camera.pitch(1);   // rotate 1 on the X axis
    break;
  case GLUT_KEY_LEFT:
    camera.yaw(1);     // rotate 1 on the Y axis 
    break;
  case GLUT_KEY_UP:
    camera.roll(1);    // rotate 1 on the Z axis
    break;
  case GLUT_KEY_DOWN:
    camera.roll(-1);   // rotate -1 on the Z axis
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

	// Calcular el desplazamiento habido
	mp = mCoord - mp;

	if (mBot == GLUT_LEFT_BUTTON)
	{
		//Recuerda que mp.x son radianes. Reducelos a tu gusto
		camera.orbit(mp.x*0.05, mp.y);
	}
	else if (mBot == GLUT_RIGHT_BUTTON)
	{
		camera.moveUD(mp.y);
		camera.moveLR(-mp.x);
	}

	glutPostRedisplay();
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
			camera.moveFB(5);
		}
		else
		{
			camera.moveFB(-5);
		}

	}
	else if (m == GLUT_ACTIVE_CTRL)
	{
		if (d == 1)
		{
			camera.uploadScale(0.1);
		}
		else
		{
			camera.uploadScale(-0.1);
		}
	}

	glutPostRedisplay();
}