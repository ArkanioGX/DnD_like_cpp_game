#pragma once
#include "Weapon.h"
#include "DamageType.h"


class Attack
{
private:
	string label;

	Weapon* weaponUsed;

	unsigned int damagePoints;

	DamageType typeOfDamage;

	unsigned int bonusDamage;

public:
	Attack();
	Attack(string n, Weapon *w, unsigned int dp, DamageType dt, unsigned int bd);
	bool resolve(int d);
};

