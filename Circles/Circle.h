#pragma once

#include "Shape.h"

class Circle : public Shape<int>
{
public:
	virtual void Draw() const override;

protected:
	virtual float GetXLength() const override;
	virtual float GetYLength() const override;

	virtual int RandomSize() const override;
};