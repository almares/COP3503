#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <windows.h>
#include <time.h>

//#include "CardDeckPlayer.h"

//Last Updated 112/3
using namespace std;

class Card{

	private:

		int rank;
		string suite;

	public:

		Card(int value, string suit);
		int getRank();
		void setRank(int newRank);
		string getSuit();
		string getCard(); //Not sure what this is for?
		void printCard();

		//No Setter Methods needed because the cards aren't being modified.
};

class Deck{

    //Use vector for deck instead of Array
	private:

		vector<Card> cards;

	public:

		Deck(); //Automatically constructs a deck of 52 cards, not shuffled.
		void shuffle();
		Card draw();
		void discard();
		int getSize(); //Added by Niko 12/1
		void printDeck();

};

class Player{

	private:

		string name;
		int balance;
		int startingBalance;
		vector<Card> hand; //Using card vector for hand instead of an array of Card objects

	public:

		Player();
		string getName();
		int getBalance();
		int getStartingBalance();
		vector<Card> getHand();
		void setName(string newName);
		void setBalance(int newBalance);
		void setStartingBalance(int sBal); //Is this needed? ...Maybe to track winnings
		void printHand();
		void printPlayer(); //Prints name and balance... (maybe history of games played)

		void add2Hand(Card nCard);
		bool delFromHand(Card dCard);

};
