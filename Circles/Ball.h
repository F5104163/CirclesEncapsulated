#pragma once

#include "Vector2.h"

class Ball
{
public:
	Ball();
	Ball(int rad, Vector2 position, Vector2 velocity, unsigned char r, unsigned char g, unsigned char b);

	void Randomise();

	void Update();

	void Draw();

	char GetRed();
	char GetGreen();
	char GetBlue();

private:
	int rad;

	Vector2 position;
	Vector2 velocity;

	unsigned char r;
	unsigned char g;
	unsigned char b;
};