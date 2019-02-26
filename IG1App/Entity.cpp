#include "Entity.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Entity::uploadMvM(dmat4 const& modelViewMat) const
{ 
	dmat4 aMat = modelViewMat * modelMat;
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(aMat));
}
//-------------------------------------------------------------------------

EjesRGB::EjesRGB(glm::dvec2 center, GLdouble l): Entity() 
{
  mesh = Mesh::createRGBAxes(center, l);
}
//-------------------------------------------------------------------------

void EjesRGB::render(Camera const& cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat()); 
		glLineWidth(1);
		mesh->render();
		glLineWidth(1);
	}
}
void EjesRGB::update()
{

}
//-------------------------------------------------------------------------

Poliespiral::Poliespiral(dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert): Entity()
{
	mesh = Mesh::generaPoliespiral(verIni, angIni, incrAng, ladoIni, incrLado, numVert);
}
//-------------------------------------------------------------------------

void Poliespiral::render(Camera const& cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glLineWidth(2);
		glColor3d(55.0, 55.0, 55.0);
		mesh->render();
	}
}
void Poliespiral::update()
{
}
//-------------------------------------------------------------------------

Dragon::Dragon(dvec2 center, GLint l) : Entity()
{
	mesh = Mesh::generadragon(center, l);
}
//-------------------------------------------------------------------------

void Dragon::render(Camera const & cam)
{
	if (mesh != nullptr) {
		dmat4 auxMat = cam.getViewMat();
		setModelMat(translate(auxMat, dvec3(-40, -170, 0)));
		setModelMat(scale(auxMat, dvec3(40, 40, 40)));

		uploadMvM(cam.getViewMat());
		glPointSize(2);
		glColor3d(55.0, 55.0, 55.0);
		mesh->render();
		glPointSize(1);
		glColor3d(1.0, 1.0, 1.0);
	}
}
void Dragon::update()
{
}
//-------------------------------------------------------------------------

TrianguloRGB::TrianguloRGB(dvec2 center, GLint l) : Entity()
{
	mesh = Mesh::generaTrianguloRGB(center, l);
}
//-------------------------------------------------------------------------

void TrianguloRGB::render(Camera const & cam) 
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
		//glPolygonMode(GL_BACK, GL_LINE);
		mesh->render();
	}
}
void TrianguloRGB::update()
{
}
//-------------------------------------------------------------------------

Rectangulo::Rectangulo(dvec2 center, GLdouble w, GLdouble h) : Entity()
{
	this->center = center;
	mesh = Mesh::generaRectangulo(center, w, h);
}
//-------------------------------------------------------------------------

void Rectangulo::render(Camera const & cam)
{
	if (mesh != nullptr) {
		dmat4 auxMat = cam.getViewMat();
		auxMat = translate(auxMat, dvec3(center.x, center.y, 0.0));
		auxMat = rotate(auxMat, radians(25.0), dvec3(0.0, 0.0, 1.0));
		auxMat = translate(auxMat, dvec3(-center.x, -center.y, 0.0));
		uploadMvM(auxMat);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		//rotate(modelMat, radians(25), dvec3(0.0, 0.0, 1.0));
		mesh->render();
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
}
void Rectangulo::update()
{
}
//-------------------------------------------------------------------------

RectanguloRGB::RectanguloRGB(dvec2 center, GLdouble w, GLdouble h) : Entity()
{
	this->center = center;
	mesh = Mesh::generaRectanguloRGB(center, w, h);
}

void RectanguloRGB::render(Camera const & cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		mesh->render();

	}
}

void RectanguloRGB::update()
{
}

TrianguloAnimado::TrianguloAnimado(glm::dvec2 center, GLint r, GLdouble angle)
{
	this->angle = angle;
	this->center = center;
	this->r = r;
	mesh = Mesh::generaTrianguloRGB(center, r);
}

void TrianguloAnimado::render(Camera const & cam)
{
	if (mesh != nullptr) {
		dmat4 auxMat = cam.getViewMat();



		// con esto tenemos la rotación respecto del centro (0,0)
		//auxMat = rotate(auxMat, radians(45.0), dvec3(0.0, 0.0, 1.0));
		GLdouble radius = sqrt(pow(center.x, 2) + pow(center.y, 2));

		

		GLint x = center.x + 50 * cos(radians(this->angle));
		GLint y = center.y + 50 * sin(radians(this->angle));

		// con esto tenemos la rotación sobre la propia figura
		auxMat = translate(auxMat, dvec3(x, y, 0.0));
		auxMat = rotate(auxMat, radians(this->angle), dvec3(0.0, 0.0, 1.0));
		//auxMat = translate(auxMat, dvec3(-center.x, -center.y, 0.0));

		///center.x = x; center.y = y;

		setModelMat(auxMat);
		uploadMvM(cam.getViewMat());
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mesh->render();
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void TrianguloAnimado::update()
{
	incrAngle();
}

Estrella3D::Estrella3D(glm::dvec2 center, GLdouble re, GLdouble np, GLdouble h)
{
	mesh = Mesh::generaEstrella3D(center, re, np, h);
}

void Estrella3D::render(Camera const & cam)
{
	if (mesh != nullptr) {
		/*
		dmat4 auxMat = cam.getViewMat();
		//setModelMat(scale(auxMat, dvec3(40, 40, 40)));

		uploadMvM(cam.getViewMat());
		glLineWidth(2);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mesh->render();
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glLineWidth(1);*/

		dmat4 auxMat = modelMat;
		modelMat = auxMat;
		uploadMvM(cam.getViewMat()); // envía a la GPU cam.getViewMat() * modelMat
		mesh->render();

		modelMat = rotate(modelMat, radians(180.0), dvec3(0.0, 1.0, 0.0));; // matP1 posiciona a P1 con respecto a P0
		uploadMvM(cam.getViewMat()); // envía a la GPU cam.getViewMat() * modelMat * matP1
		mesh->render();

		modelMat = auxMat;
	}
}

void Estrella3D::update()
{
}

Cubo::Cubo(glm::dvec3 center, GLdouble w, GLdouble h)
{
	mesh = Mesh::generaCubo(center, w, h);
}

void Cubo::render(Camera const & cam)
{
	if (mesh != nullptr) {
		dmat4 auxMat = cam.getViewMat();
		uploadMvM(auxMat);
		glLineWidth(2);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mesh->render();
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glLineWidth(1);
	}
}

void Cubo::update()
{
}

Caja::Caja(glm::dvec3 center, GLdouble w, GLdouble h)
{
	this->center = center;
	this->w = w;
	meshP0 = Mesh::generaCubo(center, w, h);
	meshP1 = Mesh::generaRectangulo(center, w, w);
}

void Caja::render(Camera const & cam)
{
	if (meshP0 != nullptr && meshP1 != nullptr) {
		
		dmat4 auxMat = modelMat;
		modelMat = auxMat;
		uploadMvM(cam.getViewMat()); // envía a la GPU cam.getViewMat() * modelMat
		meshP0->render();
		modelMat = rotate(modelMat, radians(90.0), dvec3(1.0, 0.0, 0.0)); // matP1 posiciona a P1 con respecto a P0
		modelMat = translate(modelMat,dvec3(0, 0, w/2)); //USAR WIDTH/2
		uploadMvM(cam.getViewMat()); // envía a la GPU cam.getViewMat() * modelMat * matP1
		meshP1->render();
		//modelMat = rotate(modelMat, radians(-90.0), dvec3(1.0, 0.0, 0.0));

		modelMat = auxMat;
	}
}

void Caja::update()
{
}
