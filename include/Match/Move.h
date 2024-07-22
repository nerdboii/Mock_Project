/*
    define a move by a player
*/

#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <string>

class Move {
private:
    // player == 1 means this move is played by x, otherwise y
    bool player;
    // row and column that the player choose to mark
    int row, col;

public:
    Move();
    Move(bool, int, int);
    Move(std::string);

    char getPlayer() const;
    int getRow() const;
    int getCol() const;
    void setPlayer(bool);

    std::string toString();
    void printToScreen();
    void display();
    bool inBorder(int);

    friend std::ostream &operator<<(std::ostream &, const Move &);
    friend std::istream &operator>>(std::istream &, Move &);
};

#endif