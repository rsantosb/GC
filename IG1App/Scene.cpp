#include "Scene.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Scene::init()
{ // OpenGL basic setting
	glClearColor(1.0, 1.0, 1.0, 1.0);  // background color (alpha=1 -> opaque)
	glEnable(GL_DEPTH_TEST);  // enable Depth test 

	// lights
	// textures  
	// meshes

	// Graphics objects (entities) of the scene
	grObjects.push_back(new EjesRGB(dvec2(0.0, 0.0), 200));
	grObjects.push_back(new EjesRGB(dvec2(50.0,50.0), 2));
	//grObjects.push_back(new Estrella3D(dvec3(0.0, 0.0, 0.0), 155.0, 6.0, 150.0));

	/*grObjects.push_back(new Poliespiral(dvec2(-200.0, -150.0), 0.0, 160.0, 1.0, 1.0, 50));
	grObjects.push_back(new Poliespiral(dvec2(-100.0, -150.0), 0.0, 72.0, 30.0, 0.001, 6));
	grObjects.push_back(new Poliespiral(dvec2(0.0, -150.0), 0.0, 60.0, 0.5, 0.5, 100));
	grObjects.push_back(new Poliespiral(dvec2(100.0, -150.0), 0.0, 89.5, 0.5, 0.5, 100));
	grObjects.push_back(new Poliespiral(dvec2(200.0, -150.0), 0.0, 45, 1.0, 1.0, 50));
	grObjects.push_back(new Dragon(dvec2(0.0, 0.0), 6000));
	grObjects.push_back(new TrianguloRGB(dvec2(-300.0, -150.0), 50));*/
	//grObjects.push_back(new Rectangulo(dvec2(0.0, 0.0), 100.0, 100.0));
	//grObjects.push_back(new Cubo(dvec3(50.0, 50.0, 50.0), 100.0, 100.0));
	
	/*Entity * ent = new Cubo(dvec3(0.0, 0.0, 0.0), 50.0, 50.0);
	ent->setModelMat(scale(ent->getModelMat(), dvec3(2.0, 2.0, 2.0)));
	grObjects.push_back(ent);

	ent = new Cubo(dvec3(0.0, 0.0, 0.0), 50.0, 50.0);
	ent->setModelMat(scale(ent->getModelMat(), dvec3(3.0, 3.0, 3.0)));
	grObjects.push_back(ent);

	ent = new Cubo(dvec3(0.0, 0.0, 0.0), 50.0, 50.0);
	ent->setModelMat(scale(ent->getModelMat(), dvec3(4.0, 4.0, 4.0)));
	grObjects.push_back(ent);

	ent = new Cubo(dvec3(0.0, 0.0, 0.0), 50.0, 50.0);
	ent->setModelMat(scale(ent->getModelMat(), dvec3(5.0, 5.0, 5.0)));
	grObjects.push_back(ent);*/

	/*Entity * ent = new Caja(dvec3(50.0, 50.0, 0.0), 100.0, 100.0);
	grObjects.push_back(ent);*/

	//grObjects.push_back(new RectanguloRGB(dvec2(-300.0, 50.0), 100.0, 50.0));
	
	//grObjects.push_back(new RectanguloRGB(dvec2(200.0, 0.0), 50.0, 50.0));

	Entity * ent = new TrianguloAnimado(dvec3(50.0, 50.0, 0.0), 50.0, 0.0);
	ent->setModelMat(scale(ent->getModelMat(), dvec3(2.0, 2.0, 2.0)));
	grObjects.push_back(ent);
}
//-------------------------------------------------------------------------

Scene::~Scene()
{ // free memory and resources   

	for (Entity* el : grObjects)
	{
		delete el;
	}
}
//-------------------------------------------------------------------------

void Scene::render(Camera const& cam)
{
	for (Entity* el : grObjects)
	{
		el->render(cam);
	}
}
//-------------------------------------------------------------------------

void Scene::update() {
	for (Entity* entity : grObjects) {
		entity->update();
	}
}
//-------------------------------------------------------------------------