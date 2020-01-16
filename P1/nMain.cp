#include "mainGame.h"
using namespace std;
void selector(int choice);

int main(){

    cout << "***Welcome to the G5 Casino!***" << endl;
    cout << "-------------------------------" << endl;
    cout << "First we have to create your rewards card.\nWhat is your name? : ";
    string username;
    cin >> username;
    cout << "\nHello " << username << "!\nHow much money would you like to load your card with? : $";
    int balance;
    cin >> balance;

    try{

        newPlayer.setName(username);
        newPlayer.setStartingBalance(balance);
        newPlayer.setBalance(balance);

    }catch(exception e){

        cout << "Error, exiting.";
        system("exit");

    }

    cout << "Rewards Card is now created, enjoy your stay!" << endl;
    cout << "---------------------------------------------" << endl;
    Sleep(2000);


    int choice = 9; //Default value
    do{

        system("color 0a");
        system("CLS");
        cout << "1. Change Name\n";
        cout << "2. Load Card\n";
        cout << "3. See Balance\n";
        cout << "4. Play Roulette\n";
        cout << "5. Play Blackjack\n";
        cout << "6. Play GOFISH!\n";
        cout << "7. Play Slots\n";
        cout << "8. Play WAR\n";
        cout << "9. Exit Casino\n";

        do{

            cout << "Enter a choice : ";
            cin >> choice;

        }while(choice > 9 || choice < 1);

        selector(choice);

    }while(choice != 9);

}

void selector(int choice){

    switch(choice){

case 1:

    {

        system("cls");
        cout << "What would you prefer to be referred as? : ";
        string temp;
        cin >> temp;
        newPlayer.setName(temp);
        cout << "\nThere we are " << temp << "!";
        Sleep(2000);
        system("cls");
        break;

    }

case 2:

    {
        system("cls");
        cout << "Enter the amount you would like to add : $";
        int tempMoney;
        cin >> tempMoney;
        newPlayer.setBalance(newPlayer.getBalance() + tempMoney);
        cout << "\nSuccessfully added $" << tempMoney << " to " << newPlayer.getName() << "'s Rewards card.";
        Sleep(2000);
        system("cls");
    }

case 3:

    {

        system("cls");
        cout << "Your current balance is: $" << newPlayer.getBalance();
        Sleep(3000);
        system("cls");
        cout << "Going Back to the Main Menu!";
        Sleep(1500);
        break;

    }

case 4:

    {
        system("cls");
        cout << "Loading Roulette...";
        Sleep(1500);
        system("cls");
        Roulette rGame(&newPlayer);
        Sleep(3000);
        system("cls");
        cout << "Going Back to the Main Menu!";
        Sleep(1500);
        break;

    }

case 5:

    {

        system("cls");
        cout << "Loading Blackjack...";
        Sleep(1500);
        system("cls");
        //Blackjack bjGame(&newPlayer);
        Sleep(3000);
        system("cls");
        cout << "Going Back to Main Menu!";
        Sleep(1500);
        break;

    }

case 6:

    {

        system("cls");
        cout << "Loading GOFISH!...";
        Sleep(1500);
        system("cls");
        gofish gfGame(&newPlayer);
        Sleep(3000);
        system("cls");
        cout << "Going Back to Main Menu!";
        Sleep(1500);
        break;

    }

case 7:

    {

        system("cls");
        cout << "Loading Slots...";
        Sleep(1500);
        system("cls");
        slots sGame;
        sGame.playGame();
        system("cls");
        cout << "Going Back to Main Menu!";
        Sleep(1500);
        break;

    }

case 8:

    {

        system("cls");
        cout << "Loading WAR...";
        Sleep(1500);
        system("cls");
        CasinoWar cwGame;
        cwGame.playGame();
        system("cls");
        cout << "Going Back to Main Menu!";
        Sleep(1500);
        break;

    }

case 9:

    system("cls");
    cout << "Thank you for visiting G5 Casino " << newPlayer.getName() << "!" << endl;
    cout << "Have a nice day!";
    Sleep(1000);
    system("cls");

    }

}

