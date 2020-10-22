/*
Castelo Medieval 
Feito por : 
Constantino Raptis nº21702363
Rafael Reto nº21702113
Rui Prata nº21703781
Docente: 
João Nuno Correia
*/

#include <cmath>
#include <math.h>
#include <iostream>

#ifdef __APPLE__
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "getbmp.h"


#define PI 3.14159265

#define INICIOX -5
#define INICIOY -0.5


using namespace std;
int X = 0;
int Y = 0;
int z = 0;
static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0;
static int numVertices = 500;

static int eyeX = 0;
static int eyeY = 2;
static int eyeZ = 3;
static int centerX = 0;
static int centerY = 0;
static int centerZ = 0;
static int upX = 0;
static int upY = 2;
static int upZ = 0;

static int DoorSpinAngle;
static int DoorTranslacao = 0;
static int balaZ = 0;
static int balaY = 0;
static int altura = -1;

static double xSol = INICIOX;
static double ySol = INICIOY;



static unsigned int texture[20]; // Array of texture indices.
static unsigned char sky[64][64][3]; // Storage for sky image.

void loadExternalTextures() {

	BitMapFile* image[20];

	// Load the textures.
	image[0] = getbmp("Textures/castelo.bmp");

	image[1] = getbmp("Textures/grey.bmp");

	image[2] = getbmp("Textures/portaCastelo.bmp");

	image[3] = getbmp("Textures/stark.bmp");

	image[4] = getbmp("Textures/water.bmp");

	image[5] = getbmp("Textures/grey.bmp");

	image[6] = getbmp("Textures/canhao.bmp");

	image[7] = getbmp("Textures/ponte.bmp"); //Não se usou

	image[8] = getbmp("Textures/cobertura.bmp");

	image[9] = getbmp("Textures/sky.bmp");

	image[10] = getbmp("Textures/montanhas.bmp"); //Não se usou

	image[11] = getbmp("Textures/grass.bmp");

	image[12] = getbmp("Textures/lava.bmp");

	image[13] = getbmp("Textures/dirt.bmp");


	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->sizeX, image[0]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[0]->data);

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[1]->sizeX, image[1]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[1]->data);

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[2]->sizeX, image[2]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[2]->data);

	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[3]->sizeX, image[3]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[3]->data);

	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[4]->sizeX, image[4]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[4]->data);

	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[5]->sizeX, image[5]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[5]->data);

	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[6]->sizeX, image[6]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[6]->data);

	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[7]->sizeX, image[7]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[7]->data);

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[8]->sizeX, image[8]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[8]->data);

	glBindTexture(GL_TEXTURE_2D, texture[9]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[9]->sizeX, image[9]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[9]->data);

	glBindTexture(GL_TEXTURE_2D, texture[10]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[10]->sizeX, image[10]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[10]->data);


	glBindTexture(GL_TEXTURE_2D, texture[11]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[11]->sizeX, image[11]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[11]->data);

	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[12]->sizeX, image[12]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[12]->data);

	glBindTexture(GL_TEXTURE_2D, texture[13]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[13]->sizeX, image[13]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[13]->data);

}

void loadProcedualTextures() {
	// Activate texture index texture[1].
	glBindTexture(GL_TEXTURE_2D, texture[1]);

	// Set texture parameters for wrapping.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Set texture parameters for filtering.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Specify an image as the texture to be bound with the currently active texture index.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, sky);
}



