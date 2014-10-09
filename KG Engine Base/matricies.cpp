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

#include "matricies.h"
#include "engine.h"

namespace kg
{
	Matrix16::Matrix16()
	{
		setPointers();
		setIdentity();
	}

	Matrix16::Matrix16(float _11, float _12, float _13, float _14,
					   float _21, float _22, float _23, float _24,
					   float _31, float _32, float _33, float _34,
					   float _41, float _42, float _43, float _44)
	{
		setPointers();
		*m11 = _11; *m12 = _12; *m13 = _13; *m14 = _14;
		*m21 = _21; *m22 = _22; *m23 = _23; *m24 = _24;
		*m31 = _31; *m32 = _32; *m33 = _33; *m34 = _34;
		*m41 = _41; *m42 = _42; *m43 = _43; *m44 = _44;
	}

	Matrix16::~Matrix16()
	{
		m11 = NULL; m12 = NULL; m13 = NULL; m14 = NULL;
		m21 = NULL; m22 = NULL; m23 = NULL; m24 = NULL;
		m31 = NULL; m32 = NULL; m33 = NULL; m34 = NULL;
		m41 = NULL; m42 = NULL; m43 = NULL; m44 = NULL;
	}

	float *Matrix16::getMatGL()
	{
		return &matAsArray[0][0];
	}
	
	void Matrix16::setPointers()
	{
		m11 = &matAsArray[0][0]; m12 = &matAsArray[0][1]; m13 = &matAsArray[0][2]; m14 = &matAsArray[0][3];
		m21 = &matAsArray[1][0]; m22 = &matAsArray[1][1]; m23 = &matAsArray[1][2]; m24 = &matAsArray[1][3];
		m31 = &matAsArray[2][0]; m32 = &matAsArray[2][1]; m33 = &matAsArray[2][2]; m34 = &matAsArray[2][3];
		m41 = &matAsArray[3][0]; m42 = &matAsArray[3][1]; m43 = &matAsArray[3][2]; m44 = &matAsArray[3][3];
	}

	void Matrix16::setAll(float _11, float _12, float _13, float _14,
						  float _21, float _22, float _23, float _24,
						  float _31, float _32, float _33, float _34,
					      float _41, float _42, float _43, float _44)
	{
		*m11 = _11; *m12 = _12; *m13 = _13; *m14 = _14;
		*m21 = _21; *m22 = _22; *m23 = _23; *m24 = _24;
		*m31 = _31; *m32 = _32; *m33 = _33; *m34 = _34;
		*m41 = _41; *m42 = _42; *m43 = _43; *m44 = _44;
	}

	void Matrix16::setIdentity()
	{
		// Sets the Matrix to it's Identity:
		// Multiplying another Matrix by an identity Matrix does nothing.
		*m11 = 1.0f; *m12 = 0.0f; *m13 = 0.0f; *m14 = 0.0f;
		*m21 = 0.0f; *m22 = 1.0f; *m23 = 0.0f; *m24 = 0.0f;
		*m31 = 0.0f; *m32 = 0.0f; *m33 = 1.0f; *m34 = 0.0f;
		*m41 = 0.0f; *m42 = 0.0f; *m43 = 0.0f; *m44 = 1.0f;
	}

	void Matrix16::setScale(Vector3 scale)
	{
		// Sets the Matricies scale:
		*m11 = scale.x;
		*m22 = scale.y;
		*m33 = scale.z;
	}

	void Matrix16::setRotationX(float angle)
	{
		// Sets the Matricies rotation around the X axis:
		*m22 = cos(angle);
		*m23 = sin(angle);
		*m32 = -sin(angle);
		*m33 = cos(angle);
	}

	void Matrix16::setRotationY(float angle)
	{
		// Sets the Matricies rotation around the Y axis:
		*m11 = cos(angle);
		*m13 = -sin(angle);
		*m31 = sin(angle);
		*m33 = cos(angle);
	}

	void Matrix16::setRotationZ(float angle)
	{
		// Sets the Matricies rotation around the Z axis:
		*m11 = cos(angle);
		*m12 = -sin(angle);
		*m21 = sin(angle);
		*m22 = cos(angle);
	}

