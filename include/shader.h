#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<glm/mat4x4.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"log.h"

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};
ShaderProgramSource get_file_contents(const char* filename);

class Shader {
public:
	GLuint ID;
	Shader(const char* fileName);

	void Activate();
	void Delete();
	void SetInt(const char* uniform, int unit);
	void SetFloat(const char* uniform, float unit);
	void SetMat4(const char* uniform, glm::mat4 unit);
	void SetMat3(const char* uniform, glm::mat3 unit);
	void SetVec4(const char* uniform, glm::vec4);
	void SetVec3(const char* uniform, glm::vec3);
	void SetVec2(const char* uniform, glm::vec2);

private:
	void CompileErrors(unsigned int shader, const char* type, const char* shaderName);
};

#endif
