#pragma once
#include <vector>
#include <optional>
#include <memory>
#include "../Designers/Designer.h"


struct BaseAttribute
{
	//can be anything???
	//fire, sad, 5000 power?

	virtual ~BaseAttribute() = default;

	virtual void ResolveDesigner(BaseDesigner& aDesigner) = 0;
};

template<typename T>
struct Attribute : public BaseAttribute
{
	//Attribute() = default;
	//Attribute(Attribute&&) = default;
	//Attribute& operator=(Attribute&&) = default;

	virtual void ResolveDesigner(BaseDesigner& aDesigner) override
	{
		aDesigner.HandleAttribute(*this);
	}
};

enum class ColorType
{
	SadColor,
	MixedColor,
	Monochromatic
};

struct ColorDescriptor : public Attribute<ColorDescriptor>
{
	ColorType Descriptor;
};

class Blueprint
{
public:
	std::vector<std::unique_ptr<BaseAttribute>> myAttributes;
};