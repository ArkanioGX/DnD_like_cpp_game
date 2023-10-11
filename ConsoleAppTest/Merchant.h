#pragma once
#include <string>
#include <iostream>
#include "Weapon.h"
#include <array>

using namespace std;

class Merchant
{
private:
	string mName;
	string mDesc;
	string mCatchPhrase;

	unsigned int mMoney;

	array<Weapon,6> mWeaponInventory;
public:
	Merchant(string n, string d, string cp , unsigned int m, array<Weapon,6> wl);

	//Get the names, desc
	string getName();
	string getDesc();
	string getCatchPhrase();

	//Get and change the money value
	unsigned int getMoney();
	void setMoney(unsigned int m);

	//Get the weapon sold by the merchant
	array<Weapon,6> getWeaponInventory();

	//Checks if it can buy a weapon
	bool canBuy(Weapon w);
};

