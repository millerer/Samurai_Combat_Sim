/************************************************
Author: Eric Miller
Date Created: 08/27/2014
Filename: battle.cpp

Overview:
This is the implemention file for the battle
related functions contained in my final project.

The header for these functions is contained in the
file battle.h.

*************************************************/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "samurai.h"
#include "battle.h"
#include "queue"
#include "vector"
using std::queue;
using std::vector;
using namespace budo;



/*****************************
For the combat function
*****************************/

void duel(samurai *char_1, samurai* char_2)
{
    using std::cout;
    using std::cin;
    srand(time(0));

    char menu ='1';//user input
    while (char_1->show_str() >0 && char_2->show_str() >0)
    {
        int order = rand() %2 +1; //selects player turn. 1 means char_1 goes first unless initiative bonuses apply
        kiru damage;//damage
        int defense = 0;//defense

        if (char_1->show_initative() == char_2->show_initative()) //should initiative values be the same any initiative bonus is voided
        {
            char_1->change_initiative(0);
            char_2->change_initiative(0);
        }

        if (order ==1 || char_1->show_initative() ==1) //should char 1 attack first
        {

            cout<<"\n\nTeam 1 Fighter " <<char_1->show_name()  << " attacks!\n";

            damage = char_1->calculate_attack();//calculate attack
            defense = char_2->calculate_defense();//calculate attack target damage
            damage.dmg = damage.dmg - defense; //subtract defense from attack

            if (damage.dmg <= 0)
            {
                cout<<"\n\nTeam 1 Fighter " <<char_1->show_name()  << " attacks fails.\n"; //if damage is less than 0
            }


            else
            {
                char_2->damage(damage);
                cout<<"\n\nTeam 2 Fighter " <<char_2->show_name()  << "'s strength is now ";
                if (char_2->show_str() < 1) //should defender strength fall below 1, I don't want to show a negative number for strength
                {
                    cout<< "0\n";
                }
                else
                {
                    cout<< char_2->show_str() << "\n";
                }
            }

                    cout<<  "\n\n"
                    "*****************************\n"
                    "Enter any key to Continue\n"
                    "*****************************\n"
                    "\n";
                    cin>> menu;

            if (char_2->show_str()<1) //if the char_2 dies
            {
                cout<<"\n\nFighter 2 " <<char_2->show_name()  << "'s strength is gone.\n";
                cout<<"\n\nTeam 1 Fighter " <<char_1->show_name()  << " Wins!\n";
                char_2->add_loss();
                char_1->add_win();
                char_1->add_victory(1);
            }

            else //should char 2 survive, they then attack
            {
                cout<<"\n\nTeam 2 Fighter " <<char_2->show_name()  << " attacks!\n";
                damage = char_2->calculate_attack();//calculate attack
                defense = char_1->calculate_defense();//calculate attack target damage
                damage.dmg = damage.dmg - defense;//subtract defense from attack


                if (damage.dmg <= 0)
                {
                    cout<<"\n\nTeam 2 Fighter " <<char_2->show_name()  << " attacks fails.\n"; //if damage is less than 0
                }

                else
                {
                    char_1->damage(damage);
                    cout<<"\n\nTeam 1 Fighter " <<char_1->show_name()  << "'s strength is now ";

                    if (char_1->show_str() < 1) //should defender strength fall below 1, I don't want to show a negative number for strength
                    {
                        cout<< "0\n";
                    }
                    else
                    {
                        cout<< char_1->show_str() << "\n";
                    }
                }

                if (char_1->show_str()<1) //if the char_1 dies
                {
                    cout<<"\n\nTeam 1 Fighter " <<char_1->show_name()  << "'s strength is gone.\n";
                    cout<<"\n\nTeam 2 Fighter " <<char_2->show_name()  << " Wins!\n";
                    char_1->add_loss();
                    char_2->add_win();
                    char_2->add_victory(1);
                }
            }

                    cout<<  "\n\n"
                    "*****************************\n"
                    "Enter any key to Continue\n"
                    "*****************************\n"
                    "\n";
                    cin>> menu;

        }

        else //should char 2 attack first
        {
            cout<<"\n\nTeam 2 Fighter " <<char_2->show_name()  << " attacks!\n";

            damage = char_2->calculate_attack();//calculate attack
            defense = char_1->calculate_defense();//calculate attack target damage
            damage.dmg = damage.dmg - defense; //subtract defense from attack

            if (damage.dmg <= 0)
            {
                cout<<"\n\nTeam 2 Fighter " <<char_2->show_name()  << " attacks fails.\n"; //if damage is less than 0
            }


            else
            {
                char_1->damage(damage);
                    cout<<"\n\nTeam 1 Fighter " <<char_1->show_name()  << "'s strength is now ";

                    if (char_1->show_str() < 1) //should defender strength fall below 1, I don't want to show a negative number for strength
                    {
                        cout<< "0\n";
                    }
                    else
                    {
                        cout<< char_1->show_str() << "\n";
                    }
            }

                    cout<<  "\n\n"
                    "*****************************\n"
                    "Enter any key to Continue\n"
                    "*****************************\n";
                    "\n";
                    cin>> menu;

            if (char_1->show_str()<1) //if the char_1 dies
            {
                cout<<"\n\nTeam 1 Fighter " <<char_1->show_name()  << "'s strength is gone.\n";
                cout<<"\n\nTeam 2 Fighter " <<char_2->show_name()  << " Wins!\n";
                char_1->add_loss();
                char_2->add_win();
                char_2->add_victory(1);
            }

            else //should char 1 survive, they then attack
            {
                cout<<"\n\nTeam 1 Fighter " <<char_1->show_name()  << " attacks!\n";
                damage = char_1->calculate_attack();//calculate attack
                defense = char_2->calculate_defense();//calculate attack target damage
                damage.dmg = damage.dmg - defense;//subtract defense from attack


                if (damage.dmg <= 0)
                {
                    cout<<"\n\nTeam 1 Fighter " <<char_1->show_name()  << " attacks fails.\n"; //if damage is less than 0
                }

                else
                {
                    char_2->damage(damage);
                    cout<<"\n\nTeam 2 Fighter " <<char_2->show_name()  << "'s strength is now ";

                    if (char_2->show_str() < 1) //should defender strength fall below 1, I don't want to show a negative number for strength
                    {
                        cout<< "0\n";
                    }
                    else
                    {
                        cout<< char_2->show_str() << "\n";
                    }
                }


                    cout<<  "\n\n"
                    "*****************************\n"
                    "Enter any key to Continue\n"
                    "*****************************\n"
                    "\n";
                    cin>> menu;


                if (char_2->show_str()<1) //if the char_1 dies
                {
                    cout<<"\n\nTeam 2 Fighter " <<char_2->show_name()  << "'s strength is 0.\n";
                    cout<<"\n\nTeam 1 Fighter " <<char_1->show_name()  << " Wins!\n";
                    char_2->add_loss();
                    char_1->add_win();
                    char_1->add_victory(1);
                }
            }
        }

    }


}

