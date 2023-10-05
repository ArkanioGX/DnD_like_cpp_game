#pragma once
#include <string>
#include "WeaponType.h"

using namespace std;

class Weapon
{
private:
	//Description of the weapon
	string weaponName;
	string weaponDesc;

	//Type of the weapon
	WeaponType weaponType;

	//Data of the weapon
	float weaponWeight;
	unsigned int weaponDamage;
	unsigned int weaponCost;
	float weaponDurability = 1;
public:
	Weapon();
	Weapon(string wn, string wde, WeaponType wt, float ww, unsigned int wdm, unsigned int wc);

	string getWeaponName();
	string getWeaponDesc();

	WeaponType getWeaponType();

	float getWeaponWeight();
	int getWeaponDamage();
	int getWeaponCost();
	float getWeaponDurability();
	void setWeaponDurabilty(float d);
};

