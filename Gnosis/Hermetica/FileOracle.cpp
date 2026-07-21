#include "FileOracle.hpp"

std::string FileRead(const std::string& filepath){

	std::ifstream CurrentFile(filepath);

	if(CurrentFile.is_open()){

	std::stringstream textBuffer;

	textBuffer << CurrentFile.rdbuf();

	const std::string F_Output = textBuffer.str();

	CurrentFile.close();

	return F_Output;

				 }
	return std::string();

						 }


