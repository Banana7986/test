#include "textureCache.h"
#include "imageLoader.h"
#include <iostream>



textureCache::textureCache()
{
}


textureCache::~textureCache()
{
}


glTexture  textureCache::getTexture(std::string texturePath) {

	auto mit =  _textureMap.find(texturePath);

	if (mit == _textureMap.end())
	{
		glTexture newTexture = imageLoader::loadPNG(texturePath);
		
		_textureMap.insert(make_pair(texturePath, newTexture)); \

			std::cout << "Loaded Cache Texture" << std::endl;
		return newTexture;
	}

	std::cout << "Loaded texture!" << std::endl;
	return mit->second;

}