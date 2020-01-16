#include "CardDeckPlayer.h"

using namespace std;

extern Player newPlayer;

class slots{ //Begin slots by Niko

private:

    //Player player;
    int pot;
    vector<Card> matrix;
    //int total;
    string screen[3][3];

public:

    slots();
    int ifWin();
    void tryWager();
    void results(int r);
    void printRules();
    void slotsMenu();
    void setupGame();
    void playGame();
    void pullLever();
    void playTillWin();
    void flashWinner();
    void printMatrix();

};
//End Slots by Niko
//Begin Roulette by Pedro
class Roulette{
private:
	Player player;
public:
	Roulette(Player *newUser);
	void playRoulette(Player *player);
	bool validInput(const string& userInput);
	bool validChoice(const string& userInput);
	bool validNumber(const string& userInput);
	bool canBet(int balance, int bet);
	void displayMenu();

};//End Roulette by Pedro

//Begin Casino War
class Blackjack{

    public:

        Blackjack(Player *p);
    	int getTotalRank(vector<Card> hand);
	    void hit(vector<Card> &hand, Deck &b_deck);
        void printHandsBeforeTurn(vector<Card> p_hand, vector<Card> d_hand);
        void printHandsAfterTurn(vector<Card> p_hand, vector<Card> d_hand);
        bool hasBlackjack(vector<Card> hand);
        bool checkBet(int amt, int balance);
        void play(Player *p);

};
//End Casino War

class gofish{ //Begin GoFish by Tyler

private:

    Deck deck;
    Player dealer;
    int numSetsPlayer;
    int numSetsDealer;
    string name;

public:

    gofish(Player* newPlayer);

    void runGoFish(Player* newPlayer);
    void setUpGame(Player* newPlayer);
    bool startPlayerTurn(Player* active, Player* opponent);
    bool validInput(string input);
    string toLowerCase(string s);
    string getCardRank(Card card);
    int checkForSets(Player* user);
};//End GoFish by Tyler

//Begin CasinoWar by Hunter
class CasinoWar{

    private:

        Deck deck;
        int pot;

    public:

        CasinoWar();
        void playGame();
        bool playRound();
        void addPot(int wager);
        void ifTie();
        int getPot();
        void tryWager();



}; //End CasinoWar by Hunter

