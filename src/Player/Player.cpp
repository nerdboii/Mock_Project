/*
    Implementation of class Player, this class is used for managing, displaying a player's information
*/

#include <Player.h>
#include <ValidInput.h>

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Player::Player(): name(""), wins(0), losses(0), draws(0) {}

Player::Player(string s) {
    string temp[4];
    int cnt = 0;
    temp[0] = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            temp[++cnt] = "";
            continue;
        }
        else temp[cnt] = temp[cnt] + s[i];
    }

    //cout << temp[0] << " " << temp[1] << " " << temp[2] << " " << temp[3] << endl;

    name = temp[0], wins = getNum(temp[1]), losses = getNum(temp[2]), draws = getNum(temp[3]);
}

Player::Player(string name, int wins, int losses, int draws):
    name(name), wins(wins), losses(losses), draws(draws) {}

Player::Player(Player &other): name(other.name), wins(other.wins), losses(other.losses), draws(other.draws) {}

string Player::getName() const {
    return name;
}
int Player::getWins() const {
    return wins;
}
int Player::getLosses() const {
    return losses;
}
int Player::getDraws() const {
    return draws;
}

void Player::incWins() {
    wins++;
}
void Player::incLosses() {
    losses++;
}
void Player::incDraws() {
    draws++;
}

void Player::displayInfo() {
    cout << "Player name: " << name << endl;
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "Draws: " << draws << endl;
    cout << "Win rate: " << fixed << setprecision(2) << 1.0 * wins / (wins + draws + losses) << endl;
}

/*
    Overload operator '<<' for player's information display
*/
ostream &operator<<(ostream &os, const Player &p)
{
    os << p.getName() << " " << p.getWins() << " " << p.getLosses() << " " << p.getDraws() << endl;
    return os;    
}

istream &operator>>(istream &is, Player &p) {
    is >> p.name >> p.wins >> p.losses >> p.draws;
    return is;
}
