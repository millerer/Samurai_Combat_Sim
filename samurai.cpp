/************************************************
Author: Eric Miller
Date Created: 08/27/2014
Filename: samurai.cpp

Overview:
This is the implementation file for the samurai
related classes contained in my final project.

The header for these classes is contained in the
file samurai.h.

*************************************************/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "samurai.h"
using std::string;
using namespace budo;

/*****************************
For the base character class
*****************************/

string character::show_name()
{
    return name;
}

int character::show_str()
{
    return strength;
}

/*****************************
For the base samurai class
*****************************/

samurai::samurai()
{
    name = "Yojimbo";
    strength = 999;
    atk_die_count = 5;
    atk_die_range= 50;
    def_die_count = 10;
    def_die_range = 50;
    ryuha= "Jidai-geki";
    initiative = 0;
    poison = 0;
    armor = 0;
    wins = 0;
    losses = 0;
    victory = 0;
}

int samurai::calculate_defense()
{
    using std::cout;

    srand(time(0));

    int defense_roll = 0;//holds roll results
    int defense= 0;//holds total defense results

    for (int i =0; i< def_die_count; i++)
    {
        defense_roll = defense_roll + rand() % def_die_range + 1;//adds roll results to total
    }

    cout<<"\nThe following defense was rolled: " << defense_roll;
    cout<<"\nThe armor value is: " << armor;

    defense = armor + defense_roll; //adds armor bonus to roll results

    cout<<"\nThe total defense is: " << defense;

    return defense;
}

kiru samurai::calculate_attack()
{
    using std::cout;

    srand(time(0));

    int attack_roll =0;//holds attack roll results
    int damage = 0; //holds damage results

    int psn= 0;//holds poison status

    for (int i=0; i < atk_die_count; i++)
    {
        attack_roll = attack_roll + rand() % atk_die_range + 1;//adds roll results to total
    }

    cout<<"\nThe following attack was rolled: " << attack_roll;

    damage= attack_roll;

    kiru results;

    results.dmg = damage;

    results.poi = psn;

    return results;
}

void samurai::add_loss()
{
    losses = losses +1;
}

void samurai::add_win()
{
    wins = wins +1;
}

void samurai::total_wins(int loss)
{
    wins = wins - loss;
}

void samurai::add_victory(int results)
{
    victory = results;
}

int samurai::show_wins()
{
    return wins;
}

int samurai::show_losses()
{
    return losses;
}

int samurai::show_victory()
{
    return victory;
}
void samurai::damage(kiru damage)
{
    using std::cout;

    int attack = damage.dmg;
    int psn = damage.poi;

    if (attack > 0) //should more than 0 damage be given
    {
        cout<<"\n"<<attack<<" points of damage were given!";
        strength = strength - attack; //attack damage is subtracted from strength
    }

    if (strength > 0) //should the defender still have above 0 strength
    {
        cout<<"\nThe Defender's strength is now " << strength;
    }

    if (psn ==1 && poison!=1) //should the attack be poisonous and the defender not have poison status already
    {
        poison = 1;
        cout<<"\nThe weapon used was poisonous! The Defender is now poisoned!";
    }

    if (poison == 1)//should the defender be poisoned
    {
        strength = strength -2;
        cout<<"\nThe Defender lost 2 strength to poison";
    }
}

int samurai::show_initative()
{
    return initiative;
}

void samurai::change_initiative(int change)
{
    initiative = change;
}
/*****************************
For the individual samurai characters
*****************************/

/*****************************
Hattori Hanzo
*****************************/
hanzo::hanzo()
{
    name = "Hattori Hanzo";
    strength = 20;
    atk_die_count = 2;
    atk_die_range= 6;
    def_die_count = 1;
    def_die_range = 6;
    ryuha= "Koga Ryu";
    initiative = 0;
    poison = 0;
    armor = 3;
}

kiru hanzo::calculate_attack()
{
    using std::cout;

    srand(time(0));

    int ninjutsu =0;//flags for poison attack
    int attack_roll =0;//holds attack roll results
    int damage = 0; //holds damage results
    int psn= 0;//holds poison status
    ninjutsu = rand() % 5+1;

    if (ninjutsu == 4)
    {
        psn = 1;
    }


    for (int i=0; i < atk_die_count; i++)
    {
        attack_roll = attack_roll + rand() % atk_die_range + 1;//adds roll results to total
    }

    cout<<"\nThe following attack was rolled: " << attack_roll;

    damage= attack_roll;

    kiru results;

    results.dmg = damage;

    results.poi = psn;

    return results;

}

/*****************************
Saigo Takamori
*****************************/

takamori::takamori()
{
    name = "Saigo Takamori";
    strength = 22;
    atk_die_count = 2;
    atk_die_range= 6;
    def_die_count = 1;
    def_die_range = 6;
    ryuha= "Jigen Ryu";
    initiative = 0;
    poison = 0;
    armor = 0;
}

