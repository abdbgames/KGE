/*
	___________________________________

	KG Engine Math Parent library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#include "math.h"

#include <time.h>
#include <cstdlib>

namespace kg
{
	void seedRandomGenerator()
	{
		// Seeds the Standard Library random number generator from system time:
		std::srand((unsigned int)time(NULL));
	}

	void seedRandomGenerator(const unsigned int &seed)
	{
		// Seeds the Standard Library random number generator from user input:
		std::srand(seed);
	}

	float getRandomF(const float &min, const float &max)
	{
		// Generates a random float in the range given:
		// NOTE: Assumes seedRandomGenerator() has been called! (This is
		// done automatically by KGE by default)
		
		if (max < min)
			return 0.0f;

		float diff = max - min;

		return (diff == 0.0f) ? 0.0f : min + ((((float)(rand())) / (float)(RAND_MAX)) * diff);
	}

	int getRandomI(const int &min, const int &max)
	{
		// Generates a random int in the range given:
		// NOTE: Assumes seedRandomGenerator() has been called! (This is
		// done automatically by KGE by default)

		if (max < min)
			return 0;

		int diff = max - min;

		return (diff == 0) ? 0 : min + (rand() % diff);
	}

	float degToRad(const float &in)
	{
		// Returns the angle in degrees converted to radians:
		return in / (kgPi/180.0f);
	}

	float radToDeg(const float &in)
	{
		// Returns the angle in radians converted to degrees:
		return in * (180.0f/kgPi);
	}

	bool diceRoll(const int &sides)
	{
		// Rolls a dice with a range from 1 to the number of sides entered,
		// then returns true if the dice rolls a one:
		return (getRandomI(1, sides) == 1);
	}

	int absolute(const int &in)
	{
		// Returns the absoulte value of the input.
		// So if the input is negative, it will return positive:
		return (in < 0) ? in * -1 : in;
	}

	float absolute(const float &in)
	{
		// Returns the absoulte value of the input.
		// So if the input is negative, it will return positive:
		return (in < 0.0f) ? in * -1.0f : in;
	}

	void clamp(float &in, const float &min, const float &max)
	{
		// Ensures that a specific value stays within a specific range:
		if (min == max)
		{
			// Makes sure we don't get stuck in an inifinate while loop:
			in = min;
			return;
		}

		if (min < max)
		{
			// It's a sad world where we have to put an error check here...
			while (in < min)
				in += min;

			while (in > max)
				in -= max;
		}

		// NOTE: the while loops are for if a value is more then twice the size of the clamp values.
		// So while the variable is outside of clap range, we pull it in until we get it within there.
	}

	void clamp(int &in, const int &min, const int &max)
	{
		// Ensures that a specific value stays within a specific range:
		if (min == max)
		{
			// Makes sure we don't get stuck in an inifinate while loop:
			in = min;
			return;
		}

		if (min < max)
		{
			// It's a sad world where we have to put an error check here...
			while (in < min)
				in += min;

			while (in > max)
				in -= max;
		}

		// NOTE: the while loops are for if a value is more then twice the size of the clamp values.
		// So while the variable is outside of clap range, we pull it in until we get it within there.
	}

	float clampF(const float &in, const float &min, const float &max)
	{
		float ret = in;
		clamp(ret, min, max);
		return ret;
	}

	int clampI(const int &in, const int &min, const int &max)
	{
		int ret = in;
		clamp(ret, min, max);
		return ret;
	}

	void limit(float &in, const float &min, const float &max)
	{
		// Dumb but fast version of clamp:
		if (min == max)
		{
			// Sanic checking:
			in = min;
			return;
		}

		if (min < max)
		{
			// Note the lack of loops:
			if (in < min)
				in = min;

			if (in > max)
				in = max;
		}
	}

	void limit(int &in, const int &min, const int &max)
	{
		// Dumb but fast version of clamp:
		if (min == max)
		{
			// Sanic checking:
			in = min;
			return;
		}

		if (min < max)
		{
			// Note the lack of loops:
			if (in < min)
				in = min;

			if (in > max)
				in = max;
		}
	}

	float limitF(const float &in, const float &min, const float &max)
	{
		float ret = in;
		limit(ret, min, max);
		return ret;
	}

	int limit(const int &in, const int &min, const int &max)
	{
		int ret = in;
		limit(ret, min, max);
		return ret;
	}

	void clampDeg(float &in)
	{
		// Clamps variable between 0 and 360 degrees:
		clamp(in, 0.0f, 360.0f);
	}

	void clampRad(float &in)
	{
		// Clamps variable between 0 and 360 degrees as radians:
		// (This helps avoid unessesary processor steps in your program)
		clamp(in, 0.0f, kgPi * 2.0f);
	}

	void round(float &in)
	{
		//Peforms a basic rouning operation:
		// if > 0.5 then next intiger...
		// if < 0.5 then previous intiger...
		
		float testFloor = floorf(in);

		in = (in < testFloor + 0.5f) ? testFloor : ceilf(in);
	}

	float clampDegF(const float &in)
	{
		float ret = in;
		clamp(ret, 0.0f, 360.0f);
		return ret;
	}

	float clampRadF(const float &in)
	{
		float ret = in;
		clamp(ret, 0.0f, kgPi * 2.0f);
		return ret;
	}

	float roundF(const float &in)
	{
		float testFloor = floorf(in);

		return (in < testFloor + 0.5f) ? testFloor : ceilf(in);
	}

	int roundI(const float &in)
	{
		float testFloor = floorf(in);
		
		return (int)(in < testFloor + 0.5f) ? testFloor : ceilf(in);
	}
}