#include "Scene.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Scene::init()
{ // OpenGL basic setting
	glClearColor(1.0, 1.0, 1.0, 1.0);  // background color (alpha=1 -> opaque)
	glEnable(GL_DEPTH_TEST);  // enable Depth test 
	glEnable(GL_TEXTURE_2D); // activa las texturas
     
	// lights
	// textures  
	// meshes

	// Graphics objects (entities) of the scene

	//EjesRGB -> Ejemplo de clase
	//grObjects.push_back(new EjesRGB(200.0)); 


	/*
		Ejercicio 1 POLIESPIRAL
	*/
	
	//grObjects.push_back(new Poliespiral( dvec2(0,0) , 1.0, 50.0, 3.0, 4.0, 1000.0 ) );
	//Cambios en el algoritmo de POLIESPIRAL generado POLIESPIRAL2
	//grObjects.push_back(new Poliespiral2(dvec2(0, 0), 1.0, 100.0, 3.0, 4.0, 1000.0));


	//grObjects.push_back(new Poliespiral(dvec2(0, 50), 0.0, 72.0, 30.0, 0.001, 6.0));

	/*
		Ejercicio 2 DRAGON
	*/
   
	//grObjects.push_back(new Dragon(3000));

	/*
		Ejercicio 3 TRIANGULORGB
	*/

	//grObjects.push_back(new TrianguloRGB(2));

	/*
		Ejercicio 4 RECTANGULORGB
	*/
	//grObjects.push_back(new RectanguloRGB(20,20));

	/*
		Ejercicio 5 ESCENA 2D
	*/
	//grObjects.push_back(new Poliespiral(dvec2(0, 0), 1.0, 50.0, 3.0, 4.0, 1000.0) );
	//grObjects.push_back(new Dragon(3000));
	//grObjects.push_back(new TrianguloAnimado(10));

	/*
		Ejercicio 6 ESTRELLA 3D 
		Ejercicio 9 Modificar estrella 3D
	*/
	//grObjects.push_back(new Estrella3D(15, 6,15 ));

	/*
		Ejercicio 7 Caja / Cubo
		Ejercicio 10 Modificar Caja / Cubo
	*/
	//grObjects.push_back(new Cubo(150));
	//grObjects.push_back(new Suelo(300, 200));

	/*
		Ejercicio 8 ESCENA 3D
	*/
	//grObjects.push_back(new Estrella3D(15, 6, 25));
	//grObjects.push_back(new Cubo(150));
	//grObjects.push_back(new Suelo(300, 200));

	/*
		Ejercicio 12 TEXTURAS
	*/
	grObjects.push_back(new SueloTextura(75, 55, 7, 5));

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