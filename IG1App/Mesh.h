//#pragma once
#ifndef _H_Mesh_H_
#define _H_Mesh_H_

#include <GL/freeglut.h>
#include <glm.hpp>

//-------------------------------------------------------------------------

class Mesh{
public:

	static Mesh * createRGBAxes(glm::dvec2 center, GLdouble l); // creates a new 3D RGB axes mesh
	static Mesh * generaPoliespiral(glm::dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert);
	static Mesh * generadragon(glm::dvec2 center, GLuint numVert);
	static Mesh* generaTrianguloRGB(glm::dvec2 center, GLdouble r);
	static Mesh* generaRectangulo(glm::dvec2 center, GLdouble w, GLdouble h);
	static Mesh* generaRectanguloRGB(glm::dvec2 center, GLdouble w, GLdouble h);
	static Mesh* generaEstrella3D(glm::dvec2 center, GLdouble re, GLdouble np, GLdouble h);
	static Mesh* generaCubo(glm::dvec3 center, GLdouble w, GLdouble h);

	Mesh(void) { };
	~Mesh(void);
	virtual void render();

	glm::dvec3* getVertices() { return vertices; };  // vertex array
	glm::dvec4* getColors() { return colors; };      // color array
   
protected:

	GLuint numVertices = 0;   // arrays size (number of elements)
	GLuint primitive = GL_TRIANGLES;  // graphic primitive: GL_POINTS, GL_LINES, GL_TRIANGLES, ...

	glm::dvec3* vertices = nullptr;  // vertex array
	glm::dvec4* colors = nullptr;    // color array
};

//-------------------------------------------------------------------------

#endif //_H_Scene_H_