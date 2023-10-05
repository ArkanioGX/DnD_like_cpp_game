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

	string getName();
	string getDesc();
	string getCatchPhrase();

	unsigned int getMoney();
	void setMoney(unsigned int m);

	array<Weapon,6> getWeaponInventory();

	bool canBuy(Weapon w);
};

