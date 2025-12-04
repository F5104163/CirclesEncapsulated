#pragma once

#include "Shape.h"

class Rectangle : public Shape<Vector2>
{
public:
	void Draw() const override;

protected:
	int GetXLength() const override;
	int GetYLength() const override;

	Vector2 RandomSize() const override;
};