//#pragma once
#ifndef _H_Mesh_H_
#define _H_Mesh_H_

#include <GL/freeglut.h>
#include <glm.hpp>

using namespace glm;

//-------------------------------------------------------------------------

class Mesh 
{
public:
	static Mesh* createRGBAxes(GLdouble l); // creates a new 3D RGB axes mesh
	static Mesh* generaPoliespiral(dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert);
	static Mesh* generaPoliespiral2(dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert);
	static Mesh* generaDragon(GLuint numVert);
	static Mesh* generaDragon2(GLuint numVert);
	static Mesh* generaTriangulo(GLdouble r);
	static Mesh* generaTrianguloRGB(GLdouble r);
	static Mesh* generaRectangulo(GLdouble w, GLdouble h);
	static Mesh* generaRectanguloRGB(GLdouble w, GLdouble h);
	static Mesh* generaEstrella3D(GLdouble re, GLdouble np, GLdouble h);
	static Mesh* generaContCubo(GLdouble l);
	static Mesh* generaRectanguloTexCor(GLdouble w, GLdouble h, GLuint rw, GLuint rh);
	static Mesh* generaEstrellaTexCor(GLdouble r, GLdouble nL, GLdouble h);
	static Mesh* generaCajaTexCor(GLdouble l);
	static Mesh* generaBaseTexCor(GLdouble l);
	static Mesh* generaCajaLateral(GLdouble l, GLdouble h);


	Mesh(void) { };
	~Mesh(void);
	virtual void render();

	glm::dvec3* getVertices() { return vertices; };  // vertex array
	glm::dvec4* getColors() { return colors; };      // color array
	glm::dvec2* getTexture() { return texture; };	// textura array
   
protected:

	GLuint numVertices = 0;   // arrays size (number of elements)
	GLuint primitive = GL_TRIANGLES;  // graphic primitive: GL_POINTS, GL_LINES, GL_TRIANGLES, ...

	glm::dvec3* vertices = nullptr;  // vertex array
	glm::dvec4* colors = nullptr;    // color array
	glm::dvec2* texture = nullptr; // textura array
};

class MBR : public Mesh 
{
public:
	MBR(GLuint puntos, GLuint rotaciones, dvec3* poriginal);

	void vertexBuilding();
	void normalize();
	virtual void render();

protected:
	GLuint m; //numero de puntos del perfil
	GLuint n; //numero de rotaciones (muestras) que se toman
	dvec3* perfil; //perfil original en el plano XY (definido de abajo a arriba)
	dvec3* normals = nullptr; //normals array
};

//-------------------------------------------------------------------------

#endif //_H_Scene_H_