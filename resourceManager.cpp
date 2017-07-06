#include "resourceManager.h"



textureCache resourceManager::_textureCache;


glTexture resourceManager::getTexture(std::string texturePath)
{
	return _textureCache.getTexture(texturePath);
}