void piramide() {
	glBegin(GL_TRIANGLE_FAN);
	//vertice topo
	glVertex3f(0.5, 1.0, -0.5);


	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);

	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, -1.0);

	glVertex3f(1.0, 0.0, -1.0);
	glVertex3f(0.0, 0.0, -1.0);

	glVertex3f(0.0, 0.0, -1.0);
	glVertex3f(0.0, 0.0, 0.0);


	glEnd();

}
void cuboCeu() {
	//quadrado 100x100
	glBindTexture(GL_TEXTURE_2D, texture[9]);   //cima
	glBegin(GL_POLYGON);
	glTexCoord2f(1, 1); glVertex3f(0.0, 1.0, 0.0);  //V2
	glTexCoord2f(1, 0); glVertex3f(0.0, 1.0, 1.0);   //V1
	glTexCoord2f(0, 0); glVertex3f(1, 1.0, 1.0);   //V3
	glTexCoord2f(0, 1); glVertex3f(1, 1.0, 0.0);   //V4
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[9]); //direita
	glBegin(GL_POLYGON);
	glTexCoord2f(1, 1); glVertex3f(1, 0.0, 0.0);   //V4
	glTexCoord2f(1, 0); glVertex3f(1, 1, 0.0);   //V3
	glTexCoord2f(0, 0); glVertex3f(1, 1, 1);   //V5
	glTexCoord2f(0, 1); glVertex3f(1, 0.0, 1);   //V6
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[11]); //chao
	glBegin(GL_POLYGON);
	glTexCoord2f(1, 1); glVertex3f(0, 0, 1.0);   //V3
	glTexCoord2f(1, 0); glVertex3f(0, 0, 0);   //V5
	glTexCoord2f(0, 0); glVertex3f(1.0, 0, 0);   //V7
	glTexCoord2f(0, 1); glVertex3f(1.0, 0, 1.0);   //V1
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[9]); //frente
	glBegin(GL_POLYGON);
	glTexCoord2f(1, 1); glVertex3f(0.0, 1.0, 1.0);   //V2
	glTexCoord2f(1, 0); glVertex3f(0.0, 0.0, 1.0);   //V8
	glTexCoord2f(0, 0); glVertex3f(1.0, 0.0, 1.0);   //V7
	glTexCoord2f(0, 1); glVertex3f(1.0, 1.0, 1.0);   //V1
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[9]); //esquerda
	glBegin(GL_POLYGON);
	glTexCoord2f(1, 0); glVertex3f(0.0, 0.0, 1.0);   //V8
	glTexCoord2f(1, 1); glVertex3f(0.0, 1.0, 1.0);   //V6
	glTexCoord2f(0, 0); glVertex3f(0.0, 1.0, 0.0);   //V5
	glTexCoord2f(0, 1); glVertex3f(0.0, 0.0, 0.0);   //V7
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[9]); //tras 
	glBegin(GL_POLYGON);
	glTexCoord2f(1, 1); glVertex3f(1.0, 0.0, 0.0);   //V8
	glTexCoord2f(1, 0); glVertex3f(0.0, 0.0, 0.0);   //V2
	glTexCoord2f(0, 0); glVertex3f(0.0, 1.0, 0.0);   //V4
	glTexCoord2f(0, 1); glVertex3f(1.0, 1.0, 0.0);   //V6
	glEnd();
}
void cubo() {
	//quadrado 100x100
	glBegin(GL_POLYGON);
	//primeira face
	glTexCoord2f(1, 1); glVertex3f(0.0, 1.0, 0.0);  //V2
	glTexCoord2f(1, 0); glVertex3f(0.0, 1.0, 1.0);   //V1
	glTexCoord2f(0, 0); glVertex3f(1, 1.0, 1.0);   //V3
	glTexCoord2f(0, 1); glVertex3f(1, 1.0, 0.0);   //V4
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(1, 1); glVertex3f(1, 0.0, 0.0);   //V4
	glTexCoord2f(1, 0); glVertex3f(1, 1, 0.0);   //V3
	glTexCoord2f(0, 0); glVertex3f(1, 1, 1);   //V5
	glTexCoord2f(0, 1); glVertex3f(1, 0.0, 1);   //V6
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(1, 1); glVertex3f(0, 0, 1.0);   //V3
	glTexCoord2f(1, 0); glVertex3f(0, 0, 0);   //V5
	glTexCoord2f(0, 0); glVertex3f(1.0, 0, 0);   //V7
	glTexCoord2f(0, 1); glVertex3f(1.0, 0, 1.0);   //V1
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(1, 1); glVertex3f(0.0, 1.0, 1.0);   //V2
	glTexCoord2f(1, 0); glVertex3f(0.0, 0.0, 1.0);   //V8
	glTexCoord2f(0, 0); glVertex3f(1.0, 0.0, 1.0);   //V7
	glTexCoord2f(0, 1); glVertex3f(1.0, 1.0, 1.0);   //V1
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(1, 1); glVertex3f(0.0, 0.0, 1.0);   //V8
	glTexCoord2f(1, 0); glVertex3f(0.0, 1.0, 1.0);   //V6
	glTexCoord2f(0, 0); glVertex3f(0.0, 1.0, 0.0);   //V5
	glTexCoord2f(0, 1); glVertex3f(0.0, 0.0, 0.0);   //V7
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(1, 1); glVertex3f(1.0, 0.0, 0.0);   //V8
	glTexCoord2f(1, 0); glVertex3f(0.0, 0.0, 0.0);   //V2
	glTexCoord2f(0, 0); glVertex3f(0.0, 1.0, 0.0);   //V4
	glTexCoord2f(0, 1); glVertex3f(1.0, 1.0, 0.0);   //V6
	glEnd();
}
void circulo(float R) {
	double t = 0;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < numVertices; ++i)
	{
		glVertex3f(X + R * cos(t), Y + R * sin(t), 0.0);
		t += 2 * PI / numVertices;
	}
	glEnd();

}
void porta() {

	glPushMatrix();
	glRotated(DoorSpinAngle, 1, 0, 0);
	glTranslated(0.5, 0 + DoorTranslacao, 0.04);
	glScaled(0.2, 0.4, .04);
	cubo();
	glPopMatrix();


}
void rio() {
	glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, 1.5);   //V8
	glVertex3f(0.0, 0.0, 0.0);   //V2
	glVertex3f(1.5, 0.0, 0.0);   //V4
	glVertex3f(1.5, 0.0, 1.5);   //V6
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}
void quadrado() {
	glBegin(GL_QUADS);
	//primeira face
	glVertex3f(0.0, 0.0, 0.0);   //V2
	glVertex3f(0.0, 1.0, 0.0);   //V1
	glVertex3f(1.0, 1.0, 0.0);   //V3
	glVertex3f(1.0, 0.0, 0.0);   //V4
	glEnd();
}
void piramideEmCimaDaTorre() {
	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glPushMatrix();
	glScaled(0.05, 0.4, 0.05);
	glTranslated(0, 0, 0.55);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glPushMatrix();
	glScaled(0.050, 0.09, 0.03);
	glTranslated(0, 4.5, 2);
	piramide();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
}
void coberturaFrenteMuralha() {
	glPushMatrix();
	glTranslated(0, 0, 0.01);

	glPushMatrix();
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.05, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.1, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.15, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.2, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.25, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.3, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.35, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.4, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	//adicionar porta



	glPushMatrix();
	glTranslated(0.75, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.8, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.85, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.90, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.95, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.05, 0, 0);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPopMatrix();
}
void coberturaEsquerdaMuralha() {
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(0, 0, 0.56);

	glPushMatrix();
	glTranslated(0, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.05, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.1, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.15, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.20, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.25, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.30, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.35, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.40, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.45, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.50, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.55, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.6, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.65, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.7, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.75, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.80, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.85, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.90, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.95, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPopMatrix();

}
void coberturaPortaMuralha() {
	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.2);
	glTranslated(1.5, 4, -0.3);
	cubo();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glPushMatrix();//cima esquerda
	glScaled(0.05, 0.1, 0.05);
	glTranslated(9.02, 5, -1.2);
	cubo();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glPushMatrix();//meio tras
	glScaled(0.05, 0.1, 0.05);
	glTranslated(11.5, 5, -1.2);
	cubo();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glPushMatrix();//cima direita
	glScaled(0.05, 0.1, 0.05);
	glTranslated(14, 5, -1.2);
	cubo();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glPushMatrix(); //baixo direita
	glScaled(0.05, 0.1, 0.05);
	glTranslated(14, 5, 1.9);
	cubo();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glPushMatrix(); //meio frente
	glScaled(0.05, 0.1, 0.05);
	glTranslated(11.5, 5, 1.9);
	cubo();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glPushMatrix();//baixo esquerda
	glScaled(0.05, 0.1, 0.05);
	glTranslated(9.02, 5, 1.9);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
}
void coberturaTrasMuralha() {

	glPushMatrix();
	glTranslated(0, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.05, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.1, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.15, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.20, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.25, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.30, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.35, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.40, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.45, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.50, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.55, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.6, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.65, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.7, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.75, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.80, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.85, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.90, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.95, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.05, 0, -1.17);
	piramideEmCimaDaTorre();
	glPopMatrix();

}
void coberturaDireitaMuralha() {
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(0, 0, 1.85);

	glPushMatrix();
	glTranslated(0, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.05, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.1, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.15, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.20, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.25, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.30, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.35, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.40, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.45, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.50, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.55, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.6, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.65, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.7, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.75, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.80, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.85, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.90, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.95, 0, -0.73);
	piramideEmCimaDaTorre();
	glPopMatrix();

	glPopMatrix();
}
void torre() {
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	//esquerda cima
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glScaled(0.3, 0.1, 0.3);
	glTranslatef(0, 10.0, 0);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	//esquerda baixo
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glScaled(0.3, 0.1, 0.3);
	glTranslatef(2.3, 10, 0);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	//direita cima
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glScaled(0.3, 0.1, 0.3);
	glTranslatef(0, 10, 2.3);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	//direita baixo
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glScaled(0.3, 0.1, 0.3);
	glTranslatef(2.3, 10, 2.3);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

}
void torresPequenasMeio(float raio, float altura) {
	GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;


	glPushMatrix();
	glTranslated(0, 0.5, -3);
	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = raio * cos(angle);
		y = raio * sin(angle);
		glVertex3f(x, y, altura);
		glVertex3f(x, y, 0.0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(raio, 0.0, altura);
	glVertex3f(raio, 0.0, 0.0);
	glEnd();


	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = raio * cos(angle);
		y = raio * sin(angle);
		glVertex3f(x, y, altura);
		angle = angle + angle_stepsize;
	}
	glVertex3f(raio, 0.0, altura);
	glEnd();
	glPopMatrix();

}
void torreMeio(float raio, float altura) {
	GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;


	/*glPushMatrix();
	cubo();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0.5, 1);
	glScaled(1.50, 1.50, 1.50);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; ++i) {
	glVertex2d(sin(i / 6.0 * 2 * PI), cos(i / 6.0 * 2 * PI));
	}
	glEnd();
	glPopMatrix();*/


	glPushMatrix();
	glTranslated(0, 0.5, -3);
	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = raio * cos(angle);
		y = raio * sin(angle);
		glVertex3f(x, y, altura);
		glVertex3f(x, y, 0.0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(raio, 0.0, altura);
	glVertex3f(raio, 0.0, 0.0);
	glEnd();


	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = raio * cos(angle);
		y = raio * sin(angle);
		glVertex3f(x, y, altura);
		angle = angle + angle_stepsize;
	}
	glVertex3f(raio, 0.0, altura);
	glEnd();
	glPopMatrix();


}
void torresMeio() {
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslated(0.3, 0.2, -0.4);
	glScaled(0.1, 0.2, 0.1);
	glRotated(90, 1, 0, 0);
	torreMeio(1, 4);
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);


	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslated(0.45, 0.7, -0.4);
	glScaled(0.1, 0.1, 0.1);
	glRotated(90, 1, 0, 0);
	torreMeio(0.5, 4);
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

}
void torresMeioFrente() {
	glPushMatrix();

	glTranslated(-0.16, 0, 0);

	torresMeio();
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glScaled(0.4, 0.1, 0.05);
	glTranslated(1.2, 6.7, -7.5);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glPushMatrix();
	glRotated(180, 0, 1, 0);
	glTranslated(-1.3, 0, 0.7);
	torresMeio();
	glPopMatrix();
	glPopMatrix();
}
void torresMeioAtras() {
	glPushMatrix();

	glTranslated(-0.16, 0, -0.5);
	torresMeio();

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glScaled(0.4, 0.1, 0.05);
	glTranslated(1.2, 6.7, -7.5);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glPushMatrix();
	glRotated(180, 0, 1, 0);
	glTranslated(-1.3, 0, 0.7);
	torresMeio();
	glPopMatrix();

	glPopMatrix();


}
void teto() {
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glScalef(0.7, 0.1, -0.8);
	glTranslated(0.2, 10, 0.25);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	//Pontes entre TORRES MEIO
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glScaled(0.4, 0.1, 0.05);
	glTranslated(1, 6.7, 5.2);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glScaled(0.4, 0.1, 0.05);
	glTranslated(1, 6.7, 13.5);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
}
void bordaCastelo() {
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glPushMatrix();
	glTranslated(-0.25, 0, -1.28);
	rio();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
}
void bordaRio() {
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glPushMatrix();
	glTranslated(-0.5, 0, -1.5);
	glBegin(GL_QUADS);
	glVertex3f(0.0, -0.01, 2.0);   //V8
	glVertex3f(0.0, -0.01, 0.0);   //V2
	glVertex3f(2.0, -0.01, 0.0);   //V4
	glVertex3f(2.0, -0.01, 2.0);   //V6
	glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
}
void canhao() {
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glPushMatrix();

	glTranslatef(0, 0, 0.7);

	glPushMatrix(); //CANHAO
	glRotated(-40, 1, 0, 0);
	glTranslated(0.3, 0.95, 3);
	torreMeio(0.01, 0.1);
	glPopMatrix();

	glPushMatrix(); //BANDEIRA
	glRotated(-40, 1, 0, 0);
	glTranslated(0.5, 0.95, 3);
	torreMeio(0.01, 0.1);
	glPopMatrix();

	glPushMatrix(); //BANDEIRA MEIO
	glRotated(-40, 1, 0, 0);
	glTranslated(0.5, 0.95, 3.1);
	torreMeio(0.005, 0.1);
	glPopMatrix();

	glPushMatrix(); //BANDEIRA FINO
	glRotated(-40, 1, 0, 0);
	glTranslated(0.5, 0.95, 3.2);
	torreMeio(0.002, 0.1);
	glPopMatrix();

	glPushMatrix(); // CANHAO
	glRotated(-40, 1, 0, 0);
	glTranslated(0.7, 0.95, 3);
	torreMeio(0.01, 0.1);
	glPopMatrix();

	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
}
void coberturaFrenteCanhao() {
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO FRENTE	
	glScaled(0.05, 0.1, 0.05);
	glTranslated(2.8, 11, -5);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO FRENTE
	glScaled(0.05, 0.1, 0.05);
	glTranslated(7.5, 11, -5);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO FRENTE	
	glScaled(0.05, 0.1, 0.05);
	glTranslated(12, 11, -5);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO FRENTE
	glScaled(0.05, 0.1, 0.05);
	glTranslated(15.8, 11, -5);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

}
void coberturaDireitoCanhao() {
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO LADO DIREITO
	glScaled(0.05, 0.1, 0.05);
	glTranslated(15.8, 11, -8);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO LADO DIREITO
	glScaled(0.05, 0.1, 0.05);
	glTranslated(15.8, 11, -12);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO LADO DIREITO
	glScaled(0.05, 0.1, 0.05);
	glTranslated(15.8, 11, -16);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO LADO DIREITO
	glScaled(0.05, 0.1, 0.05);
	glTranslated(15.8, 11, -20);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
}
void coberturaEsquerdaCanhao() {
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO LADO ESQUERDO
	glScaled(0.05, 0.1, 0.05);
	glTranslated(2.8, 11, -8);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO LADO ESQUERDO
	glScaled(0.05, 0.1, 0.05);
	glTranslated(2.8, 11, -12);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO LADO ESQUERDO
	glScaled(0.05, 0.1, 0.05);
	glTranslated(2.8, 11, -16);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO LADO ESQUERDO
	glScaled(0.05, 0.1, 0.05);
	glTranslated(2.8, 11, -20);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
}

