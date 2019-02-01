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

  grObjects.push_back(new Poliespiral( dvec2(0,0) , 0.0, 160.0, 1.0, 1.0, 50.0 ) );
  grObjects.push_back(new Poliespiral(dvec2(0, 50), 0.0, 72.0, 30.0, 0.001, 6.0));
  grObjects.push_back(new Poliespiral(dvec2(-100, -100), 0.0, 60.0, 0.5, 0.5, 300.0));
  grObjects.push_back(new Poliespiral(dvec2(50, 0), 0.0, 89.5, 0.5, 0.5, 100.0));
  grObjects.push_back(new Poliespiral(dvec2(-50, 0), 0.0, 45.0, 1.0, 1.0, 50.0));
 
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

