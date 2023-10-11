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

	void attack(Creature* c, Attack a); //Attack a creature class object (like player or enemies)

	void heal(unsigned int n); //Heal the creature

	string getName(); //Get the name of tthe creature
	string getDesc(); //Get the description of the creature

	vector<Attack> getAttacks(); //Get the attacks available on this creature
	void setAttacks(vector<Attack> a); //Change the attacks on this creature

	int getHP(); //Get the remaining HP
	void setHP(unsigned int h); //Change the hp value
	int getMaxHP(); //Get the maximum hp value

	int getDef(); //Get the defense score
	void setDef(unsigned int d); //Change the defence score
};
