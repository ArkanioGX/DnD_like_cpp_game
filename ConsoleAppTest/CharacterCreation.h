#pragma once
#include "Character.h"
#include <iostream>
class CharacterCreation
{
public:
	static CharacterRace changeRace();
	static CharacterClass changeClass();
	static Weapon getBaseClassWeapon(CharacterClass cc);
	static string changeFirstName();
	static string changeLastName();
	static string changeCatchPhrase();
	static vector<Attack> getClassAttacks(CharacterClass cc, Weapon* w);
};

