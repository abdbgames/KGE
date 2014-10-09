/*
	___________________________________

	KG Engine Object List library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________
	
	Description:

	This library keeps track of every
	object attached to a scene, and
	peforms the base tasks, like
	the run function on them.

	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#ifndef objectList_h
#define objectList_h

#include "object.h"

namespace kg
{
	struct ObjectList
	{
		// Desrtuctor:
		~ObjectList();

		// Methods:
		void update();

		bool addObject(char *name, Object *object);
		bool removeObject(char *name);
		bool renameObject(char *name, char *newName);

		Object *getObject(char *name);

	protected:
		// Protected Members:
		std::vector<Object*> objects;
	};
}

#endif