#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

#include <Game.h>
#include <Bot.h>

class SinglePlayerGame: public Game {
private:
    bool botTurn;
public:
    SinglePlayerGame(DIFFICULTY diff, std::string, bool, int size = 10, int winCon = 4);
    void startGame() override;
    bool getPlayerTurn();
    MATCH_RESULT handleBotMove(bool);
};

#endif