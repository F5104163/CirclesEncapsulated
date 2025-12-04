#pragma once

#include "Vector2.h"

template< typename T>
class Shape
{
public:
	Shape();
	Shape(Vector2 position, T size, char r, char g, char b);

	virtual void Draw() const;

	virtual void Tick();

	void Randomise();

	void hsv(int, float, float, float&, float&, float&) const;

protected:

	virtual float GetXLength() const;
	virtual float GetYLength() const;

	virtual T RandomSize() const;

	Vector2 position;
	Vector2 velocity;
	T size;

	unsigned char r;
	unsigned char g;
	unsigned char b;
};