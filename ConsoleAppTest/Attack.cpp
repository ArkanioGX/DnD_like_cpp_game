#include "Attack.h"

Attack::Attack() {
	label = "Punch";
	damagePoints = weaponUsed->getWeaponDamage();
	typeOfDamage = DamageType::Bludgeoning;
	bonusDamage = 2;
}

Attack::Attack(string n, Weapon *w, unsigned int dp, DamageType dt, unsigned int bd) {
	label = n;
	weaponUsed = w;
	damagePoints = dp;
	typeOfDamage = dt;
	bonusDamage = bd;
}

bool Attack::resolve(int d) {
	return true;
}
