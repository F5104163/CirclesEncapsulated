#include "Framework.h"
#include <random>
#include "Rectangle.h"

void Rectangle::Draw() const
{
	ChangeColour(r, g, b);
	DrawRectangle(position.X, position.Y, size.X, size.Y);
}

int Rectangle::GetXLength() const
{
	return roundf(size.X);
}

int Rectangle::GetYLength() const
{
	return roundf(size.Y);
}

Vector2 Rectangle::RandomSize() const
{
	return Vector2((rand() % 30 + 10), (rand() % 30 + 10));
}
