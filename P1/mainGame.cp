#include "mainGame.h"
using namespace std;

Player newPlayer;

//SLOTS by Niko
slots::slots(){

    pot = 0;
    srand (time (0));
    setupGame();
    system("color 1A");

}

void slots::playGame(){

    cout << "\n*** Welcome to Slots! ***\n";
    Sleep(500);

    printMatrix();

    int choice;

    do{

    cout << "You have $" << newPlayer.getBalance() << " ...\n";

    slotsMenu();


    do{
        cin >> choice;

        switch(choice){

        case 1:

            tryWager();

            if(pot > 0){

                pullLever();
                printMatrix();
                results(ifWin());

            }

            newPlayer.setBalance(newPlayer.getBalance() + pot);
            pot = 0;
            Sleep(5000);
            system("CLS");
            break;

        case 2:

            printRules();
            system("CLS");
            break;

        case 3:

            cout << "You ended with $" << newPlayer.getBalance() << " ...\n";
            cout << "GoodBye!";
            system("CLS");
            break;

        case 4:

            {
            tryWager();
            //int stop = 0;
            do{

                pullLever();
                pullLever();
                cout << ifWin() << endl;

            }while(ifWin() == 0);

            results(ifWin());
            newPlayer.setBalance(newPlayer.getBalance() + pot);
            pot = 0;
            break;
            }

        default:

            cout << "Not a valid choice!";

        }

    }while(choice < 1 && choice > 4);

    }while(choice != 3);
}

void slots::results(int r){

    switch(r){

    case 1:

        pot *= 3;
        cout << "Love! " << newPlayer.getName() << " has won $" << pot << endl;
        break;

    case 2:

        flashWinner();
        pot *= 2;
        cout << "Double Money! " << newPlayer.getName() << " has won $" << pot << endl;
        break;

    case 3:

        flashWinner();
        pot *= 5;
        cout << "!!JACKPOT!! " << newPlayer.getName() << " has won $" << pot << endl;
        break;

    case 4:

        flashWinner();
        pot *= 1.5;
        cout << "Triples! " << newPlayer.getName() << " has won $" << pot << endl;
        break;

    default:

        cout << "Oops! Try Again! You lost $" << pot << endl;;
        pot = 0;

    }

}

void slots::printRules(){



}

void slots::slotsMenu(){

    cout << "\n1. Add $$$ and Pull Lever!\n";
    cout << "2. See Rules\n";
    cout << "3. Quit Slots\n";
    cout << "4.(cheat)\n";

}

void slots::tryWager(){

    cout << "\nHow much would you like to wager? : ";
    int wager;
    cin >> wager;
    cout << endl;

    if(wager <= newPlayer.getBalance() && wager > 0){

        cout << newPlayer.getName() << " has inserted $" << wager << "\n";
        newPlayer.setBalance(newPlayer.getBalance() - wager);
        pot+= wager;

    }else if(wager == 0){

        cout << "You can't bet $0!";

    }else{

        cout << "You don't have that much available! Try again. \n";
        tryWager();

    }

}

int myrandom (int i) { return std::rand()%i;}

void slots::pullLever(){

    random_shuffle(matrix.begin(), matrix.end());

}
void slots::setupGame(){

    for(int i = 1; i < 5; i++){

        for(int j = 1;  j < 5; j++){

            switch(i){

                case 1:

                {

                    Card nCard = Card(j, "<>");
                    matrix.push_back(nCard);
                    break;

                    }

                case 2:

                {

                    Card nCard = Card(j, "<3");
                    matrix.push_back(nCard);
                    break;

                }

                case 3:

                {

                    Card nCard = Card(j, "$$");
                    matrix.push_back(nCard);
                    break;

                }

                case 4:

                {

                    Card nCard = Card(j, "7s");
                    matrix.push_back(nCard);
                    break;

                }

            }

        }

    }

}

void slots::printMatrix(){

    int num = 0;

    for(int i = 0; i < 16; i++){

        cout << char(219);

    }
    cout << endl;

    for(int col = 0; col < 3; col++){

        cout << char(219);
        for(int row = 0; row < 3; row++){

            screen[row][col] = matrix[num].getSuit();
            cout << screen[row][col] << char(219);
            num++;

        }

        //Lever art
        if(col == 0){

            cout << "((@))" << char(219);

        }else{

            cout << "  |  " << char(219);

        }


        cout << endl;
        for(int i = 0; i < 10; i++){

            cout << char(219);

        }

        if(col != 2){

            cout << "  |  " << char(219);

        }else if(col == 2){

            for(int i = 0; i < 6; i++){

                cout << char(219);

            }

        }

        cout << endl;

    }

}

