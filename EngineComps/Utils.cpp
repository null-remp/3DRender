#include "Utils.h"

#define GLEW_STATIC
#include <glew/glew.h>

unsigned int CreateVBO(float* verts, size_t size)
{
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size, verts, GL_STATIC_DRAW);
	return VBO;
}

unsigned int CreateVAO(float* verts, size_t size)
{
	return 0;
}
