#pragma once
#include "textureCache.h"
#include "string"
namespace Engine {
	class resourceManager
	{
	public:
		static glTexture getTexture(std::string texturePath);

	private:
		static textureCache _textureCache;
	};

}