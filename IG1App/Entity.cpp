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

void EjesRGB::update(){}
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
		glColor3d(0.45, 0.7, 0.1);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);

	}
}

void Poliespiral::update() {}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

Poliespiral2::Poliespiral2(dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert) : Entity()
{
	mesh = Mesh::generaPoliespiral2(verIni, angIni, incrAng, ladoIni, incrLado, numVert);
}
//-------------------------------------------------------------------------

Poliespiral2::~Poliespiral2()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void Poliespiral2::render(Camera const& cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glColor3d(0.6, 0.2, 0.8);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);

	}
}

void Poliespiral2::update() {}


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
		
		matAux = translate(matAux, dvec3(-40, -170, -40));
		matAux = scale(matAux, dvec3(40, 40, 40));

		uploadMvM(matAux);
		glColor3d(0.00, 0.00, 0.00);
		glPointSize(2);
		mesh->render();
		glColor3d(0,0,0);
		glPointSize(1);
	}
}

void Dragon::update() {}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

Dragon2::Dragon2(GLuint l) : Entity()
{
	mesh = Mesh::generaDragon2(l);
}
//-------------------------------------------------------------------------

Dragon2::~Dragon2()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void Dragon2::render(Camera const& cam)
{
	if (mesh != nullptr) {

		dmat4 matAux = cam.getViewMat();

		matAux = translate(matAux, dvec3(-40, -170, 0));
		matAux = scale(matAux, dvec3(40, 40, 40));

		uploadMvM(matAux);
		glColor3d(0.25, 0.45, 0.35);
		glPointSize(2);
		mesh->render();
		glColor3d(0, 0, 0);
		glPointSize(1);
	}
}

void Dragon2::update() {}


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
		//glColor3d(0, 0, 0);
		glLineWidth(1);

	}
}

