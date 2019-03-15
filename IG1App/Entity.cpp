#include "Entity.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

#include <iostream>

using namespace std;

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

void EjesRGB::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {
		uploadMvM(modelViewMat); 
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);
	}
}

void EjesRGB::update(){}

void EjesRGB::update(GLuint timeElapsed) {}

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

void Poliespiral::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {
		uploadMvM(modelViewMat);
		glColor3d(0.45, 0.7, 0.1);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);

	}
}

void Poliespiral::update() {}

void Poliespiral::update(GLuint timeElapsed) {}
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

void Poliespiral2::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {
		uploadMvM(modelViewMat);
		glColor3d(0.6, 0.2, 0.8);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);

	}
}

void Poliespiral2::update() {}

void Poliespiral2::update(GLuint timeElapsed) {}


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

void Dragon::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {

		dmat4 matAux = modelMat;
		
		modelMat = translate(modelMat, dvec3(-40, -170, -40));
		modelMat = scale(modelMat, dvec3(40, 40, 40));

		uploadMvM(modelViewMat);

		glColor3d(0.00, 0.00, 0.00);
		glPointSize(2);
		mesh->render();
		glColor3d(0,0,0);
		glPointSize(1);
		modelMat = matAux;
	}
}

void Dragon::update() {}

void Dragon::update(GLuint timeElapsed) {}

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

void Dragon2::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {

		dmat4 matAux = modelMat;
		
		modelMat = translate(modelMat, dvec3(-40, -170, 0));
		modelMat = scale(modelMat, dvec3(40, 40, 40));

		uploadMvM(modelViewMat);
		glColor3d(0.25, 0.45, 0.35);
		glPointSize(2);
		mesh->render();
		glColor3d(0, 0, 0);
		glPointSize(1);
		modelMat = matAux;
	}
}

void Dragon2::update() {}

void Dragon2::update(GLuint timeElapsed) {}



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

void Triangulo::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {
		dmat4 matAux = modelMat;
		modelMat = scale(modelMat, dvec3(40, 40, 40));

		uploadMvM(modelViewMat);

		glColor3d(0.33, 0.5, 0.9);
		glLineWidth(2);
		mesh->render();
		glColor3d(0, 0, 0);
		glLineWidth(1);
		modelMat = matAux;
	}
}

void Triangulo::update() {}

void Triangulo::update(GLuint timeElapsed) {}


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

void TrianguloRGB::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {
		dmat4 matAux = modelMat;
		modelMat = scale(modelMat, dvec3(40, 40, 40));

		uploadMvM(modelViewMat);
		glPolygonMode(GL_FRONT,GL_LINE);
		glPolygonMode(GL_BACK, GL_FILL);
		glColor3d(0.33, 0.5, 0.9);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);
		glColor3d(0, 0, 0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		modelMat = matAux;
	}
}

void TrianguloRGB::update() {}

void TrianguloRGB::update(GLuint timeElapsed) {}

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

void TrianguloAnimado::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {
		dmat4 auxMat = modelMat;

		modelMat = scale(modelMat, dvec3(40, 40, 40));
	

		// con esto tenemos la rotación respecto del centro (0,0)
		modelMat = translate(modelMat, dvec3(0.0, 0.0, 0.0));
		modelMat = translate(modelMat, dvec3(25.0 * cos(radians(ang)), 25.0 * sin(radians(ang)), 0.0));

		//Gira sobre si mismo
		modelMat = rotate(modelMat, radians(ang), dvec3(0.0, 0.0, 1.0));
		//auxMat = translate(auxMat, dvec3(-center.x, -center.y, 0.0));

		uploadMvM(modelViewMat);
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_FILL);
		glColor3d(0.33, 0.5, 0.9);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);
		glColor3d(0, 0, 0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		modelMat = auxMat;
	}
}

void TrianguloAnimado::update()
{
	this->ang = this->ang + 5.0;

}

void TrianguloAnimado::update(GLuint timeElapsed) 
{
	if (timeElapsed >= 27)
		update();

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

void Rectangulo::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {
		dmat4 matAux = modelMat;
		modelMat = scale(modelMat, dvec3(40, 40, 40));

		uploadMvM(modelViewMat);
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_FILL);
		glColor3d(0.33, 0.5, 0.9);
		glLineWidth(2);
		mesh->render();
		glLineWidth(1);
		glColor3d(0, 0, 0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		modelMat = matAux;
	}
}

void Rectangulo::update() {}

void Rectangulo::update(GLuint timeElapsed) {}

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

