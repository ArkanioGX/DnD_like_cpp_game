#pragma once
#include <string>
#include <array>

#include <time.h>
#include "CharacterType.h"
#include "Weapon.h"
#include "Merchant.h"
#include "Creature.h"

using namespace std;

class Character : public Creature
{
private:

	const string CharacterClassString[6] = { "Archer", "Rogue", "Mage", "Knight","Barbarian","Lancer" };
	
	string chFirstName;
	string chLastName;
	string chCatchphrase;

	CharacterClass chClass;
	CharacterRace chRace;

	unsigned int chMoney = 0;
	
	Weapon chWeapon;
	array<Weapon,5> chStoredWeapons;

	int hasFreePlaces();

public:
	Character();
	Character(string chfn, string chln, string chcp, CharacterClass chc, CharacterRace chr, Weapon chw, vector<Attack> cha);

	string getFirstName();
	string getLastName();
	string getCatchPhrase();

	

	CharacterClass getClass();
	CharacterRace getRace();

	unsigned int getMoney();
	void setMoney(int m);

	Weapon* getWeapon();
	void setWeapon(Weapon w);
	void swapWeapon(int i);
	
	array<Weapon,5> getStoredWeapons();
	bool addStoredWeapons(Weapon w);

	bool Buy(Weapon w, Merchant* m);
	bool Sell(int i, Merchant* m);


	void listWeapons();

	void interactWithMerchant(Merchant* m);
};

