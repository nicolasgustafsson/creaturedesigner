#pragma once
#include "ElementalType.h"
#include <string>
#include <optional>

enum class EAttackType
{
	Physical,
	Special,
	Misc
};

struct SMove
{
public:
	EElementalType ElementalType = EElementalType::Normal;
	std::string Name = "Plackle";
	EAttackType AttackType = EAttackType::Physical;
	int AttackPower = 0;
	int Accuracy = 100;
	int PowerPoints = 30;
	/*Optional effect*/
};


/*Design moves
*   Figure out what move is supposed to be
*       Type
*       Name
*       Physical/Special/Misc
*       Atk Power(optional)
*       Accuracy
*       PP
*       Optional effect % (e.g poison)
*/
