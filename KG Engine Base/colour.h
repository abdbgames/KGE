/*
	___________________________________

	KG Engine Colour library
	___________________________________

	Written by Alastair Bilby
	Edited by:

	___________________________________
	
	Description:

	Yes colour is spelt correctly in
	Australia. Also, this file just
	makes it easier for you to work
	with colours, instead of just
	being able to use Vector4's.
	Note that Colours are faster if you
	set their values of floats from
	0.0f to 1.0f, but will work if go
	outside that range (inbuilt
	clamping) and will also work with
	a "kgColour" (which is just an
	unsigned char) from 0 to 255 making
	working with Colours easier for
	people coming from web based
	platforms.
	___________________________________

	Copyright(c) Knoob Group 2013,
	All rights reserved.
	___________________________________
*/

#ifndef colour_h
#define colour_h

#include "math.h"

namespace kg
{
	typedef unsigned char kgColour;

	struct Colour : public Vector4
	{
		// Constructors:
		Colour();
		Colour(const float &r, const float &g, const float &b);
		Colour(const float &r, const float &g, const float &b, const float &a);
		Colour(const kgColour &r, const kgColour &g, const kgColour &b);
		Colour(const kgColour &r, const kgColour &g, const kgColour &b, const kgColour &a);

		// Methods:
		void setColour(const float &r, const float &g, const float &b);
		void setColour(const float &r, const float &g, const float &b, const float &a);
		void setColour(const kgColour &r, const kgColour &g, const kgColour &b);
		void setColour(const kgColour &r, const kgColour &g, const kgColour &b, const kgColour &a);
		void setR(const float &r);
		void setR(const kgColour &r);
		void setG(const float &r);
		void setG(const kgColour &r);
		void setB(const float &r);
		void setB(const kgColour &r);
		void setA(const float &r);
		void setA(const kgColour &r);

	protected:
		// Protected Methods:
		float convert(const kgColour &in);
		void clampColours();
	};
}

#endif