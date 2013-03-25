#include "map.h"

Map::Map()
{
}
void Map::release()
{
	std::cout<<"[Ending Map]"<<std::endl;
	delete grid;
	delete vert;
	delete texcoord;
}
Map::~Map()
{
	release();
}
bool Map::load(std::string filename)
{
	std::cout<<"[Loading Map: "<<filename<<"]"<<std::endl;
	grid=new MapElement[10000];
	columns=100;
	rows=100;
	TextureMgr::get().load("tile","resources/images/maptiles.tga");
	tex=TextureMgr::get().find("tile");
	int p=8;
	for(int i=0;i<rows*columns;i++)
	{
		//if(i%11==3){
			//64 slots, 8 per row, 8 rows total
			if(p<8)
				grid[i].TileStartPos=Vector(((float)p)*(64.0f/512.0f),0.0f,0.0f);
			else{
				int pr=8-p/((int)8);
				int pc=p-pr*8;
				grid[i].TileStartPos=Vector(((float)pc)*(64.0f/512.0f),((float)pr)*(64.0f/512.0f),0.0f);
			}
			grid[i].walkable=true;
		//
		//else grid[i].t=TextureMgr::Get().find("engine");
	}
	vert=new Vertex2D[rows*columns*4];
	texcoord=new Vertex2D[rows*columns*4];
	int i=0;
	for(int row=0;row<rows;row++)
	{
	for(int column=0;column<columns;column++)
	{
			int gridpos=row*rows+column;


			texcoord[i].x=grid[gridpos].TileStartPos.x+(1.0f/512.0f);
			texcoord[i].y=grid[gridpos].TileStartPos.y-(63.0f/512.0f);
			vert[i].x=10*(float)column/columns;
			vert[i].y=10*(float)row/rows;
			i++;
			texcoord[i].x=grid[gridpos].TileStartPos.x+(1.0f/512.0f);
			texcoord[i].y=grid[gridpos].TileStartPos.y-(2.0f/512.0f);
			vert[i].x=10*(float)column/columns;
			vert[i].y=10*(float)(row+1)/rows;
			i++;
			texcoord[i].x=grid[gridpos].TileStartPos.x+(62.0f/512.0f);
			texcoord[i].y=grid[gridpos].TileStartPos.y-(2.0f/512.0f);


			vert[i].x=10*(float)(column+1)/columns;
			vert[i].y=10*(float)(row+1)/rows;
			i++;
			texcoord[i].x=grid[gridpos].TileStartPos.x+(62.0f/512.0f);
			texcoord[i].y=grid[gridpos].TileStartPos.y-(63.0f/512.0f);

			vert[i].x=10*(float)(column+1)/columns;
			vert[i].y=10*(float)(row)/rows;
			i++;

	}
	}

	/*ifstream mapfile;
	mapfile.open(filename.c_str(),ios::binary);
	if(!mapfile) return false;
	if(!mapfile.read(reinterpret_cast<char*>(&header), sizeof(MapFileHeader)))
		return false;
	MapFileData *mdata=new MapFileData[header.rows*header.columns];
	if(!mapfile.read(reinterpret_cast<char*>(mdata),sizeof(MapFileData)*header.rows*header.columns))
		return false;
	grid=new MapElement[header.rows*header.columns];
	columns=header.columns;
	rows=header.rows;
	for(int i=0;i<rows*columns;i++)
	{
		grid[i].`t=TextureMgr::Get().find(mdata[i].texname);
	}
	delete mdata;*/

	return true;
}
Map::Map(std::string filename)
{
	load(filename);
}
void Map::render(Vector p, float scale)
{
	glPushMatrix();
	glMaterialfv(GL_BACK, GL_EMISSION, (const float[4]){1.0f,1.0f,1.0f,1.25f});
	glDisable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE);

	glColor4f(1.0f,1.0f,1.0f,1.0f);
	glTranslatef(-p.x,-p.y,0.0f);

	tex->bind();

	glVertexPointer(2,GL_FLOAT,0,vert);
	glTexCoordPointer(2,GL_FLOAT,0,texcoord);

	glDrawArrays(GL_QUADS,0,rows*columns*4); //20
	glPopMatrix();

}
