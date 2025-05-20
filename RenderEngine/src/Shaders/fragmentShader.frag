#version 330 core

in vec4 ourColor;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	//FragColor = ourColor + vec4(.5, .5, .5, 0);
	float value = 1f;
	//FragColor = texture(texture1, TexCoord) * (ourColor + vec4(value, value, value, 0));
	FragColor = mix(texture(texture1, TexCoord), texture(texture2, vec2(0,1) - TexCoord), 0.7f);
};