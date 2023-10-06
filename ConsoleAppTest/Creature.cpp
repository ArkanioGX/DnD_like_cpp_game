
#include "Creature.h"

Creature::Creature() {
	cName = "Goblin thief";
	cDesc = "It wants your golds";
	cHP = 100;
	cMaxHP = 100;
	cDef = 5;
	cAttacks = vector<Attack>{ Attack("Stab",new Weapon(), 5, DamageType::Piercing, 0) };
}

Creature::Creature(string cn, string cd, unsigned int chp, unsigned int cmhp, unsigned int cde, vector<Attack> catt) {
	cName = cn;
	cDesc = cd;
	cHP = chp;
	cMaxHP = cmhp;
	cDef = cde;
	cAttacks = catt;
}

int Creature::getHP() {
	return cHP;
}

void Creature::setHP(unsigned int h) {
	cHP = h;
}

int Creature::getMaxHP() {
	return cMaxHP;
}

void Creature::heal(unsigned int n) {
	cHP = min(cMaxHP,cHP+n);
}

string Creature::getName() {
	return cName;
}
string Creature::getDesc() {
	return cDesc;
}

vector<Attack> Creature::getAttacks() {
	return cAttacks;
}

void Creature::setAttacks(vector<Attack> a) {
	cAttacks = a;
}

