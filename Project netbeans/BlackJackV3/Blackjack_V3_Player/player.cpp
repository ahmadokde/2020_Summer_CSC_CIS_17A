/*
 * player.h
 *
 *   Created on: 07/28/2020
 *   Author: Ahmad Okde
 *   Class: CIS-17A
 *   Professor: Mark Lehr
 *   Purpose: blackjack definitions.
 */
#include <iostream>
#include <cctype>
#include "blackjack.h"
#include "deckofcards.h"
#include "player.h"
#include "hand.h"
using namespace std;
/**********************************************************
 *
 */
Player::Player()
{
	this->Deck = nullptr;
	this->size = 1;
	this->purse = 500;
}
/**********************************************************
 * Constructs a player object as part of the Player class.
 */
Player::Player(DeckOfCards &Deck)
{
	int c;
	this->Deck = &Deck;
	this->size = 1;
	this->purse = 500;
	for(c = 0;c < MAX_HANDS;c++)
		this->hands[c].initialize();

}
/**********************************************************
 * Function deals the first two cards in a hand at the
 * beginning of a game.
 */
void Player::firstdeal()
{
	this->hands[0].initialize();
	this->hands[0].addcard(Deck->deal());
	this->hands[0].addcard(Deck->deal());
	this->hands[0].SetStat(Hit);
}
