//#pragma once
#ifndef _H_Scene_H_
#define _H_Scene_H_

#include <GL/freeglut.h>
#include <glm.hpp>

#include "Camera.h"
#include "Entity.h"
//#include "Mesh.h"

#include <vector>

//-------------------------------------------------------------------------

class Scene	
{ 
public:
    Scene() { };
	~Scene();
    void init(); 

    void render(dmat4 const& modelViewMat);
	void update();
	void update(GLuint timeElapsed);
	void cambiar2D();
	void cambiar3D();
	void aspaNoria();
	  
protected:

	  std::vector<Entity*> grObjects;  // Entities (graphics objects) of the scene
};

//-------------------------------------------------------------------------

#endif //_H_Scene_H_

