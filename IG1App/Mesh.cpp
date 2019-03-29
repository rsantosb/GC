#include "Mesh.h"

using namespace glm;

//-------------------------------------------------------------------------

MBR::MBR(GLuint puntos, GLuint rotaciones, dvec3* poriginal) {
	m = puntos;
	n = rotaciones;
	perfil = poriginal;
	vertexBuilding();
	normalize();
	render();
}

void MBR::vertexBuilding() {
	//numVertices = m * n;
	vertices = new dvec3[m*n];

	for (int i = 0; i < n; i++) {

		double theta = i * 2 * 3.1416 / n;
		double c = cos(theta);
		double s = sin(theta);

		for (int j = 0; j < m; j++) {
			int indice = i * m + j;
			//Aplicar la matriz al punto j-ésmo del perfil
			double x = c * perfil[j][0] + s * perfil[j][2];
			double z = -s * perfil[j][0] + c * perfil[j][2];
			dvec3 p = dvec3(x, perfil[j][1], z);
			vertices[indice] = p;
		}
	}

}

void MBR::render() {
	if (vertices != nullptr) {
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_DOUBLE, 0, vertices);

		//Activación de vertex array colores y texturas
		/*if (colors != nullptr) {
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(4, GL_DOUBLE, 0, colors);   // number of coordinates per color, type of each coordinate, stride, pointer 
		}

		if (texture != nullptr) {
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(2, GL_DOUBLE, 0, texture);   // number of coordinates per color, type of each coordinate, stride, pointer 
		}*/

		if (normals != nullptr) {
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_DOUBLE, 0, normals);

			primitive = GL_LINE_LOOP; // GL_PLOYGON o GL_LINE_LOOP
			//se dan índices del vértices de caras cuadrangulares
			for (int i = 0; i < n; i++) {
				//Unir muestra i-ésima con (i+1)%n-ésima
				for (int j = 0; j < m - 1; j++) {
					//Empezar en esquina inferior izquierda de la cara
					int indice = i * m + j;
					unsigned int index[] = { indice, (indice + m) % (n*m),
											(indice + m + 1) % (n*m),
											indice + 1 };
					glDrawElements(primitive, 4, GL_UNSIGNED_INT, index);
				}
			}
		}

		//glDisableClientState(GL_VERTEX_ARRAY);
		//glDisableClientState(GL_NORMAL_ARRAY);
		//glDisableClientState(GL_COLOR_ARRAY);

	}

	
}

void MBR::normalize() {

	normals = new dvec3[m*n];
	for (int i = 0; i < m*n; i++) {
		normals[i] = dvec3(0.0, 0.0, 0.0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			//Recorrido de todos los vértices
			//Ojo, i < n (obliga a usar %(n*m))
			//y j<m-1 (para excluir los vértices del borde superior)
			int indice = i * m + j;
			//Por cada cara en la que el vértice ocupa la esquina
			//inferior izquierdo, se determinan 3 indices i0, i1, i2
			//de 3 vértices consecutivos de esa cara
			GLint i0 = indice;
			GLint i1 = (indice + m) %(n*m);
			GLint i2 = (indice + 1 + m) % (n*m);
			GLint i3 = indice + 1; 

			dvec3 aux0 = vertices[i0];
			dvec3 aux1 = vertices[i1];
			dvec3 aux2 = vertices[i2];

			dvec3 norm = glm::cross(aux2 - aux1, aux0 - aux1);
			normals[i0] += norm;
			normals[i1] += norm;
			normals[i2] += norm;
			normals[i3] += norm;

		} // fin del for j
		// se normalizan todos los vectores normales
		normals[i] = glm::normalize(normals[i]);
	}
}

Mesh ::~Mesh(void) {

  delete[] vertices;  vertices = nullptr;
  delete[] colors;    colors = nullptr;
  delete[] texture;    texture = nullptr;
}
//-------------------------------------------------------------------------

void Mesh::render() {

  if (vertices != nullptr) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, vertices);  // number of coordinates per vertex, type of each coordinate, stride, pointer 
    if (colors != nullptr) {
      glEnableClientState(GL_COLOR_ARRAY);
      glColorPointer(4, GL_DOUBLE, 0, colors);   // number of coordinates per color, type of each coordinate, stride, pointer 
    }

	if (texture != nullptr) {
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_DOUBLE, 0, texture);   // number of coordinates per color, type of each coordinate, stride, pointer 
	}
	
    glDrawArrays(primitive, 0, numVertices);   // primitive graphic, first index and number of elements to be rendered

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
  }
}
//-------------------------------------------------------------------------

