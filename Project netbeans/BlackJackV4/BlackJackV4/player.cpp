/*
 * player.h
  * Created on: 07/28/2020
 *  Author: Ahmad Okde
 *  Class: CIS 17 A
 *  Professor: Mark Lehr
 *  Purpose: To implement the card class.
 */

#include <iostream>
#include <cctype>
#include "blackjack.h"
#include "deckofcards.h"
#include "player.h"
#include "hand.h"
using namespace std;
using namespace Blackjack;

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
	Player::Player(DeckOfCards& Deck)
	{
		int c;
		this->Deck = &Deck;
		this->size = 1;
		this->purse = 500;
		for (c = 0; c < MAX_HANDS; c++)
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
	/**********************************************************
	 * Function prints all hands a player has.
	 */
	void Player::printHands()
	{
		int c;

		for (c = 0; c < size; c++) {
			cout << "Hand #" << c + 1 << " ";
			this->hands[c].print();
			this->hands[c].PrntStat();
			cout << endl;
		}
	}
	void Player::play()
	{
		int c = 0;
		char input;

		while (this->hands[this->size - 1].GetStat() != Stand && this->hands[this->size - 1].GetStat() != Bust) {
			this->printHands();
			cout << endl;
			while (this->hands[c].GetStat() != Hit && c < this->size && c < MAX_HANDS)
				c++;
			if (c < this->size) {

				cout << "Playing Hand #" << c + 1 << endl;
				cout << "H for Hit." << endl;
				cout << "S for Stand." << endl;
				cout << "T for Split." << endl;

				cout << "D for Double Down" << endl;

				cin >> input;

				switch (toupper(input)) {
				case 'H':
					this->hands[c].hit(this->Deck->deal());
					break;
				case 'S':
					this->hands[c].stand();
					break;
				case 'T':
					if (this->size < MAX_HANDS) {
						this->size++;
						this->hands[this->size - 1] = this->hands[c].split();
						this->hands[this->size - 1].addcard(this->Deck->deal());
						//this->hands[c+1].SetStat(first);
						this->hands[c].addcard(this->Deck->deal());
						//this->hands[c].SetStat(first);
					}
					break;
				case 'D':
					this->hands[c].DoubleDown(this->Deck->deal());
					break;
				case 'Q':
					exit(0);
					break;
				default:
					break;
				}
			}
		}
	}
