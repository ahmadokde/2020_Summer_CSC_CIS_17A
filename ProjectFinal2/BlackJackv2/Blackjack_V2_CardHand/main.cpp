

/* 
 * File:   main.cpp
 * Author: Ahmad okde
 *
 * Created on : 07/28/2020
 */

#include <cstdlib>

#include "deckofcards.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    DeckOfCards deck;
    deck.deal();
    deck.shuffle();
    deck.printDeck();
    return 0;
}

/* ********************************************************
 * Function itoa();
 * From The C programming language Second Edition
 * Brian w. Kernighan and Dennis M Ritchie
 *
 */
void itoa(int n, char s[])
{
    int i, sign;

    if((sign = n) < 0) /* record sign */
        n = -n;
    i = 0;
    do{
        s[i++] = n % 10 + '0';
    } while((n /= 10) > 0);
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
/**********************************************************
 * Function reverse()
 * From The C programming language Second Edition
 * Brian w. Kernighan and Dennis M Ritchie
 */
void reverse(char *s)
{
    int c, i, j;

    for(i = 0, j = strlen(s)-1; i < j; i++, j--){
        c = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = c;
    }
}

/**********************************************************
 * the function getcard determines wither a card is a
 * ace, jack, queen, king, or a number card and returns
 * a c string encoded the characters "A", "J", "Q", "K",
 * or digits.
 */
char *getcard(short card, char *str)
{
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
