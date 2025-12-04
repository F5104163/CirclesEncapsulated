#pragma once

#include "Shape.h"

class Circle : public Shape<int>
{
public:
	void Draw() const override;

protected:
	int GetXLength() const override;
	int GetYLength() const override;

	int RandomSize() const override;
};