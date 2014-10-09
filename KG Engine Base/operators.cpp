/*
	___________________________________

	KG Engine Operator library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#include "math.h"
#include "engine.h"

#include <sstream>

/* 
		 -------
		|Vector2|
		 -------
*/

kg::Vector2 operator +(const kg::Vector2 &a, const kg::Vector2 &b)
{
	// Adds the Quaternions:
	kg::Vector2 ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;

	return ret;
}

kg::Vector2 operator +(const float &a, const kg::Vector2 &b)
{
	// Multiplies the values in a Vector2 by a single value:
	kg::Vector2 ret;

	ret.x = a + b.x;
	ret.y = a + b.y;

	return ret;
}

kg::Vector2 operator +(const kg::Vector2 &a, const float &b)
{
	// Multiplies the values in a Vector2 by a single value:
	kg::Vector2 ret;

	ret.x = b + a.x;
	ret.y = b + a.y;

	return ret;
}

kg::Vector2 operator -(const kg::Vector2 &a, const kg::Vector2 &b)
{
	// Subtracts the Quaternions:
	kg::Vector2 ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;

	return ret;
}

kg::Vector2 operator -(const float &a, const kg::Vector2 &b)
{
	// Multiplies the values in a Vector2 by a single value:
	kg::Vector2 ret;

	ret.x = a - b.x;
	ret.y = a - b.y;

	return ret;
}

kg::Vector2 operator -(const kg::Vector2 &a, const float &b)
{
	// Multiplies the values in a Vector2 by a single value:
	kg::Vector2 ret;

	ret.x = b - a.x;
	ret.y = b - a.y;

	return ret;
}

kg::Vector2 operator *(const kg::Vector2 &a, const kg::Vector2 &b)
{
	// Multiplies the Quaternions:
	kg::Vector2 ret;
	
	ret.x = a.x * b.x;
	ret.y = a.x * b.x;

	return ret;
}

kg::Vector2 operator *(const float &a, const kg::Vector2 &b)
{
	// Multiplies the values in a Vector2 by a single value:
	kg::Vector2 ret;

	ret.x = a * b.x;
	ret.y = a * b.y;

	return ret;
}

kg::Vector2 operator *(const kg::Vector2 &a, const float &b)
{
	// Multiplies the values in a Vector2 by a single value:
	kg::Vector2 ret;

	ret.x = b * a.x;
	ret.y = b * a.y;

	return ret;
}

kg::Vector2 operator /(const float &a, const kg::Vector2 &b)
{
	// Multiplies the values in a Vector2 by a single value:
	kg::Vector2 ret;

	ret.x = a / b.x;
	ret.y = a / b.y;

	return ret;
}

kg::Vector2 operator /(const kg::Vector2 &a, const float &b)
{
	// Multiplies the values in a Vector2 by a single value:
	kg::Vector2 ret;

	ret.x = b / a.x;
	ret.y = b / a.y;

	return ret;
}

kg::Vector2 operator /(const kg::Vector2 &a, const kg::Vector2 &b)
{
	// Multiplies the Quaternions:
	kg::Vector2 ret;
	
	ret.x = a.x / b.x;
	ret.y = a.x / b.x;

	return ret;
}

/* 
		 -------
		|Vector3|
		 -------
*/

kg::Vector3 operator +(const kg::Vector3 &a, const kg::Vector3 &b)
{
	// Adds the Quaternions:
	kg::Vector3 ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;

	return ret;
}

kg::Vector3 operator +(const float &a, const kg::Vector3 &b)
{
	// Multiplies the values in a Vector3 by a single value:
	kg::Vector3 ret;

	ret.x = a + b.x;
	ret.y = a + b.y;
	ret.z = a + b.z;

	return ret;
}

kg::Vector3 operator +(const kg::Vector3 &a, const float &b)
{
	// Multiplies the values in a Vector3 by a single value:
	kg::Vector3 ret;

	ret.x = b + a.x;
	ret.y = b + a.y;
	ret.z = b + a.z;

	return ret;
}

kg::Vector3 operator -(const kg::Vector3 &a, const kg::Vector3 &b)
{
	// Subtracts the Quaternions:
	kg::Vector3 ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;

	return ret;
}

