#include "CreatureDesigner.h"
#include "Utility/UtilityDesigners/ColorDesigner.h"
#include "Move/MoveDesigner.h"
#include "Move/MoveAttribute.h"

Creature CreatureDesigner::Design(const Sketch& aSketch) const
{
	ColorDesigner colorDesigner;
	MoveDesigner moveDesigner;

	Creature creature;

	Sketch moveSketch;

	SElementalTypeAttribute elementalAttr;
	elementalAttr.ElementalType = EElementalType::Dark;
	moveSketch.AddAttribute(elementalAttr);

	SAttackTypeAttribute attackTypeAttr;
	attackTypeAttr.AttackType = EAttackType::Physical;
	moveSketch.AddAttribute(attackTypeAttr);

	//SAttackPowerAttribute attackPowerAttr;
	//attackPowerAttr.AttackPower = 15 + 2;
	//moveSketch.AddAttribute(attackPowerAttr);

	SMoveNameAttribute moveNameAttr;
	moveNameAttr.MoveName = "Cry In Frustration";
	moveSketch.AddAttribute(moveNameAttr);

	SMoveAccuracyAttribute accuracyAttr;
	accuracyAttr.Accuracy = 15 + 3;
	moveSketch.AddAttribute(accuracyAttr);

	SPowerPointsAttribute powerPointsAttr;
	powerPointsAttr.PowerPoints = 15 + 4;
	moveSketch.AddAttribute(powerPointsAttr);

	SMoveStrengthAttribute moveStrengthAttr;
	moveStrengthAttr.MoveStrength = 50;
	moveSketch.AddAttribute(moveStrengthAttr);

	creature.myOnlyMove = moveDesigner.Design(moveSketch);
	creature.myColor = colorDesigner.Design(aSketch);

	return creature;
}
