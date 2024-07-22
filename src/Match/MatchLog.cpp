/*
    implementation for MatchLog class
*/
#include <MatchLog.h>
#include <Move.h>
#include <Grid.h>
#include <windows.h>

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

MatchLog::MatchLog(): folderPath("resources/MatchLog/") {}

/*
    Read data of matches from a file
*/
MatchLog::MatchLog(string s): folderPath("resources/MatchLog/") {
    string fileName = folderPath + s;
    ifstream logFile(fileName);
    if (!logFile) {
        cout << "Error opening file " << s << endl;
        return;
    }

    std::streambuf* cinbuf = cin.rdbuf();
    cin.rdbuf(logFile.rdbuf());
    if (!logFile) {
        cout << "Error opening data file!\n";
        return;
    }

    string line;
    bool turn = 1;
    while (getline(logFile, line)) {
        if (line == "") break;
        Move m(line);
        m.setPlayer(turn);
        turn = !turn;
        moves.add(m);
    }

    logFile.close();
    cin.rdbuf(cinbuf);
}

/*
    copy constructor
*/
MatchLog::MatchLog(const MatchLog& log) {
    for (auto t = log.getHead(); t != NULL; t = t->next) {
        Move m = t->getData();
        moves.add(m);
    }
}

MatchLog::~MatchLog() {
    //cout << "Match Log Destructor done!\n";
}

ListNode<Move> *MatchLog::getHead() const {
    return moves.getHead();
}

int MatchLog::getSize() const {
    return moves.getSize();
}

void MatchLog::displayMatch() {
    for (auto t = moves.getHead(); t != NULL; t = t->next)
        cout << t->getData();
}

void MatchLog::addMove(Move m) {
    moves.add(m);
}

void MatchLog::printToFile(string logFileName) {
    logFileName = folderPath + logFileName;
    ofstream logFile(logFileName, std::ios::app);
    if (!logFile) {
        cout << "Error Opening file to store match log!\n";
        return;
    }

    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(logFile.rdbuf());   
    for (auto t = moves.getHead(); t != NULL; t = t->next) {
        cout << t->getData();
    }
    logFile.close();
    cout.rdbuf(coutbuf);
}

MatchLog &MatchLog::operator=(const MatchLog &other) {
    for (auto t = other.getHead(); t != NULL; t = t->next) {
        Move m = t->getData();
        this->addMove(m);
    }
    return *this;
}

void MatchLog::displayToConsole() {
    
}