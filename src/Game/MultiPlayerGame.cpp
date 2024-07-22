#define WIN32_LEAN_AND_MEAN

#include <MultiPlayerGame.h>
#include <MatchHistory.h>
#include <Move.h>
#include <MatchInfo.h>
#include <MatchLog.h>
#include <Player.h>
#include <Grid.h>
#include <SetPointer.h>
#include <ValidInput.h>

#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

MultiPlayerGame::MultiPlayerGame(string p1_name, string p2_name, int size, int winCon): Game(p1_name, p2_name, size, winCon) {
    //cin.get();
    startGame();
}

void MultiPlayerGame::startGame() {
    system("cls");
    cout << x->getName() << " = X, " << o->getName() << " = O:\n";
    drawGrid(matSize);
    bool turn = 1;
    // while the game still going
    while (true) {
        MATCH_RESULT result = handlePlayerMove(turn);
        turn = !turn;
        switch (result) {
        case X_WIN:
            x->incWins();
            o->incLosses();
            clear(0, 25);
            cout << x->getName() << " wins!";
            break;
        case O_WIN:
            o->incWins();
            x->incLosses();
            clear(0, 25);
            cout << o->getName() << " wins!";
            break;
        case DRAW:
            x->incDraws();
            o->incDraws();
            clear(0, 25);
            cout << "Draw!";
            break;
        default:
            break;
        }
        if (result != UNFINISHED) {
            updateHistory(result);
            break;
        }
    }
}