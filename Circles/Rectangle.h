#pragma once

#include "Shape.h"

class Rectangle : public Shape<Vector2>
{
public:
	virtual void Draw() const override;

protected:
	virtual float GetXLength() const override;
	virtual float GetYLength() const override;

	virtual Vector2 RandomSize() const override;
};