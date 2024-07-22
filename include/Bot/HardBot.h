#ifndef HARDBOT_H
#define HARDBOT_H

#include <Bot.h>
#include <Move.h>

class HardBot: public Bot {
private:
    HardBot();
public:
    static HardBot *getInstance();
    Move makeMove(bool turn, char currentState[10][10]) override;
};

#endif