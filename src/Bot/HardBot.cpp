#include <HardBot.h>
#include <Player.h>
#include <PlayerList.h>

HardBot::HardBot() {
    name = "HardBot";
    wins = 0;
    losses = 0;
    draws = 0;
}

HardBot *HardBot::getInstance() {
    static HardBot instance;
    return &instance;
}

bool isSuitable1(Move m, char currentState[10][10]) {
    int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
    
    for (int i = 0; i < 8; i++) {
        int r = m.getRow() + dx[i], c = m.getCol() + dy[i];
        Move t(1, r, c);
        if (t.inBorder(10) && currentState[r][c] != ' ') return true;
    }
    return false;
}

Move HardBot::makeMove(bool turn, char currentState[10][10]) {
    Move m(turn, 0, 0);
    srand(time(NULL));
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            Move t(turn, r, c);
            if (isSuitable1(t, currentState)) {
                m = t;
                break;
            }
        }
    }
    return m;
}