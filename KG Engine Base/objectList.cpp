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

#include "objectList.h"

bool checkNULL(kg::Object *in) {return (in == NULL);}

namespace kg
{
	ObjectList::~ObjectList()
	{
		// Destructor for all Objects:
		for (int i = 0; i < objects.size(); ++i)
		{
			if (objects[i] != NULL)
			{
				delete objects[i];
				objects[i] = NULL;
			}
		}

		objects.clear();
	}

	void ObjectList::update()
	{
		// Updates all Objects:
		for (int i = 0; i < objects.size(); ++i)
		{
			// Update all Objects:
			if (objects[i] != NULL)
			{
				objects[i]->run();
				objects[i]->render();
			}
		}
	}

	bool ObjectList::addObject(char *name, Object *object)
	{
		// Adds in an Object:
		if (getObject(name) == NULL)
		{
			objects.push_back(object);
			objects[objects.size() - 1]->setName(name);
			return true;
		}

		// Object never existed or could not be erased:
		return false;
	}

	bool ObjectList::removeObject(char *name)
	{
		// Removes an Object:
		Object *o = getObject(name);

		if (o != NULL)
		{
			delete o;
			o = NULL;
			objects.erase(objects.begin(), std::remove_if(objects.begin(), objects.end(), checkNULL));
			return true;
		}

		// Object never existed or could not be erased:
		return false;
	}

	Object *ObjectList::getObject(char *name)
	{
		// Finds and returns an instance of an Object:
		int i = 0;

		while (i < objects.size() && strcmp(name, objects[i]->getName()) != 0)
			++i;

		return (i == objects.size()) ? NULL : objects[i];
	}

	bool ObjectList::renameObject(char *name, char *newName)
	{
		// Renames an Object, quite a complex process actually... :P
		Object *o = getObject(name);

		if (o != NULL)
		{
			o->setName(newName);
			return true;
		}

		// Couldn't find the Object or the new name was already taken:
		return false;
	}
}