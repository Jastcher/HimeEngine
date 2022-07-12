#pragma once
#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"
#include"texture.h"

class Material {
public:
	Material();
	void LoadTexture(const char* path);

	glm::vec3 color;
	Texture* diffuseTexture;
};
