#include "Entity.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

#include <iostream>

using namespace std;

//-------------------------------------------------------------------------

void Entity::move(GLuint tecla)
{
}

void Entity::uploadMvM(dmat4 const& modelViewMat) const
{ 
	dmat4 aMat = modelViewMat * modelMat;
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(aMat));
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
void CompoundEntity::render(dmat4 const& modelViewMat) {
	glMatrixMode(GL_MODELVIEW);
	dmat4 aMat = modelViewMat * modelMat;
	glLoadMatrixd(value_ptr(aMat));

	for (Entity* it : grObjects) {
		it->render(aMat);
	}
}

void CompoundEntity::update() {
	for (Entity* it : grObjects) {
		it->update();
	}
}

void CompoundEntity::update(GLuint timeElapsed) {
	for (Entity* entity : grObjects) {
		entity->update(timeElapsed);
	}
}

void CompoundEntity::move(GLuint tecla)
{
	for (Entity* entity : grObjects) {
		entity->move(tecla);
	}
}

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
		//modelMat = scale(modelMat, dvec3(40, 40, 40));

		uploadMvM(modelViewMat);
		//glPolygonMode(GL_FRONT, GL_LINE);
		//glPolygonMode(GL_BACK, GL_FILL);
		glColor3d(0, 0, 0);
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
	lateral = l;
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
		matAux = translate(matAux, dvec3(0, lateral / 2, 0));
		uploadMvM(matAux);

		//uploadMvM(cam.getViewMat());
		glColor3d(0, 0, 0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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
	tex2.load("..\\Bmps\\Container.bmp"); // cargamos otra imagen
	texBase.load("..\\Bmps\\PapelE.bmp"); // cargamos la imagen
	lado = l;
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
		modelMat = translate(modelMat, dvec3(0, lado / 2, 0));
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


CuboConTapas::CuboConTapas(GLdouble l) {
	mesh = Mesh::generaContCubo(l);
	base = Mesh::generaRectangulo(l,l);
	tapa = Mesh::generaRectangulo(l,l);
	lado = l;
}

void CuboConTapas::render(dmat4 const& modelViewMat) {

	uploadMvM(modelViewMat);

	mesh->render();

	uploadMvM(modelViewMat);

	dmat4 i = modelMat;

	modelMat = translate(modelMat, dvec3(0, -lado/2, 0));
	modelMat = rotate(modelMat, radians(90.0), dvec3(1, 0, 0));


	uploadMvM(modelViewMat);

	base->render();

	modelMat = i;

	modelMat = translate(modelMat, dvec3(0, lado / 2, 0));
	modelMat = rotate(modelMat, radians(90.0), dvec3(1, 0, 0));

	uploadMvM(modelViewMat);

	tapa->render();

	modelMat = i;



}
void CuboConTapas::update() {}
void CuboConTapas::update(GLuint timeElapsed) {}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
/*CajaLateral::CajaLateral(GLdouble l, GLdouble h) : Entity()
{
	mesh = Mesh::generaCajaLateral(l,h);
	base = Mesh::generaBaseTexCor(l);
	
}
//-------------------------------------------------------------------------

CajaLateral::~CajaLateral()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------

void CajaLateral::render(dmat4 const& modelViewMat)
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

void CajaLateral::update() {}

void CajaLateral::update(GLuint timeElapsed) {}
*/
 // ----------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------
//-----------------------------------------------------------------

Cangilon::Cangilon(GLdouble l) : CajaTextura(l)
{
	
	lado = l;
	//modelMat = translate(modelMat, dvec3(400, 0, 0));
	modelMat = rotate(modelMat, radians(anguloGiro), dvec3(0, 0, 1));
	modelMat = translate(modelMat, dvec3(300, 0, 0));

	modelMat = rotate(modelMat, radians(-anguloGiro), dvec3(0, 0, 1));

}

Cangilon::Cangilon(GLdouble l, GLdouble angulo) : CajaTextura(l)
{
	lado = l;
	anguloGiro = angulo;

	modelMat = rotate(modelMat, radians(anguloGiro), dvec3(0, 0, 1));
	modelMat = translate(modelMat, dvec3(300, 0, 0));
	modelMat = rotate(modelMat, radians(-anguloGiro), dvec3(0, 0, 1));

}
//-------------------------------------------------------------------------

Cangilon::~Cangilon()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------


void Cangilon::update() {

	anguloGiro = anguloGiro + 10;
	dmat4 m = dmat4(1.0);
	m = rotate(m, radians(anguloGiro), dvec3(0, 0, 1));
	m = translate(m, dvec3(300, 0, 0));
	m = rotate(m, radians(-anguloGiro), dvec3(0, 0, 1));
	modelMat = m;

}

void Cangilon::update(GLuint timeElapsed) {

	if (timeElapsed >= 27)
		update();
}


TableroIzq::TableroIzq(GLdouble l) : Cubo(l)
{
	lado = l;
	modelMat = rotate(modelMat, radians(anguloGiro), dvec3(0, 0, 1));
	modelMat = translate(modelMat, dvec3(300 / 2, 0, lado / 2));
	modelMat = scale(modelMat, dvec3((325 / lado), 0.5, 0.1));

}
//-------------------------------------------------------------------------

TableroIzq::TableroIzq(GLdouble l, GLdouble angulo) : Cubo(l)
{
	lado = l;
	anguloGiro = angulo;

	modelMat = rotate(modelMat, radians(anguloGiro), dvec3(0, 0, 1));
	modelMat = translate(modelMat, dvec3(300 / 2, 0, lado / 2));
	modelMat = scale(modelMat, dvec3((325 / lado), 0.5, 0.1));
	
}

TableroIzq::~TableroIzq()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------


void TableroIzq::update() {

	anguloGiro = anguloGiro + 10;
	dmat4 m = dmat4(1.0);

	m = rotate(m, radians(anguloGiro), dvec3(0, 0, 1));
	m = translate(m, dvec3(300 / 2, 0, lado / 2));
	m = scale(m, dvec3((325 / lado), 0.5, 0.1));

	modelMat = m;

}

void TableroIzq::update(GLuint timeElapsed) {

	if (timeElapsed >= 27)
		update();
}

TableroDch::TableroDch(GLdouble l) : Cubo(l)
{
	//mesh = Mesh::generaContCubo(l);
	lado = l;

	modelMat = rotate(modelMat, radians(anguloGiro), dvec3(0, 0, 1));
	modelMat = translate(modelMat, dvec3(300 / 2, 0, -lado / 2));
	modelMat = scale(modelMat, dvec3((325 / lado), 0.5, 0.1));
}

TableroDch::TableroDch(GLdouble l, GLdouble angulo) : Cubo(l)
{
	lado = l;
	anguloGiro = angulo;

	modelMat = rotate(modelMat, radians(anguloGiro), dvec3(0, 0, 1));
	modelMat = translate(modelMat, dvec3(300 / 2, 0, -lado / 2));
	modelMat = scale(modelMat, dvec3((325 / lado), 0.5, 0.1));
}
//-------------------------------------------------------------------------

TableroDch::~TableroDch()
{
	delete mesh; mesh = nullptr;
};
//-------------------------------------------------------------------------


void TableroDch::update() {

	anguloGiro = anguloGiro + 10;

	dmat4 m = dmat4(1.0);
	
	m = rotate(m, radians(anguloGiro), dvec3(0, 0, 1));
	m = translate(m, dvec3(300 / 2, 0, -lado / 2));
	m = scale(m, dvec3((325 / lado), 0.5, 0.1));

	modelMat = m;
}

void TableroDch::update(GLuint timeElapsed) {

	if (timeElapsed >= 27)
		update();
}

QuadricEntity::QuadricEntity() {
	q = gluNewQuadric();
}

void QuadricEntity::update() {}
void QuadricEntity::update(GLuint timeElapsed) {}

Sphere::Sphere(GLdouble rr) {
	r = rr;
}
void Sphere::render(glm::dmat4 const& modelViewMat) {
	uploadMvM(modelViewMat);
	// Fijar el color con glColor3f(...);
	glColor3f(0.8, 0.4, 0.2);
	// Fijar el modo en que se dibuja la entidad con
	//gluQuadricDrawStyle(q, GLU_LINE);
	gluSphere(q, r, 50, 50);
}

void Sphere::update() {}
void Sphere::update(GLuint timeElapsed) {}


Cylinder::Cylinder(GLdouble rbase, GLdouble rtop, GLdouble altura, GLuint numLados, GLuint rodajas) {
	rb = rbase;
	rt = rtop;
	h = altura;
	nl = numLados;
	ro = rodajas;
}
void Cylinder::render(glm::dmat4 const& modelViewMat) {
	uploadMvM(modelViewMat);
	// Fijar el color con glColor3f(...);
	//glColor3f(1, 0, 0);
	if (red != -1 && green != -1 & blue != -1) {
		glColor3f(red, green, blue);
	}
	// Fijar el modo en que se dibuja la entidad con
	gluQuadricDrawStyle(q, GLU_FILL);
	gluCylinder(q, rb, rt, h, nl, ro);
}

void Cylinder::update() {}
void Cylinder::update(GLuint timeElapsed) {}

Cylinder::Cylinder(GLdouble rbase, GLdouble rtop, GLdouble altura, GLuint numLados, GLuint rodajas, GLdouble rojo, GLdouble verde, GLdouble azul)
{
	if (rojo >= 0) red = rojo;
	else red = 0;
	
	if (verde >= 0) green = verde;
	else green = 0;

	if (azul >= 0 ) blue = azul;
	else blue = 0;

	rb = rbase;
	rt = rtop;
	h = altura;
	nl = numLados;
	ro = rodajas;
	
}


Disk::Disk(GLdouble rInterno, GLdouble rExterno, GLint numLados, GLint anillos) {
	
	rInt = rInterno;
	rExt = rExterno;
	nL = numLados;
	a = anillos;

}
void Disk::render(glm::dmat4 const& modelViewMat) {
	uploadMvM(modelViewMat);
	// Fijar el color con glColor3f(...);
	glColor3f(0.5, 0.5, 0.5);
	// Fijar el modo en que se dibuja la entidad con
	gluQuadricDrawStyle(q, GLU_LINE);
	gluDisk(q, rInt, rExt, nL, a);
}
void Disk::update() {}
void Disk::update(GLuint timeElapsed) {}


PartialDisk::PartialDisk(GLdouble rInterno, GLdouble rExterno, GLint numLados, GLint anillos, GLdouble anguloIni, GLdouble anguloBarrido) {
	rInt = rInterno;
	rExt = rExterno;
	nL = numLados;
	a = anillos;
	angIni = anguloIni;
	angBarrido = anguloBarrido;
}
void PartialDisk::render(glm::dmat4 const& modelViewMat) {
	uploadMvM(modelViewMat);
	// Fijar el color con glColor3f(...);
	glColor3f(0.5, 0.5, 0.5);
	// Fijar el modo en que se dibuja la entidad con
	gluQuadricDrawStyle(q, GLU_LINE);
	gluPartialDisk(q, rInt, rExt, nL, a , angIni, angBarrido);
}
void PartialDisk::update() {}
void PartialDisk::update(GLuint timeElapsed) {}

/*Comento la constructora y el render de Rotor cuando heredaban de la clase Entity*/
/*Rotor::Rotor(GLdouble r, GLboolean giroHorario, GLboolean colorVerde) {
	radio = r;
	giro = giroHorario;
	verde = colorVerde;
	if (colorVerde) {
		base = new Cylinder(radio, radio, 50, 200, 100, 0, 1, 0);
	}
	else {
		base = new Cylinder(radio, radio, 50, 200, 100, 1, 0, 0);
	}

	rectangulo = new Rectangulo(radio*2, 50);

	//Colocamos el rectángulo

	dmat4 i = dmat4(1.0);

	i = translate(i, dvec3(0, 0, 25));

	i = rotate(i, radians(90.0), dvec3(1, 0, 0));

	rectangulo->setModelMat(i);

}

void Rotor::render(glm::dmat4 const& modelViewMat) {

	glMatrixMode(GL_MODELVIEW);
	dmat4 aMat = modelViewMat * modelMat;
	glLoadMatrixd(value_ptr(aMat));

	//Habría que comentar esto
	//dmat4 i = dmat4(1.0);
	
	//i = translate(i, dvec3(0, 0, 25));

	//if (giro) {
	//	i = rotate(i, radians(-anguloGiro), dvec3(0, 0, 1));
	//}
	//else {
	//	i = rotate(i, radians(anguloGiro), dvec3(0, 0, 1));
	//}

	//i = rotate(i, radians(90.0), dvec3(1, 0, 0));
	
	//rectangulo->render(modelViewMat*i);
	//rectangulo->render(modelViewMat*i);
	
	//Y usar esto: 
	rectangulo->render(aMat);
	base->render(aMat);

}
*/
/*CREO LA NUEVA CONSTRUCTORA DE ROTOR*/
Rotor::Rotor(GLdouble r, GLboolean giroHorario, GLboolean colorVerde) {
	radio = r;
	giro = giroHorario;
	verde = colorVerde;
	Cylinder* base;
	if (colorVerde) {
		base = new Cylinder(radio, radio, 50, 200, 100, 0, 1, 0);
	}
	else {
		base = new Cylinder(radio, radio, 50, 200, 100, 1, 0, 0);
	}

	rectangulo = new Rectangulo(radio * 2, 50);

	//Colocamos el rectángulo

	dmat4 i = dmat4(1.0);

	i = translate(i, dvec3(0, 0, 25));

	i = rotate(i, radians(90.0), dvec3(1, 0, 0));

	rectangulo->setModelMat(i);

	this->grObjects.push_back(base);
	this->grObjects.push_back(rectangulo);

}

void Rotor::update() {


	anguloGiro = anguloGiro + 10;


	dmat4 i = dmat4(1.0);

	i = translate(i, dvec3(0, 0, 25));

	if (giro) {
		i = rotate(i, radians(-anguloGiro), dvec3(0, 0, 1));
	}
	else {
		i = rotate(i, radians(anguloGiro), dvec3(0, 0, 1));
	}

	i = rotate(i, radians(90.0), dvec3(1, 0, 0));

	rectangulo->setModelMat(i);


}
void Rotor::update(GLuint timeElapsed) { update(); }


Chasis::Chasis() {
	cubo = new CuboConTapas(200);

	//Colocamos el chasis se descomenta para hacer el cambio
	dmat4 i = dmat4(1.0);

	i = scale(i, dvec3(1, 0.1, 1));

	cubo->setModelMat(i);
	
}

void Chasis::render(glm::dmat4 const& modelViewMat) {
	
	glMatrixMode(GL_MODELVIEW);
	dmat4 aMat = modelViewMat * modelMat;
	glLoadMatrixd(value_ptr(aMat));

	glColor3d(0, 0, 1);
	//Se comenta lo siguiente para hacer el cambio
	/*
	dmat4 i = dmat4(1.0);

	i = scale(i, dvec3(1, 0.1, 1));

	cubo->render(modelViewMat*i);
	*/
	//Para el cambio se pone esta
	cubo->render(aMat);


}

void Chasis::update() {}
void Chasis::update(GLuint timeElapsed) {}

//Con la nueva clase de la que hereda solo debo quitar el Chasis*. El resto sigue estando
//Añado al final el push_back de todo.
Dron::Dron(bool encendido) {
	Chasis* chasis = new Chasis();
	rotor1 = new Rotor(100, true, true); //true verde
	rotor2 = new Rotor(100, false, true); //true verde
	rotor3 = new Rotor(100, true, false); //false rojo
	rotor4 = new Rotor(100, false, false); //false rojo


	//Coloco el rotor 1 

	dmat4 i = rotor1->getModelMat();

	i = translate(i, dvec3(-100, (100 * 0.1) + (50 * 0.3), -100));
	i = rotate(i, radians(90.0), dvec3(1, 0, 0));
	i = scale(i, dvec3(0.3, 0.3, 0.3));

	rotor1->setModelMat(i);

	//Coloco el rotor 2

	dmat4 j = rotor2->getModelMat();

	j = translate(j, dvec3(-100, (100 * 0.1) + (50 * 0.3), 100));
	j = rotate(j, radians(90.0), dvec3(1, 0, 0));
	j = scale(j, dvec3(0.3, 0.3, 0.3));

	rotor2->setModelMat(j);

	//Coloco el rotor 3 

	dmat4 k = rotor3->getModelMat();

	k = translate(k, dvec3(100, (100 * 0.1) + (50 * 0.3), 100));
	k = rotate(k, radians(90.0), dvec3(1, 0, 0));
	k = scale(k, dvec3(0.3, 0.3, 0.3));

	rotor3->setModelMat(k);

	//Coloco el rotor 4

	dmat4 l = rotor4->getModelMat();

	l = translate(l, dvec3(100, (100 * 0.1) + (50 * 0.3), -100));
	l = rotate(l, radians(90.0), dvec3(1, 0, 0));
	l = scale(l, dvec3(0.3, 0.3, 0.3));

	rotor4->setModelMat(l);

	//LUZ DEL DRON
	foco = new SpotLight(); //Creo el foco
	foco->setDiff(fvec4(1.0, 1.0, 1.0, 1.0));
	foco->setSpec(fvec4(0.5, 0.5, 0.5, 1.0));
	foco->setAmb(fvec4(0.0, 0.0, 0.0, 1));
	foco->setSpot(fvec3(0.0, 0.0, -1.0), 120, 0);

	foco->enable();

	this->grObjects.push_back(chasis);
	this->grObjects.push_back(rotor1);
	this->grObjects.push_back(rotor2);
	this->grObjects.push_back(rotor3);
	this->grObjects.push_back(rotor4);

	
}
Dron::Dron() {
	Chasis* chasis = new Chasis();
	rotor1 = new Rotor(100, true, true); //true verde
	rotor2 = new Rotor(100, false, true); //true verde
	rotor3 = new Rotor(100, true, false); //false rojo
	rotor4 = new Rotor(100, false, false); //false rojo
	

	//Coloco el rotor 1 
	
	dmat4 i = rotor1->getModelMat();

	i = translate(i, dvec3(-100, (100 * 0.1) + (50 * 0.3), -100));
	i = rotate(i, radians(90.0), dvec3(1, 0, 0));
	i = scale(i, dvec3(0.3, 0.3, 0.3));

	rotor1->setModelMat(i);

	//Coloco el rotor 2

	dmat4 j = rotor2->getModelMat();

	j = translate(j, dvec3(-100, (100 * 0.1) + (50 * 0.3), 100));
	j = rotate(j, radians(90.0), dvec3(1, 0, 0));
	j = scale(j, dvec3(0.3, 0.3, 0.3));

	rotor2->setModelMat(j);

	//Coloco el rotor 3 

	dmat4 k = rotor3->getModelMat();

	k = translate(k, dvec3(100, (100 * 0.1) + (50 * 0.3), 100));
	k = rotate(k, radians(90.0), dvec3(1, 0, 0));
	k = scale(k, dvec3(0.3, 0.3, 0.3));

	rotor3->setModelMat(k);

	//Coloco el rotor 4

	dmat4 l = rotor4->getModelMat();

	l = translate(l, dvec3(100, (100 * 0.1) + (50 * 0.3), -100));
	l = rotate(l, radians(90.0), dvec3(1, 0, 0));
	l = scale(l, dvec3(0.3, 0.3, 0.3));

	rotor4->setModelMat(l);

	this->grObjects.push_back(chasis);
	this->grObjects.push_back(rotor1);
	this->grObjects.push_back(rotor2);
	this->grObjects.push_back(rotor3);
	this->grObjects.push_back(rotor4);
	
}

/*SE COMENTA EL RENDER POR LA CLASE COMPOUNDENTIT DE LA QUE AHORA HEREDA*/
/*
void Dron::render(glm::dmat4 const& modelViewMat) {
	
	glMatrixMode(GL_MODELVIEW);
	dmat4 aMat = modelViewMat * modelMat;
	glLoadMatrixd(value_ptr(aMat));

	chasis->render(aMat);
	rotor1->render(aMat);
	rotor2->render(aMat);
	rotor3->render(aMat);
	rotor4->render(aMat);
}
*/

void Dron::render(glm::dmat4 const& modelViewMat) {
	
	//glDisable(GL_COLOR_MATERIAL);

	dmat4 m = modelViewMat * modelMat;

	if (foco != nullptr) {
		foco->upload(m);
	}
	
	CompoundEntity::render(modelViewMat);

	//glEnable(GL_COLOR_MATERIAL);

}
void Dron::update() {

	rotor1->update();
	rotor2->update();
	rotor3->update();
	rotor4->update();
	
}
void Dron::update(GLuint timeElapsed) {

	if (timeElapsed >= 20) {
		rotor1->update();
		rotor2->update();
		rotor3->update();
		rotor4->update();
		
	}
}

//CONO POR REVOLUCIÓN
Cone::Cone(GLdouble h, GLdouble r)
{
	//h altura de cono y r radio de la base
	int m = 3; //m = numero puntos perfil
	dvec3* perfil = new dvec3[m];
	perfil[0] = dvec3(0.0, 0.0, 0.0);
	perfil[1] = dvec3(r, 0.0, 0.0);
	perfil[2] = dvec3(0.0, h, 0.0);

	this->mesh = new MBR(m, 50, perfil);
}

void Cone::render(glm::dmat4 const & modelViewMat)
{
	mesh->render();
}

void Cone::update()
{
}

void Cone::update(GLuint timeElapsed)
{
}

// ESFERA POR REVOLUCIÓN
Esfera::Esfera(GLint paralelos, GLint meridianos, GLdouble radio)
{
	m = paralelos; //
	n = meridianos;
	r = radio;
	
	//material.setCooper();

	GLdouble x = 0; 
	GLdouble y = -r;
	GLdouble incr = 180.0/m;
	GLdouble ang = -90.0;

	dvec3* perfil = new dvec3[m];
	
	for (int i = 0; i < m-1; i++) {

		perfil[i] = dvec3(x, y, 0.0);
		ang = ang + incr;
		x = r * cos(radians(ang));
		y = r * sin(radians(ang));

	}
	perfil[m - 1] = dvec3(0, r, 0.0);

	this->mesh = new MBR(m, n, perfil);
}

void Esfera::render(glm::dmat4 const & modelViewMat)
{
	//Quito el color para el apartado 20
	//glColor3f(0.8, 0.4, 0.2);
	//material->setCooper();

	uploadMvM(modelViewMat);

	glDisable(GL_COLOR_MATERIAL);

	material->setGold();
	material->upload();
	mesh->render();

	glEnable(GL_COLOR_MATERIAL);
}

void Esfera::update()
{
}

void Esfera::update(GLuint timeElapsed)
{
}

Satelite::Satelite(GLdouble radio)
{
	r = radio;
	esfera = new Esfera(50, 50, r);
	dron = new Dron();

	//Coloco el dron

	dmat4 m = dmat4(1.0);

	m = rotate(m, radians(anguloGiro), dvec3(0, 0, 1));
	m = translate(m, dvec3(0, r + 5.0, 0));
	m = scale(m, dvec3(0.1, 0.1, 0.1));
	
	dron->setModelMat(m);


}

void Satelite::render(dmat4 const & modelViewMat)
{
	glMatrixMode(GL_MODELVIEW);
	dmat4 aMat = modelViewMat * modelMat;
	glLoadMatrixd(value_ptr(aMat));

	esfera->render(aMat);
	dron->render(aMat);
	
}

void Satelite::update()
{
	anguloGiro = anguloGiro + 1;
	
	dmat4 m = dmat4(1.0);

	m = rotate(m, radians(anguloGiro), dvec3(0, 0, 1));
	m = translate(m, dvec3(0, r + 5.0, 0));
	m = scale(m, dvec3(0.1, 0.1, 0.1));

	dron->setModelMat(m);

	dron->update();
}

void Satelite::update(GLuint timeElapsed)
{
	if(timeElapsed > 20){
		anguloGiro = anguloGiro + 3;
		update();
		
	}
}


EsferaDron::EsferaDron(GLdouble radio)
{
	r = radio;
	esfera = new Esfera(50, 50, r);

	dron = new Dron(true);

	//Coloco el dron

	dmat4 m = dmat4(1.0);

	m = rotate(m, radians(anguloGiro), dvec3(1, 0, 0)); //arriba y abajo
	//m = rotate(m, radians(anguloOtroGiro), dvec3(0, 1, 0)); // GIRA SOBRE SÍ MISMO
	m = rotate(m, radians(anguloOtroGiro), dvec3(0, 0, 1)); // izquierda y derecha
	m = translate(m, dvec3(0, r + 25.0, 0));
	m = scale(m, dvec3(0.1, 0.1, 0.1));

	dron->setModelMat(m);

}

void EsferaDron::render(dmat4 const & modelViewMat)
{
	glMatrixMode(GL_MODELVIEW);
	dmat4 aMat = modelViewMat * modelMat;
	glLoadMatrixd(value_ptr(aMat));

	esfera->render(aMat);
	dron->render(aMat);
}

void EsferaDron::update(){}

void EsferaDron::update(GLuint timeElapsed) {}

void EsferaDron::updateNuevo(GLuint movimiento)
{
	if (movimiento == 1) {
		anguloOtroGiro += 2.0;
	}
	else if (movimiento == 2) {
		anguloOtroGiro -= 2.0;
	}
	else if (movimiento == 3) {
		anguloGiro += 2.0;
	}
	else if (movimiento == 4) {
		anguloGiro -= 2.0;
	}

	dmat4 m = dmat4(1.0);

	m = rotate(m, radians(anguloGiro), dvec3(1, 0, 0)); //arriba y abajo
	//m = rotate(m, radians(anguloOtroGiro), dvec3(0, 1, 0)); // GIRA SOBRE SÍ MISMO
	m = rotate(m, radians(anguloOtroGiro), dvec3(0, 0, 1)); // izquierda y derecha
	m = translate(m, dvec3(0, r + 25.0, 0));
	m = scale(m, dvec3(0.1, 0.1, 0.1));

	dron->setModelMat(m);
	
}

Dronitos::Dronitos()
{
	principal = new Dron();
	d1 = new Dron();
	d2 = new Dron();
	d3 = new Dron();
	d4 = new Dron();

	//Coloco el primer dronito

	dmat4 m1 = dmat4(1.0);

	m1 = translate(m1, dvec3(-100, 50, -100));
	m1 = scale(m1, dvec3(0.25, 0.25, 0.25));

	d1->setModelMat(m1);

	//Coloco el segundo dronito

	dmat4 m2 = dmat4(1.0);

	m2 = translate(m2, dvec3(-100, 50, 100));
	m2 = scale(m2, dvec3(0.25, 0.25, 0.25));
	
	d2->setModelMat(m2);

	//Coloco el tercer dronito
	dmat4 m3 = dmat4(1.0);

	m3 = translate(m3, dvec3(100, 50, -100));
	m3 = scale(m3, dvec3(0.25, 0.25, 0.25));
	
	d3->setModelMat(m3);

	//Coloco el cuarto dronito

	dmat4 m4 = dmat4(1.0);

	m4 = translate(m4, dvec3(100, 50, 100));
	m4 = scale(m4, dvec3(0.25, 0.25, 0.25));
	
	d4->setModelMat(m4);

}

void Dronitos::render(dmat4 const & modelViewMat)
{
	glMatrixMode(GL_MODELVIEW);
	dmat4 aMat = modelViewMat * modelMat;
	glLoadMatrixd(value_ptr(aMat));

	d1->render(aMat);
	d2->render(aMat);
	d3->render(aMat);
	d4->render(aMat);
	principal->render(aMat);
}

void Dronitos::update()
{
	principal->update();
	d1->update();
	d2->update();
	d3->update();
	d4->update();
}

void Dronitos::update(GLuint timeElapsed)
{
	principal->update();
	d1->update();
	d2->update();
	d3->update();
	d4->update();
}

SateliteCompound::SateliteCompound(GLdouble radio)
{
	r = radio;
	esfera = new Esfera(50, 50, r);

	dron = new Dron(true);

	//Coloco el dron

	dmat4 m = dmat4(1.0);

	m = rotate(m, radians(anguloGiro), dvec3(1, 0, 0)); //arriba y abajo
	//m = rotate(m, radians(anguloOtroGiro), dvec3(0, 1, 0)); // GIRA SOBRE SÍ MISMO
	m = rotate(m, radians(anguloOtroGiro), dvec3(0, 0, 1)); // izquierda y derecha
	m = translate(m, dvec3(0, r + 25.0, 0));
	m = scale(m, dvec3(0.1, 0.1, 0.1));

	dron->setModelMat(m);

	this->grObjects.push_back(esfera);
	this->grObjects.push_back(dron);
}

/*void SateliteCompound::update()
{
	dron->update();

}
*/

void SateliteCompound::move(GLuint tecla)
{
	switch (tecla) {
	case GLUT_KEY_UP:
		anguloGiro -= 2.0;
		break;
	case GLUT_KEY_DOWN:
		//El dron debe bajar
		anguloGiro += 2.0;
		break;
	case GLUT_KEY_RIGHT:
		anguloOtroGiro -= 2.0;
		break;
	case GLUT_KEY_LEFT:
		anguloOtroGiro += 2.0;
		break;
	case 9: {
		GLuint lucecita = dron->getLuzId();
		if (lucecita != -1) {
			glDisable(lucecita);
		}
		break;
	}
	case 8: {
		GLuint lucezota = dron->getLuzId();
		if (lucezota != -1) {
			glEnable(lucezota);
		}
		break;
	}
	}

	dmat4 m = dmat4(1.0);

	m = rotate(m, radians(anguloGiro), dvec3(1, 0, 0)); //arriba y abajo
	//m = rotate(m, radians(anguloOtroGiro), dvec3(0, 1, 0)); // GIRA SOBRE SÍ MISMO
	m = rotate(m, radians(anguloOtroGiro), dvec3(0, 0, 1)); // izquierda y derecha
	m = translate(m, dvec3(0, r + 25.0, 0));
	m = scale(m, dvec3(0.1, 0.1, 0.1));

	dron->setModelMat(m);
	dron->update();
}
