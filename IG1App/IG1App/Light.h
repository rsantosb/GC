//#pragma once
#ifndef _H_Light_H_
#define _H_Light_H_

#include <GL/freeglut.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

//-------------------------------------------------------------------------


static GLuint cont = 0; // Para generar un nuevo id cada vez

class Light
{
protected:
	GLuint id = GL_LIGHT0 + GL_MAX_LIGHTS; // id no válido

	//Atributos lumínicos y geométrico de la fuente de luz
	glm::fvec4 ambient = { 0.1, 0.1, 0.1, 1 };
	glm::fvec4 diffuse = { 0.5, 0.5, 0.5, 1 };
	glm::fvec4 specular = { 0.5, 0.5, 0.5, 1 };
	glm::fvec4 posDir = { 0, 0, 1, 0 };

	// Añade setter's para cambiar el valor de los atributos lumínicos

public:
	
	Light();

	virtual ~Light() { disable(); }

	void uploadL();
	void disable();
	void enable();
	void setAmb(glm::fvec4 amb);
	void setDiff(glm::fvec4 dif);
	void setSpec(glm::fvec4 spec);
	GLuint getId() { return id; };

	virtual void upload(glm::dmat4 const& modelViewMat) = 0;
};

//-------------------------------------------------------------------------

class DirLight : public Light {
public: 
	virtual void upload(glm::dmat4 const& modelViewMat);
	void setPosDir(glm::fvec3 dir);
};

//-------------------------------------------------------------------------

class PosLight : public Light {
protected:
	//Factores de atuenuación
	GLfloat kc = 1, kl = 0, kq = 0;

public:
	virtual void upload(glm::dmat4 const& modelViewMat);
	void setPosDir(glm::fvec3 dir);
	void setAtte(GLfloat kc, GLfloat kl, GLfloat kq);
};


//----------------------------------------------------------------------------

class SpotLight : public PosLight {
protected:
	//Atributos del foco
	glm::fvec4 direction = { 0, 0, -1, 0 };
	GLfloat cutoff = 10;
	GLfloat exp = 0;

public:
	SpotLight(glm::fvec3 pos = { 0, 0, 0 }) : PosLight() {
		posDir = glm::fvec4(pos, 1.0);
	}

	virtual void upload(glm::dmat4 const& modelViewMat);
	void setSpot(glm::fvec3 dir, GLfloat cf, GLfloat e);
};
#endif //_H_Light_H_
