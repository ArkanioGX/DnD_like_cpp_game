#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Character.h"
#include "CharacterCreation.h"
#include "Monster.h"
#include "Merchant.h"

void showPV(Creature* p, Creature* e); //Show little pv bar
std::string pvBar(int hp, int hpMax, int n);  //Prepare the numbers of | and . for the showPV()
void Combat(Character* p, Creature* e); //Engage in a combat loop with 2 creatures
Monster newEnemy(); //Create a new enemy

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

    vector<Attack> vAtt = {
    Attack("Slash",Player.getWeapon(),Dice(1,6,1),DamageType::Slashing),
    Attack("Double Time",Player.getWeapon(),Dice(2,4,2),DamageType::Slashing)};
    Player.setAttacks(vAtt);
    ///////////////////////////////////////////////////////////////////////////////////////

    //First enemy setup
    Weapon eWeapon = Weapon("Iron Dagger", "A really basic dagger that can be found at every Costco", WeaponType::Dagger, 0.8, 7, 20);
    Creature Enemy = Monster();
    vAtt = {
    Attack("Punch",new Weapon(),Dice(1,4,0),DamageType::Bludgeoning),
    Attack("Double Time",&eWeapon,Dice(2,3,1),DamageType::Slashing)};
    Enemy.setAttacks(vAtt);

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

        cout << "Choose :" << endl
             << "0- Fight " << endl
            << "1- Check Inventory" << endl
            << "2- Shop " << endl
            << "9- Quit " << endl;
        cin >> answer;
        switch (answer)                                             //Changes variables if changes wanted to be made
        {
        case 0:
            Combat(&Player, &Enemy);

            if (Player.getHP() == 0) { //Checks if the player died in the combat
                cout << endl << "YOU DIED ! GGS" << endl;
                return 0;
            }

            Player.setHP(Player.getMaxHP()); //Heals the player after a fight
            Enemy = newEnemy(); //Prepare new Enemy for next fight

            break;
        case 1:     //Check the inventory and give the possibility to equip weapons
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
        case 2:     //Engage in a loop for the merchant shop
            Player.interactWithMerchant(&gMerchant);
            break;
        case 9:     //Exit the game
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
    bool fightFinished = false;
    cout << "\n\n\n\n\n\n\n\n\n";
    do //Main fight loop
    {
        //Show PV + Little text intro
        int rdmID;
        int answer;
        if (playerTurn) {
            do {
                
                srand(time(NULL));
                rdmID = rand() % 2;
                if (rdmID == 0) { cout << p->getFirstName() << " " << p->getLastName() << " : " << p->getCatchPhrase() << endl; }
                else { cout << e->getName() << " : " << e->getDesc() << endl; }
                showPV(p, e);
                cout << endl << "=================================================================================" << endl
                    << "What will you do ?" << endl
                    << "=================================================================================\n\n";

                cout << "Choose :" << endl;

                for (int i = 0; i < p->getAttacks().size(); i++) {
                    Attack a = p->getAttacks()[i];
                    cout << i << " | " << a.getLabel() << " - DMG : " << a.getDices().getString() << endl;
                }
                cout << p->getAttacks().size() << " | Heal - +10HP" << endl;
                cout << "9 | Flee" << endl;
                cin >> answer;
                if (answer < 0 || (answer >= p->getAttacks().size() + 1 && answer != 9)) {
                    cout << "[INVALID INPUT]" << endl;
                }
            } while (answer != 9 && (answer < 0 || answer >= p->getAttacks().size() + 1 ));
            cout << "\n\n\n\n\n\n\n\n\n";
            if (answer == p->getAttacks().size()) {
                p->heal(10);
                cout << p->getName() << " healed 10 HP " << endl;
            }
            else if (answer == 9) {
                cout << "You fled the fight !" << endl;
                return;
            }
            else {
                p->attack(e, p->getAttacks()[answer]);
                
                
                if (e->getHP() == 0) {
                    fightFinished = true;
                    cout << e->getName() << " has been slain " << endl;
                    p->addStoredWeapons(Loot::getRandomLoot());
                }
            }
        }
        else {
            srand(time(NULL));
            rdmID = rand() % 100;
            if (rdmID < 5) {
                e->heal(10);
                cout << e->getName() << " healed 10 HP " << endl;
            }
            else if (rdmID < 6) {
                cout << e->getName() << " ran away " << endl;
                fightFinished = true;
            }
            else {
                rdmID = rand() % e->getAttacks().size();
                e->attack(p, e->getAttacks()[rdmID]);
                if (p->getHP() == 0) {
                    fightFinished = true;
                    cout << p->getName() << " has been slain " << endl;
                }
            }
            
        }
        playerTurn = !playerTurn;
    } while (!fightFinished);
}

Monster newEnemy() {
    vector<Monster> cList = {
        Monster("Thundercat","Every news about this cat is a shocking news",50,1, vector<Attack>{
            Attack("Headbutt", new Weapon(), Dice(1,3,0), DamageType::Bludgeoning),
            Attack("Zap", new Weapon(), Dice(1,6,2), DamageType::Bludgeoning)}),
        Monster("Blazebug","Does annoying buzzing sound but on fire",20,1, vector<Attack>{
            Attack("Bzzzzzzzzzzzz", new Weapon(), Dice(1,2,0), DamageType::Bludgeoning),
            Attack("Fire Fart", new Weapon(), Dice(2,3,1), DamageType::Bludgeoning)}),
    };

    srand(time(NULL) + rand());
    int rdm = rand() % cList.size();

    return cList[rdm];
}
