/*
	___________________________________

	KG Engine Scene Manager library
	___________________________________

	Written by Alastair Bilby
	Edited by:
	
	___________________________________
	
	Description:

	This library makes support for
	dynamic scene creation in the
	editor or via C++ code. The engine
	will automatically manage scenes
	based on this code. Feel free to
	branch it if it lacking in features.
	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#ifndef scene_h
#define scene_h

#include "objectList.h"
#include "colour.h"

namespace kg
{
	struct Scene
	{
		// Constructor:
		Scene();

		// Destructor:
		virtual ~Scene();

		// Methods:
		void update();
		void render();

		// Members:
		ObjectList *sceneObjects;

		//Colour ambientLightLevels;
	};
}

#endif