int slots::ifWin(){

    int res = 0;

    if(matrix[3].getSuit() == matrix[4].getSuit() && matrix[4].getSuit() == matrix[5].getSuit()){

        if(matrix[5].getSuit() == "<3"){

            res = 1;

        }else if(matrix[5].getSuit() == "$$"){

            res = 2;

        }else if(matrix[5].getSuit() == "7s"){

            res = 3;

        }else if(matrix[5].getSuit() == "<>"){

           res = 4;

        }

    }else{

            res = 0;

        }

        return res;

}


void slots::flashWinner(){

    HANDLE textS = GetStdHandle(STD_OUTPUT_HANDLE);

    for(int i = 2; i < 5; i++){

        system("CLS");
        //system("color 9b");
        SetConsoleTextAttribute(textS, i);
        cout << "\n";
        cout << "||   / |  / /                                         //\n";
        cout << "||  /  | / / ( )   __       __      ___      __      // \n";
        cout << "|| / /||/ / / / //   ) ) //   ) ) //___) ) //  ) )  //  \n";
        cout << "||/ / |  / / / //   / / //   / / //       //            \n";
        cout << "|  /  | / / / //   / / //   / / ((____   //       //    \n";
        //system("Color F6");
        //system("Color 44");
        Sleep(300);
        system("CLS");
        printMatrix();
        Sleep(300);


    }

    system("color 1a");

}
//End Slots by Niko

//Begin Roulette by Pedro
/*
	Takes reference to Player object as parameter.
	Plays Roulette until user exits the game or balance reaches 0.
*/
Roulette::Roulette(Player *newUser)
{
	playRoulette(newUser);
}

/*
	Takes user's input in the form of a string as its parameter.
	Returns true if: string is an integer
	Returns false if: string is not an integer
*/
bool Roulette::validInput(const string& userInput)
{
	return !userInput.empty() && std::find_if(userInput.begin(),
        userInput.end(), [](char c) { return !std::isdigit(c); }) == userInput.end();
}

