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

	Copyright� Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#include "objectProperties.h"
#include "platformControl.h"
#include "GraphicsAPI.h"
#include "engine.h"

namespace kg
{
	void BaseProperty::setName(char *name)
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

	/* 
		 ---------
		|Transform|
		 ---------
	*/

	Transform::Transform()
		: position (NULL),
		  center (NULL),
		  scale (NULL),
		  rotation (NULL),
		  transformBy (new Matrix16) {}

	Transform::~Transform()
	{
		if (position != NULL)
		{
			delete position;
			position = NULL;
		}

		if (center != NULL)
		{
			delete center;
			center = NULL;
		}

		if (rotation != NULL)
		{
			delete rotation;
			rotation = NULL;
		}

		if (transformBy != NULL)
		{
			delete transformBy;
			transformBy = NULL;
		}
	}

	void Transform::update()
	{
		// Internal update for positioning the Matrix from the given transform values:
		Matrix16 tScale;
		if (scale != NULL)
			tScale.setScale(*scale);

		Matrix16 tPos;
		if (position != NULL)
			tPos.setTranslation(*position);

		Matrix16 tRot;
		if (rotation != NULL)
			(center == NULL) ? tRot.setRotation(*rotation) : tRot.setRotationFromCenter(*rotation, *center);

		if (transformBy != NULL)
			*transformBy = tScale * tRot * tPos;
	}

	/* 
		 ------
		|Camera|
		 ------
	*/

	Camera::Camera() : m_type(KG_PERSPECTIVE),
					   m_near(NULL),
					   m_far(NULL),
					   m_left(NULL),
					   m_right(NULL),
					   m_top(NULL),
					   m_bottom(NULL),
					   m_fov(NULL),
					   m_aspect(NULL),
					   position(NULL),
					   lookAt(NULL),
					   rotation(NULL),
					   upDir(NULL),
					   cameraM(new Matrix16) {}

	Camera::~Camera()
	{
		if (cameraM != NULL)
		{
			delete cameraM;
			cameraM = NULL;
		}

		if (m_near != NULL)
		{
			delete m_near;
			m_near = NULL;
		}
		
		if (m_far != NULL)
		{
			delete m_far;
			m_far = NULL;
		}

		if (m_left != NULL)
		{
			delete m_left;
			m_left = NULL;
		}

		if (m_right != NULL)
		{
			delete m_right;
			m_right = NULL;
		}

		if (m_top != NULL)
		{
			delete m_top;
			m_top = NULL;
		}

		if (m_bottom != NULL)
		{
			delete m_bottom;
			m_bottom = NULL;
		}

		if (m_fov != NULL)
		{
			delete m_fov;
			m_fov = NULL;
		}

		if (m_aspect != NULL)
		{
			delete m_aspect;
			m_aspect = NULL;
		}

		if (lookAt != NULL)
		{
			delete lookAt;
			lookAt = NULL;
		}

		if (position != NULL)
		{
			delete position;
			position = NULL;
		}

		if (rotation != NULL)
		{
			delete rotation;
			rotation = NULL;
		}

		if (upDir != NULL)
		{
			delete upDir;
			upDir = NULL;
		}
	}

