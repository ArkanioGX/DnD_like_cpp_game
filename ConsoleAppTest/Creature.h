
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

	vector<Attack> cAttacks;

	unsigned int cDef;

public:
	Creature();
	Creature(string cn, string cd, unsigned int chp, vector<Attack> catt, unsigned int cde);

	void Attack(Creature c);

	void Heal(unsigned int n);

	string getName();
	string getDesc();

	virtual unsigned int getHP();
	void setHP(unsigned int h);

	virtual unsigned int getDef();
	void setDef(unsigned int d);
};
