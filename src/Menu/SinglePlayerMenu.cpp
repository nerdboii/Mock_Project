#define WIN32_LEAN_AND_MEAN

#include <PlayerInfoMenu.h>
#include <SetPointer.h>
#include <MatchHistory.h>
#include <MatchInfo.h>
#include <PlayerList.h>
#include <Player.h>
#include <ValidInput.h>
#include <Bot.h>
#include <SinglePlayerGame.h>
#include <BotFactory.h>

#include <iostream>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

void handleSinglePlayerChoice(DIFFICULTY, bool &);

void startSinglePlayerMenu() {
    int option, turn;
    string input;
    string pName;
    cin.get();
    while (true) {
        system("cls");
        gotoxy(0, 0, 0);
        gotoxy(0, 0, 1);
        cout << "*__________Single Player Menu__________*\n";
        cout << "1. Easy\n";
        cout << "2. Normal\n";
        cout << "3. Hard\n";
        cout << "4. Exit\n";
        cout << "Press number to choose: ";
        while (true) {
            clear (24, 5);
            if (!isValidInteger(input, option)) {
                cout << "Invalid input: not an integer! Press any key to re-enter option!\n";
                cin.get();
                clear(0, 6);
            }
            else break;
        }

        if (option == 4) {
            break;
        }
        if (option < 1 || option > 4) {
            clear(0, 6);
            cout << "Invalid option, please enter another number!\n";
            cout << "Press any key to continue\n";
            cin.ignore();
            cin.get();
        }

        clear(0, 6);
        clear(0, 7);
        cout << "Press 1 to play as X, any key else to play as O: ";
        while (true) {
            clear (49, 7);
            if (!isValidInteger(input, turn)) {
                cout << "Invalid input: not an integer! Press any key to re-enter option!\n";
                cin.get();
                clear(0, 7);
            }
            else break;
        }

        clear(0, 7);
        cout << "Enter player name: ";
        cin >> pName;

        option--;
        DIFFICULTY choice = static_cast<DIFFICULTY>(option);
        SinglePlayerGame(choice, pName, (turn == 1));
    }
}

void handleSinglePlayerChoice(DIFFICULTY choice, bool &stop, bool turn) {
    
}