#include "CardDeckPlayer.h"
using namespace std;

Card::Card(int value, string suit){

    rank = value;
    suite = suit;

}

void Card::setRank(int newRank){

    rank = newRank;

}

int Card::getRank(){

    return rank;

}

string Card::getSuit(){

    return suite;

}

string Card::getCard(){

    string rCard;

    switch(rank){
        case 2:

            rCard = "2 of " + suite;
            break;

        case 3:

            rCard = "3 of " + suite;
            break;

        case 4:

            rCard = "4 of " + suite;
            break;

        case 5:

            rCard = "5 of " + suite;
            break;

        case 6:

            rCard = "6 of " + suite;
            break;

        case 7:

            rCard = "7 of " + suite;
            break;

        case 8:

            rCard = "8 of " + suite;
            break;

        case 9:

            rCard = "9 of " + suite;
            break;

        case 10:

            rCard = "10 of " + suite;
            break;

        case 11:

            rCard = "Jack of " + suite;
            break;

        case 12:

            rCard = "Queen of " + suite;
            break;

        case 13:

            rCard = "King of " + suite;
            break;

        case 1:

            rCard = "Ace of " + suite;  //Whether ace is low or high can be sorted out later by game.
            break;

        }

        return rCard;

}

void Card::printCard(){

    //Make sure suit is always capitalized

    if(getRank() <= 10 && getRank() > 1){

        cout << rank << " of " << suite;

    }else{

        switch(getRank()){

        case 11:

            cout << "Jack of " << suite;
            break;

        case 12:

            cout << "Queen of " << suite;
            break;

        case 13:

            cout << "King of " << suite;
            break;

        case 1:

            cout << "Ace of " << suite;  //Whether ace is low or high can be sorted out later by game.
            break;

        }

    }

}

Deck::Deck(){

    //Default Deck constructor makes a standard deck of 52 cards.

    for(int i = 1; i < 5; i++){

        for(int j = 1; j < 14; j++){

            switch(i){

        case 1:

            {
             Card newCard(j, "Spades");
             cards.push_back(newCard);
             break;
            }

        case 2:

            {
             Card newCard(j, "Diamonds");
             cards.push_back(newCard);
             break;
            }

        case 3:

            {
             Card newCard(j, "Clovers");
             cards.push_back(newCard);
             break;
            }

        case 4:

            {
             Card newCard(j, "Hearts");
             cards.push_back(newCard);
             break;
            }

            }

        }

    }

}

void Deck::shuffle(){

   random_shuffle(cards.begin(), cards.end());

}

void Deck::printDeck(){

    for(int i = 0; i < (int) cards.size(); i++){

        cards[i].printCard();
        cout << endl;

    }

}

Card Deck::draw(){

    Card drwdCard = cards.back();
    discard();
    return drwdCard;

}

void Deck::discard(){

    cards.pop_back();

}

Player::Player(){

    name = "";
    balance = 0;
    startingBalance = 0;

}

void Player::setBalance(int newBalance){

    balance = newBalance;

}

void Player::setName(string newName){

    name = newName;

}

void Player::setStartingBalance(int sBal){

    startingBalance = sBal;

}

int Player::getBalance(){

    return balance;

}

string Player::getName(){

    return name;

}

int Player::getStartingBalance(){

    return startingBalance;

}

vector<Card> Player::getHand(){

    return hand;

}

void Player::printHand(){

    cout << "Your current hand is : " << endl;

    for(int i = 0; i < (int) hand.size(); i++){

        cout << "\t";
        hand[i].printCard();
        cout << endl;

    }


}

void Player::printPlayer(){

    cout << name << "has $" << balance << "available.";

}

//Added by Niko 11/29/17
int Deck::getSize(){

    return cards.size();

}

//Added by Tyler Jerd 12/1/17
void Player::add2Hand(Card nCard){

    hand.push_back(nCard);

}

bool Player::delFromHand(Card dCard){

    bool flag = false;
    for(int i = 0; i < (int) hand.size(); i++){

        if(hand[i].getCard() == dCard.getCard()){

            hand.erase(hand.begin() + i);
            flag = true;

        }

    }

    return flag;

}