	void Camera::update()
	{
		// Updates out Camera:
		if (m_type == KG_PERSPECTIVE)
		{
			// Creates a Perspective Matrix:
			cameraM->setIdentity();

			#ifdef KG_USEGL
				*cameraM->m43 = -1.0f;
				*cameraM->m44 = 0.0f;
			#endif

			float f = 1.0f / tanf(*m_fov/2.0f);
			float m = (*m_near - *m_far);

			*cameraM->m11 = f / *m_aspect;
			*cameraM->m22 = f;
			*cameraM->m33 = (*m_far + *m_near) / m;
			*cameraM->m34 = (2.0f * (*m_far  * *m_near)) / m;

			// Construct a lookAt Matrix:
			Matrix16 mLookAt;

			// If transform values don't exist, treat them as 0:
			Vector3 pos;

			if (position != NULL)
				pos = *position;

			Vector3 la;

			if (lookAt != NULL)
				la = *lookAt;

			Vector3 up(0.0f, 1.0f, 0.0f);

			if (upDir != NULL)
				up = *upDir;

			Vector3 zAxis(la - pos);
			zAxis.normalise();

			Vector3 xAxis(Vector3::getCrossProduct(up, zAxis));
			xAxis.normalise();

			Vector3 yAxis(Vector3::getCrossProduct(zAxis, xAxis));

			Matrix16 transform(xAxis.x, yAxis.x, zAxis.x, 0.0f,
							   xAxis.y, yAxis.y, zAxis.y, 0.0f,
							   xAxis.z, yAxis.z, zAxis.z, 0.0f,
							   -Vector3::getDotProduct(xAxis, pos),
							   -Vector3::getDotProduct(yAxis, pos),
							   -Vector3::getDotProduct(zAxis, pos),
							   1.0f);

			transform.setInverse();

			*cameraM = transform * *cameraM;
		}
		else
		{
			// Creates an Orthorgaphic Matrix:
			#ifndef KG_USEGL
				*cameraM->m33 = -2.0f / (*m_far - *m_near);
			#else
				*cameraM->m33 = 2.0f / (*m_far - *m_near);
			#endif

			float m1 = *m_top - *m_bottom;
			float m2 = *m_right - *m_left;

			*cameraM->m11 = 2.0f / m2;
			*cameraM->m22 = 2.0f / m1;
			*cameraM->m14 = -1.0f * ((*m_right + *m_left) / m2);
			*cameraM->m24 = -1.0f * ((*m_top + *m_bottom) / m1);
			*cameraM->m34 = -1.0f * ((*m_far + *m_near) / (*m_far - *m_near));

			Matrix16 tRot;

			if (rotation != NULL)
				tRot.setRotation(*rotation);

			Matrix16 tPos;

			if (position != NULL)
				tPos.setRotation(*position);

			Matrix16 transform = tRot * tPos;

			*cameraM = transform * *cameraM;
		}
	}

	void Camera::setOrthographic(const float &_near, const float &_far, const float &_left,
								 const float &_right, const float &_top, const float &_bottom)
	{
		// Sets up the Camera from an Orthographic camera's values:
		m_type = KG_ORTHOGRAPHIC;

		if (m_near != NULL)
			delete m_near;

		if (m_far != NULL)
			delete m_far;

		if (m_left != NULL)
			delete m_left;

		if (m_right != NULL)
			delete m_right;

		if (m_top != NULL)
			delete m_top;

		if (m_bottom != NULL)
			delete m_bottom;

		if (m_fov != NULL)
		{
			delete m_fov;
			m_fov = NULL;
		}

		if (m_aspect != NULL)
		{
			delete m_aspect;
			m_aspect = NULL;
		}

		m_near = new float(_near);
		m_far = new float(_far);
		m_left = new float(_left);
		m_right = new float(_right);
		m_top = new float(_top);
		m_bottom = new float(_bottom);
	}

	void Camera::setPerspective(const float &_near, const float &_far,
								const float &_fov, const float &_aspect)
	{
		// Sets up the Camera from a Perspective camera's values:
		if (m_near != NULL)
			delete m_near;

		if (m_far != NULL)
			delete m_far;

		if (m_fov != NULL)
			delete m_fov;

		if (m_aspect != NULL)
			delete m_aspect;

		if (m_left != NULL)
		{
			delete m_left;
			m_left = NULL;
		}

		if (m_right != NULL)
		{
			delete m_right;
			m_right = NULL;
		}

		if (m_top != NULL)
		{
			delete m_top;
			m_top = NULL;
		}

		if (m_bottom != NULL)
		{
			delete m_bottom;
			m_bottom = NULL;
		}

		m_near = new float(_near);
		m_far = new float(_far);
		m_fov = new float(_fov);
		m_aspect = new float(_aspect);
	}
}