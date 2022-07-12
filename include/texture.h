#pragma once
#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include"log.h"
#include"stb/stb_image.h"


class Texture {
public:
	Texture(const char* path);
	void ActivateBind();

	unsigned int id;
};
