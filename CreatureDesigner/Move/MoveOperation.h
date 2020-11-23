#pragma once
#include "Operation/Operation.h"

class MoveAttributesToFinishedDesign : public Operation
{
	virtual bool IsEligible(const Sketch& aSketch) const;

	virtual void Perform(Sketch& aSketch) const;
};