kg::Vector3 operator -(const float &a, const kg::Vector3 &b)
{
	// Multiplies the values in a Vector3 by a single value:
	kg::Vector3 ret;

	ret.x = a - b.x;
	ret.y = a - b.y;
	ret.z = a - b.z;

	return ret;
}

kg::Vector3 operator -(const kg::Vector3 &a, const float &b)
{
	// Multiplies the values in a Vector3 by a single value:
	kg::Vector3 ret;

	ret.x = b - a.x;
	ret.y = b - a.y;
	ret.z = b - a.z;

	return ret;
}

kg::Vector3 operator *(const kg::Vector3 &a, const kg::Vector3 &b)
{
	// Multiplies the Quaternions:
	kg::Vector3 ret;
	
	ret.x = a.x * b.x;
	ret.y = a.x * b.x;
	ret.z = a.x * b.x;

	return ret;
}

kg::Vector3 operator *(const float &a, const kg::Vector3 &b)
{
	// Multiplies the values in a Vector3 by a single value:
	kg::Vector3 ret;

	ret.x = a * b.x;
	ret.y = a * b.y;
	ret.z = a * b.z;

	return ret;
}

kg::Vector3 operator *(const kg::Vector3 &a, const float &b)
{
	// Multiplies the values in a Vector3 by a single value:
	kg::Vector3 ret;

	ret.x = b * a.x;
	ret.y = b * a.y;
	ret.z = b * a.z;

	return ret;
}

kg::Vector3 operator /(const float &a, const kg::Vector3 &b)
{
	// Multiplies the values in a Vector3 by a single value:
	kg::Vector3 ret;

	ret.x = a / b.x;
	ret.y = a / b.y;
	ret.z = a / b.z;

	return ret;
}

kg::Vector3 operator /(const kg::Vector3 &a, const float &b)
{
	// Multiplies the values in a Vector3 by a single value:
	kg::Vector3 ret;

	ret.x = b / a.x;
	ret.y = b / a.y;
	ret.z = b / a.z;

	return ret;
}

kg::Vector3 operator /(const kg::Vector3 &a, const kg::Vector3 &b)
{
	// Multiplies the Quaternions:
	kg::Vector3 ret;
	
	ret.x = a.x / b.x;
	ret.y = a.x / b.x;
	ret.z = a.x / b.x;

	return ret;
}

/* 
		 -------
		|Vector4|
		 -------
*/

kg::Vector4 operator +(const kg::Vector4 &a, const kg::Vector4 &b)
{
	// Adds the Quaternions:
	kg::Vector4 ret;
	
	ret.w = a.w + b.w;
	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;

	return ret;
}

kg::Vector4 operator +(const float &a, const kg::Vector4 &b)
{
	// Multiplies the values in a Vector4 by a single value:
	kg::Vector4 ret;

	ret.w = a + b.w;
	ret.x = a + b.x;
	ret.y = a + b.y;
	ret.z = a + b.z;

	return ret;
}

kg::Vector4 operator +(const kg::Vector4 &a, const float &b)
{
	// Multiplies the values in a Vector4 by a single value:
	kg::Vector4 ret;

	ret.w = b + a.w;
	ret.x = b + a.x;
	ret.y = b + a.y;
	ret.z = b + a.z;

	return ret;
}

kg::Vector4 operator -(const kg::Vector4 &a, const kg::Vector4 &b)
{
	// Subtracts the Quaternions:
	kg::Vector4 ret;
	
	ret.w = a.w - b.w;
	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;

	return ret;
}

kg::Vector4 operator -(const float &a, const kg::Vector4 &b)
{
	// Multiplies the values in a Vector4 by a single value:
	kg::Vector4 ret;

	ret.w = a - b.w;
	ret.x = a - b.x;
	ret.y = a - b.y;
	ret.z = a - b.z;

	return ret;
}

kg::Vector4 operator -(const kg::Vector4 &a, const float &b)
{
	// Multiplies the values in a Vector4 by a single value:
	kg::Vector4 ret;

	ret.w = b - a.w;
	ret.x = b - a.x;
	ret.y = b - a.y;
	ret.z = b - a.z;

	return ret;
}

