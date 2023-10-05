#include "Loot.h"

Weapon Loot::getRandomLoot() {
	int rdmID;
	srand(time(NULL));
	rdmID = rand() % 25;
	return weaponLootTable[rdmID];
}
