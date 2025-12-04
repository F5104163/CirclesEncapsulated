#pragma once

#include <vector>
#include "Vector2.h"
#include "Shape.h"

template<typename T>
class Trail
{
public:
	Trail(int c);
	void Draw();
	
	void Tick(Shape<T>* parentElement);
private:
	int memoryCount = 10;
	std::vector<Vector2> memory;
};