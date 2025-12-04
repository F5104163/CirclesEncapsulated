#include <math.h>
#include "Vector2.h"

Vector2::Vector2()
{
	this->X = 0;
	this->Y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->X = x;
	this->Y = y;
}

Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(X + other.X, Y + other.Y);
}

Vector2 Vector2::operator+(const float& other) const
{
	return Vector2(X + other, Y + other);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(X - other.X, Y - other.Y);
}

Vector2 Vector2::operator-(const float& other) const
{
	return Vector2(X - other, Y - other);
}

Vector2 Vector2::operator/(const float& other) const
{
	return Vector2(X / other, Y / other);
}

Vector2 Vector2::operator*(const float other) const
{
	return Vector2(X * other, Y * other);
}

bool Vector2::operator==(const Vector2& other) const
{
	return X == other.X && Y == other.Y;
}

void Vector2::operator+=(const Vector2& other)
{
	X += other.X; Y += other.Y;
}

void Vector2::operator-=(const Vector2& other)
{
	X -= other.X; Y -= other.Y;
}

void Vector2::operator/=(const float& other)
{
	X /= other; Y /= other;
}

void Vector2::operator*=(const float& other)
{
	X *= other; Y *= other;
}

float Vector2::Magnitude() const
{
	return sqrt(pow(X,2) + pow(Y,2));
}

Vector2 Vector2::Normalised() const
{
	float mag = Magnitude();
	if (mag == 0) return Vector2(0, 0);
	return (*this) * (1.f / mag);
}
