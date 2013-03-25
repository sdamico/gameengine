#include "C3ds.h"

C3ds::C3ds()
{
	fileSize=0;
	data=NULL;
	vertex=NULL;
	normal=NULL;
	texcoord=NULL;
	face=NULL;
	TexCoordUScale=0;
	TexCoordVScale=0;
	shininess=0;
	transparency=0;	
	texSmooth=0;
	color=(glRGBA){0.0f,0.0f,0.0f,0.0f};
	
}

C3ds::C3ds(std::string id, std::string file, std::string shaderProgram, float scale)
{
	fileSize=0;
	data=NULL;
	vertex=NULL;
	normal=NULL;
	texcoord=NULL;
	face=NULL;
	TexCoordUScale=0;
	TexCoordVScale=0;
	shininess=0;
	transparency=0;	
	texSmooth=0;
	color=(glRGBA){0.0f,0.0f,0.0f,0.0f};
	load(id,file,scale);
	shader = shaderProgram;
}

C3ds::~C3ds()
{
	release();
}

bool C3ds::load(std::string id, std::string file, float scale)
{
	this->id=id;
	std::ifstream in;
	ChunkInfo info;
	int Offset,SubChunkSize,Value,MatDex,MeshDex,Loop,LOff;
	short Val;
	float fVal;
	bool CopyVal=false;
	MatDex=-1;
	MeshDex=-1;
	in.open(file.c_str(),std::ios::binary);
	if(in.fail())return false;
	in.seekg(0, std::ios::end);
	fileSize=in.tellg();
	in.seekg(0,std::ios::beg);
	if(data!=NULL)
    	delete data;
 	data=new unsigned char[fileSize];
 	if(data==NULL)
 	{
 		in.close();
 		return false;
 	}
 	in.read((char*)data,fileSize);
 	in.close();
 	
	Offset=0;
	info=getChunkInfo(Offset);
	if(info.ID!=0x4D4D)
		return false;
	if(info.Size!=fileSize)
		return false;
 	countParts(fileSize);
 	std::cout <<"-- 3DS File has "<<nMesh<<" Meshes, only loading first --"<<std::endl;
 	Offset=6;
 	
 	while(Offset<fileSize)
    {
    	info=getChunkInfo(Offset);
 
      	switch(info.ID)
       	{
        	case 0x0002: // Version
          		memcpy(&Value,&data[Offset+6],4);
          		//printf("Chunk 0002 (Version) - %d\nOffset %d\n",Value,info.Size);
          		Offset+=info.Size;
          		break;
 
        	case 0x0011: // RGB1
        		//printf("Chunk 0011 (RGB1) %d %d %d\nOffset %d\n",data[Offset+6],data[Offset+7],data[Offset+8],info.Size);
 
           		if(CopyVal)
            	{
            		color=(glRGBA){data[Offset+6],data[Offset+7],data[Offset+8]};
             		CopyVal=false;
            	}
 				Offset+=info.Size;
          		break;
 
        	case 0x0012: // RGB2
         		//printf("Chunk 0012 (RGB2) %d %d %d\nOffset %d\n",data[Offset+6],data[Offset+7],data[Offset+8],info.Size);
          		Offset+=info.Size;
          		break;
 
 
        	case 0x0030: // Quantity value for parent chunks
          		memcpy(&Val,&data[Offset+6],2);
          		//printf("Chunk 0030 (Qty Value) %d\nOffset %d\n",Val,info.Size);
          		Offset+=info.Size;
          		break;
         
 
        	case 0x0100: // Config (Ignore)
         		//printf("Chunk 0100 (Config)\nOffset %d\n",info.Size);
         		Offset+=info.Size;
        		break;
 
        	case 0x3D3D: // Start of Obj
          		//printf("Chunk 3D3D (Start of Obj)\nOffset %d\n",info.Size);
          		SubChunkSize=info.Size+Offset; // Set end limit for subchunk
          		Offset+=6;
          		break;
		
 
 	       case 0x3D3E: // Editor config (Ignore)
         		//printf("Chunk 3D3E (Editor Config)\nOffset %d\n",info.Size);
         		Offset+=info.Size;
         		break;
 
        	case 0x4000: // Start of Mesh
         		//printf("Chunk 4000 (Start of Mesh) - %s\nOffset %d\n",&data[Offset+6],info.Size);
         		Offset+=6;
          		while(data[Offset]!=0) // Seek end of string
  		        	Offset++;
 
          		Offset++; // One more to move past the NULL
          		MeshDex++;
          		if(MeshDex==1) Offset=fileSize;
         		break;
 
        	case 0x4100: // Mesh data
         		//printf("Chunk 4100 (Mesh Data)\nOffset %d\n",info.Size);
         		Offset+=6;
         		break;
 
        	case 0x4110: // Vertex List
         		memcpy(&Val,&data[Offset+6],2);
         		//printf("Chunk 4110 (Vertex List) %d Vertices\nOffset %d\n",Val,info.Size);
         		numVerts=Val;
         		vertex = new FVector[Val+1];
         		sphereRadius=0;
          		for(Loop=0,LOff=Offset+8;Loop!=Val;++Loop,LOff+=12)
          	 	{
            		memcpy(&(vertex[Loop].x),&data[LOff],4);
            		memcpy(&(vertex[Loop].y),&data[LOff+4],4);
            		memcpy(&(vertex[Loop].z),&data[LOff+8],4);
            		if(vertex[Loop].magnitude()>sphereRadius)sphereRadius=vertex[Loop].magnitude();
           		}
         		Offset+=info.Size;
         		break;
 
        	case 0x4111: // Vertex Options
         		//printf("Chunk 4111 (Vertex Options)\nOffset %d\n",info.Size);
         		Offset+=info.Size;
         		break;
 
        	case 0x4120: // Face List
         		memcpy(&Val,&data[Offset+6],2);
         		//printf("Chunk 4120 (Face List) %d polys\nOffset %d\n",Val,info.Size);
         		numFaces=Val;
         		face = new Face[Val+1];
          		for(Loop=0,LOff=Offset+8;Loop!=Val;++Loop,LOff+=8)
           		{
            		memcpy(&(face[Loop].p1),&data[LOff],2);
            		memcpy(&(face[Loop].p2),&data[LOff+2],2);
            		memcpy(&(face[Loop].p3),&data[LOff+4],2);
           		}
         		Offset+=info.Size;
         		break;
 
        	case 0x4130: // Material Desc
         		Offset+=info.Size;
         		break;
 
        	case 0x4140: // UV Map List
         		memcpy(&Val,&data[Offset+6],2);
         		//printf("Chunk 4120 (UV Map List)\nOffset %d\n",info.Size);
         		numTexCoords=Val;
         		texcoord = new UVTexCoord[Val+1];
          		for(Loop=0,LOff=Offset+8;Loop!=Val;++Loop,LOff+=8)
           		{
            		memcpy(&(texcoord[Loop].u),&data[LOff],4);
            		memcpy(&(texcoord[Loop].v),&data[LOff+4],4);
           		}
        		Offset+=info.Size;
        		break;
 
        	case 0xA000: // Material Name
         		//printf("Chunk A000 (Material Name) - %s\nOffset %d\n",&data[Offset+6],info.Size);
         		//texture=data[Offset+6]; //lstrcpy(Matl[MatDex].Name,(LPSTR)&data[Offset+6]);
         		Offset+=info.Size;
         		break;
 
        	case 0xA010: // Material - Ambient Color
         		//printf("Chunk A010 (Material - Amb Col)\nOffset %d\n",info.Size);
         		//memcpy(&Val,&data[Offset+6],2);
         		ambientColor=(glRGBA){data[Offset+6]/255.0f,data[Offset+7]/255.0f,data[Offset+8]/255.0f,data[Offset+9]/255.0f};
         		Offset+=info.Size;
         		
         		break;
 
        	case 0xA020: // Material - Diffuse Color
         		//printf("Chunk A020 (Material - Dif Col)\nOffset %d\n",info.Size);
         		CopyVal=true;
         		diffuseColor=(glRGBA){data[Offset+6]/255.0f,data[Offset+7]/255.0f,data[Offset+8]/255.0f,data[Offset+9]/255.0f};
         		Offset+=info.Size;
         		//Offset+=6;//Info.Size;
         		break;
 
        	case 0xA030: // Material - Spec Color
         		specColor=(glRGBA){data[Offset+6]/255.0f,data[Offset+7]/255.0f,data[Offset+8]/255.0f,data[Offset+9]/255.0f};
         		
         		Offset+=info.Size;
         		//Offset+=6;//Info.Size;
         		break;
 
        	case 0xA040: // Material - Shininess
         		//printf("Chunk A040 (Material - Shininess)\nOffset %d\n",info.Size);
         		shininess=data[Offset+6];
         		Offset+=6;//Info.Size;
         		break;
 
        	case 0xA041: // Material - Shine Strength
         		//printf("Chunk A041 (Material - Shine Strength)\nOffset %d\n",info.Size);
         		Offset+=6;//Info.Size;
         		break;
 
        	case 0xA050: // Material - Transparency
       			//printf("Chunk A050 (Material - Transparency)\nOffset %d\n",info.Size);
         		transparency=data[Offset+6];
         		
         		Offset+=6;//Info.Size;
         		break;
 
        	case 0xA100: // Material - Type (Flat,Gourad, Phong, Metal)
         		memcpy(&Val,&data[Offset+6],2);
         		//printf("Chunk A100 (Material Type) %d\nOffset %d\n",Val,info.Size);
         		texSmooth=Val;
         		Offset+=info.Size;
         		break;
 
        	case 0xA200: // Material - Start of Texture Info
         		//printf("Chunk A200 (Material Tex Map)\nOffset %d\n",info.Size);
         		Offset+=6;
         		break;
 
        	case 0xA300: // Material - Texture Name
         		//printf("Chunk A300 (Material Tex Map Name) %s\nOffset %d\n",&data[Offset+6],info.Size);
         		
         		texture=(char *)&data[Offset+6];
         		Offset+=info.Size;
         		break;
 
        	case 0xA351: // Material - Texture Options
         		memcpy(&Val,&data[Offset+6],2);
         		//printf("Chunk A351 (Material Tex Options) %d\nOffset %d\n",Val,info.Size);
         		Offset+=info.Size;
         		break;
 
        	case 0xA354: // Material - Texture U Scale
         		memcpy(&fVal,&data[Offset+6],4);
         		//printf("Chunk A354 (Material Tex U Scale) %f\nOffset %d\n",fVal,info.Size);
         		TexCoordUScale=fVal;
         		Offset+=info.Size;
         		break;
 
        	case 0xA356: // Material - Texture V Scale
         		memcpy(&fVal,&data[Offset+6],4);
         		//printf("Chunk A356 (Material Tex V Scale) %f\nOffset %d\n",fVal,info.Size);
         		TexCoordVScale=fVal;
         		Offset+=info.Size;
         		break;
 
        	case 0xA35A: // Material - Texture V Offset
         		memcpy(&fVal,&data[Offset+6],4);
         		//printf("Chunk A35A (Material Tex V Offset) %f\nOffset %d\n",fVal,info.Size);
         		Offset+=info.Size;
         		break;
 
        	case 0xA35C: // Material - Texture V Offset
         		memcpy(&fVal,&data[Offset+6],4);
         		//printf("Chunk A35C (Material Tex Rotation) %f\nOffset %d\n",fVal,info.Size);
         		Offset+=info.Size;
         		break;
 
        	case 0xAFFF: // Material Start
        		//printf("Chunk AFFF (Start of Material)\nOffset %d\n",info.Size);
        		MatDex++;
        		Offset+=6;
        		break;
 
        	default:
        		
        		Offset+=info.Size;
        		break;
		}
		
	}
	std::string path="resources/images/";
	
	if(!TextureMgr::get().load(texture,path+texture))
	{
		std::cerr<<"[Could not load texture '"<<texture<<"', using none]"<<std::endl;
		texture="";
	}
	if(TexCoordUScale<=0.001f || TexCoordVScale<=0.001f){
		TexCoordUScale=1.0f;
		TexCoordVScale=1.0f;
	}
	/*for(int i=0;i<numTexCoords;i++)
	{
		texcoord[i].u*=TexCoordUScale;
		texcoord[i].v*=TexCoordVScale;
	}*/
	calcNormals();
	//drawelements
	buffer=new GLuint[4];
	glGenBuffersARB(4, buffer);
	
	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, buffer[0]);
	glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, ( numFaces )*sizeof(Face), face, GL_STATIC_DRAW_ARB);
	//glEnableClientState(GL_VERTEX_ARRAY);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, buffer[1]);
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, ( numVerts * 3 )*sizeof(float), vertex, GL_STATIC_DRAW_ARB);
	//glEnableClientState(GL_NORMAL_ARRAY);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, buffer[2]);
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, ( numVerts * 3 )*sizeof(float), normal, GL_STATIC_DRAW_ARB);
	if(texcoord){
	//	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glBindBufferARB(GL_ARRAY_BUFFER_ARB, buffer[3]);
		glBufferDataARB(GL_ARRAY_BUFFER_ARB, ( numVerts * 2 )*sizeof(float), texcoord, GL_STATIC_DRAW_ARB);
	}
	
	//replace when models have shininess
	shininess = 128;
	
	this->scale=scale;
	sphereRadius*=(scale*2);
	return true;
}

