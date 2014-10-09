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

#ifndef vectors_h
#define vectors_h

namespace kg
{
	/* 
		 -------
		|Vector2|
		 -------
	*/

	struct Vector2
	{
		// Consturctors:
		Vector2();
		Vector2(float x, float y);
		
		// Methods:
		void normalise();
		
		float getLength();
		float getAngle();
		float getDotProduct(Vector2 a, Vector2 b);
		float getDistTo(Vector2 a, Vector2 b);
		float getAngleTo(Vector2 a, Vector2 b);

		// Members:
		float x, y;
	};

	/* 
		 -------
		|Vector3|
		 -------
	*/

	struct Vector3
	{
		// Consturctors:
		Vector3();
		Vector3(Vector2 v);
		Vector3(Vector2 v, float _z);
		Vector3(float _x, float _y);
		Vector3(float _x, float _y, float _z);

		// Methods:
		void normalise();
		
		float getLength();
		float getAngle();

		static float getDotProduct(Vector3 a, Vector3 b);
		static float getDistTo(Vector3 a, Vector3 b);
		static float getAngleTo(Vector3 a, Vector3 b);

		static Vector3 getCrossProduct(Vector3 a, Vector3 b);

		// Members:
		float x, y, z;
	};
	
	/* 
		 -------
		|Vector4|
		 -------
	*/

	struct Vector4
	{
		// Constructors:
		Vector4();
		Vector4(Vector2 v);
		Vector4(Vector2 v, float _z);
		Vector4(Vector3 v);
		Vector4(Vector3 v, float _w);
		Vector4(float _x, float _y);
		Vector4(float _x, float _y, float _z);
		Vector4(float _x, float _y, float _z, float _w);

		// Methods:
		void setIdentity();
		void setInverse();

		float getMagnitude();
		float getDotProduct(Vector4 a, Vector4 b);

		// Members:
		float x, y, z, w;
	};
}

// Operator Overloaders:
kg::Vector2 operator +(const kg::Vector2 &a, const kg::Vector2 &b);
kg::Vector2 operator +(const float &a, const kg::Vector2 &b);
kg::Vector2 operator +(const kg::Vector2 &a, const float &b);
kg::Vector2 operator -(const kg::Vector2 &a, const kg::Vector2 &b);
kg::Vector2 operator -(const float &a, const kg::Vector2 &b);
kg::Vector2 operator -(const kg::Vector2 &a, const float &b);
kg::Vector2 operator *(const kg::Vector2 &a, const kg::Vector2 &b);
kg::Vector2 operator *(const float &a, const kg::Vector2 &b);
kg::Vector2 operator *(const kg::Vector2 &a, const float &b);
kg::Vector2 operator /(const float &a, const kg::Vector2 &b);
kg::Vector2 operator /(const kg::Vector2 &a, const float &b);
kg::Vector2 operator /(const kg::Vector2 &a, const kg::Vector2 &b);
kg::Vector3 operator +(const kg::Vector3 &a, const kg::Vector3 &b);
kg::Vector3 operator +(const float &a, const kg::Vector3 &b);
kg::Vector3 operator +(const kg::Vector3 &a, const float &b);
kg::Vector3 operator -(const kg::Vector3 &a, const kg::Vector3 &b);
kg::Vector3 operator -(const float &a, const kg::Vector3 &b);
kg::Vector3 operator -(const kg::Vector3 &a, const float &b);
kg::Vector3 operator *(const kg::Vector3 &a, const kg::Vector3 &b);
kg::Vector3 operator *(const float &a, const kg::Vector3 &b);
kg::Vector3 operator *(const kg::Vector3 &a, const float &b);
kg::Vector3 operator /(const float &a, const kg::Vector3 &b);
kg::Vector3 operator /(const kg::Vector3 &a, const float &b);
kg::Vector3 operator /(const kg::Vector3 &a, const kg::Vector3 &b);
kg::Vector4 operator +(const kg::Vector4 &a, const kg::Vector4 &b);
kg::Vector4 operator +(const float &a, const kg::Vector4 &b);
kg::Vector4 operator +(const kg::Vector4 &a, const float &b);
kg::Vector4 operator -(const kg::Vector4 &a, const kg::Vector4 &b);
kg::Vector4 operator -(const float &a, const kg::Vector4 &b);
kg::Vector4 operator -(const kg::Vector4 &a, const float &b);
kg::Vector4 operator *(const kg::Vector4 &a, const kg::Vector4 &b);
kg::Vector4 operator *(const float &a, const kg::Vector4 &b);
kg::Vector4 operator *(const kg::Vector4 &a, const float &b);
kg::Vector4 operator /(const float &a, const kg::Vector4 &b);
kg::Vector4 operator /(const kg::Vector4 &a, const float &b);

#endif