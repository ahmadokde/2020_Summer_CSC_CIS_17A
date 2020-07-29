/*
 * player.h
 *
 *   Created on: 07/28/2020
 *   Author: Ahmad Okde
 *   Class: CIS-17A
 *   Professor: Mark Lehr
 *   Purpose: blackjack definitions.
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "hand.h"
#include "deckofcards.h"

using namespace std;

class Player
{
protected:
	Hand hands[MAX_HANDS];
	int size;
	DeckOfCards *Deck;
	int purse;
public:
	Player();
	Player(DeckOfCards &Deck);
	void SetDeck(DeckOfCards &Deck){this->Deck = &Deck;}
	void firstdeal();
	
};

#endif /* PLAYER_H_ */
