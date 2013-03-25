#include "FVector.h"

//Addition
FVector FVector::operator+ (FVector p)
{ 
	FVector temp;
	temp.x=x+p.x;
	temp.y=y+p.y;
	temp.z=z+p.z;
	return temp;
}

//Subtraction
FVector FVector::operator- (FVector p)
{
	FVector temp;
	temp.x=x-p.x;
	temp.y=y-p.y;
	temp.z=z-p.z;
	return temp;
}

//Cross product
FVector FVector::operator% (FVector p)
{
	FVector temp;
	temp.x=(y*p.z)-(z*p.y);
	temp.y=(z*p.x)-(x*p.z);
	temp.z=(x*p.y)-(y*p.x);
	return temp;
}

//Dot product
float FVector::operator* (FVector p)
{
	return x*p.x+y*p.y+z*p.z;
}

//Scalar Multiplication
FVector FVector::operator* (float s)
{
	FVector temp;
	temp.x=x*s;
	temp.y=y*s;
	temp.z=z*s;
	return temp;
}

//Division by a Scalar
FVector FVector::operator/ (float s)
{
	FVector temp;
	temp.x=x/s;
	temp.y=y/s;
	temp.z=z/s;
	return temp;
}

//Assignment
void FVector::operator= (FVector p)
{
	x=p.x;
	y=p.y;
	z=p.z;
}

//Assignment
/*void FVector::operator= (Vector p)
{
	x=(float)p.x;
	y=(float)p.y;
	z=(float)p.z;
}*/

//Addition and Assignment
void FVector::operator+= (FVector p)
{
	x=x+p.x;
	y=y+p.y;
	z=z+p.z;
}

//Subtraction and Assignment
void FVector::operator-= (FVector p)
{
	x=x-p.x;
	y=y-p.y;
	z=z-p.z;
}

//Multiplication by scalar and Assignment
void FVector::operator*= (float s)
{
	x=x*s;
	y=y*s;
	z=z*s;
}

//Division by scalar and Assignment
void FVector::operator/= (float s)
{
	x=x/s;
	y=y/s;
	z=z/s;
}

//Return normalized FVector
FVector FVector::normalize()
{
	FVector v;
	float mag = magnitude();
	if(mag==0)return *this;
	v.x=x/mag;
	v.y=y/mag;
	v.z=z/mag;
	return v;

}

//Set FVector to the normal of 3 other vectors
void FVector::calcNormal(FVector v1, FVector v2, FVector v3)
{
	//Temporary storage vectors
	FVector a, b, result;
	
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
float FVector::angle(FVector p)
{
	float ang = RAD2DEG(acos(((*this)*p)/(this->magnitude()*p.magnitude())));
	//if((p-(*this)).x>=0)ang+=90.0f;
	return ang;
}

//Return the magnitude of the FVector
float FVector::magnitude()
{
	//use distance formula
	return sqrt(x*x+y*y+z*z);
}
