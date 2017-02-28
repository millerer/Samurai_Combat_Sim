/************************************************
Author: Eric Miller
Date Created: 08/27/2014
Filename: samurai.cpp

Overview:
This is the header file for the samurai character
classes used in my final project.

The implementation for these classes is in the file
'samurai.cpp'.

*************************************************/
#ifndef SAMURAI_H_INCLUDED
#define SAMURAI_H_INCLUDED
#include <iostream>
using std::string;

namespace budo //namespace for holding classes and typedef for assignment 4
{
    struct atk_results //structure for holding attack results. Is used as input for damage function
    {
        int dmg;//damage
        int poi;//poison status
    };
    typedef atk_results kiru; //typedef for atk_results struc


class character //abstract ancestor class for all game characters
{
    public:
    string show_name();//accessor for name
    int show_str();//accessor for strength
    virtual int calculate_defense() = 0;//calculates defense

    protected:
    string name;//character name
    int strength;//strength value
    int atk_die_count;//# of attack die
    int atk_die_range;//sides per attack die
    int def_die_count;//# of defense die
    int def_die_range;//sides per defense die
    int armor;//armor value
};

class samurai : public character//base class for all game characters
{
    public:
    samurai();//default constructor
    virtual int calculate_defense();//calculates defense
    virtual kiru calculate_attack();//calculates attack
    virtual void damage(kiru damage);//mutator for strength. Inputs damage and poison status
    int show_initative();//accessor for initiative
    void change_initiative(int change);//mutator for initiative
    void add_win(); //mutator for win variable
    void add_loss();//mutator for loss variable
    void total_wins(int loss);//subtracts losses from wins
    void add_victory(int results);//mutator for victory variable (1 = the victor)
    int show_wins();//returns win count
    int show_losses();//returns loss count
    int show_victory();//returns victory status
    virtual ~samurai(){}

    protected:
    string ryuha;//fighting style
    bool poison;//flags poison status
    int initiative;//can grant initiative in attacks if = 1.
    int wins; //keeps track of wins
    int losses;//keeps track of losses
    int victory;//'1' marks victor


};

class hanzo : public samurai //has special ability to poison enemy
{
    public:
    hanzo();//default constructor
    virtual atk_results calculate_attack();//calculates attack with chance to poison
};

class takamori : public samurai //potential to change attack range to d20
{
    public:
    takamori();//default constructor
    virtual atk_results calculate_attack();//calculates attack
};

class musashi : public samurai //always does an additional +1 damage
{
    public:
    musashi();//default constructor
    virtual atk_results calculate_attack();//calculates attack
};

class ono : public samurai //chance to deflect damage and gain initiative
{
    public:
    ono();//default constructor
    virtual void damage(kiru damage);//mutator for strength. Inputs damage and poison status
};

class kagenobu : public samurai//always  attacks first
{
    public:
    kagenobu();//default constructor
};

class jubei : public samurai//chance to do 100 damage
{
    public:
    jubei();//default constructor
    virtual atk_results calculate_attack();//calculates attack
};

class shusaku : public ono //chance to deflect damage and gain initiative
{
    public:
    shusaku();//default constructor
};

}

#endif // SAMURAI_H_INCLUDED
