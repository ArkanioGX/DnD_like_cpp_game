#pragma once
#include "Weapon.h"
#include "DamageType.h"

class Attack
{
private:
	string label;

	Weapon weaponUsed;

	unsigned int damagePoints;

	DamageType typeOfDamage;

	unsigned int bonusDamage;

public:
	bool Resolve();
};

