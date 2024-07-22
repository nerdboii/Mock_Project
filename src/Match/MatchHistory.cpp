/*
    implementation for MatchHistory class
*/

#include <MatchHistory.h>
#include <MatchInfo.h>

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// an instance of class MatchHistory is created with a string which is name of the file that
// contains all matches data
MatchHistory::MatchHistory(string fileName = "resources/MatchHistory.txt") {
    this->fileName = fileName;
    ifstream historyFile(fileName);
    streambuf* cinbuf = cin.rdbuf();
    cin.rdbuf(historyFile.rdbuf());
    if (!historyFile) {
        cout << "Error opening data file to get match history!\n";
        return;
    }

    string line;
    while (getline(historyFile, line)) {
        if (line == "") break;
        MatchInfo m(line);
        matches.add(m);
    }

    historyFile.close();
    cin.rdbuf(cinbuf);
}

MatchHistory::~MatchHistory() {
    //cout << "Match History Destructor called!\n";
    ofstream history(fileName, std::ios::trunc);
    if (!history) {
        cout << "Error Opening match history file to print data!\n";
        return;
    }
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(history.rdbuf());
    for (auto t = matches.getHead(); t != NULL; t = t->next)
        cout << t->getData();
    history.close();
    cout.rdbuf(coutbuf);

    //cout << "MatchHistory destructor done!\n";
}


int MatchHistory::getNumberOfMatches() const {
    return matches.getSize();
}

// get instance of this class
MatchHistory *MatchHistory::getInstance() {
    static MatchHistory historyInstance;
    return &historyInstance;
}

// print to screen all matches
void MatchHistory::displayMatchHistory() {
    for (auto t = matches.getHead(); t != NULL; t = t->next)
        t->getData().displayMinimizedMatch();
}

// add a match to match list
void MatchHistory::addMatch(MatchInfo m) {
    matches.add(m);
}

MatchInfo MatchHistory::findMatchById(const int &id) {
    MatchInfo m(-1, "", "");
    for (auto temp = matches.getHead(); temp != NULL; temp = temp->next) {
        if (temp->getData().getId() == id) return temp->getData();
    }
    return m;
}

// get the list of matches which played by a specific player
LinkedList<MatchInfo> MatchHistory::getPlayerHistory(std::string pName) {
    LinkedList<MatchInfo> result;
    for (auto temp = matches.getHead(); temp != NULL; temp = temp->next) {
        MatchInfo m(temp->getData());
        if (pName == m.getXPlayer() || pName == m.getOPlayer()) {
            result.add(m);
        }
    }
    return result;
}