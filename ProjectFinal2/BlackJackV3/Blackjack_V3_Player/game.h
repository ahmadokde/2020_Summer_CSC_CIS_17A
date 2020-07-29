/*
 * game.h
 *
 *   Created on: 07/28/2020
 *   Author: Ahmad Okde
 *   Class: CIS-17A
 *   Professor: Mark Lehr
 *   Purpose: blackjack definitions.
 */

#ifndef GAME_H_
#define GAME_H_

#include "blackjack.h"
#include "deckofcards.h"
#include "hand.h"
#include "player.h"
#include "dealer.h"

using namespace std;

class Game
{
private:
	Player player[MAX_PLAYERS];
	dealer Dealer;
	int num_of_players;
	DeckOfCards Deck;

public:
	Game();
	void Set_num_of_players(int num)
        {
            this->num_of_players = num;
            cout << this->num_of_players << " players set for the game\n\n";
        }
	
};



#endif /* GAME_H_ */
