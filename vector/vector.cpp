#include "vector.h"

Vector::Vector()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector::Vector(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

//Addition
Vector Vector::operator+ (Vector p)
{
	Vector temp;
	temp.x=x+p.x;
	temp.y=y+p.y;
	temp.z=z+p.z;
	return temp;
}

//Subtraction
Vector Vector::operator- (Vector p)
{
	Vector temp;
	temp.x=x-p.x;
	temp.y=y-p.y;
	temp.z=z-p.z;
	return temp;
}

//Cross product
Vector Vector::operator% (Vector p)
{
	Vector temp;
	temp.x=(y*p.z)-(z*p.y);
	temp.y=(z*p.x)-(x*p.z);
	temp.z=(x*p.y)-(y*p.x);
	return temp;
}

//Dot product
double Vector::operator* (Vector p)
{
	return x*p.x+y*p.y+z*p.z;
}

//Scalar Multiplication
Vector Vector::operator* (double s)
{
	Vector temp;
	temp.x=x*s;
	temp.y=y*s;
	temp.z=z*s;
	return temp;
}

//Division by a Scalar
Vector Vector::operator/ (double s)
{
	Vector temp;
	temp.x=x/s;
	temp.y=y/s;
	temp.z=z/s;
	return temp;
}

//Assignment
void Vector::operator= (Vector p)
{
	x=p.x;
	y=p.y;
	z=p.z;
}

void Vector::operator= (FVector p)
{
	x=p.x;
	y=p.y;
	z=p.z;
}

//Addition and Assignment
void Vector::operator+= (Vector p)
{
	x=x+p.x;
	y=y+p.y;
	z=z+p.z;
}

//Subtraction and Assignment
void Vector::operator-= (Vector p)
{
	x=x-p.x;
	y=y-p.y;
	z=z-p.z;
}

//Multiplication by scalar and Assignment
void Vector::operator*= (double s)
{
	x=x*s;
	y=y*s;
	z=z*s;
}

//Division by scalar and Assignment
void Vector::operator/= (double s)
{
	x=x/s;
	y=y/s;
	z=z/s;
}

//Return normalized vector
Vector Vector::normalize()
{
	Vector v;
	double m = magnitude();
	if(m==0) return *this;
	v.x=x/m;
	v.y=y/m;
	v.z=z/m;
	return v;

}

//Set vector to the normal of 3 other vectors
void Vector::calcNormal(Vector v1, Vector v2, Vector v3)
{
	//Temporary storage vectors
	Vector a, b, result;

	//Calculate cross product using 3 of the vectors
	a.x = v1.x - v2.x;
	a.y = v1.y - v2.y;
	a.z = v1.z - v2.z;
	b.x = v1.x - v3.x;
	b.y = v1.y - v3.y;
	b.z = v1.z - v3.z;
	result.x = a.y * b.z - b.y * a.z;
	result.y = b.x * a.z - a.x * b.z;
	result.z = a.x * b.y - b.x * a.y;

	// Normalize
	*this = result.normalize();

}

//angle in degrees
double Vector::angle(Vector p)
{
	double ang = RAD2DEG(acos(((*this)*p)/(this->magnitude()*p.magnitude())));
	//if((p-(*this)).x>=0)ang+=90.0f;
	return ang;
}

//Return the magnitude of the vector
double Vector::magnitude()
{
	//use distance formula
	return sqrt(x*x+y*y+z*z);
}
