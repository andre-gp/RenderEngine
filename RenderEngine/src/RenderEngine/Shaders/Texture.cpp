#include "pchRender.h"
#include "Texture.h"

#include <stb/stb_image.h>

Texture::Texture(const char* path, GLint format)
{
	/*-------- GENERATE TEXTURE --------*/
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	/*-------- TEXTURE PARAMETERS --------*/
	// Configure the texture's parameters.
	// Texture coordinates are defined as: (s,t,r)
	// <https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexParameter.xhtml>
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Which filtering method to use when the texture is being minified (MIN) or magnified (MAG)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	/*-------- LOAD TEXTURE --------*/
	int width;
	int height;
	int nrChannels;

	//stbi_set_flip_vertically_on_load(true);

	unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D); // We could manually call the glTexImage2D again for each 
										 // desired mipmap level (changing the second argument to the respective
										 // values), but this function automatically does this for us.
	}
	else
	{
		std::cout << "ERROR::TEXTURE::FAILED_TO_LOAD" << std::endl;
	}

	stbi_image_free(data);
}
