/*
	___________________________________

	KG Engine GraphicsAPI library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________
	
	Description:

	This library is defined by either
	OpenGL.cpp or DirectX.cpp depending
	on the settings created in
	platformControl.h.
	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#ifndef GraphicsAPI_h
#define GraphicsAPI_h

#include "platformControl.h"

#ifdef KG_WIN
#ifdef KG_FORCEGL
// OpenGL:
#define KG_USEGL 1

#elif
// DirectX:
#define KG_USEDX 1

#endif
#elif
// OpenGL:
#define KG_USEGL 1

#endif

namespace kg
{
	void initAPI();
	void closeAPI();
	void updateAPI();
	void openRenderPipeAPI();
	void closeRenderPipeAPI();

	int callbackShouldClose();
}

#endif