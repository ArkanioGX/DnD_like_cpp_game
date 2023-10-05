#pragma once
#include <string>
#include <array>
#include <stdlib.h>
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
	array<Weapon, 25> weaponLootTable =
	{ Weapon("Broken Sword", "What remain of a sword ",WeaponType::Sword,0.1,2,2),
		Weapon("The Ambassador", "Royal Sword that have been owned by the Old King ",WeaponType::Sword,2,15,50),
		Weapon("Sinister Diamond Katana", "Katana made in the deep caves with diamond ",WeaponType::Sword,5,25,150),
		Weapon("Willbreaker, Whisper of the Falling Sky", "Legendary sword ... nice ",WeaponType::Sword,5,55,1500),
		Weapon("A stick and a string ", "It can serve as a bow !!",WeaponType::Bow,0.2,2,3),
		Weapon("Final Whistle ", "A bow carved with magical wood that seems to enhance the arrows ",WeaponType::Bow,0.5,15,50),
		Weapon("Harbinger ", "Mechanically enhanced bow that can shoot faster and further ",WeaponType::Bow,3,25,150),
		Weapon("Phoenix, Bringer of the Immortal ", "Bow than can reborn from his ashes ",WeaponType::Bow,2,55,1500),
		Weapon("Little sharp stones ", "It can serve as daggers !!",WeaponType::Dagger,0.2,2,3),
		Weapon("Striker ", "Golden Daggers ",WeaponType::Dagger,0.5,15,50),
		Weapon("Nethersbane", "Hell infused blade with the tears of a demon ",WeaponType::Dagger,3,25,150),
		Weapon("Damnation", "A Daggers that could make a god bleed ",WeaponType::Dagger,2,55,1500),
		Weapon("An Oddly Shaped Stick ", "It can serve as a staff !!",WeaponType::Staff,0.2,2,3),
		Weapon("Lifebender", "Golden Daggers ",WeaponType::Staff,0.5,15,50),
		Weapon("Sunshard", "A powerful staff that can unleash a magma tsunami ",WeaponType::Staff,3,25,150),
		Weapon("Infinity, Betrayer of Necromancy", "Legends says this could reborn anybody ",WeaponType::Staff,2,55,1500),
		Weapon("Blunt Axe", "Better used as a Mace ",WeaponType::Axe,0.2,2,3),
		Weapon("Monsoon", "A crimson bladed axe",WeaponType::Axe,0.5,15,50),
		Weapon("Hope's Edge", "An axe able to cut through an entire forest",WeaponType::Axe,3,25,150),
		Weapon("Godslayer, Bond of Ended Dreams", "Able to cut through everything including gods and dimensions ",WeaponType::Axe,2,55,1500),
		Weapon("Stone on a stick", "Can be used as a spear ",WeaponType::Spear,0.2,2,3),
		Weapon("Eclipse", "a Spear with a crescent shaped blade",WeaponType::Spear,0.5,15,50),
		Weapon("Doom's Piercer", "Spear that legends said could pierce through the hell's gates",WeaponType::Spear,3,25,150),
		Weapon("Thunder Ivory Trident", "Emit the same energy as a god",WeaponType::Spear,2,55,1500),
		Weapon("RIZZ", "An impossible level of RIZZ",WeaponType::Sword,2,55,150000),
	};

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
	Character(string chfn, string chln, string chcp, CharacterClass chc, CharacterRace chr, Weapon chw);

	string getFirstName();
	string getLastName();
	string getCatchPhrase();

	

	CharacterClass getClass();
	CharacterRace getRace();

	unsigned int getMoney();
	void setMoney(int m);

	void Heal();

	void Loot();

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

