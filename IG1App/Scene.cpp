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
  // grObjects.push_back(new EjesRGB(200.0)); 

  //grObjects.push_back(new Poliespiral( dvec2(0,0) , 1.0, 50.0, 3.0, 4.0, 1000.0 ) );
  //grObjects.push_back(new Poliespiral2(dvec2(0, 0), 1.0, 100.0, 3.0, 4.0, 1000.0));


  //  grObjects.push_back(new Poliespiral(dvec2(0, 50), 0.0, 72.0, 30.0, 0.001, 6.0));
   // grObjects.push_back(new Dragon(3000));

//	grObjects.push_back(new TrianguloRGB(2));
  //grObjects.push_back(new RectanguloRGB(20,20));
  //grObjects.push_back(new Dragon(3000));
  //grObjects.push_back(new Estrella3D(15, 6,15 ));
  //grObjects.push_back(new Cubo(150));
  //grObjects.push_back(new RectanguloRGB(300, 200));

  grObjects.push_back(new TrianguloAnimado(10));


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

void Scene::render(Camera const& cam)
{
	for (Entity* el: grObjects)
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