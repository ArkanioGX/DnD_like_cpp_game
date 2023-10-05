#include "Weapon.h"
Weapon::Weapon() {
	weaponName = "None";
	weaponDesc = "Still no weapon";
	weaponType = WeaponType::None;
	weaponWeight = 0;
	weaponDamage = 5;
	weaponCost = 0;
}

Weapon::Weapon(string wn, string wde, WeaponType wt, float ww, unsigned int wdm, unsigned int wc) {
	weaponName = wn;
	weaponDesc = wde;
	weaponType = wt;
	weaponWeight = ww;
	weaponDamage = wdm;
	weaponCost = wc;
};

string Weapon::getWeaponName() { return weaponName; };
string Weapon::getWeaponDesc() { return weaponDesc; };

WeaponType Weapon::getWeaponType() { return weaponType; };

float Weapon::getWeaponWeight() { return weaponWeight; };
int Weapon::getWeaponDamage() { return weaponDamage; };
int Weapon::getWeaponCost() { return weaponCost; };
float Weapon::getWeaponDurability() { return weaponDurability; };
void Weapon::setWeaponDurabilty(float d) { weaponDurability = d; };
