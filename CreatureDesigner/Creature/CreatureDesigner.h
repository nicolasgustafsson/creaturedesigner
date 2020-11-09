#pragma once
#include "Designer/Designer.h"
#include "Creature/Creature.h"

class CreatureDesigner : public Designer<Creature>
{
public:
	Creature Design(const Sketch& aSketch) const override;

};

