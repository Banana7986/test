#include "textureCache.h"
#include "imageLoader.h"
#include <iostream>

namespace Engine {
	textureCache::textureCache()
	{
	}


	textureCache::~textureCache()
	{
	}


	glTexture  textureCache::getTexture(std::string texturePath) {

		auto mit = _textureMap.find(texturePath);

		if (mit == _textureMap.end())
		{
			glTexture texture = imageLoader::loadPNG(texturePath);

			_textureMap.insert(make_pair(texturePath, texture));

			std::cout << "Loaded Cache Texture" << std::endl;
			return texture;
		}

		std::cout << "Loaded texture!" << std::endl;
		return mit->second;

	}
}