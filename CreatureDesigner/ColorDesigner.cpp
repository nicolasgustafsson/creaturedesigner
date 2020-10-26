#include "ColorDesigner.h"
#include <variant>
#include <iostream>
#include "Attributes/Attributes.h"

std::string ColorDesigner::Design(const Blueprint& aBlueprint)
{	
	for (auto&& attribute : aBlueprint.myAttributes)
	{
		// convert base class to implementation
		attribute->ResolveDesigner(*this);
	}
	return "totes not brown";
}

void ColorDesigner::HandleAttribute(BaseAttribute& aAttribute)
{
	std::cout << "bruh" << std::endl;
}

void ColorDesigner::HandleAttribute(ColorDescriptor& aAttribute)
{
	std::cout << "yeet" << std::endl;
}
