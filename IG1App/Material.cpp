#include "Material.h"

//-------------------------------------------------------------------------

void Material::upload() {
	glMaterialfv(face, GL_AMBIENT, value_ptr(ambient));
	glMaterialfv(face, GL_DIFFUSE, value_ptr(diffuse));
	glMaterialfv(face, GL_SPECULAR, value_ptr(specular));
	glMaterialf(face, GL_SHININESS, expF);
	glShadeModel(sh);

	//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE); //Defecto
}

void Material::setCooper() {
	ambient = { 0.19125, 0.0735, 0.0225, 1.0 };
	diffuse = { 0.7038, 0.27048, 0.0828, 1.0 };
	specular = { 0.256777, 0.137622, 0.086014, 1.0 };
	expF = 12.8;
}

void Material::setSilver() {
	ambient = { 0.19125, 0.0735, 0.0225, 1.0 };
	diffuse = { 0.5, 0.5, 0.5, 1.0 };
	specular = {1, 1, 1, 1};
	expF = 12.8;
}

void Material::setGold() {
	ambient = { 0.19125, 0.0735, 0.0225, 1.0 };
	diffuse = { 0.917647059, 0.745098039, 0.247058824, 1.0 };
	specular = { 1, 1, 1, 1 };
	expF = 12.8;
}