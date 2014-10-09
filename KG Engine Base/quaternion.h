/*
	___________________________________

	KG Engine Quaternion library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#ifndef quaternion_h
#define quaternion_h

namespace kg
{
	#include "vectors.h"

	struct Quaternion : public Vector4
	{
		// Constructors:
		Quaternion();
		Quaternion(Vector2 v);
		Quaternion(Vector2 v, float _z);
		Quaternion(Vector3 v);
		Quaternion(Vector3 v, float _w);
		Quaternion(Vector4 v);
		Quaternion(float _x, float _y);
		Quaternion(float _x, float _y, float _z);
		Quaternion(float _x, float _y, float _z, float _w);
		Quaternion(bool _x, bool _y, bool _z, float angle);

		// Methods:
		void slerp(const Quaternion &start, const Quaternion &end, const float &t);
		void setFromEuler(const float _x, const float _y, const float _z);
	};
}

// Operator Overloaders:
kg::Quaternion operator +(const kg::Quaternion &a, const kg::Quaternion &b);
kg::Quaternion operator -(const kg::Quaternion &a, const kg::Quaternion &b);
kg::Quaternion operator *(const kg::Quaternion &a, const kg::Quaternion &b);
kg::Quaternion operator *(const float &a, const kg::Quaternion &b);
kg::Quaternion operator *(const kg::Quaternion &a, const float &b);

#endif