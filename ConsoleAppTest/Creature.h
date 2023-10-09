#pragma once
#include<string>
#include<vector>

#include "Attack.h"

using namespace std;

class Creature
{
private:
	string cName;
	string cDesc;

	unsigned int cHP;
	unsigned int cMaxHP;

	vector<Attack> cAttacks;

	unsigned int cDef;

public:
	Creature();
	Creature(string cn, string cd, unsigned int chp, unsigned int cde, vector<Attack> catt);
	Creature(string cn, string cd, unsigned int chp, unsigned int cde);

	void attack(Creature* c, Attack a);

	void heal(unsigned int n);

	string getName();
	string getDesc();

	vector<Attack> getAttacks();
	void setAttacks(vector<Attack> a);

	int getHP();
	void setHP(unsigned int h);
	int getMaxHP();

	int getDef();
	void setDef(unsigned int d);
};