void RectanguloRGB::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {
		//dmat4 matAux = modelMat;
		
		//matAux = rotate(matAux, radians(90.0), dvec3(1, 0, 0));
		uploadMvM(modelViewMat);
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

void RectanguloRGB::update(GLuint timeElapsed) {}

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

void Suelo::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {
		dmat4 matAux = modelMat;
		modelMat = rotate(modelMat, radians(90.0), dvec3(1, 0, 0));
		uploadMvM(modelViewMat);
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

void Suelo::update(GLuint timeElapsed) {}
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

void Estrella3D::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {
		dmat4 matAux = modelMat; // cam.getViewMat();
		
		modelMat = translate(modelMat, dvec3(0, 250.0, 0));
		modelMat = scale(modelMat, dvec3(3, 3, 3));

		modelMat = rotate(modelMat, radians(anguloY), dvec3(0, 1, 0));
		modelMat = rotate(modelMat, radians(anguloZ), dvec3(0, 0, 1));

		
		uploadMvM(modelViewMat);
		glColor3d(0.9, 0.6, 0.8);
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_LINE);
		glLineWidth(2);
		mesh->render();

		// No recuperamos el modelMat para que siga teniendo lo mismo y solo tengamos que hacer una rotación con respecto a la original
		modelMat = rotate(modelMat, radians(180.0), dvec3(0, 1, 0));

		uploadMvM(modelViewMat);
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

void Estrella3D::update(GLuint timeElapsed) 
{
	if (timeElapsed >= 27)
		update();
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

void Cubo::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {
		dmat4 matAux = modelViewMat;
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

void Cubo::update(GLuint timeElapsed) {}



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

void SueloTextura::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {
		tex1.bind();

		dmat4 matAux = modelMat;

		modelMat = rotate(modelMat, radians(90.0), dvec3(1, 0, 0));

		uploadMvM(modelViewMat);

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

void SueloTextura::update(GLuint timeElapsed) {}

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

void EstrellaTextura::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {
		tex1.bind();

		dmat4 matAux = modelMat;
		modelMat = rotate(modelMat, radians(90.0), dvec3(1, 0, 0));

		uploadMvM(modelViewMat);

		mesh->render();
		
		tex1.unbind();
	}
}
//-------------------------------------------------------------------------

void EstrellaTextura::update() {}

void EstrellaTextura::update(GLuint timeElapsed) {}


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

void EstrellaTexturaAnimada::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {

		tex1.bind();

		dmat4 matAux = modelMat;
		modelMat = translate(modelMat, dvec3(0, 250.0, 0));
		modelMat = scale(modelMat, dvec3(3, 3, 3));
		modelMat = translate(modelMat, dvec3(10.0, 0, 0));

		modelMat = rotate(modelMat, radians(anguloY), dvec3(0, 1, 0));
		modelMat = rotate(modelMat, radians(anguloZ), dvec3(0, 0, 1));

		uploadMvM(modelViewMat);
		mesh->render();

		// No recupetamos el modelMat para que siga teniendo las mismas rotaciones y traslaciones
		modelMat = rotate(modelMat, radians(180.0), dvec3(0, 1, 0));

		uploadMvM(modelViewMat);
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

void EstrellaTexturaAnimada::update(GLuint timeElapsed) 
{
	if (timeElapsed >= 27)
		update();
}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

CajaTextura::CajaTextura(GLdouble l) : Entity()
{
	mesh = Mesh::generaCajaTexCor(l);
	base = Mesh::generaBaseTexCor(l);
	tex1.load("..\\Bmps\\Container.bmp"); // cargamos la imagen
	tex2.load("..\\Bmps\\BaldosaF.bmp"); // cargamos otra imagen
	texBase.load("..\\Bmps\\PapelE.bmp"); // cargamos la imagen
}
//-------------------------------------------------------------------------

CajaTextura::~CajaTextura()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void CajaTextura::render(dmat4 const& modelViewMat)
{
	if (mesh != nullptr) {

		glEnable(GL_CULL_FACE);

		dmat4 matAux = modelMat; // cam.getViewMat();
///		modelMat = rotate(modelMat, radians(90.0), dvec3(1, 0, 0));
		modelMat = translate(modelMat, dvec3(0, 150.0 / 2, 0));
		uploadMvM(modelViewMat);

		tex1.bind();
		glCullFace(GL_FRONT);
		mesh->render();
		tex1.unbind();

		tex2.bind();
		glCullFace(GL_BACK);
		mesh->render();
		//base->render();
		tex2.unbind();

		modelMat = matAux;
		glCullFace(GL_FRONT_AND_BACK);
		glLineWidth(1);

		glDisable(GL_CULL_FACE);
	}
	
	if (base != nullptr) {
		texBase.bind();
		dmat4 matAux = modelMat;
		modelMat = translate(modelMat, dvec3(0, 1, 0));
		modelMat = rotate(modelMat, radians(90.0), dvec3(1, 0, 0));
		uploadMvM(modelViewMat);
		glLineWidth(2);
		glColor3d(0.9, 0.6, 0.8);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		base->render();
		modelMat = matAux;
		glLineWidth(1);
		//glColor3d(0, 0, 0);
		texBase.unbind();
	}
	
}
//-------------------------------------------------------------------------

void CajaTextura::update() {}

void CajaTextura::update(GLuint timeElapsed) {}