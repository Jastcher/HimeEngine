#pragma once
#include"object.h"
#include"camera.h"

class Scene {
public:
	Scene();
	
	Camera* activeCamera;

	void AddObject(Object* object);
	void AddCamera(Camera* camera);
	void ChangeCamera(int index);

	std::vector<Object*> objects;
	std::vector<Camera*> cameras;
private:
};
