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

	aspaNoria();

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
	Entity* c = new Cangilon(100);
	c->modelMat = rotate(c->modelMat, 0.0, dvec3(0, 0, 1));
	c->modelMat = translate(c->modelMat, dvec3(40, 0, 0));

	c->modelMat = rotate(c->modelMat, 0.0, dvec3(0, 0, 1));
	grObjects.push_back(c);
	grObjects.push_back(new TableroIzq(100));
	grObjects.push_back(new TableroDch(100));
}