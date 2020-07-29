
/* 
 * File:   dealer.h
 * Author: Ahmad Okde
 *
 * Created on : 07/28/2020
 */

#ifndef DEALER_H
#define DEALER_H
#include <iostream>
#include "hand.h"
using namespace std;

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

