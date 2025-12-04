
#include "Framework.h"
#include <random>
#include "Circle.h"

void Circle::Draw() const
{
	DrawCircle(position.X, position.Y, size);
}

float Circle::GetXLength() const
{
	return (this->size * 2);
}

float Circle::GetYLength() const
{
	return (this->size * 2);
}

int Circle::RandomSize() const
{
	return (rand() % 30) + 10;
}
