#pragma once
#include "Utility/Color.h"
#include <optional>

enum class EEmotion
{
	Angry,
	Sad,
	Happy
};

//base class?
//or something else
struct SAttribute
{
	SAttribute() = default;
	virtual ~SAttribute() = default;
	//Describes idea
};

struct SEmotionAttribute : public SAttribute
{
	EEmotion Emotion;
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

template<typename TDesignedObject>
struct SDesignedObjectAttribute : public SAttribute
{
	TDesignedObject FinishedDesign;
};