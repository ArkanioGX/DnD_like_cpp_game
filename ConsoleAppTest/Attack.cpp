#include "Attack.h"

Attack::Attack() {
	label = "Punch";
	weaponUsed = new Weapon();
	damagePoints = 2;
	typeOfDamage = DamageType::Bludgeoning;
	bonusDamage = 0;
}

Attack::Attack(string n, Weapon *w, unsigned int dp, DamageType dt, unsigned int bd) {
	label = n;
	weaponUsed = w;
	damagePoints = dp;
	typeOfDamage = dt;
	bonusDamage = bd;
}

bool Attack::resolve(int d) {
	int dice;
	srand(time(NULL)+rand());
	dice = (rand() % 20 + 1) + bonusDamage;

	return (dice >= d);
}

string Attack::getLabel() {
	return label;
}

Weapon* Attack::getWeaponUsed() {
	return weaponUsed;
}

void Attack::setWeaponUsed(Weapon* w) {
	weaponUsed = w;
}

unsigned int Attack::getDamagePoints() {
	return damagePoints;
}

DamageType Attack::getDamageType() {
	return typeOfDamage;
}

unsigned int Attack::getBonusDamage() {
	return bonusDamage;
}
