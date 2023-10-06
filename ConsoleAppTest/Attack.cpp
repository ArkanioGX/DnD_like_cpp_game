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
	srand(time(NULL));
	dice = (rand() % 20 + 1) + bonusDamage;

	if (dice >= d) {
		return true;
	}
	else {
		return false;
	}
}
