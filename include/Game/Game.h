#ifndef GAME_H
#define GAME_H

#include <MatchInfo.h>
#include <MatchLog.h>
#include <Player.h>
#include <Bot.h>

#include <iostream>
#include <string>

using namespace std;

class Game {
protected:
    int matSize;
    int winCondition;
    MatchInfo mInfo;
    Player *x, *o;
    char currentState[10][10];
public:
    Game(string, string, int, int);
    Game(DIFFICULTY, string, bool, int, int);
    virtual void startGame() = 0;
    MATCH_RESULT isOver(Move m);
    void updateUI(Move m);
    MATCH_RESULT handlePlayerMove(bool);
    bool checkLegalMove(Move m);
    void updateHistory(MATCH_RESULT);
};

#endif