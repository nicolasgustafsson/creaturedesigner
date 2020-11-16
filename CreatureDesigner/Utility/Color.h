#pragma once
#include <cmath>
struct SColor
{
	void SetFromHSV(float aHue, float aSaturation, float aValue)
	{
		//gets which 6th part of the colorWheel the color belongs to.
		int part = static_cast<int>(std::floor(aHue * 6));

		//Gets the offset from the part that the colorWheel belongs to
		//between the part and the next one.
		float deltaFromPart = aHue * 6.f - part;
		aValue *= 255;
		//what the fuck
		float p = aValue * (1.f - aSaturation);
		float q = aValue * (1.f - deltaFromPart * aSaturation);
		auto t = aValue * (1.f - (1.f - deltaFromPart) * aSaturation);
		//MATHS
		switch (part % 6)
		{
		case 0: R = static_cast<unsigned char>(aValue), G = static_cast<unsigned char>(t), B = static_cast<unsigned char>(p); break;
		case 1: R = static_cast<unsigned char>(q), G = static_cast<unsigned char>(aValue), B = static_cast<unsigned char>(p); break;
		case 2: R = static_cast<unsigned char>(p), G = static_cast<unsigned char>(aValue), B = static_cast<unsigned char>(t); break;
		case 3: R = static_cast<unsigned char>(p), G = static_cast<unsigned char>(q), B = static_cast<unsigned char>(aValue); break;
		case 4: R = static_cast<unsigned char>(t), G = static_cast<unsigned char>(p), B = static_cast<unsigned char>(aValue); break;
		case 5: R = static_cast<unsigned char>(aValue), G = static_cast<unsigned char>(p), B = static_cast<unsigned char>(q); break;
		}
	}

	float R, G, B;
};
