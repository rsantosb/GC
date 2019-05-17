//#pragma once
#ifndef _H_Entities_H_
#define _H_Entities_H_

#include <GL/freeglut.h>
#include <glm.hpp>

#include "Camera.h"
#include "Mesh.h"
#include "Texture.h"
#include "Material.h"
#include "Light.h"

#include <vector>

//using namespace std;

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
	virtual void move(GLuint tecla);
  
protected:

	Mesh* mesh = nullptr;   // surface mesh
	

	Texture tex1; 
	Texture tex2; 
	Texture texBase;

	// transfers modelViewMat to the GPU
	virtual void uploadMvM(glm::dmat4 const& modelViewMat) const;
};

class CompoundEntity : public Entity
{
public:

	std::vector<Entity*> grObjects;

	Entity* getEntity(int i) { return grObjects[i]; }

	CompoundEntity() {}
	~CompoundEntity() { 
		for (Entity* it : grObjects) 
			delete it; 
		}
	
	void render(dmat4 const& modelViewMat);
	void update();
	void update(GLuint timeElapsed);
	void move(GLuint tecla);
	


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
	GLdouble lateral = 0;

};

class CuboConTapas : public Entity
{
public:
	Mesh* base = nullptr;   // Base mesh
	Mesh* tapa = nullptr;	// Tapa mesh
	GLdouble lado = 0;
	CuboConTapas(GLdouble l);
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
	Cangilon(GLdouble l, GLdouble angulo);
	~Cangilon();
	//virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
	GLdouble lado = 0;
	GLdouble anguloGiro = 0;

};

class TableroIzq : public Cubo
{
public:
	TableroIzq(GLdouble l);
	TableroIzq(GLdouble l, GLdouble angulo);
	~TableroIzq();
	//virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
	GLdouble lado = 0;
	GLdouble anguloGiro = 0;

};

class TableroDch : public Cubo
{
public:
	TableroDch(GLdouble l);
	TableroDch(GLdouble l, GLdouble angulo);
	~TableroDch();
	//virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
	GLdouble lado = 0;
	GLdouble anguloGiro = 0;

};

class QuadricEntity : public Entity {
public:
	QuadricEntity();
	~QuadricEntity() { gluDeleteQuadric(q); };
	virtual void update();
	virtual void update(GLuint timeElapsed);
protected:
	GLUquadricObj* q;
};

class Sphere : public QuadricEntity {
public:
	Sphere(GLdouble r); // r is the radius of the sphere
	void render(glm::dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
protected:
	GLdouble r;
};

class Cylinder : public QuadricEntity {
public:
	Cylinder(GLdouble rbase, GLdouble rtop, GLdouble altura, GLuint numLados, GLuint rodajas); 
	Cylinder(GLdouble rbase, GLdouble rtop, GLdouble altura, GLuint numLados, GLuint rodajas, GLdouble rojo, GLdouble verde, GLdouble azul);