void solLua() {
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glTranslated(xSol, ySol, 0);
	glutSolidSphere(0.20, 10, 2); //sol
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

}

void coberturaTrasCanhao() {
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO TRAS
	glScaled(0.05, 0.1, 0.05);
	glTranslated(7.5, 11, -20);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();//COBERTURA PISO CANHAO TRAS
	glScaled(0.05, 0.1, 0.05);
	glTranslated(12, 11, -20);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
}
void estandarte() {
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glPushMatrix();//ESTANDARTE
	glTranslated(0.45, 0.9, 0);
	glScaled(0.1, 0.4, 0);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
}

void arvore() {

	glPushMatrix(); //ARVORE ESQUERDA FRENTE 1 1 X
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glPushMatrix(); //ARVORE TRONCO
	glRotated(90, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1,0.1,2.5);
	torreMeio(0.02, 0.6);
	glPopMatrix();

	glPushMatrix(); //ARVORE 1º RAMIFICAÇÃO
	glRotated(40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 3.1);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glPushMatrix(); //ARVORE 2º RAMIFICAÇÃO
	glRotated(-40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, -0.7 ,3.6);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix(); //ESQUERDA FRENTE X 1 1
	glTranslatef(-1, 0, 0);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glPushMatrix(); //ARVORE TRONCO
	glRotated(90, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 2.5);
	torreMeio(0.02, 0.6);
	glPopMatrix();

	glPushMatrix(); //ARVORE 1º RAMIFICAÇÃO
	glRotated(40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 3.1);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glPushMatrix(); //ARVORE 2º RAMIFICAÇÃO
	glRotated(-40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, -0.7, 3.6);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix(); //DIREITA FRENTE X 1 1
	glTranslatef(4, 0, 0);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glPushMatrix(); //ARVORE TRONCO
	glRotated(90, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 2.5);
	torreMeio(0.02, 0.6);
	glPopMatrix();

	glPushMatrix(); //ARVORE 1º RAMIFICAÇÃO
	glRotated(40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 3.1);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glPushMatrix(); //ARVORE 2º RAMIFICAÇÃO
	glRotated(-40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, -0.7, 3.6);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix(); //ESQUERDA FRENTE 1 X 1
	glTranslatef(-0.5, 0, 0.5);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glPushMatrix(); //ARVORE TRONCO
	glRotated(90, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 2.5);
	torreMeio(0.02, 0.6);
	glPopMatrix();

	glPushMatrix(); //ARVORE 1º RAMIFICAÇÃO
	glRotated(40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 3.1);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glPushMatrix(); //ARVORE 2º RAMIFICAÇÃO
	glRotated(-40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, -0.7, 3.6);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix(); //ESQUERDA FRENTE 1 X 1
	glTranslatef(3, 0, 0.5);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glPushMatrix(); //ARVORE TRONCO
	glRotated(90, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 2.5);
	torreMeio(0.02, 0.6);
	glPopMatrix();

	glPushMatrix(); //ARVORE 1º RAMIFICAÇÃO
	glRotated(40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 3.1);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glPushMatrix(); //ARVORE 2º RAMIFICAÇÃO
	glRotated(-40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, -0.7, 3.6);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix(); //ESQUERDA MEIO 1 X 1
	glTranslatef(-0.5, 0,-1);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glPushMatrix(); //ARVORE TRONCO
	glRotated(90, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 2.5);
	torreMeio(0.02, 0.6);
	glPopMatrix();

	glPushMatrix(); //ARVORE 1º RAMIFICAÇÃO
	glRotated(40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 3.1);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glPushMatrix(); //ARVORE 2º RAMIFICAÇÃO
	glRotated(-40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, -0.7, 3.6);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix(); //ESQUERDA MEIO X 1 1
	glTranslatef(4, 0, -1.5);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glPushMatrix(); //ARVORE TRONCO
	glRotated(90, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 2.5);
	torreMeio(0.02, 0.6);
	glPopMatrix();

	glPushMatrix(); //ARVORE 1º RAMIFICAÇÃO
	glRotated(40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 3.1);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glPushMatrix(); //ARVORE 2º RAMIFICAÇÃO
	glRotated(-40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, -0.7, 3.6);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix(); //ESQUERDA MEIO 1 X 1
	glTranslatef(4, 0, -2.5);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glPushMatrix(); //ARVORE TRONCO
	glRotated(90, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 2.5);
	torreMeio(0.02, 0.6);
	glPopMatrix();

	glPushMatrix(); //ARVORE 1º RAMIFICAÇÃO
	glRotated(40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 3.1);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glPushMatrix(); //ARVORE 2º RAMIFICAÇÃO
	glRotated(-40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, -0.7, 3.6);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix(); //ESQUERDA MEIO 1 X 1
	glTranslatef(2, 0, -2.5);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glPushMatrix(); //ARVORE TRONCO
	glRotated(90, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 2.5);
	torreMeio(0.02, 0.6);
	glPopMatrix();

	glPushMatrix(); //ARVORE 1º RAMIFICAÇÃO
	glRotated(40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 3.1);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glPushMatrix(); //ARVORE 2º RAMIFICAÇÃO
	glRotated(-40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, -0.7, 3.6);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix(); //MEIO TRAS 1 X 1
	glTranslatef(4, 0, -2.5);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glPushMatrix(); //ARVORE TRONCO
	glRotated(90, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 2.5);
	torreMeio(0.02, 0.6);
	glPopMatrix();

	glPushMatrix(); //ARVORE 1º RAMIFICAÇÃO
	glRotated(40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 3.1);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glPushMatrix(); //ARVORE 2º RAMIFICAÇÃO
	glRotated(-40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, -0.7, 3.6);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix(); //MEIO TRAS 1 X 1
	glTranslatef(0.8, 0, -3);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glPushMatrix(); //ARVORE TRONCO
	glRotated(90, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 2.5);
	torreMeio(0.02, 0.6);
	glPopMatrix();

	glPushMatrix(); //ARVORE 1º RAMIFICAÇÃO
	glRotated(40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, 0.1, 3.1);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glPushMatrix(); //ARVORE 2º RAMIFICAÇÃO
	glRotated(-40, 1, 0, 0);
	glColor3f(1, 0, 1);
	glTranslated(-1, -0.7, 3.6);
	torreMeio(0.01, 0.2);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);


	glPopMatrix();
	

}

