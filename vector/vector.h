#ifndef VECTOR_H
#define VECTOR_H

#include "../res.h"
#include "FVector.h"

//Vector class
class Vector
{
	public:

	Vector();

	Vector(double x, double y, double z);

	//X,Y, and Z coordinates
	double x,y,z;

	//Addition
	Vector operator+ (Vector p);

	//Subtraction
	Vector operator- (Vector p);

	//Scalar Multiplication
	Vector operator* (double s);

	//Cross Product
	Vector operator% (Vector p);

	//Dot Product33
	double operator* (Vector p);

	//Division by a Scalar
	Vector operator/ (double s);

	//Assignment
	void operator= (Vector p);

	void operator= (FVector p);

	//Addition and Assignment
	void operator+= (Vector p);

	//Subtraction and Assignment
	void operator-= (Vector p);

	//Multiplication by scalar and Assignment
	void operator*= (double s);

	//Division by scalar and Assignment
	void operator/= (double s);

	double angle(Vector p);

	//Return normalized vector
	Vector normalize();

	//Set vector to the normal of 3 other vectors
	void calcNormal(Vector v1, Vector v2, Vector v3);

	//Return the magnitude of the vector
	double magnitude();
};
#endif

