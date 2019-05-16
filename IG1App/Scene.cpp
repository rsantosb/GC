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
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);

	GLfloat amb0[] = { 0.0, 0.0, 0.0, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb0);

	//EMPIEZA APARTADO  19
	// Luz es un tipo DirLight que se declara en Scene.h
	luz = DirLight(); //La creo por lo que se activa
	luz.setPosDir(fvec3(1.0, 1.0, 0.0)); // Modifico la posición
	luz.setDiff(fvec4(1.0, 1.0, 1.0, 1.0)); //La difusa
	luz.setAmb(fvec4(0.2, 0.2, 0.2, 1.0)); //La ambiente
	luz.setSpec(fvec4(0.5, 0.5, 0.5, 1.0)); // La especular
	
	luz.enable();

	//APARTADO 20

	//OJO DESACTIVO ColorMaterial
	glDisable(GL_COLOR_MATERIAL);
	//Ahora quito el color de la esfera por revolución.


	
	// textures  
	// meshes

	// Graphics objects (entities) of the scene

	//EjesRGB -> Ejemplo de clase
	grObjects.push_back(new EjesRGB(200.0));

	//aspaNoria();
	//noria(15);

	//grObjects.push_back(new Cylinder(100, 100, 50, 200, 10));
	
	//ROTOR
	//grObjects.push_back(new Rotor(100, false, false));

	//CHASIS
	//grObjects.push_back(new Chasis());

	//DRON
	//grObjects.push_back(new Dron());
	
	//CONO REVOLUCION
	//grObjects.push_back(new Cone(100, 50));
	
	//ESFERA REVOLUCION
	grObjects.push_back(new Esfera(50, 58, 100));

	//grObjects.push_back(new Sphere(50));
	
	//SATELITE DRON GIRANDO
	//grObjects.push_back(new Satelite(200));

	//EsferaDron 
	//grObjects.push_back(esferaDron);

	

	

}
//-------------------------------------------------------------------------


void Scene::init2()
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

	//aspaNoria();
	//noria(15);

	//grObjects.push_back(new Cylinder(100, 100, 50, 200, 10));

	//ROTOR
	//grObjects.push_back(new Rotor(100, false, false));

	//CHASIS
	//grObjects.push_back(new Chasis());

	//DRON
	//grObjects.push_back(new Dron());

	//CONO REVOLUCION
	//grObjects.push_back(new Cone(100, 50));

	//ESFERA REVOLUCION
	//grObjects.push_back(new Esfera(50, 58, 100));

	//SATELITE DRON GIRANDO
	//grObjects.push_back(new Satelite(200));

	//grObjects.push_back(esferaDron);

	//DRON CON DRONCITOS
	grObjects.push_back(new Dronitos());

}
//------------------------------

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
	luz.upload(modelViewMat);
	for (Entity* el: grObjects)
	{
		el->render(modelViewMat);
	}
}
/*
//-------------------------------------------------------------------------

void Scene::update() {
	for (Entity* entity : grObjects) {
		entity->update();
	}
}
*/
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

/*
void Scene::update(GLuint timeElapsed) {
	for (Entity* entity : grObjects) {
		entity->update(timeElapsed);
	}
}
*/


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



void Scene::move(GLuint tecla)
{
	switch (tecla) {
	case GLUT_KEY_UP:
		esferaDron->updateNuevo(4);
		break;
	case GLUT_KEY_DOWN:
		//El dron debe bajar
		esferaDron->updateNuevo(3);
		break;

	case GLUT_KEY_RIGHT:
		esferaDron->updateNuevo(2);
		break;
	case GLUT_KEY_LEFT:
		esferaDron->updateNuevo(1);
		break;
	}
		//switch 
}