void caminho() {
	glBindTexture(GL_TEXTURE_2D, texture[13]);
	glPushMatrix();
	glTranslatef(0.5, 0, 0.5);
	glRotated(90, 1, 0, 0);
	glScaled(0.20, 1.0, 0);
	cubo();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.5, 0, 1.70);
	glRotated(90, 0, 1, 0);
	glRotated(90, 1, 0, 0);
	glScaled(0.20, 2, 0);
	cubo();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.5, 0, 1.50);
	glRotated(-90, 0, 1, 0);
	glRotated(90, 1, 0, 0);
	glScaled(0.20, 2, 0);
	cubo();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
}

void balas() {
	//esquerda
	glPushMatrix();
	glColor3f(1, 1, 1);
	altura = 22.5 - balaY;
	glScaled(0.05, 0.05, 0.05);
	glTranslated(6.007, 22.5 - balaY, -4 + balaZ);
	glutWireSphere(0.1, 50, 20);
	glPopMatrix();

	//direita
	glPushMatrix();
	glColor3f(1, 1, 1);
	altura = 22.5 - balaY;
	glScaled(0.05, 0.05, 0.05);
	glTranslated(14, 22.5 - balaY, -4 + balaZ);
	glutWireSphere(0.1, 50, 20);
	glPopMatrix();
}
void top_menu(int id) {
	if (id == 1) exit(0);
}
void mode_menu(int id) {

	if (id == 5) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	if (id == 4) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glutPostRedisplay();
}
void perspetive_menu(int id) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(100, 1, 1.0, 250.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//cima
	if (id == 1) {
		Xangle = 0.0;
		Yangle = 0.0;
		Zangle = 0.0;
		//gluLookAt(0, 0, 3, 0, 0, 0, 0, 50, 0);
		eyeX = 0;
		eyeY = 3;
		eyeZ = 0;
		centerX = 0;
		centerY = 0;
		centerZ = 0;
		upX = 0;
		upY = 0;
		upZ = -1;

	}
	//direita
	if (id == 2) {
		Xangle = 0.0;
		Yangle = 0.0;
		Zangle = 0.0;
		eyeX = 3;
		eyeY = 2;
		eyeZ = -0.5;
		centerX = 0;
		centerY = 0;
		centerZ = 0;
		upX = 0;
		upY = 1;
		upZ = 0;
	}
	//esquerda
	if (id == 3) {
		Xangle = 0.0;
		Yangle = 0.0;
		Zangle = 0.0;
		eyeX = -3;
		eyeY = 2;
		eyeZ = -0.5;
		centerX = 0;
		centerY = 0;
		centerZ = 0;
		upX = 0;
		upY = 1;
		upZ = 0;
	}
	//frente
	if (id == 4) {

		Xangle = 0.0;
		Yangle = 0.0;
		Zangle = 0.0;
		eyeX = 0;
		eyeY = 2;
		eyeZ = 3;
		centerX = 0;
		centerY = 0;
		centerZ = 0;
		upX = 0;
		upY = 2;
		upZ = 0;
	}
	//porta
	if (id == 5) {
		Xangle = 0.0;
		Yangle = 0.0;
		Zangle = 0.0;
		eyeX = 1;
		eyeY = 1;
		eyeZ = 1;
		centerX = 0;
		centerY = 0;
		centerZ = 0;
		upX = 0;
		upY = 2;
		upZ = 0;
	}
	glutPostRedisplay();

}
void ortho_menu(int id) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-5, 5, -5, 5, -5,15);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//cima
	if (id == 1) {
		Xangle = 0.0;
		Yangle = 0.0;
		Zangle = 0.0;
		//gluLookAt(0, 0, 3, 0, 0, 0, 0, 50, 0);
		eyeX = 0;
		eyeY = 3;
		eyeZ = 0;
		centerX = 0;
		centerY = 0;
		centerZ = 0;
		upX = 0;
		upY = 0;
		upZ = -1;
	}
	//direita
	if (id == 2) {
		Xangle = 0.0;
		Yangle = 0.0;
		Zangle = 0.0;
		eyeX = 3;
		eyeY = 2;
		eyeZ = -0.5;
		centerX = 0;
		centerY = 0;
		centerZ = 0;
		upX = 0;
		upY = 1;
		upZ = 0;
	}
	//esquerda
	if (id == 3) {
		Xangle = 0.0;
		Yangle = 0.0;
		Zangle = 0.0;
		eyeX = -3;
		eyeY = 2;
		eyeZ = -0.5;
		centerX = 0;
		centerY = 0;
		centerZ = 0;
		upX = 0;
		upY = 1;
		upZ = 0;
	}
	//frente
	if (id == 4) {
		Xangle = 0.0;
		Yangle = 0.0;
		Zangle = 0.0;
		eyeX = 0;
		eyeY = 2;
		eyeZ = 3;
		centerX = 0;
		centerY = 0;
		centerZ = 0;
		upX = 0;
		upY = 2;
		upZ = 0;
	}
	//porta
	if (id == 5) {
		Xangle = 0.0;
		Yangle = 0.0;
		Zangle = 0.0;
		eyeX = 1;
		eyeY = 1;
		eyeZ = 1;
		centerX = 0;
		centerY = 0;
		centerZ = 0;
		upX = 0;
		upY = 2;
		upZ = 0;
	}
	glutPostRedisplay();

}

