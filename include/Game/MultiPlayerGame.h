#ifndef MULTIPLAYERGAME_H
#define MULTIPLAYERGAME_H

#include <Game.h>

#include <string>

class MultiPlayerGame: public Game {
public:
    MultiPlayerGame(std::string, std::string, int size = 10, int winCon = 4);
    void startGame() override;
};

#endif