	void Matrix16::setTranslation(Vector3 position)
	{
		*m14 = position.x;
		*m24 = position.y;
		*m34 = position.z;
	}

	void Matrix16::setRotation(Quaternion rotation)
	{
		// Places a Quaternion rotation into a Matrix:
		float xx = rotation.x * rotation.x;
		float xy = rotation.x * rotation.y;
		float xz = rotation.x * rotation.z;
		float xw = rotation.x * rotation.w;
		float yy = rotation.y * rotation.y;
		float yz = rotation.y * rotation.z;
		float yw = rotation.y * rotation.w;
		float zz = rotation.z * rotation.z;
		float zw = rotation.z * rotation.w;

		*m11 = -1 * (yy + zz);
		*m12 = 2 * (xy - zw);
		*m13 = 2 * (xz + yw);
		*m21 = 2 * (xy + zw);
		*m22 = -1 * (xx + zz);
		*m23 = 2 * (yz - xw);
		*m31 = 2 * (xz - yw);
		*m32 = 2 * (yz + xw);
		*m33 = -1 * (xx + yy);
	}

	void Matrix16::setRotationFromCenter(Quaternion rotation, Vector3 center)
	{
		// Places a Quaternion rotation around a point into a Matrix:
		float qw = rotation.w*rotation.w;
		float qx = rotation.x*rotation.x;
		float qy = rotation.y*rotation.y;
		float qz = rotation.z*rotation.z;

		*m11 = qx - qy - qz + qw;
		*m22 = -qx + qy - qz + qw;
		*m33 = -qx - qy + qz + qw;

		float temp1 = rotation.x*rotation.y;
		float temp2 = rotation.z*rotation.w;
		*m12 = 2.0f * (temp1 + temp2);
		*m21 = 2.0f * (temp1 - temp2);

		temp1 = rotation.x*rotation.z;
		temp2 = rotation.y*rotation.w;
		*m13 = 2.0f * (temp1 - temp2);
		*m31 = 2.0f * (temp1 + temp2);

		temp1 = rotation.y*rotation.z;
		temp2 = rotation.x*rotation.w;
		*m23 = 2.0f * (temp1 + temp2);
		*m32 = 2.0f * (temp1 - temp2);
   
		*m14 = center.x - center.x * *m11 - center.y * *m12 - center.z * *m13;
		*m24 = center.y - center.x * *m21 - center.y * *m22 - center.z * *m23;
		*m34 = center.z - center.x * *m31 - center.y * *m32 - center.z * *m33;
	}

