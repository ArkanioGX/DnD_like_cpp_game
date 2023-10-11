#pragma once
#include "Character.h"
#include <iostream>
class CharacterCreation
{
public:
	//Everything related to the creation of the player
	static CharacterRace changeRace(); 
	static CharacterClass changeClass();
	static Weapon getBaseClassWeapon(CharacterClass cc); //Get the weapon based on the class
	static string changeFirstName();
	static string changeLastName();
	static string changeCatchPhrase();
	static vector<Attack> getClassAttacks(CharacterClass cc, Weapon* w);//Get the attack based on the class
};