Mesh * Mesh::createRGBAxes(GLdouble l) {

  Mesh* m = new Mesh();
  m->primitive = GL_LINES;
  m->numVertices = 6;

  m->vertices = new dvec3[m->numVertices];
  // X axis vertices
  m->vertices[0] = dvec3(0.0, 0.0, 0.0);   
  m->vertices[1] = dvec3(l, 0.0, 0);
  // Y axis vertices
  m->vertices[2] = dvec3(0, 0.0, 0.0);
  m->vertices[3] = dvec3(0.0, l, 0.0); 
  // Z axis vertices
  m->vertices[4] = dvec3(0.0, 0.0, 0.0);
  m->vertices[5] = dvec3(0.0, 0.0, l);

  m->colors = new dvec4[m->numVertices];
  // X axis color: red  ( Alpha = 1 : fully opaque)
  m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
  m->colors[1] = dvec4(1.0, 0.0, 0.0, 1.0);
  // Y axis color: green
  m->colors[2] = dvec4(0.0, 1.0, 0.0, 1.0);
  m->colors[3] = dvec4(0.0, 1.0, 0.0, 1.0);
  // Z axis color: blue
  m->colors[4] = dvec4(0.0, 0.0, 1.0, 1.0);
  m->colors[5] = dvec4(0.0, 0.0, 1.0, 1.0);
 
  return m; 
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaPoliespiral(dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert) {
	Mesh* m = new Mesh();
	m->primitive = GL_LINE_STRIP;
	m->numVertices = numVert;

	m->vertices = new dvec3[m->numVertices];

	double x = verIni.x;
	double y = verIni.y;

	double longit = ladoIni;
	double ang = angIni;

	for (int i = 0; i < numVert; i++) 
	{
		m->vertices[i] = dvec3(x, y, 0.0);
		x = x + longit * cos(radians(ang));
		y = y + longit * sin(radians(ang));
		longit = longit + incrLado;
		ang = ang + incrAng;
	}
	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaPoliespiral2(dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert) {
	Mesh* m = new Mesh();
	m->primitive = GL_LINE_STRIP;
	m->numVertices = numVert;

	m->vertices = new dvec3[m->numVertices];

	double x = verIni.x;
	double y = verIni.y;

	double longit = ladoIni;
	double ang = angIni;

	for (int i = 0; i < numVert; i++)
	{
		m->vertices[i] = dvec3(x, y, 0.0);
		x = x + longit * cos(radians(ang));
		y = y + longit * sin(radians(ang));
		longit = longit + incrLado;
		ang = ang + incrAng;
	}
	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaDragon(GLuint numVert) {

	Mesh* m = new Mesh();
	m->primitive = GL_POINTS;
	m->numVertices = numVert;

	m->vertices = new dvec3[m->numVertices];

	double x = 0;
	double y = 0;
	double x_aux = 0 , y_aux = 0;
	double pr1 = 0.787473;
	double pr2 = 1 - pr1;

	for (int i = 0; i < numVert; i++) {
		m->vertices[i] = dvec3(x, y, 0.0);

		x_aux = x;
		y_aux = y;

		double azar = rand() / double(RAND_MAX);

		if (azar < pr1) {
			x = 0.824074*x_aux + 0.281482*y_aux - 0.882290;
			y = -0.212346*x_aux + 0.864198*y_aux - 0.110607;
		}
		else {
			x = 0.088272*x_aux + 0.520988*y_aux + 0.785360;
			y = -0.463889*x_aux - 0.377778*y_aux + 8.095795;
		}
	}

	return m; 
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaDragon2(GLuint numVert) {

	Mesh* m = new Mesh();
	m->primitive = GL_POINTS;
	m->numVertices = numVert;

	m->vertices = new dvec3[m->numVertices];

	double x = 0;
	double y = 0;
	double x_aux = 0, y_aux = 0;
	double pr1 = 0.65854758;
	double pr2 = 1 - pr1;

	for (int i = 0; i < numVert; i++) {
		m->vertices[i] = dvec3(x, y, 0.0);

		x_aux = x;
		y_aux = y;

		double azar = rand() / double(RAND_MAX);

		if (azar < pr1) {
			x = 0.875147*x_aux + y_aux - 0.882290;
			y = -0.1492548*x_aux + y_aux - 0.110607;
		}
		else {
			x = 0.088272*x_aux + 0.520988*y_aux + 0.785360;
			y = -0.463889*x_aux - 0.377778*y_aux + 8.095795;
		}
	}

	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaTriangulo(GLdouble r) {

	Mesh* m = new Mesh();
	m->primitive = GL_TRIANGLES;
	m->numVertices = 3;

	m->vertices = new dvec3[m->numVertices];

	double ang = 90;
	double incAng = 360/3;
	double radio = r;
	double cx = 0;
	double cy = 0;
	double x = 0;
	double y = 0;

	for (int i = 0; i < m->numVertices; i++) {

		x = radio * cos(radians(ang));
		y = radio * sin(radians(ang));

		m->vertices[i] = dvec3(x, y, 0.0);

		ang = ang + incAng;
	}
	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaTrianguloRGB(GLdouble r) {

	Mesh* m = generaTriangulo(r);

	m->colors = new dvec4[m->numVertices];
	// X axis color: red  ( Alpha = 1 : fully opaque)
	m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);

	// Y axis color: green
	m->colors[1] = dvec4(0.0, 1.0, 0.0, 1.0);

	// Z axis color: blue
	m->colors[2] = dvec4(0.0, 0.0, 1.0, 1.0);

	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaRectangulo(GLdouble w, GLdouble h) {

	Mesh* m = new Mesh();
	m->primitive = GL_TRIANGLE_STRIP;
	m->numVertices = 4;

	m->vertices = new dvec3[m->numVertices];

	m->vertices[0] = dvec3(-w/2, h/2, 0);
	m->vertices[1] = dvec3(-w/2, -h/2, 0);
	m->vertices[2] = dvec3(w/2, h/2, 0);
	m->vertices[3] = dvec3(w/2, -h/2, 0);

	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaRectanguloRGB(GLdouble w, GLdouble h) {

	Mesh* m = generaRectangulo(w,h);

	m->colors = new dvec4[m->numVertices];
	m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
	m->colors[1] = dvec4(0.0, 1.0, 0.0, 1.0);
	m->colors[2] = dvec4(0.0, 0.0, 1.0, 1.0);
	m->colors[2] = dvec4(0.5, 0.5, 0.5, 1.0);

	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaEstrella3D(GLdouble re, GLdouble np, GLdouble h) {
	Mesh* m = new Mesh();
	m->primitive = GL_TRIANGLE_FAN;
	m->numVertices = 2*np + 2;

	m->vertices = new dvec3[m->numVertices];

	double ang = 90;
	double incAng = 360 / (2*np);
	double radio = re;
	double radioI = re / 2;

	double x = 0;
	double y = 0;
	double z = 0;

	//m->vertices[0] = dvec3(x, y, z);

	for (int i = 0; i < m->numVertices; i=i+2) {

		m->vertices[i] = dvec3(x, y, z);

		x = radio * cos(radians(ang));
		y = radio * sin(radians(ang));
		z = h;

		ang = ang + incAng;

		if (i != m->numVertices-1) {
			
			m->vertices[i+1] = dvec3(x, y, z);
		}

		x = radioI * cos(radians(ang));
		y = radioI * sin(radians(ang));
		z = h;

		ang = ang + incAng;
	}
	ang = 90;
	//m->vertices[m->numVertices - 2] = dvec3(radioI * cos(radians(ang)), radioI * sin(radians(ang)), h);
	m->vertices[m->numVertices - 1] = m->vertices[1];
	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaContCubo(GLdouble l) {
	Mesh* m = new Mesh();
	m->primitive = GL_TRIANGLE_STRIP;
	m->numVertices = 10;

	m->vertices = new dvec3[m->numVertices];

	m->vertices[0] = dvec3(-l/2, l/2, l/2); // v0
	m->vertices[1] = dvec3(-l/2, -l/2, l/2); // v1
	m->vertices[2] = dvec3(l/2, l/2, l/2); // v2
	m->vertices[3] = dvec3(l/2, -l/2, l/2); // v3
	m->vertices[4] = dvec3(l/2, l/2, -l/2); //v4
	m->vertices[5] = dvec3(l/2, -l/2, -l/2); //v5
	m->vertices[6] = dvec3(-l/2, l/2, -l/2); //v6
	m->vertices[7] = dvec3(-l/2, -l/2, -l/2); //v7
	m->vertices[8] = m->vertices[0]; //v8
	m->vertices[9] = m->vertices[1]; //v9
	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaRectanguloTexCor(GLdouble w, GLdouble h, GLuint rw, GLuint rh) {

	Mesh* m = generaRectangulo(w, h);
	
	m->texture = new dvec2[m->numVertices];
	m->texture[0] = dvec2(0, 0);
	m->texture[1] = dvec2(0, rh);
	m->texture[2] = dvec2(rw, 0);
	m->texture[3] = dvec2(rw, rh);
	
	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaEstrellaTexCor(GLdouble r, GLdouble nL, GLdouble h) {

	Mesh* m = generaEstrella3D(r, nL, h);

	m->texture = new dvec2[m->numVertices];

	double ang = 90;
	double incAng = 360 / (2 * nL);

	double radio = 0.5;
	double radioI = radio / 2;

	double x = 0;
	double y = 0;

	//m->vertices[0] = dvec3(x, y, z);

	for (int i = 0; i < m->numVertices; i = i + 2) {

		m->texture[i] = dvec2(x, y);

		x = radio * cos(radians(ang));
		y = radio * sin(radians(ang));

		ang = ang + incAng;

		if (i != m->numVertices - 1) {

			m->texture[i + 1] = dvec2(x, y);
		}

		x = radioI * cos(radians(ang));
		y = radioI * sin(radians(ang));

		ang = ang + incAng;
	}
	ang = 90;
	//m->vertices[m->numVertices - 2] = dvec3(radioI * cos(radians(ang)), radioI * sin(radians(ang)), h);
	m->texture[m->numVertices - 1] = m->texture[1];
	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaCajaTexCor(GLdouble l) {

	Mesh* m = generaContCubo(l);

	m->texture = new dvec2[m->numVertices];

	m->texture[0] = dvec2(0,1); // v0
	m->texture[1] = dvec2(0,0); // v1
	m->texture[2] = dvec2(1,1); // v2
	m->texture[3] = dvec2(1,0); // v3
	m->texture[4] = dvec2(0,1); //v4
	m->texture[5] = dvec2(0,0); //v5
	m->texture[6] = dvec2(1,1); //v6
	m->texture[7] = dvec2(1,0); //v7
	m->texture[8] = m->texture[0]; //v8
	m->texture[9] = m->texture[1]; //v9
	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generaBaseTexCor(GLdouble l) {

	Mesh* m = generaRectangulo(l,l);

	m->texture = new dvec2[m->numVertices];

	m->texture[0] = dvec2(0, 1); // v0
	m->texture[1] = dvec2(0, 0); // v1
	m->texture[2] = dvec2(1, 1); // v2
	m->texture[3] = dvec2(1, 0); // v3
	return m;
}

Mesh * Mesh::generaCajaLateral(GLdouble l, GLdouble h) {

	Mesh* m = new Mesh();
	m->primitive = GL_TRIANGLE_STRIP;
	m->numVertices = 10;

	m->vertices = new dvec3[m->numVertices];

	m->vertices[0] = dvec3(-l / 2, l / 2, l / 2); // v0
	m->vertices[1] = dvec3(-l / 2, -l / 2, l / 2); // v1
	m->vertices[2] = dvec3(l / 2, l / 2, l / 2); // v2
	m->vertices[3] = dvec3(l / 2, -l / 2, l / 2); // v3
	m->vertices[4] = dvec3(l / 2, l / 2, -l / 2); //v4
	m->vertices[5] = dvec3(l / 2, -l / 2, -l / 2); //v5
	m->vertices[6] = dvec3(-l / 2, l / 2, -l / 2); //v6
	m->vertices[7] = dvec3(-l / 2, -l / 2, -l / 2); //v7
	m->vertices[8] = m->vertices[0]; //v8
	m->vertices[9] = m->vertices[1]; //v9

	m->texture = new dvec2[m->numVertices];

	m->texture[0] = dvec2(0, 1); // v0
	m->texture[1] = dvec2(0, 0); // v1
	m->texture[2] = dvec2(1, 1); // v2
	m->texture[3] = dvec2(1, 0); // v3
	m->texture[4] = dvec2(0, 1); //v4
	m->texture[5] = dvec2(0, 0); //v5
	m->texture[6] = dvec2(1, 1); //v6
	m->texture[7] = dvec2(1, 0); //v7
	m->texture[8] = m->texture[0]; //v8
	m->texture[9] = m->texture[1]; //v9
	return m;
}