/*
	___________________________________

	KG Engine Object Properties library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________
	
	Description:

	This library allows us to attach KG
	Engine properties onto 'Objects'.
	You can attach anything that has a
	'BasePropety' tag directly at any
	given point in any order.
	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#ifndef objectProperties_h
#define objectProperties_h

#include "math.h"

namespace kg
{
	struct BaseProperty
	{
		// Constructor:
		BaseProperty() : m_name(NULL) {}

		// Desrtuctor:  (need to fix potential memory leak!!!)
		virtual ~BaseProperty() {m_name = NULL;}

		// Virtual Methods:
		virtual void update() {}

		// Methods:
		void setName(char *name);

		char *getName() {return m_name;}

	protected:
		// Protected Methods:
		char *m_name;
	};

	struct Transform : public BaseProperty
	{
		// Constructor:
		Transform();

		// Desrtuctor:
		virtual ~Transform();

		// Methods:
		virtual void update();
		void addParentTransform(const Matrix16 &matrix);

		Matrix16 *getSelfTransform() {return transformBy;}

		// Members:
		Vector3 *position;
		Vector3 *center;
		Vector3 *scale;
		Quaternion *rotation;

	protected:
		// Private Members:
		Matrix16 *transformBy;
	};

	enum kg_camType
	{
		KG_ORTHOGRAPHIC,
		KG_PERSPECTIVE,
	};

	struct Camera : public BaseProperty
	{
		// Consturctors:
		Camera();

		// Destructor:
		~Camera();

		// Methods:
		void update();
		void setPerspective(const float &_near, const float &_far,
							const float &_fov, const float &_aspect);
		void setOrthographic(const float &_near, const float &_far, const float &_left,
							 const float &_right, const float &_top, const float &_bottom);

		Matrix16 *getMat() {return cameraM;}

		// Members:
		Vector3 *lookAt, *position, *upDir;

		Quaternion *rotation;

	private:
		// Private Members: 
		kg_camType m_type;

		float *m_near, *m_far, *m_left, *m_right, *m_top, *m_bottom, *m_fov, *m_aspect;

		Matrix16 *cameraM;
	};
}

#endif