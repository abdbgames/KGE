/*
	___________________________________

	KG Engine Mac Helper library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________
	
	Description:

	This library gives a singleton for
	KG Engine base variables and
	functions, such as to set the
	window size, turn on/off anti
	aliasing etc.
	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#include "engine.h"
#include "platformControl.h"
#include "GraphicsAPI.h"

#include <sstream>

namespace kg
{
	// Default Engine values:
	bool Engine::looping = true;
	unsigned int Engine::time = 0;
	unsigned int Engine::currentMonitor = 1;
	Camera *Engine::currentCamera = NULL;

	void defualtExitFunction()
	{
		// Defualt function for when the program is forcibly exited:
		Engine::quit();
	}

	// This can be overriden at runtime:
	VoidF Engine::exitFunction = defualtExitFunction;

	void Engine::debug(const std::string &log)
	{
		// Platform specific log filing:
		#ifdef KG_WIN

		std::stringstream SS;
		SS << "Debuger logged: " << log << "\n";

		OutputDebugString(SS.str().c_str());
		#elif
		#include <stdio.h>
		printf("Debuger logged: %s\n", log.c_str());
		#endif
	}

	void Engine::fatal(const std::string &log)
	{
		#ifdef KG_WIN

		#elif

		#endif
	}

	void Engine::quit()
	{
		looping = false;
		debug("Non engine called Quit.");
	}

	void Engine::lowLevelUpdate()
	{
		if (callbackShouldClose())
		{
			exitFunction();
		}
	}

	int Engine::getCharSize(char *name)
	{
		int size = 0;

		while (*(name+size) != '\0')
			++size;

		return size;
	}
}