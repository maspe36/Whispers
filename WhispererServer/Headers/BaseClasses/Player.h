#pragma once

#include "stdafx.h"
#include <vector>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <algorithm>
#include <random>

/* At some point there will 
   probably need to be a unique 
   hash in all objects for each game */

using namespace std;

class Card;
class Soul;

class Player
{
public:
	~Player();
	Player(string NewUserName, vector<Card*> NewDeck);

	int Health = 30;
	int MulligansTaken = 0;
	string UserName;
	bool KeepHand = false;

	mt19937 seed{ random_device{}() };

	vector<int> Devotion = {1,1,1,1,1,1};
	vector<Card*> MainDeck;
	vector<Card*> Hand;
	vector<Soul*> SoulsInPlay;
	//vector<Swift*> SwiftsInPlay;
	//vector<Constant*> ConstantsInPlay;
	vector<Card*> Graveyard;

	
	string HandToString();
	string ToString();
	string SoulsInPlayToString();

	bool IsPlayable(int HandIndex);

	void DrawCard();
	void DrawCard(int Amount);
	void ShuffleDeck();
	void HandToDeck();
	void PrintDeck();
};

