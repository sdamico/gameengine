#ifndef RESOURCE_H
#define RESOURCE_H

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#ifdef __linux__
#include <GL/glx.h>
#include <sys/time.h>
#endif

#ifdef win32
#include <windows.h>
#endif

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdarg>
#include <memory>

//Width and height of program
#define swidth 1680
#define sheight 1050

#define PI 3.14159265358979323846f

//Degree to radian conversion macros
#define DEG2RAD(x) (x*PI)/180.0f
#define RAD2DEG(x) (x/PI)*180.0f

//Randomize between 2 values
#define RAND(a,b) b*rand()/(RAND_MAX - a)



/*struct Vertex
{
	float x,y,z;
};*/

//2D Vertex struct
struct Vertex2D
{
	float x,y;
};

struct Vertex3D
{
	float x,y,z;
};

//2D UV texture coordinate struct
struct UVTexCoord
{
	float u,v;
};

//Face struct
struct Face
{
	unsigned short p1,p2,p3;
};

//RGBA struct
struct glRGBA
{
	float r;
	float g;
	float b;
	float a;
};

#endif

