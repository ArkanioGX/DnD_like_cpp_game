#include "Monster.h"

Monster::Monster() :Creature() {
	cLoot = Loot::getRandomLoot();
}

Monster::Monster(string cn, string cd, unsigned int chp, unsigned int cmhp, unsigned int cde) :Creature(cn,cd,chp,cmhp,cde) {
	cLoot = Loot::getRandomLoot();
}

Monster::Monster(string cn, string cd, unsigned int chp, unsigned int cmhp, unsigned int cde, Weapon l) :Creature(cn, cd, chp, cmhp, cde) {
	cLoot = l;
}

Weapon Monster::getLoot() {
	return cLoot;
}