#pragma once
#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"
#include<vector>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texcoord;
};

class Mesh {
public:
	Mesh(std::vector<Vertex> _vertices, std::vector<unsigned int> _indices, int _mode = GL_TRIANGLES);

	void Render();

	int mode;

private:
	unsigned int vao, vbo, ebo;
	unsigned int indicesSize;
};
