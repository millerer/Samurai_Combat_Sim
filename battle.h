/************************************************
Author: Eric Miller
Date Created: 08/27/2014
Filename: battle.h

Overview:
This is the header file for the battle
related functions contained in my final project.

The implementation for these functions is contained in the
file battle.cpp.

*************************************************/
#ifndef BATTLE_H_INCLUDED
#define BATTLE_H_INCLUDED
#include <iostream>
#include "samurai.h"
#include <queue>
using std::queue;

using namespace budo;

void duel(samurai *char_1, samurai* char_2); //battle function that performs turn based combat between 2 samurai objects

void battleMenu();//starts battle menu where the user selects combatants

void selection (queue <samurai*> &team, string player);//

#endif // BATTLE_H_INCLUDED
