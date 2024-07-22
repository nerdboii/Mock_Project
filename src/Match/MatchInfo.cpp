/*
    implementation of class MatchInfo
*/
#define WIN32_LEAN_AND_MEAN

#include <MatchInfo.h>
#include <MatchLog.h>
#include <GetTime.h>
#include <SetPointer.h>
#include <ValidInput.h>
#include <Grid.h>

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

MatchInfo::MatchInfo(): time(getCurrentDateTime()), log(new MatchLog()) {}

// this constructor is called when the game has to read data from the storage file
// then construct all matches that were played before
MatchInfo::MatchInfo(string s) {
    string temp[5];
    int cnt = 0;
    temp[0] = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            temp[++cnt] = "";
            continue;
        }
        else temp[cnt] = temp[cnt] + s[i];
    }

    id = getNum(temp[0]);
    time = temp[1];
    xPlayer = temp[2];
    oPlayer = temp[3];
    result = static_cast<MATCH_RESULT>(getNum(temp[4]));
    log = new MatchLog(temp[0]);
}

// This constructor is called when a player starts a new match
MatchInfo::MatchInfo(int id, string x_name, string o_name):
    id(id), xPlayer(x_name), oPlayer(o_name) {
    time = getCurrentDateTime();
    log = new MatchLog();
}

MatchInfo::MatchInfo(const MatchInfo &m): id(m.id), time(m.time), xPlayer(m.xPlayer), oPlayer(m.oPlayer), result(m.result) {
    log = new MatchLog(*m.log);
}

// Destructor
MatchInfo::~MatchInfo() {
    if (log != NULL) delete log;
    //cout << "MatchInfo Destructor done!\n";
}

/*
    Implement get and set functions for class
*/

int MatchInfo::getId() const {
    return id;
}
string MatchInfo::getXPlayer() const {
    return xPlayer;
}
string MatchInfo::getOPlayer() const {
    return oPlayer;
}
MatchLog *MatchInfo::getLog() const {
    if (log == NULL) cout << "NULL POINTER";
    return log;
}
MATCH_RESULT MatchInfo::getResult() const {
    return result;
}
void MatchInfo::setId(int id) {
    this->id = id;
}
void MatchInfo::setXPlayer(string x_name) {
    xPlayer = x_name;
}
void MatchInfo::setOPlayer(string o_name) {
    oPlayer = o_name;
}
void MatchInfo::setTime() {
    time = getCurrentDateTime();
}
void MatchInfo::setResult(MATCH_RESULT res) {
    result = res;
}

/*
    print match information to file for storage purpose
*/
ostream &operator<<(ostream &os, const MatchInfo &mInfo) {
    os << mInfo.id << " " << mInfo.time << " " << mInfo.xPlayer << " " << mInfo.oPlayer << " " << mInfo.result << endl;
    return os;
}

MatchInfo &MatchInfo::operator=(const MatchInfo &other) {
    this->id = other.id;
    this->time = other.time;
    this->xPlayer = other.xPlayer;
    this->oPlayer = other.oPlayer;
    this->result = other.result;
    this->log = new MatchLog();
    *(this->log) = *(other.log);
    return *this;
}

/*
    print all information of a match to console except the moves (the log) of the match
*/
void MatchInfo::displayMinimizedMatch() {
    cout << "Match id: " << id << endl;
    cout << "Time: " << time << endl;
    cout << xPlayer << " vs " << oPlayer << endl;
    cout << "Result: ";
    switch (result) {
    case DRAW:
        cout << "Draw" << endl;
        break;
    case X_WIN:
        cout << xPlayer << " wins" << endl;
        break;
    case O_WIN:
        cout << oPlayer << " wins" << endl;
        break;
    }
    cout << endl;
}

/*
    print all information of a match to console (included the moves of that match)
*/
void MatchInfo::displayWholeMatch() {
    system("cls");
    cout << xPlayer << " = X, " << oPlayer << " = O:\n";
    drawGrid(10);
    bool turn = 1;
    cin.get();
    for (auto temp = log->getHead(); temp != NULL; temp = temp->next) {
        Move m = temp->getData();
        clear(0, 26);
        string currentPlayer = (m.getPlayer() == 'X') ? xPlayer : oPlayer;
        clear(0, 24);
        char t = m.getPlayer();
        int r = m.getRow();
        int c = m.getCol();
        cout << currentPlayer << "'s turn: " << r << " " << c << endl;
        gotoxy(4 + 4 * r, 3 + 2 * c, 1);
        cout << t;
        if (temp->next != NULL) {
            clear(0, 26);
            cout << "Press any key to see next move!";
            cin.get();
        }
        else {
            clear(0, 25);
            if (result == DRAW) cout << "Draw";
            else cout << currentPlayer << " wins!\n";
        }
    }
}