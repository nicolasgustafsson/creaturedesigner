#pragma once
#include "Designers/Designer.h"
#include <string>

struct ColorDescriptor;

class ColorDesigner : public Designer<std::string>
{
public:
	std::string Design(const Blueprint& aBlueprint) override;

private:
	virtual void HandleAttribute(BaseAttribute& aAttribute) override;
	void HandleAttribute(ColorDescriptor& aAttribute);

};

