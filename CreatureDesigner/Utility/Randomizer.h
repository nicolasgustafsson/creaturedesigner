#pragma once
#include <random>

namespace Randomizer
{
	float GetRandomFloat()
	{
		return static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
	}
}