ChunkInfo C3ds::getChunkInfo(int Offset)
{
	ChunkInfo Chunk;
	memcpy(&Chunk.ID,&data[Offset],2);
	memcpy(&Chunk.Size,&data[Offset+2],4);
	return Chunk;
}

int C3ds::countParts(int DataLen)
{
	long Offset=6;
	ChunkInfo Info;
	nMesh=0,nMatl=0;
	while(Offset<DataLen)
	{
		Info=getChunkInfo(Offset);
		switch(Info.ID)
		{
			case 0x3D3D: // Start of Obj
				Offset+=6;
				break;
			case 0x4000: // Start of Mesh
				nMesh++;
				Offset+=Info.Size;
				break;
			case 0xAFFF: // Start of Material
				nMatl++;
				Offset+=Info.Size;
				break;
			default:
				Offset+=Info.Size;
				break;
		}
	}
	return nMesh;
}
//29 sec with mine
void C3ds::calcNormals()
{
	
	normal=new FVector[numVerts];
	for(int i=0;i<numVerts;i++)
		normal[i]=(FVector){0.0f,0.0f,0.0f};
	fnormal=new FVector[numFaces+1];
	//FVector a;
	for(int i=0;i<numFaces;i++)
	{
		fnormal[i].calcNormal(vertex[face[i].p1],vertex[face[i].p2],vertex[face[i].p3]);
		normal[face[i].p1]+=fnormal[i];
		normal[face[i].p2]+=fnormal[i];
		normal[face[i].p3]+=fnormal[i];
		
	}
	for(int i=0;i<numVerts;i++)
		normal[i].normalize();
	/*
	for(int i=0;i<numFaces;i++)
	{
		
		normal[face[i].p1]=(FVector){0.0f,0.0f,0.0f};
		int c=0;
		for(int ii=0;ii<numFaces;ii++)
		{
			if(face[ii].p1==face[i].p1 || face[ii].p2==face[i].p1 || face[ii].p3==face[i].p1)
			{
				c++;
				normal[face[i].p1]+=fnormal[ii];
			}
		}
		if(c)
		{
			//normal[face[i].p1]/=c;
			normal[face[i].p1].normalize();
		}
		normal[face[i].p2]=(FVector){0.0f,0.0f,0.0f};
		c=0;
		for(int ii=0;ii<numFaces;ii++)
		{
			if(face[ii].p1==face[i].p2 || face[ii].p2==face[i].p2 || face[ii].p3==face[i].p2)
			{
				c++;
				normal[face[i].p2]+=fnormal[ii];
			}
		}
		if(c)
		{
			//normal[face[i].p2]/=c;
			normal[face[i].p2].normalize();
		}
		normal[face[i].p3]=(FVector){0.0f,0.0f,0.0f};
		c=0;
		for(int ii=0;ii<numFaces;ii++)
		{
			if(face[ii].p1==face[i].p3 || face[ii].p2==face[i].p3 || face[ii].p3==face[i].p3)
			{
				c++;
				normal[face[i].p3]+=fnormal[ii];
			}
		}
		if(c)
		{
			//normal[face[i].p2]/=c;
			normal[face[i].p3].normalize();
		}
	}*/
	
}

