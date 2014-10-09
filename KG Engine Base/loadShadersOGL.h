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

#ifndef loadShadersOGL
#define loadShadersOGL

#include "GraphicsAPI.h"

#ifdef KG_USEGL
#include <GL\glew.h>

GLuint loadShaders(char *vertexFilePath, char *fragmentFilePath);

#endif
#endif