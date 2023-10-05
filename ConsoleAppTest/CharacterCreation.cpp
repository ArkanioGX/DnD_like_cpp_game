#include "CharacterCreation.h"


CharacterRace CharacterCreation::changeRace(){
    int answer;
    CharacterRace cR = CharacterRace::Human;
    do {
        cout << "What race do you want to be ?" << endl
            << "0- Elf " << endl
            << "1- Gobelin" << endl
            << "2- Orc " << endl
            << "3- Human" << endl;
        cin >> answer;
        switch (answer)
        {
        case 0:
            cR = CharacterRace::Elf;
            break;
        case 1:
            cR = CharacterRace::Gobelin;
            break;
        case 2:
            cR = CharacterRace::Orc;
            break;
        case 3:
            cR = CharacterRace::Human;
            break;
        default:
            cout << "[INVALID ANSWER]" << endl;
            break;
        }
    } while (answer > 3 || answer < 0);
    return cR;
}

CharacterClass CharacterCreation::changeClass(){
    int answer;
    CharacterClass cC;
    do{
        cout << "What class do you want to be ?" << endl
            << "0- Archer " << endl
            << "1- Rogue" << endl
            << "2- Mage " << endl
            << "3- Knight" << endl
            << "4- Barbarian " << endl
            << "5- Lancer" << endl;
        cin >> answer;
        switch (answer)
        {
            case 0:
                cC = CharacterClass::Archer;
                break;
            case 1:
                cC = CharacterClass::Rogue;
                break;
            case 2:
                cC = CharacterClass::Mage;
                break;
            case 3:
                cC = CharacterClass::Knight;
                break;
            case 4:
                cC = CharacterClass::Barbarian;
                break;
            case 5:
                cC = CharacterClass::Lancer;
                break;
            default:
                cout << "[INVALID ANSWER]" << endl;
                break;
        }
    } while (answer > 5 || answer < 0);
return cC;
}

Weapon CharacterCreation::getBaseClassWeapon(CharacterClass cc){
    Weapon cBW;
    switch (cc)
    {
    case CharacterClass::Archer:
        cBW = Weapon("Basic Bow", "The bow that everyone used at the beginning", WeaponType::Bow, 1, 5, 10);
        break;
    case CharacterClass::Rogue:
        cBW = Weapon("Basic Dagger", "The dagger that everyone used at the beginning", WeaponType::Dagger, 1, 5, 10);
        break;
    case CharacterClass::Mage:
        cBW = Weapon("Basic Staff", "The staff that everyone used at the beginning", WeaponType::Staff, 1, 5, 10);
        break;
    case CharacterClass::Knight:
        cBW = Weapon("Basic Sword", "The sword that everyone used at the beginning", WeaponType::Sword, 1, 5, 10);
        break;
    case CharacterClass::Barbarian:
        cBW = Weapon("Basic Axe", "The axe that everyone used at the beginning", WeaponType::Axe, 1, 5, 10);
        break;
    case CharacterClass::Lancer:
        cBW = Weapon("Basic Spear", "The spear that everyone used at the beginning", WeaponType::Spear, 1, 5, 10);
        break;
    default:
        cout << "[INVALID ANSWER]" << endl;
        break;
    }
    return cBW;
}

string CharacterCreation::changeFirstName(){
    string Phrase;
    cout << "What's your first name ?" << endl;
    getline(cin, Phrase);
    return Phrase;
}

string CharacterCreation::changeLastName() {
    string Phrase;
    cout << "What's your last name ?" << endl;
    getline(cin, Phrase);
    return Phrase;
}

string CharacterCreation::changeCatchPhrase() {
    string Phrase;
    cout << "What's your catchphrase ?" << endl;
    getline(cin, Phrase);
    return Phrase;
}
