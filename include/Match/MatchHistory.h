/*
    declaration of MatchHistory, which stores all matches ever played in a linked list.
    this class is declared using Singleton design pattern
*/

#ifndef MATCHHISTORY_H
#define MATCHHISTORY_H

#include <MatchInfo.h>
#include <LinkedList.h>
#include <string>

class MatchHistory {
private:
    std::string fileName;
    LinkedList<MatchInfo> matches;
    MatchHistory(std::string);
    ~MatchHistory();
public:
    int getNumberOfMatches() const;
    // get instance of this class
    static MatchHistory *getInstance();
    // print to screen all matches
    void displayMatchHistory();
    // add a match to match list
    void addMatch(MatchInfo);
    MatchInfo findMatchById(const int &);
    // get the list of matches which played by a specific player
    LinkedList<MatchInfo> getPlayerHistory(std::string);
};

#endif