kg::Vector4 operator *(const kg::Vector4 &a, const kg::Vector4 &b)
{
	// Multiplies the Quaternions:
	kg::Vector4 ret;
	
	ret.w = (b.w * a.w) - (b.x * a.x) - (b.y * a.y) - (b.z * a.z);
	ret.x = (b.w * a.x) + (b.x * a.w) + (b.z * a.y) - (b.y * a.z);
	ret.y = (b.w * a.y) + (b.y * a.w) + (b.x * a.z) - (b.z * a.x);
	ret.z = (b.w * a.z) + (b.z * a.w) + (b.y * a.x) - (b.x * a.y);

	return ret;
}

kg::Vector4 operator *(const float &a, const kg::Vector4 &b)
{
	// Multiplies the values in a Vector4 by a single value:
	kg::Vector4 ret;

	ret.w = a * b.w;
	ret.x = a * b.x;
	ret.y = a * b.y;
	ret.z = a * b.z;

	return ret;
}

kg::Vector4 operator *(const kg::Vector4 &a, const float &b)
{
	// Multiplies the values in a Vector4 by a single value:
	kg::Vector4 ret;

	ret.w = b * a.w;
	ret.x = b * a.x;
	ret.y = b * a.y;
	ret.z = b * a.z;

	return ret;
}

kg::Vector4 operator /(const float &a, const kg::Vector4 &b)
{
	// Multiplies the values in a Vector4 by a single value:
	kg::Vector4 ret;

	ret.w = a / b.w;
	ret.x = a / b.x;
	ret.y = a / b.y;
	ret.z = a / b.z;

	return ret;
}

kg::Vector4 operator /(const kg::Vector4 &a, const float &b)
{
	// Multiplies the values in a Vector4 by a single value:
	kg::Vector4 ret;

	ret.w = b / a.w;
	ret.x = b / a.x;
	ret.y = b / a.y;
	ret.z = b / a.z;

	return ret;
}

/* 
		 -----------
		|Quaternions|
		 -----------
*/

kg::Quaternion operator +(const kg::Quaternion &a, const kg::Quaternion &b)
{
	// Adds the Quaternions:
	kg::Quaternion ret;
	
	ret.w = a.w + b.w;
	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;

	return ret;
}

kg::Quaternion operator -(const kg::Quaternion &a, const kg::Quaternion &b)
{
	// Subtracts the Quaternions:
	kg::Quaternion ret;
	
	ret.w = a.w - b.w;
	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;

	return ret;
}

kg::Quaternion operator *(const kg::Quaternion &a, const kg::Quaternion &b)
{
	// Multiplies the Quaternions:
	kg::Quaternion ret;
	
	ret.w = (b.w * a.w) - (b.x * a.x) - (b.y * a.y) - (b.z * a.z);
	ret.x = (b.w * a.x) + (b.x * a.w) + (b.z * a.y) - (b.y * a.z);
	ret.y = (b.w * a.y) + (b.y * a.w) + (b.x * a.z) - (b.z * a.x);
	ret.z = (b.w * a.z) + (b.z * a.w) + (b.y * a.x) - (b.x * a.y);

	return ret;
}

kg::Quaternion operator *(const float &a, const kg::Quaternion &b)
{
	// Multiplies the values in a Quaternion by a single value:
	kg::Quaternion ret;

	ret.w = a * b.w;
	ret.x = a * b.x;
	ret.y = a * b.y;
	ret.z = a * b.z;

	return ret;
}

kg::Quaternion operator *(const kg::Quaternion &a, const float &b)
{
	// Multiplies the values in a Quaternion by a single value:
	kg::Quaternion ret;

	ret.w = b * a.w;
	ret.x = b * a.x;
	ret.y = b * a.y;
	ret.z = b * a.z;

	return ret;
}

/* 
		 ---------
		|Matricies|
		 ---------
*/

