#pragma once
#include"mesh.h"
#include"material.h"
#include"shader.h"

struct Transform {
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

class Object {
public:
	glm::vec3 orientation = glm::vec3(0.0f, 0.0f, 1.0f);
	Transform transform;

	Object(Mesh* mesh, Material* material, Shader* shader);

	Mesh* mesh;
	Material* material;
	Shader* shader;

};
