/*
	___________________________________

	KG Engine Multi Platform Helper library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________
	
	Description:

	This library is for things that can
	be used at an engine level as non
	platform dependent code, to prevent
	multiple times per supported
	platform.
	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#ifndef multiPlatformHelper_h
#define multiPlatformHelper_h

#define kgPi		3.14159f
#define kgGravity	9.8f
#define NULL		0

typedef void (*VoidF)();

namespace kg
{
	void init();
	void update();
	void render();
	void onExit();
}

#endif