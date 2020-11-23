#pragma once
#include "Attribute/Attribute.h"
#include "Move/Move.h"

enum class EAttackRange
{
	Melee,
	Range
};

struct SElementalTypeAttribute : public SAttribute
{
	EElementalType ElementalType;
};

struct SAttackTypeAttribute : public SAttribute
{
	EAttackType AttackType;
};

struct SMoveNameAttribute : public SAttribute
{
	std::string MoveName;
};

struct SAttackPowerAttribute : public SAttribute
{
	int AttackPower = 0;
};

struct SMoveAccuracyAttribute : public SAttribute
{
	int Accuracy = 100;
};

struct SPowerPointsAttribute : public SAttribute
{
	int PowerPoints = 30;
};

struct SMoveStrengthAttribute : public SAttribute
{
	//0 = no effect
	//100 = OP
	int MoveStrength = 50;
};

struct SAttackRange : public SAttribute
{
	EAttackRange AttackRange = EAttackRange::Melee;
};









































