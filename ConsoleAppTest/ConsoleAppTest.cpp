#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Character.h"
#include "CharacterCreation.h"
#include "Monster.h"
#include "Merchant.h"

void showPV(Creature* p, Creature* e);
std::string pvBar(int hp, int hpMax, int n);
void Combat(Character* p, Creature* e);

using namespace std;

int main()
{
    cout << "Welcome to The New Land !!" << endl;
    int answer = 0;
    
    //Ask the player if he really want to play the game maybe he missclicked ¯\_(ツ)_/¯
    do{
        
        cout << "Do you wish to embark in this world ?" << endl
             << "0- Yes " << endl
             << "1- No" << endl;
        cin >> answer;
        switch (answer)
        {
        case 0:
            cout << "Now ! Let's create your character !" << endl;
            break;
        case 1:
            cout << "Welp goodbye !!" << endl; 
            return 0;
        default:
            cout << "[INVALID ANSWER]" << endl;
            break;
        }
    } while (answer > 1 || answer < 0);


    //Preparing the variables for player creation
    CharacterRace cR = CharacterCreation::changeRace();
    
    CharacterClass cC = CharacterCreation::changeClass();
    Weapon cBW = CharacterCreation::getBaseClassWeapon(cC);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string cFName = CharacterCreation::changeFirstName(); 
    string cLName = CharacterCreation::changeLastName();
    string cCPhrase = CharacterCreation::changeCatchPhrase();

    string CharacterRaceString[4] = { "Elf", "Orc", "Gobelin", "Human" };
    string CharacterClassString[6] = { "Archer", "Rogue", "Mage", "Knight","Barbarian","Lancer" };

    //Ask if any changes want to be made
    do {
        cout << endl << "=================================================================================" << endl;
        cout << "Here's the info of your character do you wish to edit something before finalizing ?" << "\n\n";
        cout << "First name : " + cFName << endl;
        cout << "Last name : " + cLName << endl;
        cout << "Catch phrase : " + cCPhrase << endl;
        cout << endl;
        cout << "your Race : " << CharacterRaceString[cR] << endl;
        cout << "your Class : " << CharacterClassString[cC] << endl;
        cout << "your base Weapon : " << cBW.getWeaponName() << 
        endl << "=================================================================================\n\n";

        cout << "Edit :" << endl
            << "0- First name " << endl
            << "1- Last name" << endl
            << "2- Catch phrase " << endl
            << "3- Race " << endl
            << "4- Class" << endl
            << "9- Continue " << endl;
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (answer)                                             //Changes variables if changes wanted to be made
        {
        case 0:
            cFName = CharacterCreation::changeFirstName();
            break;
        case 1:
            cLName = CharacterCreation::changeLastName();
            break;
        case 2:
            cCPhrase = CharacterCreation::changeCatchPhrase();
            break;
        case 3:
            cR = CharacterCreation::changeRace();
            break;
        case 4:
            cC = CharacterCreation::changeClass();
            cBW = CharacterCreation::getBaseClassWeapon(cC);
            break;
        case 9:
            break;
        default:
            cout << "[INVALID ANSWER]" << endl;
            break;
        }
    } while (answer != 9);

    //Player Created
    Character Player = Character(cFName,cLName,cCPhrase,cC,cR,cBW);
    
    //////////////////////////////// TEST SECTION /////////////////////////////////////////
    cout << Player.getCatchPhrase() << endl;
    cout << "And my weapon is " << Player.getWeapon()->getWeaponName() << "\n\n";

    Player.setMoney(20);

    Weapon w1 = Weapon("Iron Axe", "A really basic axe that was stolen from your local lumberjack", WeaponType::Axe, 2, 7, 20);

    Player.addStoredWeapons(w1);

    Player.swapWeapon(0);

    Player.setHP(25);
    ///////////////////////////////////////////////////////////////////////////////////////

    Weapon eWeapon = Weapon("Iron Dagger", "A really basic dagger that can be found at every Costco", WeaponType::Dagger, 0.8, 7, 20);
    Creature Enemy = Creature();

    //Creation of a low tier Merchant weapon list
    array<Weapon, 6> wl =
    { Weapon("Iron Sword", "A really basic sword that can be found at every Walmart",WeaponType::Sword,2,7,20),
    Weapon("Iron Dagger", "A really basic dagger that can be found at every Costco",WeaponType::Dagger,0.8,7,20),
    Weapon("Oak Bow", "A really basic bow that can be found at every Ikea",WeaponType::Bow,1,7,20),
    Weapon("Spruce Staff", "A really basic staff that can be found at every McDonalds",WeaponType::Staff,1,7,20),
    Weapon("Iron Spear", "A really basic spear that can be bought on Amazon",WeaponType::Spear,1.5,7,20),
    Weapon("Iron Axe", "A really basic axe that was stolen from your local lumberjack",WeaponType::Axe,2,7,20), };
    Merchant gMerchant = Merchant("Albert", "your local merchant", "Hello my dear friends, care for some good weapons ?", 1500, wl);

    //Creation of the weapon loot tables
    
    //Player Interaction
    do {
        
        cout << endl << "=================================================================================" << endl
             << "What will you do ?" << endl
             << "=================================================================================\n\n";

        cout << "Choose :" << endl;
        if (Enemy.getHP() <= 0) {
            cout << "0- Loot " << endl;
        }
        else {
            cout << "0- Attack " << endl;
        }
        cout << "1- Check Inventory" << endl
            << "2- Shop " << endl
            << "3- Heal (20$)" << endl
            << "9- Quit " << endl;
        cin >> answer;
        switch (answer)                                             //Changes variables if changes wanted to be made
        {
        case 0:
            Combat(&Player, &Enemy);

            break;
        case 1:
            int choice;
            do {
                Player.listWeapons();
                cout << endl << "0-4 - Equip Weapon " << endl
                     << "9   - Quit Inventory " << endl;
                cin >> choice;
                if (choice <= 4 && choice >= 0) {
                    Player.swapWeapon(choice);
                }
                else if (choice != 9) {
                    cout << "[INVALID INPUT]";
                    cin >> choice;
                }
            } while (choice != 9 );
            break;
        case 2:
            Player.interactWithMerchant(&gMerchant);
            break;
        case 3:
            Player.heal(20);
            break;
        case 9:
            break;
        default:
            cout << "[INVALID INPUT]" << endl;
            break;
        }
    } while (answer != 9);
    
}

