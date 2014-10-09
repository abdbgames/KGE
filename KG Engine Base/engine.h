/*
	___________________________________

	KG Engine Helper library
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

#ifndef engine_h
#define engine_h

#include "multiPlatformHelper.h"
#include "objectProperties.h"

#include <string>

namespace kg
{
	struct Engine
	{
		// Methods:
		static void debug(const std::string &log);
		static void fatal(const std::string &log);
		static void quit();
		static void lowLevelUpdate();

		static int getCharSize(char *name);

		// Members:
		static bool looping;

		static unsigned int time;
		static unsigned int currentMonitor;

		static VoidF exitFunction;

		static Camera *currentCamera;
	};
}

// Useful overloaders:
std::string operator +(const std::string &s, const float &f);
std::string operator +(const float &f, const std::string &s);
std::string operator +(const std::string &s, const int &i);
std::string operator +(const int &i, const std::string &s);
std::string operator +(const std::string &s, const bool &b);
std::string operator +(const bool &b, const std::string &s);

#endif