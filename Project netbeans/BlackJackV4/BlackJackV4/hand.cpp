/*
 * hand.h
  * Created on: 07/28/2020
 *  Author: Ahmad Okde
 *  Class: CIS 17 A
 *  Professor: Mark Lehr
 *  Purpose: To implement the card class.
 */

#include <iostream>
#include "blackjack.h"
#include "hand.h"
#include <cstring>

using namespace std;

using namespace Blackjack;

	/**********************************************************
	 * Class Constructor implementation
	 */
	Hand::Hand()
	{
		int c;

		this->cards = new Card[MAX_CARDS];

		for (c = 0; c < MAX_CARDS; c++)
			this->cards[c] = -1;
		this->stat = first;
		this->last = 0;
		this->wager = 0;
	}
	/**********************************************************
	 * Function Prints the status variable for a hand object.
	 */
	void Hand::PrntStat()
	{
		switch (this->stat) {
		case first:
			cout << "Open";
			break;
		case Hit:
			cout << "Hit";
			break;
		case Surrender:
			cout << "Surrender";
			break;
		case Stand:
			cout << "Stand";
			break;
		case Double:
			cout << "Double down";
			break;
		case Bust:
			cout << "Bust";
			break;
		default:
			break;
		}
	}
	Card Hand::getcard(int sub)
	{
		return this->cards[sub];
	}
	/**********************************************************
	 * Function prints a card hand stored in an object of
	 * type Hand class.
	 */
	void Hand::print()
	{
		int c;
		char* rank;
		if (this->last > 0) {
			for (c = 0; c < last; c++) {
				rank = cards[c].rank();
				cout << rank << cards[c].suit() << " ";
				delete[] rank;
			}
			cout << "\nTotal: " << this->countcards() << " ";
		}
	}
	/**********************************************************
	 * Function adds a card to the hand.
	 */
	void Hand::addcard(const char card)
	{
		if (this->last == MAX_CARDS) {
			cout << "ERROR: Maximum cards in hand." << endl;
			return;
		}
		else {
			this->cards[this->last] = card;
			this->last++;
		}
	}
	/**********************************************************
	 * Splits a two of a kind hand returns the new hand;
	 */
	Hand Hand::split() {

		Hand handtwo;

		char* str1, * str2;
		str1 = this->cards[0].rank();
		str2 = this->cards[1].rank();
		if (strcmp(str1, str2) == 0 && this->last == 2) {
			cout << "Splitting" << endl;
			handtwo.cards[0] = this->cards[1];
			handtwo.SetStat(Hit);
			handtwo.last = 1;
			this->cards[1] = -1;
			this->stat = Hit;
			this->last = 1;
		}
		delete[] str1;
		delete[] str2;
		return handtwo;
	}
	/**********************************************************
	 *
	 */
	void Hand::hit(char card)
	{
		this->addcard(card);
		this->stat = Hit;
	}
	/**********************************************************
	 *
	 */
	void Hand::DoubleDown(char card)
	{
		this->addcard(card);
		this->wager *= 2;
		this->stat = Stand;
	}
	/**********************************************************
	 *
	 */
	void Hand::stand()
	{
		this->stat = Stand;
	}
	/**********************************************************
	 * Function initializes an object type Hand class.
	 */
	void Hand::initialize()
	{
		int c;

		for (c = 0; c < MAX_CARDS; c++) {
			this->cards[c] = -1;
		}
		this->last = 0;
	}
	/**********************************************************
	 * Function counts the total velue of a hand.
	 */
	short Hand::countcards()
	{
		short accum = 0;
		short aces = 0;
		int c;

		for (c = 0; c < this->last; c++) {
			if (this->cards[c].value() == 11)
				aces++;
			if (this->cards[c].value() < 0) {
				return -1;
			}
			accum += this->cards[c].value();
		}

		while (accum > 21 && aces > 0) {
			accum -= 10; //subtracts 10 for an ace.
			aces--;
		}
		if (accum > 21)
			this->stat = Bust;
		return accum;

	}
	void Hand::operator=(const Hand& right)
	{
		int c;
		for (c = 0; c < MAX_CARDS; c++) {
			this->cards[c] = right.cards[c];
		}
		this->last = right.last;
		this->stat = right.stat;

	}
	/**********************************************************
	 * Function returns the value of a card in a hand of cards
	 * by overriding the bracket operator.
	 *
	char Hand::operator[](const int sub)
	{
		char r = this->cards[sub].get();
		return r;
	}
	*/