void drawScene(void) {
	//propriedades material vetor
	float matAmbAndDif1[] = { 0.0,0.0,0.0,1.0 };
	float matAmbAndDif2[] = { 1.0,1.0,1.0,1.0 };
	float matSpec[] = { 1.0, 1.0, 1.0, 1.0 };
	float matShine[] = { 50.0 };

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(eyeX, eyeY, 3, 0, 0, 0, 0, 2, 0);
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpec);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShine);

	glColor3f(0.0, 0.0, 0.0);

	glRotatef(Zangle, 0.0, 0.0, 1.0);
	glRotatef(Yangle, 0.0, 1.0, 0.0);
	glRotatef(Xangle, 1.0, 0.0, 0.0);

	glClearColor(1.0, 1.0, 1.0, 0.0);

	//muralha da frente DIVIDIDA EM 3//
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif2);

	//ceu
	glPushMatrix();
	//glRotated();
	glScaled(100, 100, 100);
	glTranslated(-0.5, -0.0015, -0.6);
	cuboCeu();
	glPopMatrix();

	//Muralha frente lado esquerdo
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glScalef(0.5, 0.4, 0.04);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	//Muralha frente lado direito
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glScalef(0.4, 0.4, 0.04);
	glTranslated(1.75, 0, 0);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	//muralha da esquerda
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glTranslated(-0.09, 0, 0);
	glRotated(90, 0, 1, 0);
	glScalef(1, 0.4, 0.04);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);



	//muralha da direita
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glTranslated(1.11, 0, 0);
	glRotated(90, 0, 1, 0);
	glScalef(1, 0.4, 0.04);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

	//muralha de tras
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
	glTranslated(0, 0, -1.09);
	glScalef(1.1, 0.4, 0.04);
	cubo();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);


	//torre esquerda baixo
	glPushMatrix();
	glTranslated(-0.10, 0, -0.005);
	glScaled(0.1, 0.45, 0.1);
	torre();
	glPopMatrix();

	//torre direita baixo
	glPushMatrix();
	glTranslated(1.1, 0, 0);
	glScaled(0.1, 0.45, 0.1);
	torre();
	glPopMatrix();

	//torre direita cima
	glPushMatrix();
	glTranslated(1.07, 0, -1.1);
	glScaled(0.1, 0.45, 0.1);
	torre();
	glPopMatrix();

	//torre esquerda cima
	glPushMatrix();
	glTranslated(-0.1, 0, -1.1);
	glScaled(0.1, 0.45, 0.1);
	torre();
	glPopMatrix();


	//torre do meio FRENTE
	torresMeioFrente();
	//torre do meio ATRÁS
	torresMeioAtras();

	//EDIFICIO TETO
	teto();

	//borda perto do castelo
	bordaCastelo();

	//borda do rio
	bordaRio();
	//canhao
	canhao();


	coberturaFrenteCanhao();
	coberturaDireitoCanhao();
	coberturaEsquerdaCanhao();
	coberturaTrasCanhao();
	estandarte();
	solLua();
	arvore();
	
	caminho();
	coberturaFrenteMuralha();

	coberturaDireitaMuralha();

	coberturaTrasMuralha();

	coberturaEsquerdaMuralha();

	coberturaPortaMuralha();
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	porta();
	glBindTexture(GL_TEXTURE_2D, 0);
	balas();

	glFlush();

}

