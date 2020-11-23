#include "MoveOperation.h"
#include "Move/MoveAttribute.h"

bool MoveAttributesToFinishedDesign::IsEligible(const Sketch& aSketch) const
{
	return aSketch.ContainsAttribute<SElementalTypeAttribute>()
		&& aSketch.ContainsAttribute<SAttackTypeAttribute>()
		&& aSketch.ContainsAttribute<SMoveNameAttribute>()
		&& aSketch.ContainsAttribute<SAttackPowerAttribute>()
		&& aSketch.ContainsAttribute<SMoveAccuracyAttribute>()
		&& aSketch.ContainsAttribute<SPowerPointsAttribute>();
}

void MoveAttributesToFinishedDesign::Perform(Sketch& aSketch) const
{
	SDesignedObjectAttribute<SMove> finalized;
	finalized.FinishedDesign.ElementalType = aSketch.GetAttribute<SElementalTypeAttribute>()->ElementalType;
	finalized.FinishedDesign.AttackType = aSketch.GetAttribute<SAttackTypeAttribute>()->AttackType;
	finalized.FinishedDesign.Name = aSketch.GetAttribute<SMoveNameAttribute>()->MoveName;
	finalized.FinishedDesign.AttackPower = aSketch.GetAttribute<SAttackPowerAttribute>()->AttackPower;
	finalized.FinishedDesign.Accuracy = aSketch.GetAttribute<SMoveAccuracyAttribute>()->Accuracy;
	finalized.FinishedDesign.PowerPoints = aSketch.GetAttribute<SPowerPointsAttribute>()->PowerPoints;

	aSketch.AddAttribute<SDesignedObjectAttribute<SMove>>(std::move(finalized));
}
