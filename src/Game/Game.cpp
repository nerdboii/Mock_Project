#define WIN32_LEAN_AND_MEAN

#include <MatchHistory.h>
#include <PlayerList.h>
#include <Move.h>
#include <Player.h>
#include <Game.h>
#include <MatchInfo.h>
#include <MatchLog.h>
#include <SetPointer.h>
#include <Bot.h>
#include <BotFactory.h>
#include <ValidInput.h>

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

/*
    define the direction that can make a straight line for a player to win
*/
const int directions = 8;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};

/*
    create a game between p1 and p2 knowing their name as strings
*/
Game::Game(string p1_name, string p2_name, int sz = 10, int winCon = 4): matSize(sz), winCondition(winCon) {
    MatchHistory *history = MatchHistory::getInstance();
    PlayerList *pList = PlayerList::getInstance();

    mInfo.setId(history->getNumberOfMatches());
    mInfo.setXPlayer(p1_name);
    mInfo.setOPlayer(p2_name);

    x = pList->findPlayerByName(p1_name);
    o = pList->findPlayerByName(p2_name);
    if (x == NULL) {
        x = new Player(p1_name, 0, 0, 0);
        pList->addPlayer(x);
    }
    if (o == NULL) {
        o = new Player(p2_name, 0, 0, 0);
        pList->addPlayer(o);
    }
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            currentState[i][j] = ' ';
}

/*
    turn = 1 -> player goes first
    turn = 0 -> bot goes first
*/
Game::Game(DIFFICULTY diff, string pName, bool turn, int sz = 10, int winCon = 4): matSize(sz), winCondition(winCon) {

}

bool inBorder(int x, int size) {
    if (x < 0 || x >= size) return false;
    return true;
}

/*
    check if game is over or not after each move
*/
MATCH_RESULT Game::isOver(Move m) {
    char t = m.getPlayer();
    int r = m.getRow(), c = m.getCol();
    int cnt = 0;

    currentState[r][c] = t;

    for (int i = 0; i < directions; i++) {
        if (i % 2 == 0) cnt = 0;
        for (int x = r, y = c; inBorder(x, matSize) && inBorder(y, matSize) && currentState[x][y] == t; x += dx[i], y += dy[i])
            cnt++;
        if (i % 2 != 0 && cnt >= winCondition + 1) return t == 'X' ? X_WIN : O_WIN;
    }

    for (int x = 0; x < matSize; x++) {
        for (int y = 0; y < matSize; y++) {
            if (currentState[x][y] == ' ') return UNFINISHED;
        }
    }
    return DRAW;
}

/*
    Update console after each move
*/
void Game::updateUI(Move m) {
    char t = m.getPlayer();
    int r = m.getRow();
    int c = m.getCol();
    gotoxy(4 + 4 * r, 3 + 2 * c, 1);
    cout << t;
}

/*
    check if last input move was legal or not
*/
bool Game::checkLegalMove(Move m) {
    int r = m.getRow();
    int c = m.getCol();
    if (currentState[r][c] != ' ' || !m.inBorder(matSize)) return false;
    return true;
}

MATCH_RESULT Game::handlePlayerMove(bool turn) {
    clear(0, 24);
    string currentPlayer = turn ? x->getName() : o->getName();
    cout << currentPlayer << "'s turn:";
    string inputMove;
    Move m;
    while (true) {
        clear(currentPlayer.size() + 9, 24);
        getline(cin, inputMove);
        if (!isValidMove(inputMove)) {
            clear(0, 25);
            cout << "Illegal move, please enter another number!";
        }
        else {
            Move temp(turn, (int)(inputMove[0] - '0'), (int)(inputMove[2] - '0'));
            m = temp;
            if (!checkLegalMove(m)) {
                clear(0, 25);
                cout << "Illegal move, please enter another number!";
            }
            else {
                clear(0, 25);
                break;
            }
        }
    }
    mInfo.getLog()->addMove(m);
    updateUI(m);
    return isOver(m);
}

/*
    add the last match to history after it ends
*/
void Game::updateHistory(MATCH_RESULT result) {
    MatchHistory *history = MatchHistory::getInstance();
    mInfo.setTime();
    mInfo.setResult(result);
    mInfo.getLog()->printToFile(to_string(mInfo.getId()));
    history->addMatch(mInfo);
    clear(0, 26);
    cout << "Press any key to continue: ";
    cin.ignore();
    cin.get();
}