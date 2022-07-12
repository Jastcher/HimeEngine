#include"scene.h"

Scene::Scene() 
	: activeCamera(nullptr) {}

void Scene::AddObject(Object* object) {
	objects.push_back(object);
}

void Scene::AddCamera(Camera* camera) {
	cameras.push_back(camera);
	if (activeCamera == nullptr) {
		activeCamera = camera;
	}
}

void Scene::ChangeCamera(int index) {
	activeCamera = cameras[index];
}
