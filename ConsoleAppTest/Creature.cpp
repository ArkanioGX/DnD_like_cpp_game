
#include "Creature.h"

Creature::Creature() {
	cHP = 100;
	cMaxHP = 100;
	cDef = 5;
}

Creature::Creature(string cn, string cd, unsigned int chp, unsigned int cmhp, unsigned int cde) {
	cName = cn;
	cDesc = cd;
	cHP = chp;
	cMaxHP = cmhp;
	cDef = cde;
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

