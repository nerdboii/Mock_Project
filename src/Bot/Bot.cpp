#include <Bot.h>
#include <iostream>

bool Bot::isLegal(Move m, char currentState[10][10]) {
    int r = m.getRow(), c = m.getCol();
    if (!m.inBorder(10) || currentState[r][c] != ' ') return false;
    return true;
}