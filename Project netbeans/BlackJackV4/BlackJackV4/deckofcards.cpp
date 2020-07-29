/*
 * DeckOfCards.cpp
  * Created on: 07/28/2020
 *  Author: Ahmad Okde
 *  Class: CIS 17 A
 *  Professor: Mark Lehr
 *  Purpose: To implement the card class.
 * 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "deckofcards.h"
#include "blackjack.h"
using namespace std;

using namespace Blackjack;

	/**********************************************************
	 * Function shuffles a deck of 52 cards
	 */
	void DeckOfCards::shuffle()
	{
		int i;
		int card;
		char temp;

		for (i = 0; i < DECK_SIZE; i++) {
			card = static_cast<short>(rand() % 52);
			temp = this->deck[i];
			this->deck[i] = this->deck[card];
			this->deck[card] = temp;
		}
		nextcard = 0;
	}
	/**********************************************************
	 * Function returns the next card in the deck.
	 */
	char DeckOfCards::deal()
	{
		char card = deck[static_cast<int>(nextcard)];

		nextcard++;
		return card;

	}
