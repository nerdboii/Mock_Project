#ifndef NORMALBOT_H
#define NORMALBOT_H

#include <Bot.h>
#include <Move.h>

class NormalBot: public Bot {
private:
    NormalBot();
public:
    static NormalBot *getInstance();
    Move makeMove(bool turn, char currentState[10][10]) override;
};

#endif