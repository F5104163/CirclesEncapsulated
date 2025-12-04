#include "Framework.h"
#include <random>
#include "Rectangle.h"

void Rectangle::Draw() const
{
	DrawRectangle(position.X, position.Y, size.X, size.Y);
}

float Rectangle::GetXLength() const
{
	return size.X;
}

float Rectangle::GetYLength() const
{
	return size.Y;
}

Vector2 Rectangle::RandomSize() const
{
	return Vector2((rand() % 30 + 10), (rand() % 30 + 10));
}
