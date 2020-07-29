/*
 * game.h
 *
 *  Created on: 07/28/2020
 *   Author: Ahmad okde
 */

#include "blackjack.h"
#include "deckofcards.h"
#include "hand.h"
#include "player.h"
#include "dealer.h"

using namespace std;

namespace Blackjack
{
#ifndef GAME_H_
#define GAME_H_


	class Game
	{
	private:
		Player player[MAX_PLAYERS];
		dealer Dealer;
		int num_of_players;
		DeckOfCards Deck;

	public:
		Game();
		void Set_num_of_players(int num) { this->num_of_players = num; }
		void firstDeal();
		void prntGame();
		void prntEnd();
		void play();
		void DealerPlay();
	};



#endif /* GAME_H_ */
}