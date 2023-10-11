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

	//Get the names of the character
	string getFirstName();
	string getLastName();
	string getCatchPhrase();

	//Get the info of the character
	CharacterClass getClass();
	CharacterRace getRace();

	//Get and change the money variable
	unsigned int getMoney();
	void setMoney(int m);

	//Get and change the weapon used
	Weapon* getWeapon();
	void setWeapon(Weapon w);
	void swapWeapon(int i);
	
	//Get and add weapons in the inventory
	array<Weapon,5> getStoredWeapons();
	bool addStoredWeapons(Weapon w);

	//Function to buy and sell items
	bool Buy(Weapon w, Merchant* m);
	bool Sell(int i, Merchant* m);

	//open the inventory
	void listWeapons();

	//Engage in a interaction loop with the merchant
	void interactWithMerchant(Merchant* m);
};

