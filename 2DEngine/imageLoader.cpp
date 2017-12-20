#include "imageLoader.h"
#include "picoPNG.h"
#include "IOmanager.h"
#include "fatal.h"


namespace Engine {
	glTexture imageLoader::loadPNG(std::string filePath)
	{
		glTexture texture = {};
		std::vector<unsigned char> in;
		std::vector<unsigned char> out;


		unsigned long width, height;

		if (IOmanager::readFileToBuffer(in, filePath) == false)
		{
			fatalError("Failed to load PNG file to buffer");
		}

		int errorCode = decodePNG(out, width, height, &(in[0]), in.size());
		if (errorCode != 0)
		{
			fatalError("decodePNG failed with error : " + std::to_string(errorCode));
		}

		glGenTextures(1, &(texture.id));
		//Bind the texture object
		glBindTexture(GL_TEXTURE_2D, texture.id);
		//Upload the pixels to the texture
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));

		//Set some texture parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		//Generate the mipmaps
		glGenerateMipmap(GL_TEXTURE_2D);
		//Unbind the texture
		glBindTexture(GL_TEXTURE_2D, 0);

		texture.width = width;
		texture.height = height;
		texture.filePath = filePath;

		//Return a copy of the texture data
		return texture;
	}


}