#pragma once

#include "Vector2.h"
#include "Trail.h"
#include <random>

extern int gScreenWidth;
extern int gScreenHeight;

template< typename T>
class Shape
{
public:
	Shape();
	Shape(Vector2 position, T size, char r, char g, char b);

	virtual void Draw() const;

	void Tick()
	{
		position += velocity;

		bool updateColour = false;
		if (position.X + GetXLength() > gScreenWidth || position.X < 0)
		{
			velocity.X *= -1;
			position.X = position.X < 0 ? 0 : gScreenWidth - GetXLength();

			updateColour = true;
		}
		if (position.Y + GetYLength() > gScreenHeight || position.Y < 0)
		{
			velocity.Y *= -1;
			position.Y = position.Y < 0 ? 0 : gScreenHeight - GetYLength();
			updateColour = true;
		}

		if (updateColour)
		{
			float r, g, b;
			hsv(rand() % 360, 1, 1, r, g, b);
			this->r = (int)round(r * 255);
			this->g = (int)round(g * 255);
			this->b = (int)round(b * 255);
		}

		myTrail.Tick(this);
	}


	void Randomise()
	{
		size = RandomSize();
		velocity.X = rand() % 2 == 0 ? -1 : 1;
		velocity.Y = rand() % 2 == 0 ? -1 : 1;
		int rnd = (rand() % 4) + 1;
		velocity.X *= rnd;
		velocity.Y *= rnd;

		float r = 0, g = 0, b = 0;
		hsv(rand() % 360, 1, 1, r, g, b);
		//cout << r << ", " << g << ", " << b << endl;
		r *= 255;
		g *= 255;
		b *= 255;

		this->r = r; this->g = g; this->b = b;

		position.X = rand() % (gScreenWidth - GetXLength()); position.Y = rand() % (gScreenHeight - GetYLength());
	}

	void hsv(int, float, float, float&, float&, float&) const;

	Vector2 GetPosition()
	{
		return position;
	}

protected:

	virtual int GetXLength() const;
	virtual int GetYLength() const;

	virtual T RandomSize() const;

	Vector2 position;
	Vector2 velocity;
	T size;

	Trail<T> myTrail;

	unsigned char r;
	unsigned char g;
	unsigned char b;
};