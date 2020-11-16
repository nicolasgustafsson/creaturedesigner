#include "Operation.h"
#include <iostream>
#include <cassert>
#include "Utility/Randomizer.h"

bool HsvToRgbOperation::IsEligible(const Sketch& aSketch) const
{
	return aSketch.ContainsAttribute<SColorAttributeHSV>();
}

void HsvToRgbOperation::Perform(Sketch& aSketch) const
{
	auto hsv = aSketch.GetAttribute<SColorAttributeHSV>();

	SColor color;
	color.SetFromHSV(hsv->Hue.value_or(Randomizer::GetRandomFloat() * 360.f), hsv->Saturation.value_or(Randomizer::GetRandomFloat()), hsv->Value.value_or(Randomizer::GetRandomFloat()));
	
	SColorAttribute attrib;
	attrib.Color = color;

	if (hsv)
		aSketch.AddAttribute<SColorAttribute>(attrib);
}

bool ColorToFinishedDesign::IsEligible(const Sketch& aSketch) const
{
	return aSketch.ContainsAttribute<SColorAttribute>();
}

void ColorToFinishedDesign::Perform(Sketch& aSketch) const
{
	auto color = aSketch.GetAttribute<SColorAttribute>();

	if (!color)
	{
		//todo: proper error management
		assert(false);
		return;
	}

	SDesignedObjectAttribute<SColor> finalized;
	finalized.FinishedDesign = color->Color;
	aSketch.AddAttribute<SDesignedObjectAttribute<SColor>>(finalized);
}

bool EmotionToHsv::IsEligible(const Sketch& aSketch) const
{
	return aSketch.ContainsAttribute<SEmotionAttribute>();
}

void EmotionToHsv::Perform(Sketch& aSketch) const
{
	auto emotionAttribute = aSketch.GetAttribute<SEmotionAttribute>();

	if (!emotionAttribute)
	{
		assert(false);
		return;
	}
	SColorAttributeHSV hsv;

	switch (emotionAttribute->Emotion)
	{
	case EEmotion::Angry:
		hsv.Hue = 0.f;
		hsv.Saturation = 0.5f + (Randomizer::GetRandomFloat() * 0.5f);
		hsv.Value = Randomizer::GetRandomFloat();
		break;
	case EEmotion::Happy:
		hsv.Hue = 120.f;
		hsv.Saturation = 0.5f + (Randomizer::GetRandomFloat() * 0.5f);
		hsv.Value = Randomizer::GetRandomFloat();
		break;
	case EEmotion::Sad:
		hsv.Hue = Randomizer::GetRandomFloat() * 360.f;
		hsv.Saturation = 0.1f;
		hsv.Value = 0.5f;
		break;
	}
	aSketch.AddAttribute<SColorAttributeHSV>(hsv);
}
