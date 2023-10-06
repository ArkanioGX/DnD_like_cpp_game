#include "Attack.h"

Attack::Attack() {
	label = "Punch";
	damagePoints = 2;
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
	if (d <= (damagePoints+bonusDamage)) {
		return true;
	}
	else {
		return false;
	}
}
