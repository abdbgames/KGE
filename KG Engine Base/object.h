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

#ifndef object_h
#define object_h

#include "objectProperties.h"

#include <vector>
#include <algorithm>

namespace kg
{
	// Various render types:
	enum kg_renderType
	{
		KG_NORENDER,
		KG_PLANERENDER,
		KG_MESHRENDER,
		KG_LINERENDER,
		KG_TRIRENDER,
		KG_SPRITERENDER,
		KG_TEXTRENDER,
	};

	struct ObjectList;

	struct Object
	{
		// Constructor:
		Object();

		// Destructor:
		virtual ~Object();

		// Methods:
		void run();
		void render();
		void setName(char *name);

		bool addProperty(char *name, BaseProperty *propertyType);
		bool removeProperty(char *name);
		bool addChild(char *name, Object *childObject);
		bool removeChild(char *name);

		char *getName() {return m_name;}

		BaseProperty *getProperty(char *name);
		Object *getChild(char *name);

		// Virtual Methods:
		virtual void start() {}
		virtual void update() {}

	protected:
		// Protected Methods:
		void getSelf();

		// Protected Members:
		std::vector<BaseProperty*> properties;

		char *m_name;

		ObjectList *children;

		Object *self;

		kg_renderType m_renderType;
	};
}

#endif