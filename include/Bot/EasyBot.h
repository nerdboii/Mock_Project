#ifndef EASYBOT_H
#define EASYBOT_H

#include <Bot.h>
#include <Move.h>

class EasyBot: public Bot {
private:
    EasyBot();
public:
    static EasyBot *getInstance();
    Move makeMove(bool turn, char currentState[10][10]) override;
};

#endif