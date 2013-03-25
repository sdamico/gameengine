#include "texturemgr.h"

TextureMgr::TextureMgr()
{
	std::cout<<"[Starting Texture Manager]"<<std::endl;	
}

TextureMgr::~TextureMgr()
{
	std::cout<<"[Ending Texture Manager]"<<std::endl;
}

bool TextureMgr::load(std::string id, std::string filename)
{
	tlist.addElement(new Texture(id,filename));
	return true;
}

void TextureMgr::unload(std::string id)
{
	tlist.deleteElement(id);
}

void TextureMgr::use(std::string id)
{
	if(tlist.find(id))
	{
		tlist.currentElement()->bind();
	}
}

Texture *TextureMgr::find(std::string id)
{
	if(tlist.find(id))
	{
		return tlist.currentElement();
	}
	return false;
}
