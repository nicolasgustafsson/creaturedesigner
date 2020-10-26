#include "CreatureDesigner.h"
#include "../ColorDesigner.h"

Creature CreatureDesigner::Design(const Blueprint& aBlueprint)
{	
	Creature bajs;
	
	ColorDesigner designer;
	bajs.myColor = designer.Design(aBlueprint);

	return bajs;
}
