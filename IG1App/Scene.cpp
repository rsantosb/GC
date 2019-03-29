#include "Scene.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Scene::init()
{ // OpenGL basic setting
	glClearColor(0.6f, 0.7f, 0.8f, 1.0);  // background color (alpha=1 -> opaque)
	glEnable(GL_DEPTH_TEST);  // enable Depth test 
	glEnable(GL_TEXTURE_2D); // activa las texturas

	// lights
	// textures  
	// meshes

	// Graphics objects (entities) of the scene

	//EjesRGB -> Ejemplo de clase
	grObjects.push_back(new EjesRGB(200.0));

	//grObjects.push_back(new Cylinder(100, 100, 50, 200, 10));
	//grObjects.push_back(new Rotor(100, false, false));

	//grObjects.push_back(new Chasis());
	//grObjects.push_back(new Chasis());
	//grObjects.push_back(new Dron());
	
	//grObjects.push_back(new Cone(100, 50));
	grObjects.push_back(new Esfera(50, 58, 100));
	//aspaNoria();
	//noria(15);

}
//-------------------------------------------------------------------------

Scene::~Scene()
{ // free memory and resources   
  
  for (Entity* el: grObjects)
  {
	  delete el;  el = nullptr;
  }
}
//-------------------------------------------------------------------------

void Scene::render(dmat4 const& modelViewMat)
{
	for (Entity* el: grObjects)
	{
		el->render(modelViewMat);
	}
}

//-------------------------------------------------------------------------

void Scene::update() {
	for (Entity* entity : grObjects) {
		entity->update();
	}
}

//-------------------------------------------------------------------------

void Scene::cambiar2D() {
	grObjects.push_back(new Poliespiral(dvec2(0, 0), 1.0, 50.0, 3.0, 4.0, 1000.0));
	grObjects.push_back(new TrianguloAnimado(15));
	grObjects.push_back(new Dragon(3000));
}

//-------------------------------------------------------------------------

void Scene::cambiar3D() {

	grObjects.push_back(new SueloTextura(1500, 1500, 20, 10));
	grObjects.push_back(new EstrellaTexturaAnimada(15, 6, 15));
	grObjects.push_back(new CajaTextura(150));

}

void Scene::update(GLuint timeElapsed) {
	for (Entity* entity : grObjects) {
		entity->update(timeElapsed);
	}
}

void Scene::aspaNoria() {
	
	grObjects.push_back(new Cangilon(100));
	grObjects.push_back(new TableroIzq(100));
	grObjects.push_back(new TableroDch(100));

}

void Scene::noria(GLuint aspas) {

	GLdouble angulo = 360 / aspas;
	GLdouble ang = 0;

	for (GLuint i = 0; i < aspas; i++) {
		grObjects.push_back(new Cangilon(100, ang));
		grObjects.push_back(new TableroIzq(100, ang));
		grObjects.push_back(new TableroDch(100, ang));
		ang = ang + angulo;
	}

}