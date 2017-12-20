#pragma once
#include <GL\glew.h>
#include "glTexture.h"
#include <string>
namespace Engine {
	class Sprite
	{
	public:
		Sprite();
		~Sprite();

		void render();

		void Init(float x, float y, float width, float height, std::string texturePath);
	private:
		float _x;
		float _y;
		float _width;
		float _height;
		GLuint  _vboID;
		glTexture _texture;
	};

}