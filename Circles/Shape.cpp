#include "Shape.h"
#include <random>
#include "Framework.h"

extern int gScreenWidth;
extern int gScreenHeight;

template class Shape<Vector2>;
template class Shape<float>;
template class Shape<int>;

template<typename T>
Shape<T>::Shape() : position(Vector2(0, 0)), size(T{}), r(255), g(255), b(255), myTrail(Trail<T>(10))
{

}

template<typename T>
Shape<T>::Shape(Vector2 position, T size, char r, char g, char b) : position(position), size(size), r(r), g(g), b(b), myTrail(Trail<T>(10))
{

}

template<typename T>
void Shape<T>::Draw() const
{
	// ChangeColour(r,g,b);
	// Nothing to draw since its an abstract class
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
int Shape<T>::GetXLength() const
{
	return 0.0f;
}

template<typename T>
int Shape<T>::GetYLength() const
{
	return 0.0f;
}

template<typename T>
T Shape<T>::RandomSize() const
{
	return T{};
}