void Triangulo::update() {}


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
		glColor3d(0, 0, 0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void TrianguloRGB::update() {}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

TrianguloAnimado::TrianguloAnimado(GLdouble r) : Entity()
{
	mesh = Mesh::generaTriangulo(r);
}
//-------------------------------------------------------------------------

TrianguloAnimado::~TrianguloAnimado()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void TrianguloAnimado::render(Camera const& cam)
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
		glColor3d(0, 0, 0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void TrianguloAnimado::update()
{
	dmat4 auxMat = modelMat;

	//rotación sobre su figura
	modelMat = translate(modelMat, dvec3(0.0, 0.0, 0.0));
	modelMat = rotate(modelMat, radians(20.0), dvec3(0.0, 0.0, 1.0));
	modelMat = translate(modelMat, dvec3(0.0, 0.0, 0.0));

	setModelMat(modelMat);
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
		glColor3d(0, 0, 0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void Rectangulo::update() {}

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
		
		//matAux = rotate(matAux, radians(90.0), dvec3(1, 0, 0));
		uploadMvM(matAux);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glColor3d(0.33, 0.5, 0.9);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);
		glColor3d(0, 0, 0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void RectanguloRGB::update() {}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

Suelo::Suelo(GLdouble w, GLdouble h) : Entity()
{
	mesh = Mesh::generaRectanguloRGB(w, h);
}

//-------------------------------------------------------------------------

Suelo::~Suelo() 
{
	delete mesh; mesh = nullptr;
};

//-------------------------------------------------------------------------

void Suelo::render(Camera const& cam)
{
	if (mesh != nullptr) {
		dmat4 matAux = modelMat;
		modelMat = rotate(modelMat, radians(90.0), dvec3(1, 0, 0));
		uploadMvM(cam.getViewMat());
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glColor3d(0.33, 0.5, 0.9);
		glLineWidth(2);
		mesh->render();
		glColor3d(0, 0, 0);
		glLineWidth(1);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		modelMat = matAux;

	}
}
void Suelo::update() {}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

Estrella3D::Estrella3D(GLdouble re, GLdouble np, GLdouble h) : Entity()
{
	mesh = Mesh::generaEstrella3D(re, np, h);
}
//-------------------------------------------------------------------------

Estrella3D::~Estrella3D()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void Estrella3D::render(Camera const& cam)
{
	if (mesh != nullptr) {
		dmat4 matAux = modelMat; // cam.getViewMat();
		
		modelMat = translate(modelMat, dvec3(0, 250.0, 0));
		modelMat = scale(modelMat, dvec3(3, 3, 3));

		modelMat = rotate(modelMat, radians(anguloY), dvec3(0, 1, 0));
		modelMat = rotate(modelMat, radians(anguloZ), dvec3(0, 0, 1));

		
		uploadMvM(cam.getViewMat());
		glColor3d(0.9, 0.6, 0.8);
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_LINE);
		glLineWidth(2);
		mesh->render();

		// No recuperamos el modelMat para que siga teniendo lo mismo y solo tengamos que hacer una rotación con respecto a la original
		modelMat = rotate(modelMat, radians(180.0), dvec3(0, 1, 0));

		uploadMvM(cam.getViewMat());
		mesh->render();

		modelMat = matAux;
		glLineWidth(1);
		//glColor3d(0, 0, 0);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}
//-------------------------------------------------------------------------

void Estrella3D::update() {

	anguloZ = anguloZ + 10.00;
	anguloY = anguloY + 25.00;

}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

Cubo::Cubo(GLdouble l) : Entity()
{
	mesh = Mesh::generaContCubo(l);
}
//-------------------------------------------------------------------------

Cubo::~Cubo()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void Cubo::render(Camera const& cam)
{
	if (mesh != nullptr) {
		dmat4 matAux = cam.getViewMat();
		//matAux = scale(matAux, dvec3(40, 40, 40));
		matAux = translate(matAux, dvec3(0, 150.0 / 2, 0));
		uploadMvM(matAux);

		//uploadMvM(cam.getViewMat());
		glColor3d(0.9, 0.6, 0.8);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);
		
	}
}

void Cubo::update() {}



/*
Caja::Caja(GLdouble l) : Entity()
{
	mesh = Mesh::generaContCubo(l);
}
//-------------------------------------------------------------------------

Caja::~Caja()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void Caja::render(Camera const& cam)
{
	if (mesh != nullptr) {
		dmat4 matAux = modelMat; // cam.getViewMat();

		modelMat = translate(modelMat, dvec3(0, 150.0 / 2, 0));
		uploadMvM(matAux);

		glColor3d(0.9, 0.6, 0.8);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glLineWidth(2);
		mesh->render();


		glLineWidth(1);
	}
}

void Caja::update() {}

*/

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

SueloTextura::SueloTextura(GLdouble w, GLdouble h, GLuint rw, GLuint rh) : Entity()
{
	mesh = Mesh::generaRectanguloTexCor(w, h, rw, rh);
	tex1.load("..\\Bmps\\BaldosaC.bmp"); // cargamos la imagen
}
//-------------------------------------------------------------------------

SueloTextura::~SueloTextura()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void SueloTextura::render(Camera const& cam)
{
	if (mesh != nullptr) {
		tex1.bind();
		dmat4 matAux = modelMat;
		modelMat = rotate(modelMat, radians(90.0), dvec3(1, 0, 0));
		uploadMvM(cam.getViewMat());
		glLineWidth(2);
		glColor3d(0.9, 0.6, 0.8);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		mesh->render();
		modelMat = matAux;
		glLineWidth(1);
		glColor3d(0, 0, 0);
		tex1.unbind();

	}
}
//-------------------------------------------------------------------------

void SueloTextura::update() {}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

EstrellaTextura::EstrellaTextura(GLdouble r, GLdouble nL, GLdouble h) : Entity()
{
	mesh = Mesh::generaEstrellaTexCor(r, nL, h);
	tex1.load("..\\Bmps\\BaldosaP.bmp"); // cargamos la imagen
}
//-------------------------------------------------------------------------

EstrellaTextura::~EstrellaTextura()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void EstrellaTextura::render(Camera const& cam)
{
	if (mesh != nullptr) {
		tex1.bind();

		dmat4 matAux = modelMat;
		modelMat = rotate(modelMat, radians(90.0), dvec3(1, 0, 0));

		uploadMvM(cam.getViewMat());

		mesh->render();
		
		tex1.unbind();
	}
}
//-------------------------------------------------------------------------

void EstrellaTextura::update() {}


//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

EstrellaTexturaAnimada::EstrellaTexturaAnimada(GLdouble r, GLdouble nL, GLdouble h) : Entity()
{
	mesh = Mesh::generaEstrellaTexCor(r, nL, h);
	tex1.load("..\\Bmps\\BaldosaP.bmp"); // cargamos la imagen
}
//-------------------------------------------------------------------------

EstrellaTexturaAnimada::~EstrellaTexturaAnimada()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void EstrellaTexturaAnimada::render(Camera const& cam)
{
	if (mesh != nullptr) {

		tex1.bind();

		dmat4 matAux = modelMat;
		modelMat = translate(modelMat, dvec3(0, 250.0, 0));
		modelMat = scale(modelMat, dvec3(3, 3, 3));
		modelMat = translate(modelMat, dvec3(10.0, 0, 0));

		modelMat = rotate(modelMat, radians(anguloY), dvec3(0, 1, 0));
		modelMat = rotate(modelMat, radians(anguloZ), dvec3(0, 0, 1));

		uploadMvM(cam.getViewMat());
		mesh->render();

		// No recupetamos el modelMat para que siga teniendo las mismas rotaciones y traslaciones
		modelMat = rotate(modelMat, radians(180.0), dvec3(0, 1, 0));

		uploadMvM(cam.getViewMat());
		mesh->render();

		modelMat = matAux;
		tex1.unbind();
	}
}
//-------------------------------------------------------------------------

void EstrellaTexturaAnimada::update() {
	anguloZ = anguloZ + 10.00;
	anguloY = anguloY + 25.00;
}




//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

CajaTextura::CajaTextura(GLdouble l) : Entity()
{
	mesh = Mesh::generaCajaTexCor(l);
	tex1.load("..\\Bmps\\Container.bmp"); // cargamos la imagen
	tex2.load("..\\Bmps\\BaldosaF.bmp"); // cargamos otra imagen
}
//-------------------------------------------------------------------------

CajaTextura::~CajaTextura()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void CajaTextura::render(Camera const& cam)
{
	if (mesh != nullptr) {

		glEnable(GL_CULL_FACE);

		dmat4 matAux = modelMat; // cam.getViewMat();
		modelMat = translate(modelMat, dvec3(0, 150.0 / 2, 0));
		uploadMvM(cam.getViewMat());

		tex1.bind();
		glCullFace(GL_FRONT);
		mesh->render();
		tex1.unbind();
		
		tex2.bind();
		glCullFace(GL_BACK);
		mesh->render();
		tex2.unbind();

		modelMat = matAux;
		glCullFace(GL_FRONT_AND_BACK);
		glLineWidth(1);


		glDisable(GL_CULL_FACE);
	}
}
//-------------------------------------------------------------------------

void CajaTextura::update() {}