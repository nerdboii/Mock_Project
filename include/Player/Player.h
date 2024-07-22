/*
    Create class Player for CRUD player's information
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player {
protected:
    std::string name;
    int wins, losses, draws;

public:
    Player();
    Player(std::string);
    Player(std::string, int, int, int);
    Player(Player &);

    std::string getName() const;
    int getWins() const;
    int getLosses() const;
    int getDraws() const;
    void displayInfo();

    void incWins();
    void incLosses();
    void incDraws();

    friend std::ostream &operator<<(std::ostream &, const Player &);
    friend std::istream &operator>>(std::istream &, Player &);
};

#endif //PLAYER_H