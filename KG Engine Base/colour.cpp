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

#include "colour.h"

namespace kg
{
	Colour::Colour(const float &r, const float &g, const float &b)
	{
		setColour(r, g, b);
	}

	Colour::Colour(const float &r, const float &g, const float &b, const float &a)
	{
		setColour(r, g, b, a);
	}

	Colour::Colour(const kgColour &r, const kgColour &g, const kgColour &b)
	{
		setColour(r, g, b);
	}

	Colour::Colour(const kgColour &r, const kgColour &g, const kgColour &b, const kgColour &a)
	{
		setColour(r, g, b, a);
	}

	void Colour::setColour(const float &r, const float &g, const float &b)
	{
		x = r;
		y = g;
		z = b;

		clampColours();
	}

	void Colour::setColour(const float &r, const float &g, const float &b, const float &a)
	{
		x = r;
		y = g;
		z = b;
		w = a;

		clampColours();
	}

	void Colour::setColour(const kgColour &r, const kgColour &g, const kgColour &b)
	{
		x = convert(r);
		y = convert(g);
		z = convert(b);

		clampColours();
	}

	void Colour::setColour(const kgColour &r, const kgColour &g, const kgColour &b, const kgColour &a)
	{
		x = convert(r);
		y = convert(g);
		z = convert(b);
		w = convert(a);

		clampColours();
	}

	void Colour::setR(const float &r)
	{
		x = r;
		limit(x, 0.0f, 1.0f);
	}

	void Colour::setG(const float &g)
	{
		y = g;
		limit(y, 0.0f, 1.0f);
	}

	void Colour::setB(const float &b)
	{
		z = b;
		limit(z, 0.0f, 1.0f);
	}

	void Colour::setA(const float &a)
	{
		w = a;
		limit(w, 0.0f, 1.0f);
	}

	void Colour::setR(const kgColour &r)
	{
		setR(convert(r));
	}

	void Colour::setG(const kgColour &g)
	{
		setG(convert(g));
	}

	void Colour::setB(const kgColour &b)
	{
		setB(convert(b));
	}

	void Colour::setA(const kgColour &a)
	{
		setA(convert(a));
	}

	void Colour::clampColours()
	{
		// Make sure the colour channels are within correct bounds:
		limit(x, 0.0f, 1.0f);
		limit(y, 0.0f, 1.0f);
		limit(z, 0.0f, 1.0f);
		limit(w, 0.0f, 1.0f);
	}

	float Colour::convert(const kgColour &in)
	{
		// Converts a value of 0 to 255 to a value of 0 to 1:
		return (float)(in)/255.0f;
	}
}