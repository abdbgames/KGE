/*
	___________________________________

	KG Engine Shader Helper for OpenGL
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________
	
	Description:

	This helper assists OpenGL to load
	in shaders assosiated with our
	application.
	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#include "loadShadersOGL.h"

#ifdef KG_USEGL

#include "engine.h"

#include <string>
#include <sstream>
#include <fstream>
#include <vector>

GLuint loadShaders(char *vertexFilePath, char *fragmentFilePath)
{ 
	// Create the shaders:
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	
	// Read the Vertex Shader code from the file:
	std::string vertexShaderCode;
	std::ifstream vertexShaderStream(vertexFilePath, std::ios::in);
	
	if (vertexShaderStream.is_open())
	{
		std::string Line = "";
		
		while(getline(vertexShaderStream, Line))
			vertexShaderCode += "\n" + Line;
		
		vertexShaderStream.close();
	}
	
	// Read the Fragment Shader code from the file:
	std::string fragmentShaderCode;
	std::ifstream fragmentShaderStream(fragmentFilePath, std::ios::in);
	
	if(fragmentShaderStream.is_open())
	{
		std::string Line = "";
		
		while(getline(fragmentShaderStream, Line))
			fragmentShaderCode += "\n" + Line;
		
		fragmentShaderStream.close();
	}
	
	GLint result = GL_FALSE;
	int infoLogLength;
	
	// Compile Vertex Shader:
	std::stringstream SS;
	SS << "Compiling shader: " << vertexFilePath;
	kg::Engine::debug(SS.str());
	
	char const * vertexSourcePointer = vertexShaderCode.c_str();
	
	glShaderSource(vertexShaderID, 1, &vertexSourcePointer , NULL);
	glCompileShader(vertexShaderID);
	
	// Check Vertex Shader:
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
	
	if (infoLogLength > 0)
	{
		std::vector<char> vertexShaderErrorMessage(infoLogLength);
	
		glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
		kg::Engine::debug(&vertexShaderErrorMessage[0]);
	}
	
	// Compile Fragment Shader
	SS.str(std::string());
	SS << "Compiling shader: " << fragmentFilePath;
	kg::Engine::debug(SS.str());
	
	char const * fragmentSourcePointer = fragmentShaderCode.c_str();
	
	glShaderSource(fragmentShaderID, 1, &fragmentSourcePointer , NULL);
	glCompileShader(fragmentShaderID);
	
	// Check Fragment Shader
	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
	
	if (infoLogLength > 0)
	{
		std::vector<char> fragmentShaderErrorMessage(infoLogLength);
	
		glGetShaderInfoLog(fragmentShaderID, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
		kg::Engine::debug(&fragmentShaderErrorMessage[0]);
	}
	
	// Link the program
	kg::Engine::debug("Linking Shaders");
	
	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
	
	// Check the program
	kg::Engine::debug("Checking for errors in Shaders:");
	
	glGetProgramiv(programID, GL_LINK_STATUS, &result);
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
	
	std::vector<char> programErrorMessage(max(infoLogLength, int(1)));
	
	glGetProgramInfoLog(programID, infoLogLength, NULL, &programErrorMessage[0]);
	kg::Engine::debug(&programErrorMessage[0]);
	
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
	
	kg::Engine::debug("Shaders Done!");
	
	return programID;
}

#endif