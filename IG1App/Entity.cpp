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
//-------------------------------------------------------------------------

EjesRGB::EjesRGB(GLdouble l): Entity() 
{
  mesh = Mesh::createRGBAxes(l);
}
//-------------------------------------------------------------------------

EjesRGB::~EjesRGB() 
{ 
	delete mesh; mesh = nullptr; 
};
//-------------------------------------------------------------------------

void EjesRGB::render(Camera const& cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat()); 
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);
	}
}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

Poliespiral::Poliespiral(dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert) : Entity()
{
	mesh = Mesh::generaPoliespiral(verIni, angIni, incrAng, ladoIni, incrLado, numVert);
}
//-------------------------------------------------------------------------

Poliespiral::~Poliespiral()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void Poliespiral::render(Camera const& cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glColor3d(0.33, 0.5, 0.9);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);

	}
}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

Dragon::Dragon(GLuint l) : Entity()
{
	mesh = Mesh::generaDragon(l);
}
//-------------------------------------------------------------------------

Dragon::~Dragon()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void Dragon::render(Camera const& cam)
{
	if (mesh != nullptr) {

		dmat4 matAux = cam.getViewMat();
		
		matAux = translate(matAux, dvec3(-40, -170, 0));
		matAux = scale(matAux, dvec3(40, 40, 40));

		uploadMvM(matAux);
		glColor3d(0.25, 0.45, 0.35);
		glPointSize(2);
		mesh->render();
		glColor3d(0,0,0);
		glPointSize(1);
	}
}


//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

Triangulo::Triangulo(GLdouble r) : Entity()
{
	mesh = Mesh::generaTriangulo(r);
}
//-------------------------------------------------------------------------

Triangulo::~Triangulo()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void Triangulo::render(Camera const& cam)
{
	if (mesh != nullptr) {
		dmat4 matAux = cam.getViewMat();
		matAux = scale(matAux, dvec3(40, 40, 40));

		uploadMvM(matAux);

		glColor3d(0.33, 0.5, 0.9);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);

	}
}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

TrianguloRGB::TrianguloRGB(GLdouble r) : Entity()
{
	mesh = Mesh::generaTrianguloRGB(r);
}
//-------------------------------------------------------------------------

TrianguloRGB::~TrianguloRGB()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void TrianguloRGB::render(Camera const& cam)
{
	if (mesh != nullptr) {
		dmat4 matAux = cam.getViewMat();
		matAux = scale(matAux, dvec3(40, 40, 40));

		uploadMvM(matAux);
		glPolygonMode(GL_FRONT,GL_LINE);
		glPolygonMode(GL_BACK, GL_FILL);
		glColor3d(0.33, 0.5, 0.9);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

Rectangulo::Rectangulo(GLdouble w, GLdouble h) : Entity()
{
	mesh = Mesh::generaRectangulo(w,h);
}
//-------------------------------------------------------------------------

Rectangulo::~Rectangulo()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void Rectangulo::render(Camera const& cam)
{
	if (mesh != nullptr) {
		dmat4 matAux = cam.getViewMat();
		matAux = scale(matAux, dvec3(40, 40, 40));

		uploadMvM(matAux);
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_FILL);
		glColor3d(0.33, 0.5, 0.9);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

RectanguloRGB::RectanguloRGB(GLdouble w, GLdouble h) : Entity()
{
	mesh = Mesh::generaRectanguloRGB(w,h);
}
//-------------------------------------------------------------------------

RectanguloRGB::~RectanguloRGB()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void RectanguloRGB::render(Camera const& cam)
{
	if (mesh != nullptr) {
		dmat4 matAux = cam.getViewMat();
		matAux = scale(matAux, dvec3(40, 40, 40));

		uploadMvM(matAux);
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_FILL);
		glColor3d(0.33, 0.5, 0.9);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

