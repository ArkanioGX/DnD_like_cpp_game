#include "Character.h"
#include <iostream>

Character::Character():Creature() {
	chFirstName = "Arnold";
	chLastName = "Noobius";
	chCatchphrase = "I am Arnold Noobius from the caves of Hello World !";
	chClass = CharacterClass::Knight;
	chRace = CharacterRace::Gobelin;
}
Character::Character(string chfn, string chln, string chcp, CharacterClass chc, CharacterRace chr, Weapon chw, vector<Attack> cha):Creature(chfn,chcp,100,5, cha)
{
	chFirstName = chfn;
	chLastName = chln;
	chCatchphrase = chcp;
	chClass = chc;
	chRace = chr;
	chWeapon = chw;
};

string Character::getFirstName() { return chFirstName; };
string Character::getLastName() { return chLastName; };
string Character::getCatchPhrase() { return chCatchphrase; };

CharacterClass Character::getClass() { return chClass; };
CharacterRace Character::getRace() { return chRace; };

unsigned int Character::getMoney() { return chMoney; };
void Character::setMoney(int m) { chMoney = m; };

Weapon* Character::getWeapon() { return &chWeapon; };
void Character::setWeapon(Weapon w) { chWeapon = w; };
void Character::swapWeapon(int i) { //swap the weapon used with a weapon in the inventory
	if (chStoredWeapons[i].getWeaponType() == chClass) {
		Weapon tempWeapon = chWeapon;
		chWeapon = chStoredWeapons[i];
		chStoredWeapons[i] = tempWeapon;
		cout << chWeapon.getWeaponName() + " Equipped" << endl;

		vector<Attack> att;
		for (int i = 0; i < getAttacks().size(); i++) { //Change the weapon on the attacks
			Attack a = getAttacks()[i];
			a.setWeaponUsed(&chWeapon);
			att.push_back(a);
		}

		setAttacks(att);
	}
	else {
		cout << "\n\n /!\\ " << chStoredWeapons[i].getWeaponName() + " not Equipped (Might be a weapon type different from your class) /!\\" << endl;
	}
};


array<Weapon,5> Character::getStoredWeapons() { return chStoredWeapons; };

bool Character::addStoredWeapons(Weapon w) {  //Give the player a weapon in the inventory
	for (int i = 0; i < 5; i++) {
		if (chStoredWeapons[i].getWeaponType() == WeaponType::None) {
			chStoredWeapons[i] = w;
			cout << "Weapon Given - " + w.getWeaponName() << endl;
			return true;
		}
	} 
	cout << "Inventory Full" << endl;
	return false;
};

bool Character::Buy(Weapon w, Merchant* m) { //Ability to buy 
	if (w.getWeaponCost() * w.getWeaponDurability() <= chMoney && hasFreePlaces() != 5) {
		chStoredWeapons[hasFreePlaces()] = w;
		int price = w.getWeaponCost() * (0.2+w.getWeaponDurability());
		chMoney -= price;
		m->setMoney(m->getMoney() + price);
		return true;
	}
	return false;
};
bool Character::Sell(int i, Merchant* m) { //Ability to sell
	Weapon w = chStoredWeapons[i];
	int price = w.getWeaponCost() * w.getWeaponDurability();
	if (w.getWeaponType() != WeaponType::None && m->getMoney() >= price) {
		chMoney += price;
		chStoredWeapons[i] = Weapon();
		m->setMoney(m->getMoney() - price);
		return true;
	}
	return false;
};

int Character::hasFreePlaces() { //Check if the inventory can take one more weapon
	int i = 0;
	while (i < 5) {
		if (chStoredWeapons[i].getWeaponType() == WeaponType::None) {
			return i;
		}
		i++;
	}
	return i;
}