void C3ds::setShader(std::string program)
{
	shader = program;
}

void C3ds::release()
{
	std::cout<<"[Unloading Model: "<<id<<"]"<<std::endl;
	//glDeleteBuffers(4, buffer);
	//delete buffer;
	if(data)
	{
		
    	delete data;
    	data=NULL;
    }
    if(vertex)
    {
    	
    	delete vertex;
    	vertex=NULL;
    	
    }
    if(normal)
    {
    	
    	delete normal;
    	normal=NULL;
    }
    if(fnormal)
    {
    	
    	delete fnormal;
    	fnormal=NULL;
    }
    if(texcoord)
    {
    	
    	delete texcoord;
    	texcoord=NULL;
    }
    if(face)
    {
    	
    	delete face;
    	face=NULL;
    }
  	
	
}

void C3ds::render()
{
	 
	ShaderMgr::get().useProgram(shader);
	//glVertexPointer(3,GL_FLOAT,0,vertex);
	//glNormalPointer(GL_FLOAT,0,normal);
	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);
	//glDisable(GL_BLEND);
	//glEnable(GL_BLEND);
	glEnable(GL_COLOR_MATERIAL);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	
	glMaterialfv(GL_FRONT,GL_AMBIENT,(float*)(&ambientColor));
	glMaterialfv(GL_FRONT,GL_DIFFUSE,(float*)(&diffuseColor));
	glMaterialfv(GL_FRONT,GL_SPECULAR,(float*)(&specColor));
	
	glMaterialf(GL_FRONT,GL_SHININESS,shininess);
	
	glScalef(scale,scale,scale);
	TextureMgr::get().use(texture);
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB,buffer[1]);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB,buffer[2]);
	glNormalPointer(GL_FLOAT, 0, 0);
	if(numTexCoords==numVerts){
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glBindBufferARB(GL_ARRAY_BUFFER_ARB,buffer[3]);
		glTexCoordPointer(2, GL_FLOAT, 0, 0);
	}
	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, buffer[0]);
	glDrawElements(GL_TRIANGLES, numFaces*3, GL_UNSIGNED_SHORT, 0); 
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	
	/*
	glBegin(GL_TRIANGLES);
	
	for(int i=0;i<numFaces;i++)
	{
		//glNormal3f(fnormal[i].x,fnormal[i].y,fnormal[i].z);
		if(texcoord)glTexCoord2f(texcoord[face[i].p1].u*TexCoordUScale,texcoord[face[i].p1].v*TexCoordVScale);
		glNormal3f(normal[face[i].p1].x,normal[face[i].p1].y,normal[face[i].p1].z);
		glVertex3f(vertex[face[i].p1].x,vertex[face[i].p1].y,vertex[face[i].p1].z);
		if(texcoord)glTexCoord2f(texcoord[face[i].p2].u*TexCoordUScale,texcoord[face[i].p2].v*TexCoordVScale);
		glNormal3f(normal[face[i].p2].x,normal[face[i].p2].y,normal[face[i].p2].z);
		glVertex3f(vertex[face[i].p2].x,vertex[face[i].p2].y,vertex[face[i].p2].z);
		if(texcoord)glTexCoord2f(texcoord[face[i].p3].u*TexCoordUScale,texcoord[face[i].p3].v*TexCoordVScale);
		glNormal3f(normal[face[i].p3].x,normal[face[i].p3].y,normal[face[i].p3].z);
		glVertex3f(vertex[face[i].p3].x,vertex[face[i].p3].y,vertex[face[i].p3].z);
	}
	glEnd();
	*/
	glPopMatrix();
	glDisable(GL_COLOR_MATERIAL);
	ShaderMgr::get().useNone();
	//glEnable(GL_TEXTURE_2D);
}

