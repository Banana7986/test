#pragma once
#include "glTexture.h"
#include <string>
class imageLoader
{
public:
	static glTexture loadPNG(std::string filePath);
};

