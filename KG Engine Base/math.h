/*
	___________________________________

	KG Engine Math Parent library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________

	Copyright� Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#ifndef math_h
#define math_h

#include <math.h>

#include "vectors.h"
#include "quaternion.h"
#include "matricies.h"
#include "multiPlatformHelper.h"

namespace kg
{
	// TODO: Make all sub classes input types const referances to increase peformance.

	// Maths Methods:
	void clamp(int &in, const int &min, const int &max);
	void limit(int &in, const int &min, const int &max);
	void clamp(float &in, const float &min, const float &max);
	void limit(float &in, const float &min, const float &max);
	void round(float &in);
	void clampDeg(float &in);
	void clampRad(float &in);
	void seedRandomGenerator();
	void seedRandomGenerator(const unsigned int &seed);

	int clampI(const int &in, const int &min, const int &max);
	int limitI(const int &in, const int &min, const int &max);
	int roundI(const float &in);
	int roundI(const float &in);

	float clampF(const float &in, const float &min, const float &max);
	float limitF(const float &in, const float &min, const float &max);
	float roundF(const float &in);
	float clampDeg(const float &in);
	float clampRad(const float &in);

	bool diceRoll(const int &sides);

	float getRandomF(const float &min, const float &max);
	float degToRad(const float &in);
	float radToDeg(const float &in);
	float absolute(const float &in);

	int absolute(const int &in);
	int getRandomI(const int &min, const int &max);
}

#endif