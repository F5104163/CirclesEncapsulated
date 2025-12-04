#pragma once

class Vector2
{
public:
	float X;
	float Y;

	Vector2();
	Vector2(float, float);

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator+(const float& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator-(const float& other) const;

	Vector2 operator/(const float& other) const;
	Vector2 operator*(const float other) const;

	bool operator==(const Vector2& other) const;
	
	void operator+=(const Vector2& other);
	void operator-=(const Vector2& other);
	void operator/=(const float& other);
	void operator*=(const float& other);

	float Magnitude() const;
	Vector2 Normalised() const;
};