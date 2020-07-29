
/* 
 * File:   dealer.h
 * Author: Ahmad okde
 *
 * Created on 07/28/2020
 */
#include <iostream>
#include "hand.h"
using namespace std;

namespace Blackjack
{
#ifndef DEALER_H
#define DEALER_H


    class dealer : public Hand
    {
    public:
        void print_one_card()
        {
            cout << this->cards[0].rank()
                << this->cards[0].suit();
        }
    };


#endif /* DEALER_H */

}