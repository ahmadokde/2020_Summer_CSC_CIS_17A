/*
 * player.h
 
 * Created on: 07/28/2020
 *  Author: Ahmad Okde
 *  Class: CIS 17 A
 *  Professor: Mark Lehr
 *  Purpose: To implement the card class.
 */

#include "hand.h"
#include "deckofcards.h"

namespace Blackjack
{
#ifndef PLAYER_H_
#define PLAYER_H_


	using namespace std;

	class Player
	{
	protected:
		Hand hands[MAX_HANDS];
		int size;
		DeckOfCards* Deck;
		int purse;
	public:
		Player();
		Player(DeckOfCards& Deck);
		void SetDeck(DeckOfCards& Deck) { this->Deck = &Deck; }
		void firstdeal();
		virtual void printHands();
		void play();

	};

#endif /* PLAYER_H_ */
}