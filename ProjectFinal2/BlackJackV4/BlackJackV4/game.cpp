/*
 * game.cpp
 *
 *  Created on: 07/28/2020
 *  Author: Ahmad okde
 */
#include <iostream>
#include "blackjack.h"
#include "deckofcards.h"
#include "card.h"
#include "hand.h"
#include "player.h"
#include "game.h"
#include "dealer.h"
using namespace std;
using namespace Blackjack;

	Game::Game()
	{
		int players;
		this->num_of_players = 0;
		for (players = 0; players < MAX_PLAYERS; players++) {
			this->player[players].SetDeck(this->Deck);
		}
	}
	void Game::prntGame()
	{
		int players;

		cout << "Dealer's hand: ";
		this->Dealer.print_one_card();
		for (players = 0; players < this->num_of_players; players++) {
			cout << "\nplayer #" << players + 1 << endl;
			this->player[players].printHands();
			cout << endl;
		}

	}
	void Game::prntEnd()
	{
		int players;
		cout << "Dealer's hand: ";
		this->Dealer.print();
		cout << endl;
		for (players = 0; players < this->num_of_players; players++) {
			cout << "\nplayer #" << players + 1 << endl;
			this->player[players].printHands();
			cout << endl;
		}
	}
	void Game::firstDeal()
	{
		int players;

		this->Deck.shuffle();
		for (players = 0; players < this->num_of_players; players++) {
			this->player[players].firstdeal();
		}
		this->Dealer.addcard(this->Deck.deal());
		this->Dealer.addcard(this->Deck.deal());

	}

	void Game::play()
	{
		int c;
		this->firstDeal();
		this->prntGame();
		for (c = 0; c < this->num_of_players; c++) {
			cout << "\nPlayer #" << c + 1 << endl;
			this->player[c].play();
		}
		this->DealerPlay();
		this->prntEnd();
	}
	void Game::DealerPlay()
	{
		while (this->Dealer.countcards() < 17)
			this->Dealer.addcard(this->Deck.deal());
	}