void make_menu(void) {

	int sub_menu;
	sub_menu = glutCreateMenu(mode_menu);
	glutAddMenuEntry("FILL", 4);
	glutAddMenuEntry("OUTLINE", 5);

	int sub_menu2;
	sub_menu2 = glutCreateMenu(perspetive_menu);
	glutAddMenuEntry("Cima", 1);
	glutAddMenuEntry("Direita", 2);
	glutAddMenuEntry("Esquerda", 3);
	glutAddMenuEntry("Frente", 4);

	int sub_menu3;
	sub_menu3 = glutCreateMenu(ortho_menu);
	glutAddMenuEntry("Cima", 1);
	glutAddMenuEntry("Direita", 2);
	glutAddMenuEntry("Esquerda", 3);
	glutAddMenuEntry("Frente", 4);

	

	glutCreateMenu(top_menu);
	glutAddSubMenu("Mode", sub_menu);
	glutAddSubMenu("Perspetive", sub_menu2);
	glutAddSubMenu("Ortho", sub_menu3);

	glutAddMenuEntry("Quit", 1);

	// The menu is attached to a mouse button.
	glutAttachMenu(GLUT_RIGHT_BUTTON);



}

void setup(void)
{

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glGenTextures(20, texture);

	//vetores para a luz
	float lightAmb[] = { 1.0, 1.0, 1.0, 1.0 };
	float lightDifAndSpec[] = { 0, 0, 0, 1.0 };
	float lightPos[] = { xSol,ySol, 0, 0 };//fonte de luz direcional
	float globAmb[] = { 1, 1, 1 ,0 };



	loadExternalTextures();
	loadProcedualTextures();


	//propriedades luzes

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glEnable(GL_LIGHT0);//luz individual
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // ambiente global
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);//enable local point view
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE); // Enable two-sided lighting.

	//atenuaçao modelo de phong
	//GL_CONSTANT_ATTENUATION(4);
	//GL_LINEAR_ATTENUATION(4);
	//GL_QUADRATIC_ATTENUATION(4);





	glEnable(GL_TEXTURE_2D);

	// Specify how texture values combine with current surface color values.
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

}