kg::Matrix16 operator +(const float &a, const kg::Matrix16 &b)
{
	// Addition of a Matrix to a float:
	kg::Matrix16 ret;

	*ret.m11 = a + *b.m11; *ret.m12 = a + *b.m12;
	*ret.m21 = a + *b.m21; *ret.m22 = a + *b.m22;
	*ret.m31 = a + *b.m31; *ret.m32 = a + *b.m32;
	*ret.m41 = a + *b.m41; *ret.m42 = a + *b.m42;
	*ret.m13 = a + *b.m13; *ret.m14 = a + *b.m14;
	*ret.m23 = a + *b.m23; *ret.m24 = a + *b.m24;
	*ret.m33 = a + *b.m33; *ret.m34 = a + *b.m34;
	*ret.m43 = a + *b.m43; *ret.m44 = a + *b.m44;

	return ret;
}

kg::Matrix16 operator +(const kg::Matrix16 &a, const float &b)
{
	// Addition of a Matrix to a float:
	kg::Matrix16 ret;

	*ret.m11 = *a.m11 + b; *ret.m12 = *a.m12 + b;
	*ret.m21 = *a.m21 + b; *ret.m22 = *a.m22 + b;
	*ret.m31 = *a.m31 + b; *ret.m32 = *a.m32 + b;
	*ret.m41 = *a.m41 + b; *ret.m42 = *a.m42 + b;
	*ret.m13 = *a.m13 + b; *ret.m14 = *a.m14 + b;
	*ret.m23 = *a.m23 + b; *ret.m24 = *a.m24 + b;
	*ret.m33 = *a.m33 + b; *ret.m34 = *a.m34 + b;
	*ret.m43 = *a.m43 + b; *ret.m44 = *a.m44 + b;

	return ret;
}

kg::Matrix16 operator +(const kg::Matrix16 &a, const kg::Matrix16 &b)
{
	// Addition of two Matricies:
	kg::Matrix16 ret;

	*ret.m11 = *a.m11 + *b.m11; *ret.m12 = *a.m12 + *b.m12;
	*ret.m21 = *a.m21 + *b.m21; *ret.m22 = *a.m22 + *b.m22;
	*ret.m31 = *a.m31 + *b.m31; *ret.m32 = *a.m32 + *b.m32;
	*ret.m41 = *a.m41 + *b.m41; *ret.m42 = *a.m42 + *b.m42;
	*ret.m13 = *a.m13 + *b.m13; *ret.m14 = *a.m14 + *b.m14;
	*ret.m23 = *a.m23 + *b.m23; *ret.m24 = *a.m24 + *b.m24;
	*ret.m33 = *a.m33 + *b.m33; *ret.m34 = *a.m34 + *b.m34;
	*ret.m43 = *a.m43 + *b.m43; *ret.m44 = *a.m44 + *b.m44;

	return ret;
}

kg::Matrix16 operator -(const kg::Matrix16 &a, const kg::Matrix16 &b)
{
	// Subtraction of two Matricies:
	kg::Matrix16 ret;

	*ret.m11 = *a.m11 - *b.m11; *ret.m12 = *a.m12 - *b.m12;
	*ret.m21 = *a.m21 - *b.m21; *ret.m22 = *a.m22 - *b.m22;
	*ret.m31 = *a.m31 - *b.m31; *ret.m32 = *a.m32 - *b.m32;
	*ret.m41 = *a.m41 - *b.m41; *ret.m42 = *a.m42 - *b.m42;
	*ret.m13 = *a.m13 - *b.m13; *ret.m14 = *a.m14 - *b.m14;
	*ret.m23 = *a.m23 - *b.m23; *ret.m24 = *a.m24 - *b.m24;
	*ret.m33 = *a.m33 - *b.m33; *ret.m34 = *a.m34 - *b.m34;
	*ret.m43 = *a.m43 - *b.m43; *ret.m44 = *a.m44 - *b.m44;

	return ret;
}

