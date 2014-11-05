/*
	___________________________________

	KG Engine Object library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#include "object.h"
#include "objectList.h"
#include "engine.h"

#include <stdlib.h>

bool checkNULL(kg::BaseProperty *in) {return (in == NULL);}

namespace kg
{
	Object::Object()
	{
		// Constructor for all Objects:
		children = new ObjectList;
		self = NULL;
		m_name = NULL;
		m_renderType = KG_NORENDER;
	}

	Object::~Object()
	{
		// Destructor for all Objects:
		for (int i = 0; i < properties.size(); ++i)
		{
			if (properties[i] != NULL)
			{
				delete properties[i];
				properties[i] = NULL;
			}
		}

		properties.clear();

		if (children != NULL)
		{
			delete children;
			children = NULL;
		}

		if (m_name != NULL)
			// Fix memory leak...
			m_name = NULL;

		self = NULL;
	}

	void Object::getSelf()
	{
		self = this;
	}

	void Object::setName(char *name)
	{
		if (name != NULL)
		{
			if (m_name != NULL)
			{
				delete [] m_name;
				m_name = NULL;
			}

			m_name = new char[Engine::getCharSize(name)];

			strcpy(m_name, name);
		}
	}

	void Object::run()
	{
		if (self == NULL)
		{
			getSelf();
			self->start();
		}
		
		self->update();

		// Update Method for all Properties:
		for (int i = 0; i < properties.size(); ++i)
			// Attempt to update all Object properties:
			properties[i]->update();

		children->update();
	}

	void Object::render()
	{
		// function for rendering each object:
		switch (m_renderType)
		{
		case KG_NORENDER:
			return;
		case KG_LINERENDER:
			break;
		case KG_MESHRENDER:
			break;
		case KG_PLANERENDER:
			break;
		case KG_SPRITERENDER:
			break;
		case KG_TRIRENDER:
			break;
		case KG_TEXTRENDER:
			break;
		default:
			Engine::debug("A non valid option was entered for Object::render.");
			break;
		}
	}

	bool Object::addProperty(char *name, BaseProperty *propertyType)
	{
		// Attaches a property to the Object:
		BaseProperty *p = getProperty<BaseProperty>(name);

		if (p == NULL)
		{
			properties.push_back(propertyType);
			properties[properties.size() - 1]->setName(name);
			return true;
		}

		p = NULL;

		// Property never existed or could not be erased:
		return false;
	}

	bool Object::removeProperty(char *name)
	{
		// Detaches a property from the Object:
		BaseProperty *p = getProperty<BaseProperty>(name);

		if (p != NULL)
			delete p;

		p = NULL;

		// Property never existed or could not be erased:
		return false;
	}

	bool Object::addChild(char *name, Object *childObject)
	{
		// Attaches a child Object to the Object:
		return (children != NULL) ? children->addObject(name, childObject) : false;
	}

	bool Object::removeChild(char *name)
	{
		// Detaches a child Object from the Object:
		return (children != NULL) ? children->removeObject(name) : false;
	}

	template <typename T>
	T *Object::getProperty(char *name)
	{
		// Checks if an Object property exists and return a pointer to it:
		int i = 0;

		while (i < properties.size() && strcmp(name, properties[i]->getName()) != 0)
			++i;

		return (i == properties.size()) ? NULL : dynamic_cast<T*>properties[i];
	}

	template <typename T>
	T *Object::getChild(char *name)
	{
		return children->getObject<T>(name);
	}
}