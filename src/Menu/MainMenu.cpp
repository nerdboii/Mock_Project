#define WIN32_LEAN_AND_MEAN

#include <MainMenu.h>
#include <windows.h>
#include <SetPointer.h>
#include <ReplayMenu.h>
#include <PlayerInfoMenu.h>
#include <MultiPlayerMenu.h>
#include <ValidInput.h>
#include <SinglePlayerMenu.h>

#include <iostream>

using namespace std;

void handleChoice(MENU_OPTION, bool &);

void startMainMenu() {
    int option;
    string input;
    bool stop = 0;
    while (true) {
        system("cls");
        gotoxy(0, 0, 0);
        gotoxy(0, 0, 1);
        cout << "*__________MAIN MENU___________*" << endl;
        cout << "1. Multiplayer\n";
        cout << "2. Singleplayer\n";
        cout << "3. Replay\n";
        cout << "4. Players' Information\n";
        cout << "5. Guide\n";
        cout << "6. Exit\n";
        cout << "Press number to choose: ";
        while (true) {
            clear (24, 7);
            if (!isValidInteger(input, option)) {
                cout << "Invalid input: not an integer! Press any key to re-enter option!\n";
                cin.get();
                clear(0, 8);
            }
            else break;
        }
        option--;
        MENU_OPTION choice = static_cast<MENU_OPTION>(option);
        handleChoice(choice, stop);
        if (stop) break;
    }
}

void handleChoice(MENU_OPTION choice, bool &stop) {
    switch (choice) {
    case MULTIPLAYER:
        startMultiPlayerMenu();
        break;
    case SINGLEPLAYER:
        startSinglePlayerMenu();
        break;
    case REPLAY:
        startReplayMenu();
        break;
    case PLAYER_INFO:
        startPlayerInfoMenu();
        break;
    case GUIDE:

        break;
    case EXIT:
        stop = 1;
        break;
    default:
        cout << "Invalid option, please enter another number!\n";
        cin.ignore();
        cin.get();
        break;
    }
}