/* blackjack.h
 *  Created on: 07/28/2020
 *  Author: Ahmad Okde
 *  Class: CIS 17 A
 *  Professor: Mark Lehr
 *  Purpose: blackjack definitions.
 */
namespace Blackjack
{
#ifndef BLACKJACK_H_
#define BLACKJACK_H_

    const int DECK_SIZE = 52;
    const int MAX_CARDS = 12;
    const int MAX_HANDS = 4;
    const int MAX_PLAYERS = 5;

    
    enum status { Not_Used = -1, first, Hit, Surrender, Stand, Double, Bust };


    void itoa(int n, char s[]);
    void reverse(char* s);
    char* getcard(short card, char* str);

#endif /* BLACKJACK_H_ */
}