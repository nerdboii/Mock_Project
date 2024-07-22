#define WIN32_LEAN_AND_MEAN

#include <ReplayMenu.h>
#include <MatchHistory.h>
#include <SetPointer.h>
#include <MatchInfo.h>
#include <ValidInput.h>

#include <iostream>
#include <limits>

using namespace std;

void handleReplayChoice(REPLAY_OPTION choice, bool &stop);

void startReplayMenu() {
    int option;
    string input;
    bool stop = 0;
    cin.get();
    while (true) {
        system("cls");
        gotoxy(0, 0, 0);
        gotoxy(0, 0, 1);
        cout << "*__________Replay Menu__________*\n";
        cout << "1. View all matches info\n";
        cout << "2. View one match's info\n";
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
        REPLAY_OPTION choice = static_cast<REPLAY_OPTION>(option);
        handleReplayChoice(choice, stop);
        if (stop) break;
    }
}

void handleReplayChoice(REPLAY_OPTION choice, bool &stop) {
    MatchHistory *history = MatchHistory::getInstance();
    MatchInfo m(-1, "", "");
    int mId;
    switch (choice) {
    case ALL_REPLAY:
        history->displayMatchHistory();
        cout << "Press any key to continue\n";
        cin.ignore();
        cin.get();
        break;
    case FIND_REPLAY:
        cout << "Enter match's id: ";
        cin >> mId;
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid number!\n";
            break;
        }
        m = history->findMatchById(mId);
        if (m.getId() == -1) {
            cout << "no match of id " << mId << ", please enter another number!\n";
        }
        else {
            m.displayWholeMatch();
        }
        cout << "Press any key to continue\n";
        cin.ignore();
        cin.get();
        break;
    case EXIT_REPLAY:
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