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
	bool resolve(int d); //Check if the attacks misses or not

	string getLabel(); //Get the name of the attack

	Weapon* getWeaponUsed(); //Get the weapon used (used to reduce the durability of the weapon)
	void setWeaponUsed(Weapon* w); //Change the weapon used on the attack

	Dice getDices(); //Get the dice class to determine the damage

	DamageType getDamageType(); //Get the type of damage

};

