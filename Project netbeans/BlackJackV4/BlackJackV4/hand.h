/*
 * hand.h
 * Created on: 07/28/2020
 *  Author: Ahmad Okde
 *  Class: CIS 17 A
 *  Professor: Mark Lehr
 *  Purpose: To implement the card class.
 */

#include <string>
#include "blackjack.h"
#include "card.h"
using namespace std;

namespace Blackjack
{
#ifndef HAND_H_
#define HAND_H_

	class Hand
	{
	protected:
		Card* cards;
		int last;
		status stat;
		int wager;
	public:
		// Initializer
		Hand();
		virtual void print();
		void PrntStat();
		Card getcard(int sub);
		void SetStat(status s) { this->stat = s; }
		status GetStat() { return this->stat; }
		void addcard(const char card);
		Hand split();
		void hit(char card);
		void DoubleDown(char card);
		void stand();
		void initialize();
		short countcards();
		void operator=(const Hand& right);
		~Hand() { delete[] cards; }
	};

#endif /* HAND_H_ */
}