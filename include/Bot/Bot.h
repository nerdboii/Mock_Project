#ifndef BOT_H
#define BOT_H

#include <Player.h>
#include <Move.h>

enum DIFFICULTY: int {
    EASY,
    NORMAL,
    HARD,
};

class Bot: public Player {
private:
    DIFFICULTY diff;
public:
    using Player::Player;
    /*
        pure virtual function for bot to generate their move. Will be overridden in each difficulty (polymorphism)
    */
    virtual Move makeMove(bool turn, char currentState[10][10]) = 0;
    bool isLegal(Move m, char currentState[10][10]);

    
};

#endif