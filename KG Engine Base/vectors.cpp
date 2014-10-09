/*
	___________________________________

	KG Engine Vector Math Library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#include "vectors.h"
#include "math.h"

namespace kg
{
	/* 
		 -------
		|Vector2|
		 -------
	*/

	Vector2::Vector2()
	{
		x = y = 0.0f;
	}

	Vector2::Vector2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	void Vector2::normalise()
	{
		float l = getLength();
		x = x / l;
		y = y / l;
	}

	float Vector2::getLength()
	{
		// Returns the length (or hypotenuse) of the Vector:
		// This is the Magnitude of the Vector.
		return sqrtf((x*x) + (y*y));
	}

	float Vector2::getAngle()
	{
		// Returns the angle from this Vector2 to a straight up (positive on y) Vector2 in radians:
		float length = getLength();

		return (length == 0.0f) ? 0.0f : acosf(getDotProduct(*this, Vector2(0.0f, 1.0f)) / length);
	}

	float Vector2::getDotProduct(Vector2 a, Vector2 b)
	{
		// Returns the dot product between two Vectors:
		return (a.x*b.x) + (a.y*b.y);
	}

	float Vector2::getDistTo(Vector2 a, Vector2 b)
	{
		// Returns the distance between two Vectors:
		// This is the Magnitude of the Vectors.
		float xL = b.x - a.x;
		float yL = b.y - a.y;

		return sqrtf((xL*xL) + (yL*yL));
	}

	float Vector2::getAngleTo(Vector2 a, Vector2 b)
	{
		// Returns the angle between two Vectors in radians:
		float length = a.getLength() * b.getLength();

		// Avoid division by 0:
		return (length == 0.0f) ? 0.0f : acosf(getDotProduct(a, b) / length);
	}

	/*
		 -------
		|Vector3|
		 -------
	*/

	Vector3::Vector3()
	{
		x = y = z = 0.0f;
	}

	Vector3::Vector3(Vector2 v)
	{
		x = v.x;
		y = v.y;
		z = 0.0f;
	}

	Vector3::Vector3(Vector2 v, float _z)
	{
		x = v.x;
		y = v.y;
		z = _z;
	}

	Vector3::Vector3(float _x, float _y)
	{
		x = _x;
		y = _y;
		z = 0.0f;
	}

	Vector3::Vector3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	void Vector3::normalise()
	{
		float l = getLength();
		x = x / l;
		y = y / l;
		z = z / l;
	}

	float Vector3::getLength()
	{
		// Returns the length (or hypotenuse) of the Vector:
		return sqrtf((x*x) + (y*y) + (z*z));
	}

	float Vector3::getAngle()
	{
		// TODO: Requires Quaternion math...
		return -1.0f;
	}

	float Vector3::getDotProduct(Vector3 a, Vector3 b)
	{
		// Returns the dot product between two Vectors:
		return (a.x*b.x) + (a.y*b.y) + (a.z*b.z);
	}

	float Vector3::getDistTo(Vector3 a, Vector3 b)
	{
		// Returns the distance between two Vectors:
		float xL = b.x - a.x;
		float yL = b.y - a.y;
		float zL = b.z - a.z;

		return sqrtf((xL*xL) + (yL*yL) + (zL*zL));
	}

	float Vector3::getAngleTo(Vector3 a, Vector3 b)
	{
		// TODO: Requires Quaternions.
		return -1.0f;
	}

	Vector3 Vector3::getCrossProduct(Vector3 a, Vector3 b)
	{
		// Returns a Cross Product:
		Vector3 ret;

		ret.x = a.y * b.z - b.y * a.z;
		ret.y = a.x * b.z - b.x * a.z;
		ret.z = a.x * b.y - b.x * a.y;

		return ret;
	}

	/* 
		 -------
		|Vector4|
		 -------
	*/

	Vector4::Vector4()
	{
		x = y = z = 0.0f;
		w = 1.0f;
	}

	Vector4::Vector4(Vector2 v)
	{
		x = v.x;
		y = v.y;
		z = 0.0f;
		w = 1.0f;
	}

	Vector4::Vector4(Vector2 v, float _z)
	{
		x = v.x;
		y = v.y;
		z = _z;
		w = 1.0f;
	}

	Vector4::Vector4(float _x, float _y)
	{
		x = _x;
		y = _y;
		z = 0.0f;
		w = 1.0f;
	}

	Vector4::Vector4(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
		w = 1.0f;
	}

	Vector4::Vector4(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	Vector4::Vector4(Vector3 v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = 1.0f;
	}

	Vector4::Vector4(Vector3 v, float _w)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = _w;
	}

	void Vector4::setIdentity()
	{
		// Resets the Vector 4 to the identity of a 1 * 4 Matrix:
		x = y = z = 0.0f;
		w = 1.0f;
	}

	void Vector4::setInverse()
	{
		// Inverts the Vector4:
		Vector4 conjugate(-x, -y, -z, w);

		float m = getMagnitude();
		
		conjugate.x /= m;
		conjugate.y /= m;
		conjugate.z /= m;
		conjugate.w /= m;

		x = conjugate.x;
		y = conjugate.y;
		z = conjugate.z;
		w = conjugate.w;
	}
	
	float Vector4::getDotProduct(Vector4 a, Vector4 b)
	{
		// Returns the dot product between two Vectors:
		return (a.x*b.x) + (a.y*b.y) + (a.z*b.z) + (a.w*b.w);
	}

	float Vector4::getMagnitude()
	{
		// The same as getting length, but since w is effectivly an imaginary number,
		// the length of a Vector4 is of no real use to us as a length value but is of use as
		// a magnitude value.
		return sqrtf((x*x) + (y*y) + (z*z) + (w*w));
	}
}