kg::Matrix16 operator -(const float &a, const kg::Matrix16 &b)
{
	// Subtraction of a Matrix from a float:
	kg::Matrix16 ret;

	*ret.m11 = a - *b.m11; *ret.m12 = a - *b.m12;
	*ret.m21 = a - *b.m21; *ret.m22 = a - *b.m22;
	*ret.m31 = a - *b.m31; *ret.m32 = a - *b.m32;
	*ret.m41 = a - *b.m41; *ret.m42 = a - *b.m42;
	*ret.m13 = a - *b.m13; *ret.m14 = a - *b.m14;
	*ret.m23 = a - *b.m23; *ret.m24 = a - *b.m24;
	*ret.m33 = a - *b.m33; *ret.m34 = a - *b.m34;
	*ret.m43 = a - *b.m43; *ret.m44 = a - *b.m44;

	return ret;
}

kg::Matrix16 operator -(const kg::Matrix16 &a, const float &b)
{
	// Subtraction of a Matrix from a float:
	kg::Matrix16 ret;

	*ret.m11 = *a.m11 - b; *ret.m12 = *a.m12 - b;
	*ret.m21 = *a.m21 - b; *ret.m22 = *a.m22 - b;
	*ret.m31 = *a.m31 - b; *ret.m32 = *a.m32 - b;
	*ret.m41 = *a.m41 - b; *ret.m42 = *a.m42 - b;
	*ret.m13 = *a.m13 - b; *ret.m14 = *a.m14 - b;
	*ret.m23 = *a.m23 - b; *ret.m24 = *a.m24 - b;
	*ret.m33 = *a.m33 - b; *ret.m34 = *a.m34 - b;
	*ret.m43 = *a.m43 - b; *ret.m44 = *a.m44 - b;

	return ret;
}

kg::Matrix16 operator *(const kg::Matrix16 &a, const float &b)
{
	// Multiplacation of a Matrix with a float:
	kg::Matrix16 ret;

	*ret.m11 = *a.m11 * b; *ret.m12 = *a.m12 * b;
	*ret.m21 = *a.m21 * b; *ret.m22 = *a.m22 * b;
	*ret.m31 = *a.m31 * b; *ret.m32 = *a.m32 * b;
	*ret.m41 = *a.m41 * b; *ret.m42 = *a.m42 * b;
	*ret.m13 = *a.m13 * b; *ret.m14 = *a.m14 * b;
	*ret.m23 = *a.m23 * b; *ret.m24 = *a.m24 * b;
	*ret.m33 = *a.m33 * b; *ret.m34 = *a.m34 * b;
	*ret.m43 = *a.m43 * b; *ret.m44 = *a.m44 * b;

	return ret;
}

kg::Matrix16 operator *(const float &a, const kg::Matrix16 &b)
{
	// Multiplacation of a Matrix with a float:
	kg::Matrix16 ret;

	*ret.m11 = a * *b.m11; *ret.m12 = a * *b.m12;
	*ret.m21 = a * *b.m21; *ret.m22 = a * *b.m22;
	*ret.m31 = a * *b.m31; *ret.m32 = a * *b.m32;
	*ret.m41 = a * *b.m41; *ret.m42 = a * *b.m42;
	*ret.m13 = a * *b.m13; *ret.m14 = a * *b.m14;
	*ret.m23 = a * *b.m23; *ret.m24 = a * *b.m24;
	*ret.m33 = a * *b.m33; *ret.m34 = a * *b.m34;
	*ret.m43 = a * *b.m43; *ret.m44 = a * *b.m44;

	return ret;
}

