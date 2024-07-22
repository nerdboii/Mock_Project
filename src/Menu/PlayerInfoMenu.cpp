#define WIN32_LEAN_AND_MEAN

#include <PlayerInfoMenu.h>
#include <SetPointer.h>
#include <MatchHistory.h>
#include <MatchInfo.h>
#include <PlayerList.h>
#include <Player.h>
#include <ValidInput.h>

#include <iostream>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

void handlePlayerInfoChoice(PLAYER_INFO_MENU, bool &);

void startPlayerInfoMenu() {
    int option;
    string input;
    bool stop = 0;
    cin.get();
    while (true) {
        system("cls");
        gotoxy(0, 0, 0);
        gotoxy(0, 0, 1);
        cout << "*__________Player Info Menu__________*\n";
        cout << "1. View all players info\n";
        cout << "2. View one player's info\n";
        cout << "3. Exit to Main Menu\n";
        cout << "Press number to choose: ";
        while (true) {
            clear (24, 4);
            if (!isValidInteger(input, option)) {
                cout << "Invalid input: not an integer! Press any key to re-enter option!\n";
                cin.get();
                clear(0, 5);
            }
            else break;
        }
        
        option--;
        PLAYER_INFO_MENU choice = static_cast<PLAYER_INFO_MENU>(option);
        handlePlayerInfoChoice(choice, stop);
        if (stop) break;
    }
}

void handlePlayerInfoChoice(PLAYER_INFO_MENU choice, bool &stop) {
    PlayerList *pList = PlayerList::getInstance();
    MatchHistory *history = MatchHistory::getInstance();
    Player *p;
    string pName;
    int i = 0;
    switch (choice) {
    case ALL_PLAYER:
        pList->printAllInfo();
        cout << "Press any key to continue\n";
        cin.get();
        break;
    case FIND_PLAYER:
        cout << "Enter player's name: ";
        cin >> pName;
        p = pList->findPlayerByName(pName);
        if (p == NULL) {
            cout << "Invalid player, please enter another name!\n";
        }
        else {
            p->displayInfo();
            LinkedList<MatchInfo> mList = history->getPlayerHistory(pName);
            cout << "\nMatches played by this player: " << mList.getSize() << endl;
            for (auto t = mList.getHead(); t != NULL; t = t->next) {
                t->getData().displayMinimizedMatch();
            }
        }
        cout << "Press any key to continue\n";
        cin.ignore();
        cin.get();
        break;
    case EXIT_INFO_MENU:
        stop = 1;
        break;
    default:
        cout << "Invalid option, please enter another number!\n";
        cout << "Press any key to continue\n";
        cin.ignore();
        cin.get();
        break;
    }
}