// OpenGL window reshape routine.

// PT: Função que lida com o ajuste à janela de Opengl

void resize(int w, int h)
{

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	//glOrtho(-100.0, 200.0, -100.0, 200.0, -5, 5);
	gluPerspective(100, 1, 1.0, 100.0);

}


// Keyboard input processing routine.

// PT: função que recebe o input do teclado

void keyInput(unsigned char key, int x, int y)
{

	switch (key)

	{

	case 27:

		exit(0);

		break;

	case 'x':

		Xangle += 5.0;

		if (Xangle > 360.0) Xangle -= 360.0;

		glutPostRedisplay();

		break;

	case 'X':

		Xangle -= 5.0;

		if (Xangle < 0.0) Xangle += 360.0;

		glutPostRedisplay();

		break;

	case 'y':

		Yangle += 5.0;

		if (Yangle > 360.0) Yangle -= 360.0;

		glutPostRedisplay();

		break;

	case 'Y':

		Yangle -= 5.0;

		if (Yangle < 0.0) Yangle += 360.0;

		glutPostRedisplay();

		break;

	case 'z':

		Zangle += 5.0;

		if (Zangle > 360.0) Zangle -= 360.0;

		glutPostRedisplay();

		break;

	case 'Z':

		Zangle -= 5.0;

		if (Zangle < 0.0) Zangle += 360.0;

		glutPostRedisplay();

		break;

	case 'b':
		if (altura > 0) {
			balaZ += 1;
			balaY += 1;
			cout << "balaZ=" << balaZ << endl;
			cout << "balaY=" << balaY << endl;
			glutPostRedisplay();
		}
		break;
	case 'B':

		balaZ = 0;
		balaY = 0;
		cout << "angulo=" << DoorSpinAngle << endl;

		glutPostRedisplay();

		break;
	case 'p':
		if (DoorSpinAngle < 75.0) {
			DoorSpinAngle += 2;
			DoorTranslacao += 0.1;
			cout << "angulo=" << DoorSpinAngle << endl;

			glutPostRedisplay();
		}

		break;
	case 'P':
		if (DoorSpinAngle > 0) {
			DoorSpinAngle -= 2;
			DoorTranslacao -= 0.1;
			cout << "angulo=" << DoorSpinAngle << endl;

			glutPostRedisplay();
		}
		break;
	case 's':
		if (xSol <= 0.45) {
			ySol += 0.025;
			xSol += 0.05;
			glutPostRedisplay();

		}
		else if (ySol <= 0 && xSol >= 0.45) {
			ySol = INICIOY;
			xSol = INICIOX;
			glutPostRedisplay();

		}
		else {
			ySol -= 0.025;
			xSol += 0.05;
			glutPostRedisplay();
		}

		break;


	default:

		break;

	}
	cout << "x=" << Xangle << endl;
	cout << "y=" << Yangle << endl;
	cout << "z=" << Zangle << endl;
	cout << " " << endl;
}


//Aparece no terminal ...

void printInteraction(void)
{

	cout << "Interaction:" << endl;

	cout << "Press x, X, y, Y, z, Z to turn the hemisphere." << endl;

}



int main(int argc, char** argv)
{

	printInteraction();

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(100, 100);

	glutCreateWindow("Castelo Medieval.cpp");

	setup();

	glutDisplayFunc(drawScene);

	glutReshapeFunc(resize);

	glutKeyboardFunc(keyInput);

	make_menu();

	glutMainLoop();


	return 0;

}
