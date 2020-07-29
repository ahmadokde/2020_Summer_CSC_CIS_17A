/*
 * DeckOfCards.h
  * Created on: 07/28/2020
 *  Author: Ahmad Okde
 *  Class: CIS 17 A
 *  Professor: Mark Lehr
 *  Purpose: To implement the card class.
 */
 
#include <iostream>
#include <string>
#include "blackjack.h"

using namespace std;

namespace Blackjack
{
#ifndef DECKOFCARDS_H_
#define DECKOFCARDS_H_



	class DeckOfCards
	{
	private:
		char* deck;
		char nextcard;
	public:
		DeckOfCards() {
			deck = new char[DECK_SIZE];
			for (char i = 0; i < DECK_SIZE; i++)
				deck[static_cast<int>(i)] = i; // should be set to i
			nextcard = 0;
		}
		void shuffle();
		char deal();
		~DeckOfCards() {
			delete[] deck;
		}
	};

#endif /* DECKOFCARDS_H_ */
}