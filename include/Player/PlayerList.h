/*
    Declaration of class PlayerList using Singleton Design Pattern
*/

#ifndef PLAYERLIST_H
#define PLAYERLIST_H

#include <Player.h>
#include <LinkedList.h>

#include <fstream>

class PlayerList {
private:
    LinkedList<Player *> players;
    std::string fileName;

    PlayerList(std::string);
    ~PlayerList();
public:
    static PlayerList *getInstance();
    void addPlayer(Player *);
    int getNumberPlayer() const;
    Player *findPlayerByName(const std::string &);
    void printAllInfo();
};

#endif //PLAYERLIST_H