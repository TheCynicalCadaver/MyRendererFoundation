#include "ResourceSack.hpp"



Shader ResourceSack::MakeShader(std::string VertShaderPath, std::string FragShaderPath, std::string ShaderName){

std::string Vert = FileRead(VertShaderPath);
std::string Frag = FileRead(FragShaderPath);

Shader shader;

shader.Compile(Vert.c_str(), Frag.c_str());

Shaders[ShaderName] = shader;

return Shaders[ShaderName];
}

Shader ResourceSack::FindShader(std::string ShaderName){

	return Shaders[ShaderName];
						       }
