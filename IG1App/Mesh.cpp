#include "Mesh.h"
#include "time.h"

using namespace glm;

//-------------------------------------------------------------------------

Mesh ::~Mesh(void) 
{
  delete[] vertices;
  delete[] colors;
}
//-------------------------------------------------------------------------

void Mesh::render()
{
  if (vertices != nullptr) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, vertices);  // number of coordinates per vertex, type of each coordinate, stride, pointer 
    if (colors != nullptr) {
      glEnableClientState(GL_COLOR_ARRAY);
      glColorPointer(4, GL_DOUBLE, 0, colors);   // number of coordinates per color, type of each coordinate, stride, pointer 
    }
	
    glDrawArrays(primitive, 0, numVertices);   // primitive graphic, first index and number of elements to be rendered

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
  }
}
//-------------------------------------------------------------------------

Mesh* Mesh::createRGBAxes(glm::dvec2 center, GLdouble l)
{
  Mesh* m = new Mesh();
  m->primitive = GL_LINES;
  m->numVertices = 6;

  m->vertices = new dvec3[m->numVertices];
  // X axis vertices
  m->vertices[0] = dvec3(center.x, center.y, 0.0);   
  m->vertices[1] = dvec3(center.x + l, center.y, 0);
  // Y axis vertices
  m->vertices[2] = dvec3(center.x, center.y, 0.0);
  m->vertices[3] = dvec3(center.x, center.y + l, 0.0);
  // Z axis vertices
  m->vertices[4] = dvec3(center.x, center.y, 0.0);
  m->vertices[5] = dvec3(center.x, center.y, l);

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

Mesh* Mesh::generaPoliespiral(glm::dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert){
	
	Mesh* m = new Mesh();
	m->primitive = GL_LINE_STRIP;
	m->numVertices = numVert;
	m->colors = new dvec4[m->numVertices];
	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(verIni[0], verIni[1], 0);

	for (int i = 1; i < m->numVertices; i++) {

		dvec3 last = m->vertices[i - 1];

		//m->vertices[i] = siguiente(last[0], last[1], angIni, ladoIni);
		m->colors[i] = dvec4(0.0, 0.0, 1.0, 1.0);
		m->vertices[i] = dvec3(last[0] + ladoIni * cos(radians(angIni)), last[1] + ladoIni * sin(radians(angIni)), 0);
		angIni += incrAng;
		ladoIni += incrLado;
	}

	return m;
}
//-------------------------------------------------------------------------

Mesh* Mesh::generadragon(glm::dvec2 center, GLuint numVert) {

	Mesh* m = new Mesh();
	m->primitive = GL_POINTS;
	m->numVertices = numVert;
	m->colors = new dvec4[m->numVertices];
	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(center.x, center.y, 0);

	for (int i = 1; i < m->numVertices; i++) {
		m->colors[i] = dvec4(0.0, 0.0, 1.0, 1.0);
		double azar = rand() / double(RAND_MAX);

		if (azar < 0.787473) {
			m->vertices[i] = dvec3(0.824074 * m->vertices[i - 1].x + 0.281482 * m->vertices[i - 1].y - 0.882290, -0.212346 * m->vertices[i - 1].x + 0.864198 * m->vertices[i - 1].y - 0.110607, 0);
		}
		else { // azar >= 0.787473
			m->vertices[i] = dvec3(0.088272 * m->vertices[i - 1].x + 0.520988 * m->vertices[i - 1].y + 0.785360, -0.463889 * m->vertices[i - 1].x - 0.377778 * m->vertices[i - 1].y + 8.095795, 0);
		}
	}

	return m;
}

Mesh * Mesh::generaTrianguloRGB(dvec2 center, GLdouble r)
{
	Mesh * m = new Mesh();
	m->primitive = GL_TRIANGLES;
	m->numVertices = 3;
	m->vertices = new dvec3[m->numVertices];
	m->colors = new dvec4[m->numVertices];

	m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
	m->colors[1] = dvec4(0.0, 1.0, 0.0, 1.0);
	m->colors[2] = dvec4(0.0, 0.0, 1.0, 1.0);

	for (int i = 0; i < m->numVertices; i++) {
		m->vertices[i] = dvec3(center.x + r * cos(radians(90.0 + 120.0*i)), center.y + r * sin(radians(90.0 + 120.0*i)), 0.0);
	}

	return m;
}

Mesh * Mesh::generaRectangulo(dvec2 center, GLdouble w, GLdouble h)
{
	Mesh * m = new Mesh();
	m->primitive = GL_TRIANGLE_STRIP;
	m->numVertices = 4;
	m->vertices = new dvec3[m->numVertices];
	m->colors = new dvec4[m->numVertices];



	m->vertices[0] = dvec3(-w / 2 + center.x, h / 2 + center.y, 0.0);
	m->vertices[1] = dvec3(-w / 2 + center.x, -h / 2 + center.y, 0.0);
	m->vertices[2] = dvec3(w / 2 + center.x, h / 2 + center.y, 0.0);
	m->vertices[3] = dvec3(w / 2 + center.x, -h / 2 + center.y, 0.0);

	return m;
}
Mesh * Mesh::generaRectanguloRGB(dvec2 center, GLdouble w, GLdouble h)
{
	Mesh * m = generaRectangulo(center, w, h);
	m->colors = new dvec4[m->numVertices];
	m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
	m->colors[1] = dvec4(0.0, 1.0, 0.0, 1.0);
	m->colors[2] = dvec4(0.0, 0.0, 1.0, 1.0);
	m->colors[3] = dvec4(0.0, 0.0, 0.0, 1.0);

	return m;
}
Mesh * Mesh::generaEstrella3D(glm::dvec2 center, GLdouble re, GLdouble np, GLdouble h)
{
	Mesh * m = new Mesh();
	m->primitive = GL_TRIANGLE_FAN;
	m->numVertices = 2 * np + 2;
	m->vertices = new dvec3[m->numVertices];
	m->colors = new dvec4[m->numVertices];
	m->vertices[0] = dvec3(0.0, 0.0, 0.0);

	GLdouble incrAng = 360.0 / (m->numVertices-2);
	GLdouble angIni = 90.0;
	GLdouble x = 0.0;
	GLdouble y = 0.0;

	for (int i = 1; i < m->numVertices; i++) {
		
		if (i % 2 == 1) { //impar
			x = center.x + re * cos(radians(angIni + incrAng * (i - 1)));
			y = center.y + re * sin(radians(angIni + incrAng * (i - 1)));
		}
		else { //par
			x = center.x + re/2 * cos(radians(angIni + incrAng * (i - 1)));
			y = center.y + re/2 * sin(radians(angIni + incrAng * (i - 1)));
		}
		
		m->vertices[i] = dvec3(x, y, h);
	}

	m->vertices[m->numVertices - 1] = m->vertices[1];
	for (int i = 0; i < m->numVertices; i++) {
		m->colors[i] = dvec4((GLdouble)rand() / (RAND_MAX), (GLdouble)rand() / (RAND_MAX), (GLdouble)rand() / (RAND_MAX), 0.9);
	}
	return m;
}

Mesh * Mesh::generaCubo(glm::dvec3 center, GLdouble w, GLdouble h)
{

	Mesh * m = new Mesh();
	m->primitive = GL_TRIANGLE_STRIP;
	m->numVertices = 10;
	m->vertices = new dvec3[m->numVertices];
	m->colors = new dvec4[m->numVertices];

	GLdouble z = w / 2;

	m->vertices[0] = dvec3(center.x + -w / 2, center.y + h / 2, center.z + z);
	m->vertices[1] = dvec3(center.x + -w / 2, center.y - h / 2, center.z + z);
	m->vertices[2] = dvec3(center.x + w / 2, center.y + h / 2, center.z + z);
	m->vertices[3] = dvec3(center.x + w / 2, center.y - h / 2, center.z + z);
	m->vertices[4] = dvec3(center.x + w / 2, center.y + h / 2, center.z + -z);
	m->vertices[5] = dvec3(center.x + w / 2, center.y - h / 2, center.z + -z);
	m->vertices[6] = dvec3(center.x + -w / 2, center.y + h / 2, center.z + -z);
	m->vertices[7] = dvec3(center.x + -w / 2, center.y - h / 2, center.z + -z);
	m->vertices[8] = m->vertices[0];
	m->vertices[9] = m->vertices[1];

	for (int i = 0; i < m->numVertices; i++){
		m->colors[i] = dvec4((GLdouble)rand() / (RAND_MAX), (GLdouble)rand() / (RAND_MAX), (GLdouble)rand() / (RAND_MAX), 0.9);
	}
	return m;
}
//-------------------------------------------------------------------------