//#pragma once
#ifndef _H_Entities_H_
#define _H_Entities_H_

#include <GL/freeglut.h>
#include <glm.hpp>

#include "Camera.h"
#include "Mesh.h"

//-------------------------------------------------------------------------

class Entity
{
public:
	Entity() : modelMat(1.0) { };
	virtual ~Entity() { };

	virtual void render(Camera const& cam) = 0;
	virtual void update() = 0;

	// modeling matrix
	glm::dmat4 const& getModelMat() const { return modelMat; };

	void setModelMat(glm::dmat4 const& aMat) { modelMat = aMat; }

protected:

	Mesh* mesh = nullptr;   // surface mesh
	Mesh* meshP0 = nullptr;
	Mesh* meshP1 = nullptr;
	glm::dmat4 modelMat;    // modeling matrix

	// transfers modelViewMat to the GPU
	virtual void uploadMvM(glm::dmat4 const& modelViewMat) const;
};

//-------------------------------------------------------------------------

class EjesRGB : public Entity
{
public:
	EjesRGB(glm::dvec2 center, GLdouble l);
	~EjesRGB() { delete mesh; };
	virtual void render(Camera const& cam);
	virtual void update();
};

//-------------------------------------------------------------------------


class Poliespiral : public Entity
{
public:
	Poliespiral(glm::dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert);
	~Poliespiral() { delete mesh; };
	virtual void render(Camera const& cam);
	virtual void update();

};

//-------------------------------------------------------------------------


class Dragon : public Entity
{
public:
	Dragon(glm::dvec2 center, GLint l);
	~Dragon() { delete mesh; };
	virtual void render(Camera const& cam);
	virtual void update();

};

//-------------------------------------------------------------------------


class TrianguloRGB : public Entity
{
public:
	TrianguloRGB(glm::dvec2 center, GLint l);
	~TrianguloRGB() { delete mesh; };
	virtual void render(Camera const& cam);
	virtual void update();

};

//-------------------------------------------------------------------------

class Rectangulo : public Entity
{
public:
	glm::dvec2  center;
	Rectangulo(glm::dvec2 center, GLdouble w, GLdouble h);
	~Rectangulo() { delete mesh; };
	virtual void render(Camera const& cam);
	virtual void update();

};

//-------------------------------------------------------------------------

class RectanguloRGB : public Entity
{
public:
	glm::dvec2  center;
	RectanguloRGB(glm::dvec2 center, GLdouble w, GLdouble h);
	~RectanguloRGB() { delete mesh; };
	virtual void render(Camera const& cam);
	virtual void update();

};
//-------------------------------------------------------------------------

class TrianguloAnimado : public Entity {
public:
	
	TrianguloAnimado(glm::dvec2 center, GLint l, GLdouble angle);
	~TrianguloAnimado() { delete mesh; };
	virtual void render(Camera const& cam);
	virtual void update();
	void incrAngle() { angle = (GLint(angle) + 20); }

protected:

	GLint r;
	GLdouble angle;
	glm::dvec2 center;
};

class Estrella3D : public Entity {
public:
	Estrella3D(glm::dvec2 center, GLdouble re, GLdouble np, GLdouble h);
	~Estrella3D() { delete mesh; delete meshP0; delete meshP1; };
	virtual void render(Camera const& cam);
	virtual void update();
};

class Cubo : public Entity {
public:
	Cubo(glm::dvec3 center, GLdouble w, GLdouble h);
	~Cubo() { delete mesh; };
	virtual void render(Camera const& cam);
	virtual void update();
};

class Caja : public Entity {
public:
	glm::dvec2 center;
	GLdouble w;
	Caja(glm::dvec3 center, GLdouble w, GLdouble h);
	~Caja() { delete mesh; };
	virtual void render(Camera const& cam);
	virtual void update();
};

#endif //_H_Entities_H_