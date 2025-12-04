
#include "Framework.h"
#include <random>
#include "Circle.h"

void Circle::Draw() const
{
	ChangeColour(r, g, b);
	DrawCircle(position.X, position.Y, size);
}

int Circle::GetXLength() const
{
	return (this->size * 2);
}

int Circle::GetYLength() const
{
	return (this->size * 2);
}

int Circle::RandomSize() const
{
	return (rand() % 30) + 10;
}
