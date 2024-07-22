#define WIN32_LEAN_AND_MEAN

#include <SinglePlayerGame.h>
#include <Game.h>
#include <Player.h>
#include <Move.h>
#include <MatchHistory.h>
#include <MatchInfo.h>
#include <PlayerList.h>
#include <Grid.h>
#include <SetPointer.h>
#include <ValidInput.h>
#include <BotFactory.h>

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

SinglePlayerGame::SinglePlayerGame(DIFFICULTY diff, string pName, bool prio, int size, int winCon): Game(diff, pName, prio, size, winCon) {
    MatchHistory *history = MatchHistory::getInstance();
    PlayerList *pList = PlayerList::getInstance();

    cin.ignore();
    cin.get();
    
    Player *bot = static_cast<Player *>(getBot(diff));
    Player *player = pList->findPlayerByName(pName);
    if (player == NULL) player = new Player(pName, 0, 0, 0);
    if (prio) {
        x = player;
        o = bot;
    }
    else {
        x = bot;
        o = player;
    }

    for (int i = 0; i < matSize; i++)
        for (int j = 0; j < matSize; j++)
            currentState[i][j] = ' ';
    
    mInfo.setId(history->getNumberOfMatches());
    mInfo.setXPlayer(x->getName());
    mInfo.setOPlayer(o->getName());
    botTurn = !prio;
    startGame();
}

void SinglePlayerGame::startGame() {
    system("cls");
    cout << x->getName() << " = X, " << o->getName() << " = O:\n";
    drawGrid(matSize);
    bool turn = 1;
    while (true) {
        MATCH_RESULT result = UNFINISHED;
        if (turn == botTurn) {
            result = handleBotMove(turn);
        }
        else {
            result = handlePlayerMove(turn);
        }
        turn = !turn;
        switch (result) {
        case X_WIN:
            x->incWins();
            o->incLosses();
            clear(0, 25);
            cout << x->getName() << " wins!";
            break;
        case O_WIN:
            o->incWins();
            x->incLosses();
            clear(0, 25);
            cout << o->getName() << " wins!";
            break;
        case DRAW:
            x->incDraws();
            o->incDraws();
            clear(0, 25);
            cout << "Draw!";
            break;
        default:
            break;
        }
        if (result != UNFINISHED) {
            updateHistory(result);
            break;
        }
    }
}

/*
    handle each move that bot generates
*/
MATCH_RESULT SinglePlayerGame::handleBotMove(bool turn) {
    Bot *bot = botTurn ? static_cast<Bot *>(x) : static_cast<Bot *>(o);
    Move m = bot->makeMove(turn, currentState);
    clear(0, 24);
    cout << bot->getName() << "'s turn:";

    mInfo.getLog()->addMove(m);
    updateUI(m);
    return isOver(m);
}