/*
	Takes user's input in the form of a string as its parameter.
	Returns true if: string is one of the available options 0-7
	Returns false if: string is not a valid choice
*/
bool Roulette::validChoice(const string& userInput)
{
	if(atoi(userInput.c_str()) < 0 || atoi(userInput.c_str()) > 7)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*
	Takes user's input in the form of a string as its parameter.
	Returns true if: string is an int from [0-36]
	Returns false otherwise.
*/
bool Roulette::validNumber(const string& userInput)
{
	int userNumber;

	if(validInput(userInput))
	{
		userNumber = atoi(userInput.c_str());

		if(userNumber < 0 || userNumber > 36){
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

/*
	Takes two ints as paramaters (balance and bet).
	Return true if: bet < balance
	Return false if: bet > balance or user places no bet
*/
bool Roulette::canBet(int balance, int bet)
{
	if(bet > balance)
	{
		return false;
	}
	else if (bet <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*
	Displays Roulette menu.
*/
void Roulette::displayMenu()
{
	cout << "\nSelect a move." << endl;
	cout << "(0)Exit Game" << endl;
	cout << "(1)Bet on Number" << endl;
	cout << "(2)Bet on Red" << endl;
	cout << "(3)Bet on Black" << endl;
	cout << "(4)Bet on Evens" << endl;
	cout << "(5)Bet on Odds" << endl;
	cout << "(6)Bet on High" << endl;
	cout << "(7)Bet on Low" << endl;
}


void Roulette::playRoulette(Player *player)
{
	srand(time(NULL)); //for random numbers

	int bet;
	int rolled;
	int number;
	int choice;

	string move;
	string str;

	bool endGame = false;
	bool validMove = false;
	int balance = player->getBalance();

	vector<int> red = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
	vector<int> black = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};

	cout << "Welcome to Roulette" << endl;

	while(!endGame)
	{
		cout << "Balance: $" << balance << endl;

		if (balance == 0)
		{
			cout << "You have no money." << endl;
			endGame = true;
			break;
		}

		cout << "How much would you like to bet? " << endl;
		cin >> str;

		if(!validInput(str))
		{
			str = "";
			cout << "\nPlease enter a valid bet." << endl;
			continue;
		}
		else
		{
			bet = atoi(str.c_str());
			str = "";
		}



		//Check if user is able to place the bet
		if(!canBet(balance,bet))
		{
			cout << "\nPlease enter a valid bet." << endl;
			continue;
		}

		//Displays menu until user has chosen a valid choice from the menu
		do
		{
			displayMenu();
			cin >> move;
			cin.clear();
		} while (!validInput(move) || !validChoice(move));


		choice = atoi(move.c_str());

		//Choose 0 to exit?? *Remove if not needed
		if(choice == 0)
		{
			cout << "Thanks for Playing!" << endl;
			cout << "Your Balance: " << player->getBalance() << endl;
			break;
		}

		switch(choice)
		{
			case 1:

				//Keep asking user for number until an integer is entered
				do
				{
					cout << "\nWhat number would you like to bet on? [0-36]" << endl;
					cin >> str;
				} while (!validInput(str) || !validNumber(str));

				number = atoi(str.c_str());

				cout << "You placed " << bet << " on " << number << endl;
			break;

			case 2:
				cout << "You placed " << bet << " on " << "RED" << endl;
			break;

			case 3:
				cout << "You placed " << bet << " on " << "BLACK" << endl;
			break;

			case 4:
				cout << "You placed " << bet << " on " << "EVENS" << endl;
			break;

			case 5:
				cout << "You placed " << bet << " on " << "ODDS" << endl;
			break;

			case 6:
				cout << "You placed " << bet << " on " << "HIGH" << endl;
			break;

			case 7:
				cout << "You placed " << bet << " on " << "LOW" << endl;
			break;

		}

		//Roll
		cout << "\n\nRolling..." << endl;
		rolled = rand() % 36;
		cout << "Rolled " << rolled << "\n\n" << endl;

		//Win or Lose
		if(rolled == number && choice == 1)
		{
			cout << "You won!" << endl;
			balance += bet;
			player->setBalance(balance);
		}
		else if(rolled == 0)
		{
			cout << "Sorry, you lost." << endl;
			balance -= bet;
			player->setBalance(balance);
		}
		else if(find(red.begin(), red.end(), rolled) != red.end() && choice ==2) //RED
		{
			cout << "You won!" << endl;
			balance += bet;
			player->setBalance(balance);
		}
		else if(find(black.begin(), black.end(), rolled) != black.end() && choice == 3) //BLACK
		{
			cout << "You won!" << endl;
			balance += bet;
			player->setBalance(balance);
		}
		else if(rolled % 2 == 0 && choice == 4) //EVENS
		{
			cout << "You won!" << endl;
			balance += bet;
			player->setBalance(balance);
		}
		else if(rolled % 2 != 0 && choice == 5) //ODDS
		{
			cout << "You won!" << endl;
			balance += bet;
			player->setBalance(balance);
		}
		else if(rolled >= 19 && rolled <= 36 && choice == 6) //HIGHS (19-36)
		{
			cout << "You won!" << endl;
			balance += bet;
			player->setBalance(balance);
		}
		else if(rolled >= 1 && rolled <= 18 && choice == 7) //LOWS (1-18)
		{
			cout << "You won!" << endl;
			balance += bet;
			player->setBalance(balance);
		}
		else
		{
			cout << "Sorry, you lost. Better luck next time!" << endl;
			balance -= bet;
			player->setBalance(balance);
		}
	}
}
//End Roulette by Pedro
gofish::gofish(Player* newPlayer)
{
    name = newPlayer->getName();
    dealer.setName("Dealer");
    srand(time(0));
    runGoFish(newPlayer);
}


void gofish::runGoFish(Player* newPlayer){
    // acting main method
    int ante;
    cout << "Welcome to the Go Fish Table\n";
    cout << "\nPlease ante up: $";
    cin >> ante;
    while (!cin) {
        cout << "\n ERROR, enter a number: $" ;

        cin.clear();
        cin.ignore(256,'\n');
        cin >> ante;
    }
    while (ante > newPlayer->getBalance()){
        cout << "\n ERROR, insufficient funds, place a smaller bet: $" ;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> ante;
    }

    setUpGame(newPlayer);
    bool playersTurn = true; // Player starts the game
    while (deck.getSize() > 0){
        if (playersTurn){
            cout << name << "'s turn\n";
            newPlayer->printHand();
            if (startPlayerTurn(newPlayer, &dealer)){
                // if playerTurn function returns true, they get to go again
                playersTurn=true;
            }
            else{
                playersTurn=false;
            }
        }
        else {
            cout << "Dealer's turn\n";
            if (startPlayerTurn(&dealer, newPlayer)){
                playersTurn = false;
            }
            else {
                playersTurn=true;
            }
        }
        cout << "Player sets: " << checkForSets(newPlayer) << "\n";
        cout << "Dealer sets: " << checkForSets(&dealer) << "\n\n";
    }
    // Deck is empty, determine winner
    if (numSetsPlayer > numSetsDealer){
        // Player Wins (Give 2x ante up to the player and return to the casino menu)
        cout << "Congratulations " << name << ", you have beaten the dealer! " << 2*ante << " has been added to your account.\n";
    }
    else {
        cout << "Game Over. The dealer has beaten you. " << 2*ante << " will be taken from your account.\n";
    }
}

void gofish::setUpGame(Player* newPlayer){
    numSetsDealer = 0;
    numSetsPlayer = 0;
    deck.shuffle();

    // adds 7 cards to the player's and dealer's hands
    for(int i =0; i < 7; i++){
       newPlayer->add2Hand(deck.draw());
       dealer.add2Hand(deck.draw());
    }
    //newPlayer->printHand();
    //dealer.printHand();
}

bool gofish::startPlayerTurn(Player* active, Player* opponent){
    string inputRank;
    string cardRank;
    string input;

    // If the active player (current turn) is the dealer, generate a random pick
    if (active->getName() == name){
        cin.clear();
        cout << "Enter the rank of card you're looking for: ";
        bool yeet = true;
        bool run = true;
        while (run == true){
            //ensures string input
           while (yeet == true){
                cin >> input;
                if (!validInput(input)){
                    cout << "\nERROR, please enter a standard rank of a card (\"Threes\", \"Sevens\", \"Kings\"): ";
                    getline(cin, input);
                }
                else {
                    yeet=false;
                }
            }
            //ensures input rank is actually in players deck (part of the rules of gofish)
            bool found = false;
            for(int i = 0; i < (int) active->getHand().size(); i++){
                if(toLowerCase(input) == getCardRank(active->getHand()[i])){
                    found = true;
                }
            }
            if (found){
                run = false;
            }
            else {
                cout << "\nERROR, please enter a card rank that is in your deck: ";
            }
            yeet = true;
        }

    }
    else { // dealers turn
        int randIndex = rand()%active->getHand().size();
        input = getCardRank(active->getHand()[randIndex]);
        cout << "Dealer asked for " << input << "\n";

    }

    // Input is valid, check dealer's hand
    bool found = false;
    vector<int> indexOfFound;
    for (int i = 0; i < (int) opponent->getHand().size(); i++){
        // cout << toLowerCase(input) << " " << getCardRank(opponent->getHand()[i]) << "\n";
        if (toLowerCase(input) == getCardRank(opponent->getHand()[i])){
            indexOfFound.push_back(i);
            found = true;
        }
    }
    if (found){
        Card foundCard = opponent->getHand()[indexOfFound[0]];
        // Give all cards of that rank to player
        for (int i = 0; i < (int) indexOfFound.size(); i++){
            Card tempCard = opponent->getHand()[indexOfFound[0]];
            opponent->delFromHand(tempCard);
            active->add2Hand(tempCard);
        }
        cout << active->getName() << " took " << indexOfFound.size() << " of the " << foundCard.getCard() << " card(s)\n";
        //active->printHand();
        //opponent->printHand();
        return true; // current player gets another turn
    }
    else{
        // draw, GO FISH
        cout << "GO FISH! ";
        Card temp = deck.draw();
        if (active->getName() == name){
            cout << "You drew the card " << temp.getCard();
        }
        cout << "\n";

        active->add2Hand(temp);
        return false; // current players turn is over
    }
}


string gofish::toLowerCase(string s){
    string newnew = "";
    for (int i = 0; i < (int) s.length(); i++){
        char c = tolower(s[i]);
        newnew.append(1, c);

    }
    return newnew;
}

bool gofish::validInput(string input){
    vector<string> listOfValidInputs = {"Twos","Threes","Fours","Fives","Sixes",
        "Sevens","Eights","Nines","Tens","Jacks","Queens","Kings","Aces"
    };

    for (int i = 0; i < (int) listOfValidInputs.size(); i++){
        if (toLowerCase(input) == toLowerCase(listOfValidInputs[i]))
            return true;
    }
    return false;
}

string gofish::getCardRank(Card card){
    //cout << card.getCard() << " " << card.getCard().substr(0,1) << "\n";
    string firstChar = card.getCard().substr(0,1);
    int cardRank = card.getRank();
    string rank;
    if (cardRank == 2){
        rank = "twos";
    }
    else if (cardRank == 3){
        rank = "threes";
    }
    else if (cardRank == 4){
        rank = "fours";
    }
    else if (cardRank == 5){
        rank = "fives";
    }
    else if (cardRank == 6){
        rank = "sixes";
    }
    else if (cardRank == 7){
        rank = "sevens";
    }
    else if (cardRank == 8){
        rank = "eights";
    }
    else if (cardRank == 9){
        rank = "nines";
    }
    else if (cardRank == 10){
        rank = "tens";
    }
    else if (cardRank == 11){
        rank = "jacks";
    }
    else if (cardRank == 12){
        rank = "queens";
    }
    else if (cardRank == 13){
        rank = "kings";
    }
    else if (cardRank == 1){
        rank = "aces";
    }

    return rank;
}

int gofish::checkForSets(Player* user){
    int numSets = 0;

    vector<Card> set1;
    vector<Card> set2;
    vector<Card> set3;
    vector<Card> set4;
    vector<Card> set5;
    vector<Card> set6;
    vector<Card> set7;
    vector<Card> set8;
    vector<Card> set9;
    vector<Card> set10;
    vector<Card> set11;
    vector<Card> set12;
    vector<Card> set13;


    for (int i = 0; i  < (int) user->getHand().size(); i++){
        if (user->getHand()[i].getRank() == 1){
            set1.push_back(user->getHand()[i]);
            if (set1.size() == 4){
                for (int i = 0; i < 4; i++){
                    user->delFromHand(set1[i]);
                }
                numSets++;
                set1.clear();
            }
        }
        else if (user->getHand()[i].getRank() == 2){
            set2.push_back(user->getHand()[i]);
            if (set2.size() == 4){
                for (int i = 0; i < 4; i++){
                    user->delFromHand(set2[i]);
                }
                numSets++;
                set2.clear();
            }
        }
        else if (user->getHand()[i].getRank() == 3){
            set3.push_back(user->getHand()[i]);
            if (set3.size() == 4){
                for (int i = 0; i < 4; i++){
                    user->delFromHand(set3[i]);
                }
                numSets++;
                set3.clear();
            }
        }
        else if (user->getHand()[i].getRank() == 4){
            set4.push_back(user->getHand()[i]);
            if (set4.size() == 4){
                for (int i = 0; i < 4; i++){
                    user->delFromHand(set4[i]);
                }
                numSets++;
                set4.clear();
            }
        }
        else if (user->getHand()[i].getRank() == 5){
            set5.push_back(user->getHand()[i]);
            if (set5.size() == 4){
                for (int i = 0; i < 4; i++){
                    user->delFromHand(set5[i]);
                }
                numSets++;
                set5.clear();
            }
        }
        else if (user->getHand()[i].getRank() == 6){
            set6.push_back(user->getHand()[i]);
            if (set6.size() == 4){
                for (int i = 0; i < 4; i++){
                    user->delFromHand(set6[i]);
                }
                numSets++;
                set6.clear();
            }
        }
        else if (user->getHand()[i].getRank() == 7){
            set7.push_back(user->getHand()[i]);
            if (set7.size() == 4){
                for (int i = 0; i < 4; i++){
                    user->delFromHand(set7[i]);
                }
                numSets++;
                set7.clear();
            }
        }
        else if (user->getHand()[i].getRank() == 8){
            set8.push_back(user->getHand()[i]);
            if (set8.size() == 4){
                for (int i = 0; i < 4; i++){
                    user->delFromHand(set8[i]);
                }
                numSets++;
                set8.clear();
            }
        }
        else if (user->getHand()[i].getRank() == 9){
            set9.push_back(user->getHand()[i]);
            if (set1.size() == 4){
                for (int i = 0; i < 4; i++){
                    user->delFromHand(set9[i]);
                }
                numSets++;
                set9.clear();
            }
        }
        else if (user->getHand()[i].getRank() == 10){
            set10.push_back(user->getHand()[i]);
            if (set1.size() == 4){
                for (int i = 0; i < 4; i++){
                    user->delFromHand(set10[i]);
                }
                numSets++;
                set10.clear();
            }
        }
        else if (user->getHand()[i].getRank() == 11){
            set11.push_back(user->getHand()[i]);
            if (set11.size() == 4){
                for (int i = 0; i < 4; i++){
                    user->delFromHand(set11[i]);
                }
                numSets++;
                set11.clear();
            }
        }
        else if (user->getHand()[i].getRank() == 12){
            set12.push_back(user->getHand()[i]);
            if (set12.size() == 4){
                for (int i = 0; i < 4; i++){
                    user->delFromHand(set12[i]);
                }
                numSets++;
                set12.clear();
            }
        }
        else if (user->getHand()[i].getRank() == 13){
            set13.push_back(user->getHand()[i]);
            if (set1.size() == 4){
                for (int i = 0; i < 4; i++){
                    user->delFromHand(set13[i]);
                }
                numSets++;
                set13.clear();
            }
        }
    }
    // If the current player has no more cards in his hand, add 7 from the deck
    // if the deck has less than seven cards, add all the remaining cards
    if (user->getHand().size() == 0){
        int count;
        if (deck.getSize() < 7){
            count = deck.getSize();
        }
        else {
            count = 7;
        }
        cout << "Looks like you're out of cards, " << count << " more will be added to your hand\n";
        for (int i=0; i < count; i++){
            user->add2Hand(deck.draw());
        }
    }

    if (user->getName() == name){
        numSetsPlayer += numSets;
        return numSetsPlayer;
    }
    else {
        //dealer
        numSetsDealer += numSets;
        return numSetsDealer;
    }
}
//End goFish by Tyler
//Start Casino War by Hunter
CasinoWar::CasinoWar(){

    pot = 0;

}

void CasinoWar::addPot(int wager){

    pot += wager;

}

int CasinoWar::getPot(){

    return pot;

}

void CasinoWar::playGame(){

    cout << "\n***Welcome to War!***\n";
    cout << "You have $" << newPlayer.getBalance() << " ...\n";
    do{

        deck.shuffle();
        playRound();

    }while(newPlayer.getBalance() > 0);

}

bool CasinoWar::playRound(){

    //First check at least 2 cards exist in deck
    if(deck.getSize() < 2){

        //If not make a new deck
        Deck newDeck;
        deck = newDeck;

    }

    //Otherwise, get bets, flip two cards and compare

    tryWager();

    Card dealerCard = deck.draw();
    Card newPlayerCard = deck.draw();

    //Display cards
    cout << newPlayer.getName() << ": ";
    newPlayerCard.printCard();
    cout << endl;
    cout << "Dealer: ";
    dealerCard.printCard();
    cout << endl;

    if(dealerCard.getRank() > newPlayerCard.getRank()){

        cout << "Dealer wins! " << newPlayer.getName() << " lost $" << (pot / 2);
        newPlayer.setBalance(newPlayer.getBalance() - (pot / 2));

    }else if(dealerCard.getRank() < newPlayerCard.getRank()){

        cout << newPlayer.getName() << " wins $" << pot << "!";
        newPlayer.setBalance(newPlayer.getBalance() + pot);

    }else{

        ifTie();

    }

    return false; //Not needed

}

void CasinoWar::ifTie(){

    cout << "\nYou've gone to WAR with the dealer!";
    Card dCard1 = deck.draw();
    Card dCard2 = deck.draw();
    Card dCard3 = deck.draw();
    Card pCard1 = deck.draw();
    Card pCard2 = deck.draw();
    Card pCard3 = deck.draw();

    cout << "\n Dealer flips : ";
    dCard1.printCard();
    cout << " , ";
    dCard2.printCard();
    cout << " , ";
    dCard2.printCard();
    cout << " ! ";

    cout << "\n newPlayer flips : ";
    pCard1.printCard();
    cout << " , ";
    pCard2.printCard();
    cout << " , ";
    pCard2.printCard();
    cout << " ! ";

    tryWager();
    cout << "** BATTLE **\n";
    playRound();

}

void CasinoWar::tryWager(){

    cout << "\nHow much would you like to wager? : ";
    int wager;
    cin >> wager;
    cout << endl;

    if(wager <= newPlayer.getBalance() && wager > 0){

        cout << newPlayer.getName() << ": bet " << wager;
        addPot(wager * 2); //Always doubled because the dealer matches

    }else if(wager == 0){

        cout << newPlayer.getName() << ": Check.";

    }else if(wager == newPlayer.getBalance()){

        cout << newPlayer.getName() << ": ALL IN!";

    }else{

        cout << "You don't have that much available! Try again. \n";
        tryWager();

    }

}
//End Casino War by Hunter
Blackjack::Blackjack(Player *player)
{
        srand(time(0));
        play(player);

};

int Blackjack::getTotalRank(vector<Card> hand)
{
    int numAces = 0;
    int total = 0;
    int aceTotal = 0;
    bool aceChange = false;

    for (int i = 0; i < (int) hand.size(); i++) {
        if (hand.at(i).getRank() == 1) {
            total+= 11;
            numAces++;
        }else if(hand.at(i).getRank() == 11){
            total+= 10;
        }else if(hand.at(i).getRank() == 12){
            total+= 10;
        }else if(hand.at(i).getRank() == 13){
            total+= 10;
        } else {
            total += hand.at(i).getRank();
        }
    }

    for (int i = 0; i < (int) hand.size(); i++) {
        while (total > 21 && numAces > 0) {
            aceChange = true;
            if (hand.at(i).getRank() == 1) {
                aceTotal += 1;
                numAces--;
            }
        }

        if(hand.at(i).getRank() == 11){
            aceTotal+= 10;
        }else if(hand.at(i).getRank() == 12){
            aceTotal+= 10;
        }else if(hand.at(i).getRank() == 13){
            aceTotal+= 10;
        }else {
            aceTotal += hand.at(i).getRank();
        }
    }
    if (aceChange) {
        return aceTotal;
    }
    else return total;
};

void Blackjack::hit(vector<Card> &hand, Deck &b_deck)
{
    Card card(0,"");
    card = b_deck.draw();
    hand.push_back(card);
};

void Blackjack::printHandsBeforeTurn(vector<Card> p_hand, vector<Card> d_hand)
{
        std::cout << "\nYour Hand: " << endl;
        for (int i = 0; i < (int) p_hand.size(); i++) {
                p_hand.at(i).printCard();
                std::cout << "\n";
        }
        //for dealer the first card is face up and the second is face down
        std::cout << "\nDealer's Hand: " << endl;
        d_hand.at(0).printCard();
        std::cout << "\n";
        std::cout << "Face down card" << endl;

};

void Blackjack::printHandsAfterTurn(vector<Card> p_hand, vector<Card> d_hand)
{
        std::cout << "\nYour Hand: " << endl;
        for (int i = 0; i < (int) p_hand.size(); i++) {
                p_hand.at(i).printCard();
                std::cout << "\n";
        }
        std::cout << "\nDealer's Hand: " << endl;
        for (int i = 0; i < (int) d_hand.size(); i++) {
                d_hand.at(i).printCard();
                std::cout << "\n";
        }
        std::cout << "\n";
};

bool Blackjack::hasBlackjack(vector<Card> hand)
{
        if ((hand.at(0).getSuit().find("Ace") != std::string::npos) && hand.at(1).getRank() >= 10 && hand.at(1).getRank() <= 13) {
                return true;
        }
        else if ((hand.at(1).getSuit().find("Ace") != std::string::npos) && hand.at(0).getRank() >= 10 && hand.at(0).getRank() <= 13) {
                return true;
        }
    return false;
};

bool Blackjack::checkBet(int amt, int balance)
{
    if (amt <= balance && amt > 0) {
        return true;
    }
    return false;
};
//Begin Blackjack by Aaron and Max
//runs only once, simulates one round
void Blackjack::play(Player *p)
{
    std::cout << "Welcome to Blackjack!\n" << endl;

    std::cout << "House Rules: \nNo splitting\nCan only double down once\n" << endl;

    Card p_card(0,""); //player card object

    vector<Card> d_hand; //dealer's hand and card object
    Card d_card(0,"");

    //create new deck and shuffle before each round
    int winnings;
    bool p_blackjack = false;
    bool d_blackjack = false;
    int bet;
    int balance = p->getBalance();
    int new_balance;
    vector<Card> p_hand;
    bool good_bet = false;
    Deck b_deck;
    b_deck.shuffle();


    //user places bet here
    //subtract from player balance
    std::cout << "Current Balance: " << balance << endl;
    std::cout << "Input how much you want to bet here: ";
    std::cin >> bet;
    while (!cin) {
        cout << "\nERROR, enter a number: " ;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> bet;
    }
    good_bet = checkBet(bet, balance);

    //checks valid bet input
    while (!good_bet) {
        std::cout << "Invalid bet. Please input again here: ";
        std::cin >> bet;
        good_bet = checkBet(bet, balance);
    }

    //removes bet from player balance
    if (good_bet) {
        new_balance = balance - bet;
        p->setBalance(new_balance);
    }

    winnings = bet;

    //get player's and dealer's hands
    for (int i = 0; i < 2; i++) {
        p_card = b_deck.draw();
        p->add2Hand(p_card);
        d_card = b_deck.draw();
        d_hand.push_back(d_card);
    }

    p_hand = p->getHand();

    printHandsBeforeTurn(p_hand, d_hand);
    std::cout << "\nYour Total: " << getTotalRank(p_hand) << endl;
    p_blackjack = hasBlackjack(p_hand);
    d_blackjack = hasBlackjack(d_hand);

    if (p_blackjack && !d_blackjack) {
        printHandsAfterTurn(p_hand, d_hand);
        std::cout << "\nYou got Blackjack and Dealer did not!" << endl;
        //player win
        new_balance = balance + 2*winnings;
        p->setBalance(new_balance);
        std::cout << "Congratulations! You won " << winnings << " dollars" << endl;
    }

    //more game play cases here
    else {
        int input;
        int p_total = getTotalRank(p_hand);
        int d_total = getTotalRank(d_hand);
        string choice;
        bool done = false;

        //check if dealer has blackjack
        if (d_hand.at(0).getRank() == 1 || (d_hand.at(0).getRank() >= 10 && d_hand.at(0).getRank() <= 13)) {

            std::cout << "\nDealer has a rank 10 card or an ace face up, so they will check to see if they have blackjack" << endl;
            if (d_blackjack && !p_blackjack) {
                //dealer win
                new_balance = balance - winnings;
                p->setBalance(new_balance);
                std::cout << "Sorry. You lost " << winnings << " dollars" << endl;
            }
            else if (d_blackjack && p_blackjack) {
                //tie
                int new_balance = balance + winnings;
                p->setBalance(new_balance);
                std::cout << "Both you and the dealer tied. \nSo you get all " << winnings << " dollars of your bet back" << endl;
            }
            else {
                std::cout << "\nDealer does not have blackjack so continue play" << endl;
            }
        }

        std::cout << "\nDo you want to double down? (y or n)" << endl;
        std::cin >> choice;

        if (choice.compare("y") == 0) {
            winnings = 2*winnings;
            std::cout << "\nOkay. Current bet is " << winnings << " dollars" << endl;
        }

        while(!done) {
            done = true;
            //print menu of player turn choices
            std::cout << "\nYour current total: " << p_total << endl;
            std::cout << "\n1. Stand\n2. Hit\n" << endl;
            std::cout << "Input the number of the option you want here: ";
            std::cin >> input;
            while (!cin) {
                cout << "\nERROR, enter a number: " ;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> input;
            }
            cin.clear();
            while(input != 1 && input != 2) {
                std::cout << "Input either 1 or 2 for option here: ";
                std::cin >> input;
                while (!cin) {
                    cout << "\nERROR, enter a number: " ;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> input;
                }
                cin.clear();
            }

            if (input == 1) {
                printHandsAfterTurn(p_hand, d_hand);
                std::cout << "Your current total: " << p_total << endl;
                std::cout << "Dealer's current total: " << d_total << "\n" << endl;
                if (d_blackjack) {
                        //dealer win
                        new_balance = balance - winnings;
                        p->setBalance(new_balance);
                        std::cout << "Sorry. You lost " << winnings << " dollars" << endl;
                }
                while (d_total < 17)
                {
                        hit(d_hand, b_deck);
                        printHandsAfterTurn(p_hand, d_hand);
                        d_total = getTotalRank(d_hand);
                        std::cout << "Your current total: " << p_total << endl;
                        std::cout << "Dealer's current total: " << d_total << endl;
                }
                if (d_total <= 21 && d_total > p_total) {
                        //dealer win
                        new_balance = balance - winnings;
                        p->setBalance(new_balance);
                        std::cout << "Sorry. You lost " << winnings << " dollars" << endl;
                }
                else if (d_total > 21) {
                        //player win
                        winnings = 2*winnings;
                        new_balance = balance + winnings;
                        p->setBalance(new_balance);
                        std::cout << "Congratulations! You won " << winnings << " dollars" << endl;
                }
                else if (d_total <= 21 && d_total < p_total) {
                        //player win
                        winnings = 2*winnings;
                        new_balance = balance + winnings;
                        p->setBalance(new_balance);
                        std::cout << "Congratulations! You won " << winnings << " dollars" << endl;
                }
                else {
                        //tie
                        int new_balance = balance + winnings;
                        p->setBalance(new_balance);
                        std::cout << "Both you and the dealer tied, so you get all " << winnings << " dollars of your bet back" << endl;
                }
            }
            else if (input == 2) {
                string gomble;
                do {
                        hit(p_hand, b_deck);
                        printHandsBeforeTurn(p_hand, d_hand);
                        p_total = getTotalRank(p_hand);
                        std::cout << "Your current total: " << p_total << endl;
                        if (p_total < 21) {
                            std::cout << "Would you like to hit again? (y or n)" << endl;
                            std::cin >> gomble;
                        }
                        else gomble = "N";
                } while (gomble.compare("y") == 0);

                std::cout << endl;
                if (p_total > 21)
                {
                        printHandsAfterTurn(p_hand, d_hand);
                        //dealer win
                        new_balance = balance - winnings;
                        p->setBalance(new_balance);
                        std::cout << "Sorry. You lost " << winnings << " dollars" << endl;
                }
                else {
                    while (d_total < 17)
                    {
                            hit(d_hand, b_deck);
                            printHandsAfterTurn(p_hand, d_hand);
                            d_total = getTotalRank(d_hand);
                            std::cout << "Your current total: " << p_total << endl;
                            std::cout << "Dealer's current total: " << d_total << endl;
                    }
                    if (d_total <= 21 && d_total > p_total) {
                            //dealer win
                            new_balance = balance - winnings;
                            p->setBalance(new_balance);
                            std::cout << "Sorry. You lost " << winnings << " dollars" << endl;
                    }
                    else if (d_total > 21) {
                        //player win
                        winnings = 2*winnings;
                        new_balance = balance + winnings;
                        p->setBalance(new_balance);
                        std::cout << "Congratulations! You won " << winnings << " dollars" << endl;
                    }
                    else if (d_total <= 21 && d_total < p_total) {
                        //player win
                        winnings = 2*winnings;
                        new_balance = balance + winnings;
                        p->setBalance(new_balance);
                        std::cout << "Congratulations! You won " << winnings << " dollars" << endl;
                    }
                    else {
                        //tie
                        int new_balance = balance + winnings;
                        p->setBalance(new_balance);
                        std::cout << "Both you and the dealer tied, so you get all " << winnings << " dollars of your bet back" << endl;
                    }
                }
            }

            else {
                std::cout << "Invalid entry, please input again." << endl;
                done = false;
            }
        }

        std::cout << endl;
    }
};//End BlackJack by Aaron and Max
