#pragma once
#include "Sketch/Sketch.h"

class Operation
{
public:
	virtual bool IsEligible(const Sketch& aSketch) const = 0;

	virtual void Perform(Sketch& aSketch) const = 0;
};

class EmotionToHsv : public Operation
{
	virtual bool IsEligible(const Sketch& aSketch) const;

	virtual void Perform(Sketch& aSketch) const;
};


class HsvToRgbOperation : public Operation
{
	virtual bool IsEligible(const Sketch& aSketch) const;

	virtual void Perform(Sketch& aSketch) const;
};

class ColorToFinishedDesign : public Operation
{
	virtual bool IsEligible(const Sketch& aSketch) const;

	virtual void Perform(Sketch& aSketch) const;
};
