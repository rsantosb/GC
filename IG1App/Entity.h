//#pragma once
#ifndef _H_Entities_H_
#define _H_Entities_H_

#include <GL/freeglut.h>
#include <glm.hpp>

#include "Camera.h"
#include "Mesh.h"
#include "Texture.h"

//-------------------------------------------------------------------------

class Entity 
{
public:
	Entity() : modelMat(1.0) { }; 
	virtual ~Entity() { };

	glm::dmat4 modelMat;    // modeling matrix

	virtual void render(dmat4 const& modelViewMat) = 0;

	// modeling matrix
	glm::dmat4 const& getModelMat() const { return modelMat; };

	void setModelMat(glm::dmat4 const& aMat) { modelMat = aMat; }
	virtual void update() = 0;
	virtual void update(GLuint timeElapsed) = 0;
  
protected:

	Mesh* mesh = nullptr;   // surface mesh
	

	Texture tex1; 
	Texture tex2; 
	Texture texBase;

	// transfers modelViewMat to the GPU
	virtual void uploadMvM(glm::dmat4 const& modelViewMat) const;
};

//-------------------------------------------------------------------------

class EjesRGB : public Entity 
{
public:
	EjesRGB(GLdouble l);
	~EjesRGB();
	virtual void render(dmat4 const& modelViewMat);
	void update();
	virtual void update(GLuint timeElapsed);

};

//-------------------------------------------------------------------------

class Poliespiral : public Entity
{
public:
	Poliespiral(dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert);
	~Poliespiral();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

};

//-------------------------------------------------------------------------

class Poliespiral2 : public Entity
{
public:
	Poliespiral2(dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert);
	~Poliespiral2();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

};

//-------------------------------------------------------------------------

class Dragon : public Entity
{
public:
	Dragon(GLuint l);
	~Dragon();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	void update(GLuint timeElapsed);
};

//-------------------------------------------------------------------------

class Dragon2 : public Entity
{
public:
	Dragon2(GLuint l);
	~Dragon2();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

};

//-------------------------------------------------------------------------

class Triangulo : public Entity
{
public:
	Triangulo(GLdouble l);
	~Triangulo();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

};

//-------------------------------------------------------------------------

class TrianguloRGB : public Entity
{
public:
	TrianguloRGB(GLdouble l);
	~TrianguloRGB();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

};

//-------------------------------------------------------------------------

class TrianguloAnimado : public Entity
{
public:
	double ang = 0.0;
	double angy = 0.0;

	TrianguloAnimado(GLdouble l);
	~TrianguloAnimado();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

};


//-------------------------------------------------------------------------

class Rectangulo : public Entity
{
public:
	Rectangulo(GLdouble w, GLdouble h);
	~Rectangulo();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

};

//-------------------------------------------------------------------------

class RectanguloRGB : public Entity
{
public:
	RectanguloRGB(GLdouble w, GLdouble h);
	~RectanguloRGB();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

};

//-------------------------------------------------------------------------

class Suelo : public Entity
{
public:
	Suelo(GLdouble w, GLdouble h);
	~Suelo();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

};

//-------------------------------------------------------------------------

class Estrella3D : public Entity
{
public:
	GLdouble anguloY = 10.0;
	GLdouble anguloZ = 10.0;
	Estrella3D(GLdouble re, GLdouble np, GLdouble h);
	~Estrella3D();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

};

//-------------------------------------------------------------------------

class Cubo : public Entity
{
public:
	Cubo(GLdouble l);
	~Cubo();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

};

//-------------------------------------------------------------------------

class SueloTextura : public Entity
{
public:
	SueloTextura(GLdouble w, GLdouble h, GLuint rw, GLuint rh);
	~SueloTextura();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
};

//-------------------------------------------------------------------------

class EstrellaTextura : public Entity
{
public:
	EstrellaTextura(GLdouble r, GLdouble nL, GLdouble h);
	~EstrellaTextura();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

};

class EstrellaTexturaAnimada : public Entity
{
public:
	EstrellaTexturaAnimada(GLdouble r, GLdouble nL, GLdouble h);
	~EstrellaTexturaAnimada();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	GLdouble anguloY = 10.0;
	GLdouble anguloZ = 10.0;
	virtual void update(GLuint timeElapsed);


};
//-------------------------------------------------------------------------

class CajaTextura : public Entity
{
public:
	Mesh* base = nullptr;   // Base mesh
	CajaTextura(GLdouble l);
	~CajaTextura();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
	GLdouble lado = 0;

};



class Cangilon : public CajaTextura
{
public:
	//Mesh* base = nullptr;   // Base mesh
	Cangilon(GLdouble l);
	~Cangilon();
	//virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	//virtual void update(GLuint timeElapsed);
	GLdouble lado = 0;
	GLdouble anguloGiro = 0;

};

class TableroIzq : public Entity
{
public:
	TableroIzq(GLdouble l);
	~TableroIzq();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
	GLdouble lado = 0;
	GLdouble anguloGiro = 0;

};

class TableroDch : public Entity
{
public:
	TableroDch(GLdouble l);
	~TableroDch();
	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
	GLdouble lado = 0;
	GLdouble anguloGiro = 0;

};

#endif //_H_Entities_H_