#include <EasyBot.h>
#include <Player.h>
#include <PlayerList.h>
#include <Move.h>

#include <time.h>

using namespace std;

EasyBot::EasyBot() {
    name = "EasyBot";
    wins = 0;
    losses = 0;
    draws = 0;
}

EasyBot *EasyBot::getInstance() {
    static EasyBot instance;
    return &instance;
}

Move EasyBot::makeMove(bool turn, char currentState[10][10]) {
    Move m(turn, 0, 0);
    srand(time(NULL));
    while (true) {
        int r = rand() % 10;
        int c = rand() % 10;
        Move t(turn, r, c);
        if (isLegal(t, currentState)) {
            m = t;
            break;
        }
    }
    return m;
}