kg::Matrix16 operator *(const kg::Matrix16 &a, const kg::Matrix16 &b)
{
	// Multiplacation of a Matrix with a Matrix:
	kg::Matrix16 ret;
	kg::Vector4 dot;

	*ret.m11 = dot.getDotProduct(kg::Vector4(*a.m11, *a.m12, *a.m13, *a.m14),
								 kg::Vector4(*b.m11, *b.m21, *b.m31, *b.m41));
	*ret.m12 = dot.getDotProduct(kg::Vector4(*a.m11, *a.m12, *a.m13, *a.m14),
								 kg::Vector4(*b.m12, *b.m22, *b.m32, *b.m42));
	*ret.m13 = dot.getDotProduct(kg::Vector4(*a.m11, *a.m12, *a.m13, *a.m14),
								 kg::Vector4(*b.m13, *b.m23, *b.m33, *b.m43));
	*ret.m14 = dot.getDotProduct(kg::Vector4(*a.m21, *a.m22, *a.m23, *a.m24),
								 kg::Vector4(*b.m14, *b.m24, *b.m34, *b.m44));
	*ret.m21 = dot.getDotProduct(kg::Vector4(*a.m21, *a.m22, *a.m23, *a.m24),
								 kg::Vector4(*b.m11, *b.m21, *b.m31, *b.m41));
	*ret.m22 = dot.getDotProduct(kg::Vector4(*a.m21, *a.m22, *a.m23, *a.m24),
								 kg::Vector4(*b.m12, *b.m22, *b.m32, *b.m42));
	*ret.m23 = dot.getDotProduct(kg::Vector4(*a.m21, *a.m22, *a.m23, *a.m24),
								 kg::Vector4(*b.m13, *b.m23, *b.m33, *b.m43));
	*ret.m24 = dot.getDotProduct(kg::Vector4(*a.m21, *a.m22, *a.m23, *a.m24),
								 kg::Vector4(*b.m14, *b.m24, *b.m34, *b.m44));
	*ret.m31 = dot.getDotProduct(kg::Vector4(*a.m31, *a.m32, *a.m33, *a.m34),
								 kg::Vector4(*b.m11, *b.m21, *b.m31, *b.m41));
	*ret.m32 = dot.getDotProduct(kg::Vector4(*a.m31, *a.m32, *a.m33, *a.m34),
								 kg::Vector4(*b.m12, *b.m22, *b.m32, *b.m42));
	*ret.m33 = dot.getDotProduct(kg::Vector4(*a.m31, *a.m32, *a.m33, *a.m34),
								 kg::Vector4(*b.m13, *b.m23, *b.m33, *b.m43));
	*ret.m34 = dot.getDotProduct(kg::Vector4(*a.m31, *a.m32, *a.m33, *a.m34),
								 kg::Vector4(*b.m14, *b.m24, *b.m34, *b.m44));
	*ret.m41 = dot.getDotProduct(kg::Vector4(*a.m41, *a.m42, *a.m43, *a.m44),
								 kg::Vector4(*b.m11, *b.m21, *b.m31, *b.m41));
	*ret.m42 = dot.getDotProduct(kg::Vector4(*a.m41, *a.m42, *a.m43, *a.m44),
								 kg::Vector4(*b.m12, *b.m22, *b.m32, *b.m42));
	*ret.m43 = dot.getDotProduct(kg::Vector4(*a.m41, *a.m42, *a.m43, *a.m44),
								 kg::Vector4(*b.m13, *b.m23, *b.m33, *b.m43));
	*ret.m44 = dot.getDotProduct(kg::Vector4(*a.m41, *a.m42, *a.m43, *a.m44),
								 kg::Vector4(*b.m14, *b.m24, *b.m34, *b.m44));

	return ret;
}

/* 
		 ------
		|Engine|
		 ------
*/

char* boolToString(const bool &in)
{
	// Makes a legacy string from a bool:
	return (in) ? "True" : "False";
}

std::string operator +(const std::string &s, const float &f)
{
	// Adds a float to the end of a string:
	std::stringstream ret;
	ret << f;
	return (s + ret.str());
}

std::string operator +(const float &f, const std::string &s)
{
	// Adds a float to the start of a string:
	std::stringstream ret;
	ret << f;
	return (ret.str() + s);
}

std::string operator +(const std::string &s, const int &i)
{
	// Adds an int to the end of a string:
	std::stringstream ret;
	ret << i;
	return (s + ret.str());
}

std::string operator +(const int &i, const std::string &s)
{
	// Adds an int to the start of a string:
	std::stringstream ret;
	ret << i;
	return (ret.str() + s);
}

std::string operator +(const std::string &s, const bool &b)
{
	// Adds a bool to the end of a string:
	return (boolToString(b) + s);
}

std::string operator +(const bool &b, const std::string &s)
{
	// Adds a bool to the start of a string:
	return (s + boolToString(b));
}