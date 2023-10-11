#pragma once
#include "Creature.h"
#include "loot.h"
class Monster : public Creature
{
private:
	
	Weapon cLoot;

public:
	Monster();
	Monster(string cn, string cd, unsigned int chp, unsigned int cde, vector<Attack> catt);
	Monster(string cn, string cd, unsigned int chp, unsigned int cde, Weapon l);

	//Get a random weapon from the loot class
	Weapon getLoot();
};

