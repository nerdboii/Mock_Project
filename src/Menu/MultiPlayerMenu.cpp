#define WIN32_LEAN_AND_MEAN

#include <MultiPlayerMenu.h>
#include <MultiPlayerGame.h>
#include <SetPointer.h>
#include <ValidInput.h>

#include <iostream>
#include <windows.h>

using namespace std;

void handlePlayingChoice(MULTIPLAYER_OPTION, bool &);

void startMultiPlayerMenu() {
    int option;
    string input;
    bool stop = 0;
    cin.get();
    while (true) {
        system("cls");
        gotoxy(0, 0, 0);
        gotoxy(0, 0, 1);
        cout << "*__________Multiplayer Menu__________*\n";
        cout << "1. Start multiplayer game\n";
        cout << "2. Exit to Main Menu\n";
        cout << "Press number to choose: ";
        while (true) {
            clear (24, 3);
            if (!isValidInteger(input, option)) {
                cout << "Invalid input: not an integer! Press any key to re-enter option!\n";
                cin.get();
                clear(0, 4);
            }
            else break;
        }
        option--;
        MULTIPLAYER_OPTION choice = static_cast<MULTIPLAYER_OPTION>(option);
        handlePlayingChoice(choice, stop);
        if (stop) break;
    }
}

void handlePlayingChoice(MULTIPLAYER_OPTION choice, bool &stop) {
    string p1_name, p2_name;
    switch (choice) {
    case PLAY:
        // Create another Match
        system("cls");
        cout << "Enter Player 1's name: ";
        cin >> p1_name;
        cout << endl;
        cout << "Enter Player 2's name: ";
        cin >> p2_name;
        MultiPlayerGame(p1_name, p2_name);
        break;
    case EXIT_MULTIPLAYER:
        stop = 1;
        break;
    default:
        cout << "Invalid option, please enter another number!\n";
        cin.ignore();
        cin.get();
        break;
    }
}