//#pragma once
#ifndef _H_Scene_H_
#define _H_Scene_H_

#include <GL/freeglut.h>
#include <glm.hpp>

#include "Camera.h"
#include "Entity.h"
#include "Light.h"
//#include "Mesh.h"

#include <vector>

//-------------------------------------------------------------------------

class Scene	: public CompoundEntity
{ 
public:
    Scene() { };
	~Scene();
	void render(dmat4 const & modelViewMat);
    void init(); 
	void init2();

    //void render(dmat4 const& modelViewMat);
	//void update();
	//void update(GLuint timeElapsed);
	void cambiar2D();
	void cambiar3D();
	void aspaNoria();
	void noria(GLuint aspas);
	void setLuzDireccion(bool encender);
	void setLuzMinero(bool encender);
	//void move(GLuint tecla);

	  
protected:

	  //std::vector<Entity*> grObjects;  // Entities (graphics objects) of the scene

	  EsferaDron* esferaDron = new EsferaDron(100);

	  DirLight* luz;
	  SpotLight* minero;
};

//-------------------------------------------------------------------------

#endif //_H_Scene_H_

