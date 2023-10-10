#pragma once
#include <time.h>
#include <stdlib.h>
#include "Weapon.h"
#include "DamageType.h"
#include "Dice.h"


class Attack
{
private:
	string label;

	Weapon* weaponUsed;

	Dice attDices;

	DamageType typeOfDamage;

public:
	Attack();
	Attack(string n, Weapon *w, Dice dd, DamageType dt);
	bool resolve(int d);

	string getLabel();

	Weapon* getWeaponUsed();
	void setWeaponUsed(Weapon* w);

	Dice getDices();

	DamageType getDamageType();

};

