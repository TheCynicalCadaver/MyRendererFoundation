#include "TextureSeer.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <glad/gl.h> //OpenGL

Image::Image(const std::string& TexturePath, bool alpha){
	
	int width, height, nr_channels;
	unsigned char* data;

stbi_set_flip_vertically_on_load(true);

 data = stbi_load(TexturePath.c_str(), &width, &height, &nr_channels, 0);

glCreateTextures(GL_TEXTURE_2D, 1, &GL_ID);

glBindTexture(GL_TEXTURE_2D, GL_ID);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

if(!alpha){
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height,
		0, GL_RGB, GL_UNSIGNED_BYTE, data);
	  }

if(alpha){
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height,
		0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	 }

if(data == nullptr){
	std::cout << "Texture Failed" << std::endl;
		   }

stbi_image_free(data);
					   		 }
