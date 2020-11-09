#pragma once
#include "Utility/Color.h"
#include <optional>

//base class?
//or something else
struct SAttribute
{
	virtual ~SAttribute() = default;
	//Describes idea
};

struct SColorAttributeHSV : public SAttribute
{
	std::optional<float> Hue = 0.f;
	std::optional<float> Saturation = 0.f;
	std::optional<float> Value = 0.f;
};

struct SColorAttribute : public SAttribute
{
	SColor Color;
};