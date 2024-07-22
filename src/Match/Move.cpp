/*
    implementation of class Move
*/

#include <Move.h>
#include <ValidInput.h>

#include <iostream>
#include <string>

using namespace std;

Move::Move() {}
Move::Move(bool turn, int r, int c): player(turn), row(r), col(c) {}
Move::Move(string s) {
    row = (int)s[0] - '0';
    col = (int)s[2] - '0';
}

/*
    get, set functions for this class
*/
char Move::getPlayer() const {
    return player ? 'X' : 'O';
}
int Move::getRow() const {
    return row;
}
int Move::getCol() const {
    return col;
}
void Move::setPlayer(bool t) {
    player = t;
}

string Move::toString() {
    string result = (player ? "X" : "O");
    result = result + " " + to_string(row) + " " + to_string(col);
    return result;
}

// this function is called to display the move to screen
void Move::printToScreen() {
    if (player) cout << "X ";
    else cout << "O ";
    cout << *this;
}

bool Move::inBorder(int size) {
    if (row < 0 || row >= size) return false;
    if (col < 0 || col >= size) return false;
    return true;
}

// this function is called when create a log file to print a move's info to file
ostream &operator<<(ostream &os, const Move &m) {
    os << m.row << " " << m.col << endl;
    return os;
}

// this function is called to get a move from console
istream &operator>>(istream &is, Move &m) {
    is >> m.row >> m.col;
    return is;
}