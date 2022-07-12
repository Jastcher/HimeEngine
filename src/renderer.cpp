#include"renderer.h"



Renderer::Renderer() {
}


void Renderer::RenderScene(Scene* scene) {
	// Render the scene
	glm::mat4 cameraViewMatrix = scene->activeCamera->GetViewMatrix();
	glm::mat4 cameraProjectionMatrix = scene->activeCamera->GetProjectionMatrix(0.1f, 100.0f);

	for (Object* object : scene->objects) {
		RenderObject(object, cameraViewMatrix, cameraProjectionMatrix);
	}

}

void Renderer::RenderObject(Object* object, glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix) {
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, object->transform.position);
		model = glm::rotate(model, glm::radians(object->transform.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(object->transform.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(object->transform.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, object->transform.scale);

		object->orientation = glm::rotate(object->orientation, glm::radians(object->transform.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		object->orientation = glm::rotate(object->orientation, glm::radians(object->transform.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		object->orientation = glm::rotate(object->orientation, glm::radians(object->transform.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		object->orientation = glm::normalize(object->orientation);

		object->shader->Activate();
		object->material->diffuseTexture->ActivateBind();
		object->shader->SetInt("tex0", 0);
		object->shader->SetMat4("view", cameraViewMatrix);
		object->shader->SetMat4("projection", cameraProjectionMatrix);
		object->shader->SetMat4("model", model);
		object->shader->SetVec3("color", object->material->color);

		object->mesh->Render();
}
