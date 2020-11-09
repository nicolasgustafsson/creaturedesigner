#include "Operation.h"
#include <iostream>

bool HsvToRgbOperation::IsEligible(const Sketch& aSketch) const
{
	return aSketch.ContainsAttribute<SColorAttributeHSV>();
}

void HsvToRgbOperation::Perform(Sketch& aSketch) const
{
	const SColorAttributeHSV* hsv = aSketch.GetAttribute<SColorAttributeHSV>();

	if (hsv)
	{
		std::cout << "we did the thing!" << std::endl;
	}
}
