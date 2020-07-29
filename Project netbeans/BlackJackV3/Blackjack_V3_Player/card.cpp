/*  card.cpp
 *
 *   Created on: 07/28/2020
 *   Author: Ahmad Okde
 *   Class: CIS-17A
 *   Professor: Mark Lehr
 *   Purpose: blackjack definitions.
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "blackjack.h"
#include "card.h"
using namespace std;
/**********************************************************
 * Constructor function for Card class
 */
Card::Card()
{
	card = -1;
}
/**********************************************************
 * Function sets card object to a value between 0 and 51.
 */
void Card::setcard(const char card)
{
	if(card >= 0 && card < 52)
		this->card = card;
	else
		this->card = 0;
}
/**********************************************************
 *
 */
void Card::operator=(const char card)
{
	if(card >= -1 && card < 52)
		this->card = card;
	else{
		cout << "Error the var card in function Card:operator= is out of bounds." << endl;
		this->card = -1;
	}
}
void Card::operator=(const Card &right)
{
	this->card = right.card;
}
bool Card::operator==(const Card card)
{
	if(this->card == card.card){
		return true;
	}
	return false;
}
/**********************************************************
 * Returns the card's suit.
 */
char Card::suit()
{
	if(card < 13 && card >= 0)
			return 'S';
		else if(card < 26 && card >= 0)
			return 'C';
		else if(card < 39 && card >= 0)
			return 'H';
		else if(card < 52 && card >= 0)
			return 'D';
		return '\0';
}
/**********************************************************
 * Function returns a cards rank A through K.
 */
char *Card::rank()
{
	char *str = new char[3];

	if(card%13 == 0){
			str[0] = 'A';
	                str[1] = '\0';
	        }else if(card%13 >= 1 && card%13 < 9)
			itoa(card%13+1,str);
		else if(card%13 == 9 ){
			str[0]='1';
	                str[1]='0';
	                str[2]='\0';
	        }
		else if(card%13 == 10){
	            str[0] = 'J';
	            str[1] = '\0';
	        }
		else if(card%13 == 11){
	            str[0] = 'Q';
	            str[1] = '\0';
	        }
		else if(card%13 == 12){
	            str[0] = 'K';
	            str[1] = '\0';
	        }
		else {
	           str[0] = '\0';
	        }
		return str;

}
/**********************************************************
 * Function returns a cards value 2 through 11.
 */
int Card::value()
{

		char *str = new char[3];
		short i = 0;
		str = getcard(static_cast<int>(card), str);


		if(str[0] == 'A')
			i = 11;
		else if (str[0] == 'J' || str[0] == 'Q' || str[0] == 'K')
			i = 10;
		else if(str[0] >= '1' && str[0] <= '9')
			i = static_cast<short>(atoi(str));
		else
			i = -1; //If an error happens.
		delete[] str;
		return i;

}
