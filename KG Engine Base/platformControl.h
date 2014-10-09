/*
	___________________________________

	KG Engine Platform Control library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________
	
	Description:

	This library automatically detects
	the platform you are building for
	and updates the rest of the engine
	to cooperate with platform specific
	dependencies as required.

	Platforms thus far:
	KG_OSX
	KG_WIN

	To make Windows ude OpenGL uncomment:
	#define KG_FORCEGL
	on line 60.

	To get the project to build, you
	can get away with simply removing
	the header and cpp files not
	nessesary for your target platform.
	___________________________________

	Copyright� Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#ifndef platformControl_h
#define platformControl_h
	#ifdef _WIN64
		#define KG_WIN 1
	#elif _WIN32
		#define KG_WIN 1
	#elif __APPLE__
		#include "TargetConditionals.h"
		#if TARGET_IPHONE_SIMULATOR
			 // TODO: Support.
		#elif TARGET_OS_IPHONE
			// TODO: Support.
		#elif TARGET_OS_MAC
			#define KG_OSX 1
		#else
			// Unsupported platform
		#endif
	#elif __linux
		// linux
	#else
		// Unsupported platform
	#endif

	#ifdef KG_OSX
		#include "osxSupport.h"
	#elif KG_WIN
		#define KG_FORCEGL 1
		#include "winSupport.h"
	#endif
#include "multiPlatformHelper.h"
#endif