/*****************************
For the combat menu screen
*****************************/


void battleMenu()  //starts battle menu where the user selects combatants
{
    srand(time(0));
    using namespace std;
    string player1 = "PLAYER 1"; //used for the player names
    string player2= "PLAYER 2";
    int round =1; //counts battle rounds

    char menu = '0'; //used for menu input

    vector<samurai*> player_1_dead; //holds dead team 1 members
    vector<samurai*> player_2_dead; //holds dead team 2 members

    queue <samurai*>player_1_team;//holds team for player 1
     queue <samurai*> player_2_team; //holds team for player 2

    selection(player_1_team, player1);
    selection(player_2_team, player2);


    samurai *head1 = player_1_team.front();//holds team for player 1
    samurai *head2 = player_2_team.front();//holds team for player 2
    samurai *destroy;
    cout<< "The combatants have been chosen!\n\nPRESS ANY KEY TO CONTINUE: ";

    cin>> menu;

    while (player_1_team.size() != 0 && player_2_team.size() !=0) //while both teams still have at least one member alive
        {

            head1 = player_1_team.front();
            head2 = player_2_team.front();

            cout << "\n\n******************\n"<<
            "ROUND "<< round <<"\n******************\n\n"<<

            "Team 1 Fighter: " << head1->show_name() <<
            "\nTeam 2 Fighter: "<< head2->show_name()<< "\n\n";

            cout<< "\n\nPRESS ANY KEY TO CONTINUE: ";

            cin>> menu;

            duel(head1, head2);

            if (head1->show_victory() == 1) //if player 1's team member won
                {
                    cout<<"\nTeam 2 Fighter: " <<head2->show_name()<< " has been added to the team 2 graveyard.\n";
                    cout<<"\nTeam 1 Fighter: " <<head1->show_name()<< " has gone to the back of their roster.\n";

                    player_2_dead.push_back(player_2_team.front());//player 2's team member is added to their graveyard
                    destroy = player_2_team.front();
                    player_2_team.pop();//team 2 fighter is removed from their roster
                    head1->add_victory(0); //reset victory flag
                    player_1_team.push(head1);//team 1 fighter is pushed to the back of their roster
                    player_1_team.pop();

                }

            else//if player 2's team member won
                {
                    cout<<"\nTeam 1 Fighter: " <<head1->show_name()<< " has been added to the team 1 graveyard.\n";
                    cout<<"\nTeam 2 Fighter: " <<head2->show_name()<< " has gone to the back of their roster.\n";

                    player_1_dead.push_back(player_1_team.front());//player 1's team member is added to their graveyard
                    destroy = player_1_team.front();
                    player_1_team.pop();//team 2 fighter is removed from their roster
                    head2->add_victory(0); //reset victory flag
                    player_2_team.push(head2);//team 1 fighter is pushed to the back of their roster
                    player_2_team.pop();

                }


            cout<< "\n\nPRESS ANY KEY TO CONTINUE: ";

            cin>> menu;

            cout << "\n\n******************\n"<<
            "\nTeam 1 Roster Size: " <<player_1_team.size() <<
            "\nTeam 1 Graveyard Size: " <<player_1_dead.size() <<
            "\n\nTeam 2 Roster Size: " <<player_2_team.size() <<
            "\nTeam 2 Graveyard Size: " <<player_2_dead.size() <<
            "\n******************\n\n";

            cout<< "\n\nPRESS ANY KEY TO CONTINUE: ";

          cin>> menu;

            round++; //round increases in number
        }
    cout<< "\n\nTHE BATTLE IS OVER!\n";


    while (player_1_team.size() != 0)
        {
            player_1_dead.push_back(player_1_team.front());
            destroy = player_1_team.front();
            player_1_team.pop(); //clears out the team 1 queue
        }
    while (player_2_team.size() != 0)
        {
            player_2_dead.push_back(player_2_team.front());
            destroy = player_2_team.front();
            player_2_team.pop(); //clears out the team 2 queue
        }


/*****************************
For calculating the rankings
*****************************/

    vector<samurai*>::iterator zanshin; //iterator for calculating final scores and clearing dynamic variables from the graveyards
    samurai* adjust; //used in conjunction with the iterator
    int random; //used to calculate random numbers to break ties in score

    struct ranking //holds name/win data of the fighters
    {
        string player_rank_name;
        int player_rank_wins;
    };

    ranking finale[6]; //array for holding ranking structs, 1 for each fighter

    zanshin = player_1_dead.begin();

    for (int i = 0; i < 3; i++) //inputs team 1 name/win data into an array to be sorted
            {
                adjust = *zanshin;
                finale[i].player_rank_name = "Team 1 " + adjust->show_name();
                finale[i].player_rank_wins = adjust->show_wins();
                zanshin++;
            }

    zanshin = player_2_dead.begin();//inputs team 2 name/win data into an array to be sorted

     for (int i = 3; i < 6; i++)
        {
            adjust = *zanshin;
            finale[i].player_rank_name = "Team 2 " + adjust->show_name();
            finale[i].player_rank_wins = adjust->show_wins();
            zanshin++;
        }




/*****************************
Break to clear out dynamic variables
*****************************/
    zanshin = player_1_dead.begin();
    while (zanshin != player_1_dead.end()) //team 1 graveyard is cleared
        {
            adjust= *zanshin;
            zanshin++;
            delete adjust;
        }

    player_1_dead.clear();


    zanshin = player_2_dead.begin();

    while (zanshin != player_2_dead.end())//team 2 graveyard is cleared
        {
            adjust= *zanshin;
            zanshin++;
            delete adjust;
        }
        player_2_dead.clear();

/*****************************
Back to calculating the rankings
*****************************/

    for (int i = 0; i < 6; i++) //sorts array by win count
    {
        ranking temp; //temporary ranking for array swapping

        for (int k = 0; k < 6; k++)
        {

            if (finale[i].player_rank_wins > finale[k].player_rank_wins) //if smaller than next array
            {
                temp = finale[i];
                finale[i] = finale[k];
                finale[k] = temp;

            }

            else if (finale[i].player_rank_wins == finale[k].player_rank_wins) //should value be the same they are randomly sorted
            {
                random = rand()%1;
                if (random == 1)
                {
                    temp = finale[i];
                    finale[i] = finale[k];
                    finale[k] = temp;
                }
                else
                {
                    //no swap
                }

            }

        }

    }

    cout<<"\n\nThe Final Rankings are:\n************************\n";
    cout<<finale[0].player_rank_name;
    cout<<" in first place with ";
    cout << finale[0].player_rank_wins;
    cout<< " wins\n";
    cout<<finale[1].player_rank_name;
     cout<< " in Second place with ";
     cout << finale[1].player_rank_wins;
     cout<< " wins\n";
    cout<<finale[2].player_rank_name;
    cout << " in third place with ";
    cout << finale[2].player_rank_wins;
    cout<< " wins\n************************\n";

    int team1_count=0; //counts team 1 characters
    int team2_count=0; //counts team 2 characters

    for (int i = 0; i < 3; i++) //counts top team members per team
    {
            if (finale[i].player_rank_name.at(6) ==1) //if the 6th character in the string is '1'. that means it is player 1's character
            {
                team1_count++;
            }
            else//if a character is form team 2
            {
                team2_count++;
            }
    }


    if (team1_count > team2_count)
    {
            cout << "\n\n******************\n"<<
            "TEAM 1 is the winner! \n******************\n\n";
    }

    else
    {
            cout << "\n\n******************\n"<<
            "TEAM 2 is the winner! \n******************\n\n";
    }
}

