#pragma once
#include "Sketch/Sketch.h"

class Operation
{
public:
	virtual bool IsEligible(const Sketch& aSketch) const = 0;

	virtual void Perform(Sketch& aSketch) const = 0;
};

class HsvToRgbOperation : public Operation
{
	virtual bool IsEligible(const Sketch& aSketch) const;

	virtual void Perform(Sketch& aSketch) const;
};

