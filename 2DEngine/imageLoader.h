#pragma once
#include "glTexture.h"
#include <string>

namespace Engine {
	class imageLoader
	{
	public:
		static glTexture loadPNG(std::string filePath);
	};

}