/*
 * Note - do not use - needs to be fixed
 */
bool C3ds::segInTriangle(FVector p, FVector d, FVector* v)
{
    for(int j=2, i=0; i<3; j=i,i++)
    {
        FVector e = v[i] - v[j];
        FVector h = p - v[j]; 
        FVector f = e%d;
        float  dot = h*f;
        
        if (dot > 0.0f)
        {
            return false;
        }
    }
    FVector a = (v[1]-v[0]);
    FVector b = (v[2]-v[0]);
    FVector segNormal = (a%b).normalize();
    FVector proj = b.normalize();
    proj = a*(proj*proj);
    if(proj.magnitude()>=d.magnitude())
    {
    	std::cout<<proj.magnitude()<<std::endl;
    	return true;
    }
    else return false;
}

/*
 * Note - do not use - needs to be fixed
 */
bool C3ds::intersect(C3ds *other, float scale, float otherScale, FVector separation, Quaternion q1, Quaternion q2)
{
	if(!other) return false;
	
	int within = 0;
	float m1[16];
	q1.createMatrix(m1);
	float m2[16];
	q2.createMatrix(m2);
	
	FVector selfTemp[3];
	FVector selfNormalTemp;
	FVector otherTemp[3];
	FVector otherNormalTemp;
	FVector rotOther[3];
	FVector rot[3];
	
	rotOther[0]=(FVector){m2[0],m2[1],m2[2]};
	rotOther[1]=(FVector){m2[4],m2[5],m2[6]};
	rotOther[2]=(FVector){m2[8],m2[9],m2[10]};
	
	rot[0]=(FVector){m1[0],m1[1],m1[2]};
	rot[1]=(FVector){m1[4],m1[5],m1[6]};
	rot[2]=(FVector){m1[8],m1[9],m1[10]};
	
	FVector u,v,w;
	
	float radius = scale*getSphereRadius();
	float otherRadius = otherScale*other->getSphereRadius();
	
	float t;
	
	for(int i=0;i<other->numFaces;i++)
	{
		within = 0;
		
		otherTemp[0] = (FVector){rotOther[0]*other->vertex[other->face[i].p1]*otherScale,rotOther[1]*other->vertex[other->face[i].p1]*otherScale,rotOther[2]*other->vertex[other->face[i].p1]*otherScale};
		otherTemp[1] = (FVector){rotOther[0]*other->vertex[other->face[i].p2]*otherScale,rotOther[1]*other->vertex[other->face[i].p2]*otherScale,rotOther[2]*other->vertex[other->face[i].p2]*otherScale};
		otherTemp[2] = (FVector){rotOther[0]*other->vertex[other->face[i].p3]*otherScale,rotOther[1]*other->vertex[other->face[i].p3]*otherScale,rotOther[2]*other->vertex[other->face[i].p3]*otherScale};
		if((otherTemp[0]+separation).magnitude()<radius || (otherTemp[1]+separation).magnitude()<radius || (otherTemp[2]+separation).magnitude()<radius)
		{
			u = otherTemp[1]-otherTemp[0];
			v = otherTemp[2]-otherTemp[0];
			w = otherTemp[2]-otherTemp[1];
			otherNormalTemp = (FVector){rotOther[0]*other->fnormal[i],rotOther[1]*other->fnormal[i],rotOther[2]*other->fnormal[i]};
			for(int j=0;j<numFaces;j++)
			{
				selfTemp[0] = (FVector){rot[0]*vertex[face[j].p1]*scale,rot[1]*vertex[face[j].p1]*scale,rot[2]*vertex[face[j].p1]*scale};
				selfTemp[1] = (FVector){rot[0]*vertex[face[j].p2]*scale,rot[1]*vertex[face[j].p2]*scale,rot[2]*vertex[face[j].p2]*scale};
				selfTemp[2] = (FVector){rot[0]*vertex[face[j].p3]*scale,rot[1]*vertex[face[j].p3]*scale,rot[2]*vertex[face[j].p3]*scale};
				
				if(segInTriangle(otherTemp[0],u,selfTemp))
				{
					return true;
				}
				
				if(segInTriangle(otherTemp[0],v,selfTemp))
				{
					return true;
				}
				
				if(segInTriangle(otherTemp[1],w,selfTemp))
				{
					return true;
				}
			}
		}
		
		//if(within==other->numVerts) return true;
	}
	return false;
}