	void render(glm::dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
protected:
	GLuint ro;
	GLdouble rb;
	GLdouble rt;
	GLdouble h; 
	GLuint nl; 
	GLdouble red = -1;
	GLdouble green = -1;
	GLdouble blue = -1;
	
};

class Disk : public QuadricEntity {
public:
	Disk(GLdouble rInterno, GLdouble rExterno, GLint numLados, GLint anillos); // r is the radius of the sphere
	void render(glm::dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
protected:
	GLdouble rInt; 
	GLdouble rExt; 
	GLint nL; 
	GLint a;
};

class PartialDisk : public QuadricEntity {
public:
	PartialDisk(GLdouble rInterno, GLdouble rExterno, GLint numLados, GLint anillos, GLdouble anguloIni, GLdouble anguloBarrido); // r is the radius of the sphere
	void render(glm::dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
protected:
	GLdouble rInt;
	GLdouble rExt; 
	GLint nL; 
	GLint a; 
	GLdouble angIni; 
	GLdouble angBarrido;
};
/*Dejo comentada la clase Rotor que hereda de Entity para crear la que herede de CompoundEntity*/
/*class Rotor : public Entity {
public:
	Rotor(GLdouble r, GLboolean giroHorario, GLboolean colorVerde);
	virtual void render(glm::dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
protected: 
	Cylinder* base;
	Rectangulo* rectangulo; 
	GLdouble radio;
	GLdouble anguloGiro = 0;
	GLboolean giro;
	GLboolean verde;
	
};
*/
class Rotor : public CompoundEntity {
public:
	Rotor(GLdouble r, GLboolean giroHorario, GLboolean colorVerde);
	void update();
	void update(GLuint timeElapsed);
protected:
	Rectangulo* rectangulo; //Lo dejo para usar la animaci�n
	GLdouble radio;
	GLdouble anguloGiro = 0;
	GLboolean giro;
	GLboolean verde;
};

class Chasis : public Entity {
public: 
	Chasis();
	virtual void render(glm::dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
protected:
	CuboConTapas* cubo;
	
};

/*Dejo comentada la clase Dron que hereda de Entity para crear la que herede de CompoundEntity*/
/*class Dron : public Entity {
public:
	Dron();
	virtual void render(glm::dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

protected:
	Chasis* chasis;
	Rotor* rotor1;
	Rotor* rotor2;
	Rotor* rotor3;
	Rotor* rotor4;

};
*/
class Dron : public CompoundEntity {
public: 
	Dron(bool encendido);
	Dron();
	void update();
	virtual void render(glm::dmat4 const& modelViewMat); //A�ADIDO PARA EL APARTADO 22 luces
	void update(GLuint timeElapsed);
	GLuint getLuzId() { if (foco != nullptr) { return foco->getId(); } return -1; }
protected:
	Rotor* rotor1; // Lo dejo para el update
	Rotor* rotor2; // Lo dejo para el update
	Rotor* rotor3; // Lo dejo para el update
	Rotor* rotor4; // Lo dejo para el update

	SpotLight* foco = nullptr;
};


class Cone : public Entity {
public:
	Cone(GLdouble h, GLdouble r);

	virtual void render(glm::dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

};

class Esfera : public Entity {
public:
	Esfera(GLint paralelos, GLint meridianos, GLdouble radio);

	virtual void render(glm::dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

protected:
	GLint m; //numero de puntos del perfil y paralelos
	GLint n; //meridianos de la esfera numero de muestras
	GLdouble r; //radio
	Material* material = new Material(); //atributo de tipo material para el apartado 20

	
};

class Satelite : public Entity {
public:
	Satelite(GLdouble radio);

	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

protected:
	Esfera* esfera;
	Dron* dron;
	GLdouble r; //radio
	GLdouble anguloGiro = 0;

};

class EsferaDron : public Entity {
public:
	EsferaDron(GLdouble radio);

	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);
	void updateNuevo(GLuint control);


protected:
	Esfera* esfera;
	Dron* dron;
	GLdouble r; //radio
	GLdouble anguloGiro = 0;
	GLdouble anguloOtroGiro = 0;
};


class Dronitos : public Entity {
public:
	Dronitos();

	virtual void render(dmat4 const& modelViewMat);
	virtual void update();
	virtual void update(GLuint timeElapsed);

protected:
	Dron* principal;
	Dron* d1;
	Dron* d2;
	Dron* d3;
	Dron* d4;

};

class EntityMaterial : public Entity {
public:
	EntityMaterial() : Entity() {};
	virtual ~EntityMaterial() {};

	void setTexture(Texture* tex) { texture = tex; }
	void setMaterail(Material matl) { material = matl; }

protected:
	Texture* texture = nullptr;
	Material material;
};

class SateliteCompound : public CompoundEntity {
public:
	SateliteCompound(GLdouble radio);
	//void update();
	void move(GLuint tecla);

protected:
	Esfera* esfera;
	Dron* dron;
	GLdouble r; //radio
	GLdouble anguloGiro = 0;
	GLdouble anguloOtroGiro = 0;

};

#endif //_H_Entities_H_