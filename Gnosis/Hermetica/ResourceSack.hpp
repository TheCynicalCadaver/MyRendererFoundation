#ifndef RESOURCE_SACK_HPP
#define RESOURCE_SACK_HPP

#include "OpenGospeL.hpp"
#include "FileOracle.hpp"

#include <unordered_map>

class ResourceSack{

	public:

ResourceSack(void){} 
		
std::unordered_map<std::string, Shader> Shaders;

Shader MakeShader(std::string VertShaderPath, std::string FragShaderPath, std::string ShaderName);

Shader FindShader(std::string ShaderName);
		  };

#endif
