#include <iostream>
#include "Creature.h"

using namespace std;

Creature::Creature() {
	cName = "Goblin thief";
	cDesc = "It wants your golds";
	cHP = 100;
	cMaxHP = 100;
	cDef = 5;
	cAttacks = vector<Attack>{ Attack("Stab",new Weapon(), 5, DamageType::Piercing, 0) };
}

Creature::Creature(string cn, string cd, unsigned int chp, unsigned int cde, vector<Attack> catt) {
	cName = cn;
	cDesc = cd;
	cHP = chp;
	cMaxHP = chp;
	cDef = cde;
	cAttacks = catt;
}

Creature::Creature(string cn, string cd, unsigned int chp, unsigned int cde) {
	cName = cn;
	cDesc = cd;
	cHP = chp;
	cMaxHP = chp;
	cDef = cde;
	cAttacks = vector<Attack>{ Attack("Punch",new Weapon(), 2, DamageType::Bludgeoning, 0) };
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

int Creature::getDef() {
	return cDef;
}

void Creature::setDef(unsigned int d) {
	cDef = d;
}   

void Creature::attack(Creature* c, Attack a) {
	bool attackSuccess = a.resolve(c->getDef());
	if (attackSuccess) {
		int dmg = a.getDamagePoints() + a.getBonusDamage() ;
		cout << endl << cName << " used " << a.getLabel() << " and hit " << c->getName() << " for " << dmg << " HP " << endl;
		c->setHP(max(c->getHP() - dmg,0));
	}
	else {
		cout << "Attack missed !" << endl;
	}
}

