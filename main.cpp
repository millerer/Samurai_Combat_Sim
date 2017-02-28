/************************************************
Author: Eric Miller
Date Created: 08/28/2014
Filename: Final_project_CS162

Overview:
This is the final project for CS 162. It builds upon the
fantasy combat game we have been making and incorporates
data structures to cycle between two teams of opposing
samurai. The battle function continues until one team
losses all their samurai, then the samurai are ranked
by total wins. The team with the most samurai in the top
three rankings is considered the overall winner.


Output:
CPU controlled turn based combat between teams of three each.
*************************************************/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "samurai.h"
#include "battle.h"


using namespace std;
using namespace budo;

void about(); //game information menu
void rules(); //shows game rules
void show_samurai();//shows samurai stats


int main()
{
    char menu; //used for menu input

    menu = '0';

    while (menu != '3')
    {
        cout << "\n\n******************\n"<<
            "Samurai Duel\n******************\n\n"<<
            "1) About the Game \n\n"<<
            "2) Battle\n\n"<<
            "3) Exit\n\n"<<
            "\nPlease type in an option: ";
        cin >> menu;

        if (menu == '1')
        {
            about();//call to about the game
        }
        else if (menu == '2')
        {
          battleMenu();
        }

    }

    return 0;
}

void about()
{
    char menu; //used for menu input
    menu = '0';

    while (menu != '3')
    {
        cout << "\n\n******************\n"<<
            "About the Game\n******************\n\n"<<
            "1) Rules \n\n"<<
            "2) Samurai\n\n"<<
            "3) Main Menu\n\n"<<
            "\nPlease type in an option: ";
        cin >> menu;

        if (menu == '1')
        {
            rules();
        }

        else if (menu == '2')
        {
            show_samurai();
        }

    }

}

void rules()
{
    char menu = '0'; //used for menu input
    cout << "\n\n******************\n"
    "Rules\n******************\n\n"
    "In this game you stage a sword duel between\n"
    "two teams of historical samurai figures (3 per team).\n\n"
    "All attacks are taken in turns. Attacks are made via\n"
    "'dice' roll with one or more die (2 six sided die for\n"
    "example) being used to calculate the initial attack \n"
    "value, and Defense (armor value + another dice roll) being\n"
    "subtracted from the result. If the remaining attack \n"
    "balance is over 0, the attack value is taken away\n"
    "from the defending samurai's strength.\n\n"
    "Should either samurai's strength reach 0, the winner is cycled\n"
    "to the back of their roster and the loser is put into a\n"
    "team graveyard. Should one team lose all samurai, the battle\n"
    "ends and the top three samurai per win count are chosen. The \n"
    "team with the most samurai in the top three rankings wins.\n\n"
    "Note that some samurai have special abilities that can\n"
    "affect battle."
    "\n"
    "\n"
    "*****************************\n"
    "Enter any key to Continue\n"
    "*****************************\n"
    "\n";

    cin>> menu;

}

void show_samurai()
{
    char menu = '0'; //used for menu input
    cout<<"*****************************\n"
    "Samurai\n"
    "*****************************\n"
    "-Hattori Hanzo-\n"
    "Attack: 2D6 \n"
    "Defense: 1D6 \n"
    "Armor: 3\n"
    "Strength: 16\n"
    "School: Koga Ryu\n"
    "Special: Ninjutsu (chance for poison attack)\n"
    "\n"
    "-Saigo Takamori-\n"
    "Attack: 2D6 \n"
    "Defense: 1D6 \n"
    "Armor: 0\n"
    "Strength: 22\n"
    "School: Jigen Ryu\n"
    "Special: Berserker (chance to deal 2D20 attack)\n"
    "\n"
    "-Miyamoto Musashi-\n"
    "Attack: 3D6 \n"
    "Defense: 1D6 \n"
    "Armor: 2\n"
    "Strength: 24\n"
    "School: Niten-ichi ryu\n"
    "Special: Dual Wielding (+1 attack damage)\n"
    "*****************************\n"
    "Enter any key to Continue\n"
    "*****************************\n"
    "\n";
    cin>> menu;

    cout<<"\n\n-Ono Jiroemon-\n"
    "Attack: 2D8 \n"
    "Defense: 1D10 \n"
    "Armor: 2\n"
    "Strength: 23\n"
    "School: Ono-ha itto ryu\n"
    "Special: Kiri-otoshi (chance to counter attacks)\n"
    "\n"
    "-Mima Kagenobu-\n"
    "Attack: 1D15 \n"
    "Defense: 1D6 \n"
    "Armor: 3\n"
    "Strength: 19\n"
    "School: Suio ryu\n"
    "Special: Iaijutsu (always has initiative)\n"
    "\n"
    "-Yagyu Jubei-\n"
    "Attack: 3D5 \n"
    "Defense: 1D6 \n"
    "Armor: 5\n"
    "Strength: 19\n"
    "School: Yagyu Shinkage Ryu\n"
    "Special: Itto-seki (small chance to deal 100 damage)\n"
    "\n"
    "-Chiba Shusaku-\n"
    "Attack: 2D10 \n"
    "Defense: 1D8 \n"
    "Armor: 1\n"
    "Strength: 20\n"
    "School: Hokushin itto ryu\n"
    "Special: Kiri-otoshi (chance to counter attacks)\n"
    "\n"
    "*****************************\n"
    "Enter any key to Continue\n"
    "*****************************\n"
    "\n";
    cin>> menu;
}


