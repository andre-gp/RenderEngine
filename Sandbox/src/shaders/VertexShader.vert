#version 330 core
/* -------- VERTEX ATTRIBUTES --------*/
// These attributes are defined per-vertex.
// We need to set the attribute pointer and enable them.
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 Normal;
out vec4 WorldPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 lightPos;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);

	Normal = normalize(mat3(transpose(inverse(model))) * aNormal);

	WorldPos = model * vec4(aPos, 1.f);

	//Normal = aNormal;
}