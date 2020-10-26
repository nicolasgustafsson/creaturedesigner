#pragma once
#include <string>
#include "Designer.h"
#include <array>

class Creature
{
public:
	std::string myColor;
};

class CreatureDesigner : public Designer<Creature>
{
public:
	virtual Creature Design(const Blueprint& aBlueprint) override;
};

