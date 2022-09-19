#pragma once

#include <string>

class Shader
{
public:
	unsigned int ProgramId;

	Shader(const char* vPath, const char* fPath);

	void use();

	void setPrimitive(const std::string& name, bool value) const;
	void setPrimitive(const std::string& name, int value) const;
	void setPrimitive(const std::string& name, float value) const;

private:
	void checkErrors(unsigned int shader, std::string&& type);
};

