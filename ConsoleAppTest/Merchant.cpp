#include "Merchant.h"

Merchant::Merchant(string n, string d, string cp, unsigned int m, array<Weapon, 6> wl) {
	mName = n;
	mDesc = d;
	mCatchPhrase = cp;
	mMoney = m;
	mWeaponInventory = wl;
}

string Merchant::getName() { return mName; }
string Merchant::getDesc() { return mDesc; }
string Merchant::getCatchPhrase() { return mCatchPhrase; }

unsigned int Merchant::getMoney() { return mMoney; }
void Merchant::setMoney(unsigned int m) { mMoney = m; }

array<Weapon, 6> Merchant::getWeaponInventory() { return mWeaponInventory; }

bool Merchant::canBuy(Weapon w){ //Check if the merchant have enough money to buy the weapon
	return ((w.getWeaponCost() * w.getWeaponDurability()) <= mMoney);
}

