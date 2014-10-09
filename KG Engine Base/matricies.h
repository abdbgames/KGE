/*
	___________________________________

	KG Engine Matrix library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#ifndef matricies_h
#define matricies_h

#include "math.h"

namespace kg
{
	struct Matrix16
	{
		// Constructors:
		Matrix16();
		Matrix16(float _11, float _12, float _13, float _14,
				 float _21, float _22, float _23, float _24,
				 float _31, float _32, float _33, float _34,
				 float _41, float _42, float _43, float _44);

		// Destructor:
		~Matrix16();

		// Methods:
		void setIdentity();
		void setInverse();
		void setScale(Vector3 scale);
		void setTranslation(Vector3 position);
		void setRotation(Quaternion rotation);
		void setRotationFromCenter(Quaternion rotation, Vector3 center);
		void setRotationX(float angle);
		void setRotationY(float angle);
		void setRotationZ(float angle);
		void setAll(float _11, float _12, float _13, float _14,
				    float _21, float _22, float _23, float _24,
				    float _31, float _32, float _33, float _34,
				    float _41, float _42, float _43, float _44);
		
		float *getMatGL();

		// Members:
		float *m11, *m12, *m13, *m14,
			  *m21, *m22, *m23, *m24,
			  *m31, *m32, *m33, *m34,
			  *m41, *m42, *m43, *m44;

	private:
		// Private Members:
		float matAsArray[4][4];

		// Private Methods:
		void setPointers();
	};
}

kg::Matrix16 operator +(const kg::Matrix16 &a, const float &b);
kg::Matrix16 operator +(const float &a, const kg::Matrix16 &b);
kg::Matrix16 operator +(const kg::Matrix16 &a, const kg::Matrix16 &b);
kg::Matrix16 operator -(const kg::Matrix16 &a, const float &b);
kg::Matrix16 operator -(const float &a, const kg::Matrix16 &b);
kg::Matrix16 operator -(const kg::Matrix16 &a, const kg::Matrix16 &b);
kg::Matrix16 operator *(const kg::Matrix16 &a, const float &b);
kg::Matrix16 operator *(const float &a, const kg::Matrix16 &b);
kg::Matrix16 operator *(const kg::Matrix16 &a, const kg::Matrix16 &b);

#endif