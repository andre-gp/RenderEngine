#version 330 core
/* -------- VERTEX ATTRIBUTES --------*/
// These attributes are defined per-vertex.
// We need to set the attribute pointer and enable them.
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 Normal;
out vec4 WorldPos;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main()
{
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(aPos, 1.0f);	
}