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

#include "math.h"

namespace kg
{
	Quaternion::Quaternion()
	{
		x = y = z = 0.0f;
		w = 1.0f;
	}

	Quaternion::Quaternion(Vector2 v)
	{
		x = v.x;
		y = v.y;
		z = 0.0f;
		w = 1.0f;
	}

	Quaternion::Quaternion(Vector2 v, float _z)
	{
		x = v.x;
		y = v.y;
		z = _z;
		w = 1.0f;
	}

	Quaternion::Quaternion(float _x, float _y)
	{
		x = _x;
		y = _y;
		z = 0.0f;
		w = 1.0f;
	}

	Quaternion::Quaternion(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
		w = 1.0f;
	}

	Quaternion::Quaternion(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	Quaternion::Quaternion(Vector3 v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = 1.0f;
	}

	Quaternion::Quaternion(Vector3 v, float _w)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = _w;
	}

	Quaternion::Quaternion(Vector4 v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
	}

	Quaternion::Quaternion(bool _x, bool _y, bool _z, float angle)
	{
		x = (float)(_x);
		y = (float)(_y);
		z = (float)(_z);
		w = angle;
	}

	void Quaternion::setFromEuler(const float _x, const float _y, const float _z)
	{
		// Sets up a Quaternion from a Euler angle:
		Quaternion temp;
		Quaternion X(true, false, false, _x);
		Quaternion Y(false, true, false, _y);
		Quaternion Z(false, false, true, _z);

		temp = X*Y*Z;

		x = temp.x;
		y = temp.y;
		z = temp.z;
		w = temp.w;
	}

	void Quaternion::slerp(const Quaternion &start, const Quaternion &end, const float &t)
	{
		// Sets the Quaternion rotation to interpolate between two Quaternion values.
		// Therefore, if t is at 0.5f, then the Quaternion will sit 50% between
		// the start and end Quaternion values.

		Vector4 temp;

		float theta = acosf(temp.getDotProduct(start, end));

		float st = sinf(theta);

		Vector4 ret((((sinf(1.0f - t) * theta) / st) * start) +
					((sinf(t * theta) / st) * end));

		x = ret.x;
		y = ret.y;
		z = ret.z;
		w = ret.w;
	}
}