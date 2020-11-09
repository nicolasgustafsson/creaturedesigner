#include "CreatureDesigner.h"
#include "Utility/UtilityDesigners/ColorDesigner.h"

Creature CreatureDesigner::Design(const Sketch& aSketch) const
{
	ColorDesigner colorDesigner;

	Creature creature;
	creature.myColor = colorDesigner.Design(aSketch);

	return creature;
}