/*****************************
Character Selection Function
*****************************/

void selection(queue <samurai*> &team, string player)
{
    using std::cout;
    using std::cin;

/*****************************
For the first team member
*****************************/

    char menu; //used for user input
    cout << "\n\n******************\n"<<
    "Choose Your Team "<< player <<"\n******************\n\n"<<
    "1) Hattori Hanzo \n\n"<<
    "2) Chiba Shusaku\n\n"<<
    "3) Saigo Takamori\n\n"<<
    "4) Miyamoto Musashi\n\n"<<
    "5) Ono Jiroemon\n\n"<<
    "6) Mima Kagenobu\n\n"<<
    "7) Yagyu Jubei\n\n"<<
    "\nPlease chose the first team member: ";

    cin>> menu;

    while (menu != '1' && menu != '2' && menu != '3' && menu != '4'&& menu != '5'&& menu != '6'&& menu != '7')
    {
        cout<< "\n\nThat's not a valid choice. Try again: ";
        cin>> menu;
    }

    if (menu == '1')
    {
        team.push(new hanzo);
    }

    if (menu == '2')
    {
        team.push(new shusaku);
    }

    if (menu == '3')
    {
       team.push(new takamori);
    }

    if (menu == '4')
    {
        team.push(new musashi);
    }

    if (menu == '5')
    {
        team.push(new ono);
    }

    if (menu == '6')
    {
        team.push(new kagenobu);
    }

    if (menu == '7')
    {
        team.push(new jubei);
    }

/*****************************
For the second team member
*****************************/

    cout<<"1) Hattori Hanzo \n\n"<<
    "2) Chiba Shusaku\n\n"<<
    "3) Saigo Takamori\n\n"<<
    "4) Miyamoto Musashi\n\n"<<
    "5) Ono Jiroemon\n\n"<<
    "6) Mima Kagenobu\n\n"<<
    "7) Yagyu Jubei\n\n"<<
    "\nPlease chose the second team member: ";
     cin>> menu;

    while (menu != '1' && menu != '2' && menu != '3' && menu != '4'&& menu != '5'&& menu != '6'&& menu != '7')
    {
        cout<< "\n\nThat's not a valid choice. Try again: ";
        cin>> menu;
    }

     if (menu == '1')
    {
        team.push(new hanzo);
    }

    if (menu == '2')
    {
        team.push(new shusaku);
    }

    if (menu == '3')
    {
       team.push(new takamori);
    }

    if (menu == '4')
    {
        team.push(new musashi);
    }

    if (menu == '5')
    {
        team.push(new ono);
    }

    if (menu == '6')
    {
        team.push(new kagenobu);
    }

    if (menu == '7')
    {
        team.push(new jubei);
    }
 /*****************************
For the third team member
*****************************/

    cout<<"1) Hattori Hanzo \n\n"<<
    "2) Chiba Shusaku\n\n"<<
    "3) Saigo Takamori\n\n"<<
    "4) Miyamoto Musashi\n\n"<<
    "5) Ono Jiroemon\n\n"<<
    "6) Mima Kagenobu\n\n"<<
    "7) Yagyu Jubei\n\n"<<
    "\nPlease chose the third team member: ";
     cin>> menu;

    while (menu != '1' && menu != '2' && menu != '3' && menu != '4'&& menu != '5'&& menu != '6'&& menu != '7')
    {
        cout<< "\n\nThat's not a valid choice. Try again: ";
        cin>> menu;
    }
    if (menu == '1')
    {
        team.push(new hanzo);
    }

    if (menu == '2')
    {
        team.push(new shusaku);
    }

    if (menu == '3')
    {
       team.push(new takamori);
    }

    if (menu == '4')
    {
        team.push(new musashi);
    }

    if (menu == '5')
    {
        team.push(new ono);
    }

    if (menu == '6')
    {
        team.push(new kagenobu);
    }

    if (menu == '7')
    {
        team.push(new jubei);
    }
}
