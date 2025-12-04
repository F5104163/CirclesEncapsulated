#include "Shape.h"
#include <random>

extern int gScreenWidth;
extern int gScreenHeight;

template<typename T>
Shape<T>::Shape() : position(Vector2(0,0)), size(0), r(255), g(255), b(255)
{

}

template<typename T>
Shape<T>::Shape(Vector2 position, T size, char r, char g, char b) : position(position), size(size), r(r), g(g), b(b)
{
}

template<typename T>
void Shape<T>::Draw() const
{
	// Nothing to draw since its an abstract class
}

template<typename T>
void Shape<T>::Tick()
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
}

template<typename T>
void Shape<T>::Randomise()
{
	size = RandomSize();
	velocity.X = rand() % 2 == 0 ? -1 : 1;
	velocity.Y = rand() % 2 == 0 ? -1 : 1;
	int rnd = (rand() % 4) + 1;
	velocity.X *= rnd;
	velocity.Y *= rnd;

	float r = 0, g = 0, b = 0;
	hsv(rand() % 360, 1, 1, r, g, b);
	r *= 255;
	g *= 255;
	b *= 255;

	this->r = r; this->g = g; this->b = b;

	position.X = rand() % (gScreenWidth - GetXLength()); position.Y = rand() % (gScreenHeight - GetYLength());
}

template<typename T>
void Shape<T>::hsv(int h, float s, float v, float& r, float& g, float& b) const
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

template<typename T>
float Shape<T>::GetXLength() const
{
	return 0.0f;
}

template<typename T>
float Shape<T>::GetYLength() const
{
	return 0.0f;
}

template<typename T>
T Shape<T>::RandomSize() const
{
	return T();
}