/*
bool C3ds::intersect(C3ds *other, float scale, float otherScale, FVector separation, Quaternion q1, Quaternion q2)
{
	if(!other) return false;
	
	int within = 0;
	float m1[16];
	q1.createMatrix(m1);
	float m2[16];
	q2.createMatrix(m2);
	
	FVector selfTemp;
	FVector selfNormalTemp;
	FVector otherTemp;
	FVector v1,v2,v3;

	int obj1Resolution = 1;
	if(numVerts>130)obj1Resolution=numVerts/80;
	
	int obj2Resolution = 1;
	if(other->numVerts>130)obj2Resolution=other->numVerts/80;
		
	for(int i=0;i<numVerts;i+=obj1Resolution)
	{
		within = 0;
		v1=(FVector){m2[0],m2[1],m2[2]};
		v2=(FVector){m2[4],m2[5],m2[6]};
		v3=(FVector){m2[8],m2[9],m2[10]};
		otherTemp = (FVector){v1*other->vertex[i]*otherScale,v2*other->vertex[i]*otherScale,v3*other->vertex[i]*otherScale};
		for(int j=0;j<other->numVerts;j+=obj2Resolution)
		{
			v1=(FVector){m1[0],m1[1],m1[2]};
			v2=(FVector){m1[4],m1[5],m1[6]};
			v3=(FVector){m1[8],m1[9],m1[10]};
			selfTemp = (FVector){v1*vertex[j]*otherScale,v2*vertex[j]*otherScale,v3*vertex[j]*otherScale};
			selfNormalTemp = (FVector){v1*normal[j],v2*normal[j],v3*normal[j]};
			float d = selfNormalTemp*selfTemp*-1;
			
			//point-plane distance
			float distance = selfNormalTemp*(otherTemp+separation)+d;
			if(distance<0.01f || isnan(distance)){
				within++;
			}
			if(within>other->numVerts/(obj2Resolution*1.5)){
				return true;
			}
		}
		
		//if(within==other->numVerts) return true;
	}
	return false;
}
*/

//Needs to be fixed
FVector C3ds::intersect(FVector x1, FVector x2, float scale, Quaternion q1)
{
	float threshold = sphereRadius*scale/20;
	
	float m1[16];
	q1.createMatrix(m1);
	
	FVector selfTemp;
	FVector curVert;
	FVector v1,v2,v3;
	
	for(int i=0;i<numVerts;i++)
	{
		v1=(FVector){m1[0],m1[1],m1[2]};
		v2=(FVector){m1[4],m1[5],m1[6]};
		v3=(FVector){m1[8],m1[9],m1[10]};
		curVert = vertex[i]*scale;
		selfTemp = (FVector){v1*curVert,v2*curVert,v3*curVert};
		
		//line-point intersection?
		float distance = ((x2-x1)%(x1-selfTemp)).magnitude()/(x2-x1).magnitude();
		if(fabs(distance)<threshold){
			return vertex[i];
		}
	}
	return (FVector){0.0f,0.0f,0.0f};
}