	void Matrix16::setInverse()
	{
		// Invert a Matrix16:
		Matrix16 ret;

		float inv[4][4], det;

		inv[0][0] =  matAsArray[1][1] * matAsArray[2][2] * matAsArray[3][3] -
					 matAsArray[1][1] * matAsArray[2][3] * matAsArray[3][2] -
					 matAsArray[2][1] * matAsArray[1][2] * matAsArray[3][3] +
					 matAsArray[2][1] * matAsArray[1][3] * matAsArray[3][2] +
					 matAsArray[3][1] * matAsArray[1][2] * matAsArray[2][3] -
					 matAsArray[3][1] * matAsArray[1][3] * matAsArray[2][2] ;
		inv[1][0] = -matAsArray[1][0] * matAsArray[2][2] * matAsArray[3][3] + 
					 matAsArray[1][0] * matAsArray[2][3] * matAsArray[3][2] + 
					 matAsArray[2][0] * matAsArray[1][2] * matAsArray[3][3] - 
					 matAsArray[2][0] * matAsArray[1][3] * matAsArray[3][2] - 
					 matAsArray[3][0] * matAsArray[1][2] * matAsArray[2][3] + 
					 matAsArray[3][0] * matAsArray[1][3] * matAsArray[2][2] ;
		inv[2][0] =  matAsArray[1][0] * matAsArray[2][1] * matAsArray[3][3] - 
					 matAsArray[1][0] * matAsArray[2][3] * matAsArray[3][1] - 
					 matAsArray[2][0] * matAsArray[1][1] * matAsArray[3][3] + 
					 matAsArray[2][0] * matAsArray[1][3] * matAsArray[3][1] + 
					 matAsArray[3][0] * matAsArray[1][1] * matAsArray[2][3] - 
					 matAsArray[3][0] * matAsArray[1][3] * matAsArray[2][1] ;
		inv[3][0] = -matAsArray[1][0] * matAsArray[2][1] * matAsArray[3][2] + 
					 matAsArray[1][0] * matAsArray[2][2] * matAsArray[3][1] +
					 matAsArray[2][0] * matAsArray[1][1] * matAsArray[3][2] - 
					 matAsArray[2][0] * matAsArray[1][2] * matAsArray[3][1] - 
					 matAsArray[3][0] * matAsArray[1][1] * matAsArray[2][2] + 
					 matAsArray[3][0] * matAsArray[1][2] * matAsArray[2][1] ;
		inv[0][1] = -matAsArray[0][1] * matAsArray[2][2] * matAsArray[3][3] + 
					 matAsArray[0][1] * matAsArray[2][3] * matAsArray[3][2] + 
					 matAsArray[2][1] * matAsArray[0][2] * matAsArray[3][3] - 
					 matAsArray[2][1] * matAsArray[0][3] * matAsArray[3][2] - 
					 matAsArray[3][1] * matAsArray[0][2] * matAsArray[2][3] + 
					 matAsArray[3][1] * matAsArray[0][3] * matAsArray[2][2] ;
		inv[1][1] =  matAsArray[0][0] * matAsArray[2][2] * matAsArray[3][3] - 
					 matAsArray[0][0] * matAsArray[2][3] * matAsArray[3][2] - 
					 matAsArray[2][0] * matAsArray[0][2] * matAsArray[3][3] + 
					 matAsArray[2][0] * matAsArray[0][3] * matAsArray[3][2] + 
					 matAsArray[3][0] * matAsArray[0][2] * matAsArray[2][3] - 
					 matAsArray[3][0] * matAsArray[0][3] * matAsArray[2][2] ;
		inv[2][1] = -matAsArray[0][0] * matAsArray[2][1] * matAsArray[3][3] + 
					 matAsArray[0][0] * matAsArray[2][3] * matAsArray[3][1] + 
					 matAsArray[2][0] * matAsArray[0][1] * matAsArray[3][3] - 
					 matAsArray[2][0] * matAsArray[0][3] * matAsArray[3][1] - 
					 matAsArray[3][0] * matAsArray[0][1] * matAsArray[2][3] + 
					 matAsArray[3][0] * matAsArray[0][3] * matAsArray[2][1] ;
		inv[3][1] =  matAsArray[0][0] * matAsArray[2][1] * matAsArray[3][2] - 
					 matAsArray[0][0] * matAsArray[2][2] * matAsArray[3][1] - 
					 matAsArray[2][0] * matAsArray[0][1] * matAsArray[3][2] + 
					 matAsArray[2][0] * matAsArray[0][2] * matAsArray[3][1] + 
					 matAsArray[3][0] * matAsArray[0][1] * matAsArray[2][2] - 
					 matAsArray[3][0] * matAsArray[0][2] * matAsArray[2][1] ;
		inv[0][2] =  matAsArray[0][1] * matAsArray[1][2] * matAsArray[3][3] - 
					 matAsArray[0][1] * matAsArray[1][3] * matAsArray[3][2] - 
					 matAsArray[1][1] * matAsArray[0][2] * matAsArray[3][3] + 
					 matAsArray[1][1] * matAsArray[0][3] * matAsArray[3][2] + 
					 matAsArray[3][1] * matAsArray[0][2] * matAsArray[1][3] - 
					 matAsArray[3][1] * matAsArray[0][3] * matAsArray[1][2] ;
		inv[1][2] = -matAsArray[0][0] * matAsArray[1][2] * matAsArray[3][3] + 
					 matAsArray[0][0] * matAsArray[1][3] * matAsArray[3][2] + 
					 matAsArray[1][0] * matAsArray[0][2] * matAsArray[3][3] - 
					 matAsArray[1][0] * matAsArray[0][3] * matAsArray[3][2] - 
					 matAsArray[3][0] * matAsArray[0][2] * matAsArray[1][3] + 
					 matAsArray[3][0] * matAsArray[0][3] * matAsArray[1][2] ;
		inv[2][2] =  matAsArray[0][0] * matAsArray[1][1] * matAsArray[3][3] - 
					 matAsArray[0][0] * matAsArray[1][3] * matAsArray[3][1] - 
					 matAsArray[1][0] * matAsArray[0][1] * matAsArray[3][3] + 
					 matAsArray[1][0] * matAsArray[0][3] * matAsArray[3][1] + 
					 matAsArray[3][0] * matAsArray[0][1] * matAsArray[1][3] - 
					 matAsArray[3][0] * matAsArray[0][3] * matAsArray[1][1] ;
		inv[3][2] = -matAsArray[0][0] * matAsArray[1][1] * matAsArray[3][2] + 
					 matAsArray[0][0] * matAsArray[1][2] * matAsArray[3][1] + 
					 matAsArray[1][0] * matAsArray[0][1] * matAsArray[3][2] - 
					 matAsArray[1][0] * matAsArray[0][2] * matAsArray[3][1] - 
					 matAsArray[3][0] * matAsArray[0][1] * matAsArray[1][2] + 
					 matAsArray[3][0] * matAsArray[0][2] * matAsArray[1][1] ;
		inv[0][3] = -matAsArray[0][1] * matAsArray[1][2] * matAsArray[2][3] + 
					 matAsArray[0][1] * matAsArray[1][3] * matAsArray[2][2] + 
					 matAsArray[1][1] * matAsArray[0][2] * matAsArray[2][3] - 
					 matAsArray[1][1] * matAsArray[0][3] * matAsArray[2][2] - 
					 matAsArray[2][1] * matAsArray[0][2] * matAsArray[1][3] + 
					 matAsArray[2][1] * matAsArray[0][3] * matAsArray[1][2] ;
		inv[1][3] =  matAsArray[0][0] * matAsArray[1][2] * matAsArray[2][3] - 
					 matAsArray[0][0] * matAsArray[1][3] * matAsArray[2][2] - 
					 matAsArray[1][0] * matAsArray[0][2] * matAsArray[2][3] + 
					 matAsArray[1][0] * matAsArray[0][3] * matAsArray[2][2] + 
					 matAsArray[2][0] * matAsArray[0][2] * matAsArray[1][3] - 
					 matAsArray[2][0] * matAsArray[0][3] * matAsArray[1][2] ;
		inv[2][3] = -matAsArray[0][0] * matAsArray[1][1] * matAsArray[2][3] +
					 matAsArray[0][0] * matAsArray[1][3] * matAsArray[2][1] +
					 matAsArray[1][0] * matAsArray[0][1] * matAsArray[2][3] -
					 matAsArray[1][0] * matAsArray[0][3] * matAsArray[2][1] -
					 matAsArray[2][0] * matAsArray[0][1] * matAsArray[1][3] +
					 matAsArray[2][0] * matAsArray[0][3] * matAsArray[1][1] ;
		inv[3][3] =  matAsArray[0][0] * matAsArray[1][1] * matAsArray[2][2] -
					 matAsArray[0][0] * matAsArray[1][2] * matAsArray[2][1] -
					 matAsArray[1][0] * matAsArray[0][1] * matAsArray[2][2] +
					 matAsArray[1][0] * matAsArray[0][2] * matAsArray[2][1] +
					 matAsArray[2][0] * matAsArray[0][1] * matAsArray[1][2] -
					 matAsArray[2][0] * matAsArray[0][2] * matAsArray[1][1] ;

		det = matAsArray[0][0] * inv[0][0] + matAsArray[0][1] * inv[1][0] +
			  matAsArray[0][2] * inv[2][0] + matAsArray[0][3] * inv[3][0];

		if (det == 0)
			Engine::debug("Division by 0. Matrix16 inverse cancelled");
		else
		{
			det = 1.0f / det;

			for (int y = 0; y < 4; ++y)
				for (int x = 0; x < 4; ++x)
					matAsArray[y][x] = inv[y][x] * det;
		}
	}
}