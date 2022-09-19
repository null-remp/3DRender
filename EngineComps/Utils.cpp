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
	unsigned int VBO = CreateVBO(verts, size);
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	//glDeleteBuffers(1, &VBO);
	return VAO;

}
