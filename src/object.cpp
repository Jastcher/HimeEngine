#include"object.h"

Object::Object(Mesh* mesh, Material* material, Shader* shader)
	: mesh(mesh), material(material), shader(shader) {
	transform.position = glm::vec3(0.0f);
	transform.rotation = glm::vec3(0.0f);
	transform.scale = glm::vec3(1.0f);
}
