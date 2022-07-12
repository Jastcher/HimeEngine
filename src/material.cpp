#include"material.h"

Material::Material()
	: color(glm::vec3(0.0f)) {}

void Material::LoadTexture(const char* path) {
	diffuseTexture = new Texture(path);
}
