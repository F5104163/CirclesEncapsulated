
#include "Framework.h"
#include "Ball.h"

#include<iostream>
#include "Shape.h"

extern int gScreenWidth;
extern int gScreenHeight;

using namespace std;

void hsv(int, float, float, float&, float&, float&);

Ball::Ball()
{
	rad = 100;
	position = Vector2(0, 0);
	velocity = Vector2(0, 0);
	r = 1;
	g = 0;
	b = 0;
}

Ball::Ball(int rad, Vector2 position, Vector2 velocity, unsigned char r, unsigned char g, unsigned char b)
{
	this->rad = rad;
	this->position = position;
	this->velocity = velocity;
	this->r = r;
	this->g = g;
	this->b = b;
}

void Ball::Randomise()
{
	rad = (rand() % 30) + 10;
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

	position.X = rand() % (gScreenWidth - rad); position.Y = rand() % (gScreenHeight - rad);
}


void Ball::Update()
{
	position += velocity;

	bool updateColour = false;
	if (position.X + (this->rad * 2) > gScreenWidth || position.X < 0)
	{
		velocity.X *= -1;
		position.X = position.X < 0 ? 0 : gScreenWidth - (this->rad * 2);

		updateColour = true;
	}
	if (position.Y + (this->rad * 2) > gScreenHeight || position.Y < 0)
	{
		velocity.Y *= -1;
		position.Y = position.Y < 0 ? 0 : gScreenHeight - (this->rad * 2);
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
}

void Ball::Draw()
{
	ChangeColour(r, g, b);
	DrawCircle(position.X, position.Y, rad);
}

char Ball::GetRed() { return r; }
char Ball::GetGreen() { return g; }
char Ball::GetBlue() { return b; }

void hsv(int h, float s, float v, float& r, float& g, float& b)
{
	float h2 = h / (float)60;
	float c = v * s;

	float x = c * (1 - abs(fmod(h2, 2) - 1));

	if (h2 >= 0 && h2 < 1) { r = c; g = x; b = 0; }
	if (h2 >= 1 && h2 < 2) { r = x; g = c; b = 0; }
	if (h2 >= 2 && h2 < 3) { r = 0; g = c; b = x; }
	if (h2 >= 3 && h2 < 4) { r = 0; g = x; b = c; }
	if (h2 >= 4 && h2 < 5) { r = x; g = 0; b = c; }
	if (h2 >= 5 && h2 < 6) { r = c; g = 0; b = x; }

	float m = v - c;
	r += m;
	g += m;
	b += m;
}
