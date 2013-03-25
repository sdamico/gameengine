#ifndef MAP_H
#define MAP_H
#include "../res.h"
#include "../mm/singleton.h"
#include "../texture/texturemgr.h"
#include "../vector/vector.h"

class Map : public Singleton<Map>
{
	Vertex2D *vert;
	Vertex2D *texcoord;
	Texture *tex;
	struct MapElement
	{
		Vector TileStartPos;
		bool walkable;
	}*grid;
	struct MapFileHeader
	{
		int rows;
		int columns;
	} header;
	struct MapFileData
	{
		std::string texname;
	};
	int rows,columns;
	public:
	Map();
	~Map();
	Map(std::string filename);
	bool load(std::string filename);
	void release();
	void render(Vector p, float scale);
};
#endif

