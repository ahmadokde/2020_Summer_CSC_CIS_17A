/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ahmad okde
 *
 * Created on 22 July, 2020, 12:06 AM
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

