	#pragma once
#include <string>
#include<GL\glew.h>
namespace Engine {
	class GLSLprogram
	{
	public:
		GLSLprogram();
		~GLSLprogram();

		void compileShaders(const std::string vertexShaderFilter, const std::string fragmentShaderFile);
		void linkShaders();
		void addAttrib(const std::string& attribName);

		void use();
		void unuse();
		GLint getUniformLocation(const std::string& uniformName);
	private:
		int _numAttributes;

		void compileShader(const std::string vertexShaderFilter, GLuint& id);


		GLuint _programID;
		GLuint _vertexShaderID;
		GLuint _fragmentShaderID;
	};

}