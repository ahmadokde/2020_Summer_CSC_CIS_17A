/*
 * game.cpp
 *   Created on: 07/28/2020
 *   Author: Ahmad Okde
 *   Class: CIS-17A
 *   Professor: Mark Lehr
 *   Purpose: blackjack definitions.
 */
#include <iostream>
#include "blackjack.h"
#include "deckofcards.h"
#include "card.h"
#include "hand.h"
#include "player.h"
#include "game.h"
#include "dealer.h"
using namespace std;
Game::Game()
{
	int players;
	this->num_of_players = 0;
	for(players = 0; players < MAX_PLAYERS; players++){
		this->player[players].SetDeck(this->Deck);
	}
}



