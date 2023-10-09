#include "Monster.h"

Monster::Monster() :Creature() {
	cLoot = Loot::getRandomLoot();
}

Monster::Monster(string cn, string cd, unsigned int chp, unsigned int cde, vector<Attack> catt):Creature(cn,cd,chp,cde,catt) {
	cLoot = Loot::getRandomLoot();
}

Monster::Monster(string cn, string cd, unsigned int chp, unsigned int cde, Weapon l) :Creature(cn, cd, chp, cde) {
	cLoot = l;
}

Weapon Monster::getLoot() {
	return cLoot;
}