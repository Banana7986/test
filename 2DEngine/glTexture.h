#pragma once
#include <GL\glew.h>
#include <string>
namespace Engine {
	struct glTexture
	{
		std::string filePath = "";
		GLuint id;
		int width;
		int height;
	};

}