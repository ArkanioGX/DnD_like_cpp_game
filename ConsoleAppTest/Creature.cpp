#include <iostream>
#include "Creature.h"

using namespace std;

Creature::Creature() {
	cName = "Goblin thief";
	cDesc = "It wants your golds";
	cHP = 100;
	cMaxHP = 100;
	cDef = 5;
	cAttacks = vector<Attack>{ Attack("Stab",new Weapon(), Dice(1,6,0), DamageType::Piercing)};
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
	cAttacks = vector<Attack>{ Attack("Punch",new Weapon(), Dice(1,3,0), DamageType::Bludgeoning)};
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

void Creature::attack(Creature* c, Attack a) { //Ability to attack another creature
	bool attackSuccess = a.resolve(c->getDef());
	if (attackSuccess) {
		vector<int> dmg;
		dmg = a.getDices().Roll();
		int dmgTotal = Dice::getRollTotal(dmg);
		cout << endl << cName << " used " << a.getLabel() << " and hit " << c->getName() << " for " << Dice::getRollString(dmg) << " HP " << endl;
		c->setHP(max(c->getHP() - dmgTotal,0));
		Weapon* w = a.getWeaponUsed();
		w->setWeaponDurabilty(max(w->getWeaponDurability() - 0.05,0.01));
	}
	else {
		cout << "Attack missed !" << endl;
	}
}

