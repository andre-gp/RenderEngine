#version 330 core
/* -------- VERTEX ATTRIBUTES --------*/
// These attributes are defined per-vertex.
// We need to set the attribute pointer and enable them.
layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec3 avertexColor;
layout (location = 1) in vec2 aTexCoordinate;

out vec4 ourColor;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);
	//ourColor = vec4(avertexColor, 1.f);
	ourColor = vec4(1.f);
	TexCoord = vec2(aTexCoordinate.x, aTexCoordinate.y);
}