void Character::listWeapons(){ //Output the inventory
	cout << endl << "=================================================================================" << endl
		<< "Inventory" << endl
		<< "=================================================================================\n\n";
	cout << endl << "Money : " << chMoney << " | HP : " << getHP() << endl;
	cout << "Weapons List : " << endl;
	Weapon w = chWeapon;
	cout << endl << "Weapons Equipped : "<< endl 
		 << "X | " << w.getWeaponName() << " - " << (w.getWeaponCost() * w.getWeaponDurability()) << "$ (" << w.getWeaponDurability() * 100 << "%)" << endl
	    << "		Damage - " << w.getWeaponDamage() << " | Class Required : " << CharacterClassString[w.getWeaponType()] << endl
		<< "		Description - " << w.getWeaponDesc() << endl;
	cout << "Weapons Stored : " << endl;
	for (int i = 0; i < 5; i++) {
		w = chStoredWeapons[i];
		if (w.getWeaponType() != WeaponType::None) {
			cout << i << " | " << w.getWeaponName() << " - " << (w.getWeaponCost() * w.getWeaponDurability()) << "$ (" << w.getWeaponDurability() * 100 << "%)" << endl;
			cout << "		Damage - " << w.getWeaponDamage() << " | Class Required : " << CharacterClassString[w.getWeaponType()] << endl
				<< "		Description - " << w.getWeaponDesc() << endl;
		}
	}
}

void Character::interactWithMerchant(Merchant* m) { //Engage in a loop with the merchant
	int answer, choice;
	
	do {
		cout << endl << "=================================================================================" << endl;
		cout << m->getCatchPhrase();
		cout << endl << "=================================================================================" << endl;
		cout << "What would you like to do ? " << endl
			<< "0 - Buy Weapons" << endl
			<< "1 - Sell Weapons" << endl
			<< "9 - Quit " << endl;
		cin >> answer;
		switch (answer)
		{
		case 0:
			
			do {
				cout << endl << "=================================================================================" << endl;
				cout << "Choose a weapon to buy ( Your Money : " << chMoney <<"$ | Merchant Money : " << m->getMoney() << "$ )";
				cout << endl << "=================================================================================" << "\n\n";
				for (int i = 0; i < 6 ; i++)
				{
					Weapon w = m->getWeaponInventory()[i];
					cout << i << "- " << w.getWeaponName() << " - " << (w.getWeaponCost() * (0.2+w.getWeaponDurability())) << "$ (" << w.getWeaponDurability()*100 <<"%)" << endl;
					cout << "		Damage - " << w.getWeaponDamage() << " | Class Required : " << CharacterClassString[w.getWeaponType()] << endl
						<< "		Description - " << w.getWeaponDesc() << endl;
						
				}
				cout << endl << "9 - Cancel " << endl;
				cin >> choice;
				if (choice <= 5 && choice >= 0) {
					Weapon w = m->getWeaponInventory()[choice];
					if (Buy(w, m)) {
						cout << "You succesfully bought " << w.getWeaponName();
					}
					else {
						cout << "Error buying the item ";
					}
				}
				else if (choice != 9) { cout << "[Invalid INPUT]"; }
			} while (choice != 9);
			break;
		case 1:
			do {
				cout << endl << "=================================================================================" << endl;
				cout << "Choose a weapon to sell ( Your Money : " << chMoney << "$ | Merchant Money : " << m->getMoney() << "$ )";
				cout << endl << "=================================================================================" << "\n\n";
				bool haveAWeapon = false;
				for (int i = 0; i < 5; i++)
				{
					Weapon w = chStoredWeapons[i];
					if (w.getWeaponType() != WeaponType::None) {
						cout << i << "- " << w.getWeaponName() << " - " << (w.getWeaponCost() * w.getWeaponDurability()) << "$ (" << w.getWeaponDurability() * 100 << "%)" << endl;
						cout << "		Damage - " << w.getWeaponDamage() << " | Class Required : " << CharacterClassString[w.getWeaponType()] << endl
							<< "		Description - " << w.getWeaponDesc() << endl;
						haveAWeapon = true;
					}
				}
				if (!haveAWeapon) { cout << "No Weapons to sell !!"; }
				cout << endl << "9 - Cancel " << endl;
				cin >> choice;
				
				if (choice <= 4 && choice >= 0) {
					Weapon w = chStoredWeapons[choice];
					if (Sell(choice, m)) {
						cout << "You succesfully sold " << w.getWeaponName();
					}
					else {
						cout << "Error selling the item ";
					}
				}
				else if (choice != 9) { cout << "[Invalid INPUT]"; }
			} while (choice != 9);
			break;
		case 9:
			cout << "Goodbye !" << endl;
			break;
		default:
			cout << "[INVALID ANSWER]" << endl;
			break;
		}
	} while (answer != 9);
	
}
