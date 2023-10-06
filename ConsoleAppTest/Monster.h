#pragma once
#include "Creature.h"
#include "loot.h"
class Monster : public Creature
{
private:
	
	Weapon cLoot;

public:
	Monster();
	Monster(string cn, string cd, unsigned int chp, unsigned int cmhp, unsigned int cde);
	Monster(string cn, string cd, unsigned int chp, unsigned int cmhp, unsigned int cde, Weapon l);

	Weapon getLoot();
};

