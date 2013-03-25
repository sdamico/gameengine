#include "RawTriangles.h"

RawTriangles::RawTriangles()
{
}
RawTriangles::RawTriangles(std::string id, std::string file, int vert, float scale)
{
	load(id,file,vert,scale);
}
RawTriangles::~RawTriangles()
{
	release();
}
bool RawTriangles::load(std::string id, std::string file, int vert, float scale)
{
	this->id=id;
	vertex=NULL;
	vertex=new FVector[vert];
	normal=new FVector[vert];
	std::ifstream input(file.c_str());
	for(int i=0;i<vert;i++)
	{
		input >> vertex[i].x;
		input >> vertex[i].y;
		input >> vertex[i].z;
	}
	input.close();
	for(int i=0;i<vert;i++)
	{
		vertex[i]*=scale;
		//cout<<vertex[i].x<<" "<<vertex[i].y<<" "<<vertex[i].z<<endl;
	}
	
	for(int i=0;i<vert;i+=3){
		normal[i].calcNormal(vertex[i],vertex[i+1],vertex[i+2]);
		normal[i].normalize();
	}
	numVerts=vert;
	
	this->scale=scale;
	sphereRadius=scale*6;
	return true;
}
void RawTriangles::release()
{
	delete vertex;
	delete normal;
}
void RawTriangles::render()
{
	
	glVertexPointer(3,GL_FLOAT,0,vertex);
	glNormalPointer(GL_FLOAT,0,normal);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPushMatrix();
	
	glDrawArrays(GL_TRIANGLES, 0, numVerts);
	glPopMatrix();
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
}
