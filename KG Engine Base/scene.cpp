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

#include "scene.h"

namespace kg
{
	Scene::Scene()
	{
		// Defualt constructor for a scene:
		sceneObjects = new ObjectList;
	}

	Scene::~Scene()
	{
		// Default destructor for a scene:
		delete sceneObjects;
	}

	void Scene::update()
	{
		sceneObjects->update();
	}
}