void showPV(Creature* p, Creature* e) {
    cout << "Your PV [" << pvBar(p->getHP(), p->getMaxHP(), 20) << "] -|- Enemy PV [" << pvBar(e->getHP(), e->getMaxHP(), 20) << "]";
}

string pvBar(int hp, int hpMax, int n) {
    string s;
    float hpPrct = float(hp) / float(hpMax);
    for (float i = 0; i < n; i++) {
        if (hpPrct > float(i) / float(n)) { s.push_back('|'); }
        else { s.push_back('.'); }
    }
    return s;
}

void Combat(Character* p, Creature* e) {
    bool playerTurn = true;

    //Show PV + Little text intro
    int rdmID;
    srand(time(NULL));
    rdmID = rand() % 2;
    if (rdmID == 0) { cout << p->getFirstName() << " " << p->getLastName() << " : " << p->getCatchPhrase() << endl; }
    else { cout << e->getName() << " : " << e->getDesc() << endl; }
    showPV(p, e);
    int answer;
    if (playerTurn) {
        do {

            cout << endl << "=================================================================================" << endl
                << "What will you do ?" << endl
                << "=================================================================================\n\n";

            cout << "Choose :" << endl;
            
            for (int i = 0; i < p->getAttacks().size(); i++) {

            }
            cin >> answer;
            cout << "[INVALID INPUT]" << endl;

        } while (answer != 9);
    }
}

