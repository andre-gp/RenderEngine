#version 330 core


in vec3 Normal;
in vec4 WorldPos;

out vec4 FragColor;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;


void main()
{
	vec3 calcLightColor = lightColor * 1f;

	vec3 worldPos = vec3(WorldPos.x, WorldPos.y, WorldPos.z);

	float ambientStrength = 0.1;
	vec3 ambient = ambientStrength * calcLightColor;

	vec3 lightDirection = normalize(lightPos - worldPos);

	float diffuseStrenght = dot(vec4(lightDirection, 1.f), vec4(Normal, 1.f));

	diffuseStrenght = max(diffuseStrenght, 0.0); // Removing negative influence of the light (when it is not facing the obj)

	vec3 diffuse = calcLightColor * diffuseStrenght; 

	vec3 viewDirection = normalize(viewPos - worldPos);
	vec3 lightReflection = reflect(lightDirection, Normal);

	float specularStrength = 1f;

	float spec = pow(max(dot(viewDirection, lightReflection), 0.0), 4);
	vec3 specular = specularStrength * spec * lightColor;  
	
	FragColor = vec4( ((diffuse + ambient + specular) * objectColor), 1.f);	

	FragColor = vec4(specular, 1.f);
};