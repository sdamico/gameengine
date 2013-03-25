#ifndef FVECTOR_H_
#define FVECTOR_H_

#include "../res.h"

class FVector
{
	public:
	
	//X,Y, and Z coordinates
	float x,y,z;
	
	//Addition
	FVector operator+ (FVector p);
	
	//Subtraction
	FVector operator- (FVector p);
	
	//Scalar Multiplication
	FVector operator* (float s);
	
	//Cross Product
	FVector operator% (FVector p);
	
	//Dot Product
	float operator* (FVector p);  
	
	//Division by a Scalar
	FVector operator/ (float s);
	
	//Assignment
	void operator= (FVector p);
	
	//Addition and Assignment
	void operator+= (FVector p);
	
	//Subtraction and Assignment
	void operator-= (FVector p);
	
	//Multiplication by scalar and Assignment
	void operator*= (float s);
	
	//Division by scalar and Assignment
	void operator/= (float s);
	
	float angle(FVector p);
	
	//Return normalized FVector
	FVector normalize();
	
	//Set FVector to the normal of 3 other vectors
	void calcNormal(FVector v1, FVector v2, FVector v3);
	
	//Return the magnitude of the FVector
	float magnitude();
};

#endif /*FVECTOR_H_*/
