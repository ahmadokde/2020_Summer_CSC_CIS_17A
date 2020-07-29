/*  card.h
 * Created on: 07/28/2020
 *  Author: Ahmad Okde
 *  Class: CIS 17 A
 *  Professor: Mark Lehr
 *  Purpose: To implement the card class.
 */
namespace Blackjack
{
#ifndef CARD_H_
#define CARD_H_
	/**********************************************************
	 * Card Class represents one of 52 possible cards
	 */
	class Card
	{
	private:
		char card;
	public:
		Card();
		void setcard(const char card);
		char get() { return this->card; }
		void operator=(const char card);
		void operator=(const Card& right);
		bool operator==(const Card card);
		char suit();
		char* rank();
		int value();
	};



#endif /* CARD_H_ */
}