kiru takamori::calculate_attack()
{
    using std::cout;

    srand(time(0));
    int flurry = 0; //sees if damage modifier occurs
    int attack_roll =0;//holds attack roll results
    int damage = 0; //holds damage results

    int psn= 0;//holds poison status

    flurry = rand() %10+1;

    if (flurry == 10)
    {
            for (int i=0; i < atk_die_count; i++)
            {
                attack_roll = attack_roll + rand() % 20 + 1;//adds roll results to total
            }
        cout<<"\nThe following attack was rolled in a flurry of blows: " << attack_roll;

    }

    else
    {
            for (int i=0; i < atk_die_count; i++)
            {
                attack_roll = attack_roll + rand() % atk_die_range + 1;//adds roll results to total
            }

            cout<<"\nThe following attack was rolled: " << attack_roll;
    }


    damage= attack_roll;

    kiru results;

    results.dmg = damage;

    results.poi = psn;

    return results;
}

/*****************************
Miyamoto Musashi
*****************************/

musashi::musashi()
{
    name = "Miyamoto Musashi";
    strength = 24;
    atk_die_count = 3;
    atk_die_range= 6;
    def_die_count = 1;
    def_die_range = 6;
    ryuha= "Niten-Ichi ryu";
    initiative = 0;
    poison = 0;
    armor = 2;
}

kiru musashi::calculate_attack()
{
    using std::cout;

    srand(time(0));

    int attack_roll =0;//holds attack roll results
    int damage = 0; //holds damage results

    int psn= 0;//holds poison status

    for (int i=0; i < atk_die_count; i++)
    {
        attack_roll = attack_roll + rand() % atk_die_range + 1;//adds roll results to total
    }

    cout<<"\nThe following attack was rolled: " << attack_roll;

    damage= attack_roll +1;//musashi always does +1 bonus damage

    kiru results;

    results.dmg = damage;

    results.poi = psn;

    return results;

}

/*****************************
Ono Jiroemon
*****************************/

ono::ono()
{
    name = "Ono Jiroemon";
    strength = 23;
    atk_die_count = 2;
    atk_die_range= 8;
    def_die_count = 1;
    def_die_range = 10;
    ryuha= "Ono-ha itto ryu";
    initiative = 0;
    poison = 0;
    armor = 2;
}

void ono::damage(kiru damage)
{
    using std::cout;

    int attack = damage.dmg;
    int psn = damage.poi;

    srand(time(0));

    int kiri_otoshi =0;//calculates chance of attack deflection
    kiri_otoshi = rand()% 5 +1;

    if (kiri_otoshi ==5)
    {
        attack = 0;
        psn = 0;
        cout<<"\nThe attack was countered!";
        initiative =1;
    }

    else if (attack > 0) //should more than 0 damage be given
    {
        cout<<"\n"<<attack<<" points of damage were given!";
        strength = strength - attack; //attack damage is subtracted from strength


        if (strength > 0) //should the defender still have above 0 strength
        {
            cout<<"\nThe Defender's strength is currently " << strength;
        }
    }

    if (psn ==1 && poison!=1) //should the attack be poisionous and the defender not have poison status already
    {
        poison = 1;
        cout<<"\nThe weapon used was poisonous! The Defender is now poisoned!";
    }

    if (poison == 1)//should the defender be poisoned
    {
        strength = strength -4;
        cout<<"\nThe Defender lost 4 strength to poison";
    }
}

/*****************************
Mima Kagenobu
*****************************/
kagenobu::kagenobu()
{
    name = "Mima Kagenobu";
    strength = 19;
    atk_die_count = 1;
    atk_die_range= 15;
    def_die_count = 1;
    def_die_range = 6;
    ryuha= "Suio ryu";
    initiative = 1;
    poison = 0;
    armor = 3;
}

/*****************************
Yagyu Jubei
*****************************/

jubei::jubei()
{
    name = "Yagyu Jubei";
    strength = 19;
    atk_die_count = 3;
    atk_die_range= 5;
    def_die_count = 1;
    def_die_range = 6;
    ryuha= "Yagyu Shinkage Ryu";
    initiative = 0;
    poison = 0;
    armor = 5;
}

kiru jubei::calculate_attack()
{
    using std::cout;

    srand(time(0));
    int itto_seki = 0; //sees if damage modifier occurs
    int attack_roll =0;//holds attack roll results
    int damage = 0; //holds damage results

    int psn= 0;//holds poison status

    itto_seki = rand() %30+1;

    if (itto_seki == 30)
    {
        attack_roll = 100;//adds roll results to total
        cout<<"\nThe attack cleaves the very Earth in two with the following damage: " << attack_roll;
    }

    else
    {
            for (int i=0; i < atk_die_count; i++)
            {
                attack_roll = attack_roll + rand() % atk_die_range + 1;//adds roll results to total
            }

            cout<<"\nThe following attack was rolled: " << attack_roll;
    }


    damage= attack_roll;

    kiru results;

    results.dmg = damage;

    results.poi = psn;

    return results;

}

/*****************************
Chiba Shusaku
*****************************/

shusaku::shusaku()
{
    name = "Chiba Shusaku";
    strength = 20;
    atk_die_count = 2;
    atk_die_range= 10;
    def_die_count = 1;
    def_die_range = 8;
    ryuha= "Hokushin Itto Ryu";
    initiative = 0;
    poison = 0;
    armor = 1;
}

