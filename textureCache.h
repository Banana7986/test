#pragma once
#include <map>
#include "glTexture.h"
class textureCache
{
public:
	textureCache();
	~textureCache();

	glTexture getTexture(std::string texturePath);

private :
	std::map<std::string, glTexture> _textureMap;
};

