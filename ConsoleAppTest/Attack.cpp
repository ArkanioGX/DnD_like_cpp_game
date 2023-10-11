#include "Attack.h"

Attack::Attack() {
	label = "Punch";
	weaponUsed = new Weapon();
	attDices = Dice();
	typeOfDamage = DamageType::Bludgeoning;
}

Attack::Attack(string n, Weapon *w, Dice dd, DamageType dt) {
	label = n;
	weaponUsed = w;
	attDices = dd;
	typeOfDamage = dt;
}

bool Attack::resolve(int d) { 
	int dice;
	srand(time(NULL)+rand());
	dice = (rand() % 20 + 1) + attDices.getBonus();

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

Dice Attack::getDices() {
	return attDices;
}

DamageType Attack::getDamageType() {
	return typeOfDamage;
}
