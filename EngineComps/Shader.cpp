#include "Shader.h"

#define GLEW_STATIC
#include <glew/glew.h>

#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const char* vPath, const char* fPath)
{
	std::string vCode;
	std::string fCode;

	std::ifstream vFile;
	std::ifstream fFile;

	vFile.exceptions(std::ifstream::failbit || std::ifstream::badbit);
	fFile.exceptions(std::ifstream::failbit || std::ifstream::badbit);
	try
	{
		vFile.open(vPath);
		fFile.open(fPath);

		std::stringstream vsShaderStream, fsShaderStream;

		vsShaderStream << vFile.rdbuf();
		fsShaderStream << fFile.rdbuf();

		vFile.close();
		fFile.close();
		
		vCode = vsShaderStream.str();
		fCode = fsShaderStream.str();

	}
	catch (std::ifstream::failure e)
	{

		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;

	}

	const char* vShaderCode = vCode.c_str();
	const char* fShaderCode = fCode.c_str();


	unsigned int vertexShader;
	unsigned int fragmentShader;
	
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, nullptr);
	glCompileShader(vertexShader);
	checkErrors(ProgramId, "VERTEX");

	

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, nullptr);
	glCompileShader(fragmentShader);
	checkErrors(ProgramId, "FRAGMENT");

	
	ProgramId = glCreateProgram();
	glAttachShader(ProgramId, vertexShader);
	glAttachShader(ProgramId, fragmentShader);
	glLinkProgram(ProgramId);
	
	checkErrors(ProgramId, "PROGRAM");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use()
{
	glUseProgram(ProgramId);
}

void Shader::setPrimitive(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(ProgramId, name.c_str()), static_cast<int>(value));
}

void Shader::setPrimitive(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ProgramId, name.c_str()), value);
}

void Shader::setPrimitive(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(ProgramId, name.c_str()), value);
}

void Shader::checkErrors(unsigned int shader, std::string&& type)
{
	int success;
	char infoBuffer[512];

	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, nullptr, infoBuffer);
			std::cerr << "ERROR::SHADER_COMPILATION_ERROR of TYPE: " << type << '\n' << infoBuffer << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(ProgramId, 512, nullptr, infoBuffer);
			std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILD of TYPE: " << type << '\n' << infoBuffer << std::endl;
		}

	}
}
