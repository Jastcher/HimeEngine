#shader vertex
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexUV;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

out vec2 texUV;

void main()
{
	texUV = aTexUV;

	mat4 modelView = view * model;
	modelView[0][0] = model[0][0];
	modelView[0][1] = 0.0f;
	modelView[0][2] = 0.0f;

	modelView[1][0] = 0.0f;
	modelView[1][1] = model[1][1];
	modelView[1][2] = 0.0f;

	modelView[2][0] = 0.0f;
	modelView[2][1] = 0.0f;
	modelView[2][2] = model[2][2];

	gl_Position = projection * modelView * vec4(aPos, 1.0f);
}

#shader fragment
#version 330 core
out vec4 FragColor;

uniform sampler2D tex0;
uniform vec3 color;

in vec2 texUV;

void main()
{
	//FragColor = vec4(color, 1.0f);
	FragColor = texture(tex0, texUV);
}
