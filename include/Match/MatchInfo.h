/*
    class MatchInfo to store all information of a match, include:
    time, 2 players, result, every move made in match
    a match info is created when the game starts initialy, the game has to read from data file to get match info
    or when a new match is started
*/

#ifndef MATCHINFO_H
#define MATCHINFO_H

#include <MatchLog.h>

#include <string>

enum MATCH_RESULT: int {
    UNFINISHED,
    X_WIN,
    O_WIN,
    DRAW,
};

using namespace std;

class Replay;

class MatchInfo {
private:
    int id;
    string time;
    string xPlayer, oPlayer;
    // presents match result, result == 1 -> x wins, == 2 -> y wins, 3 -> draw
    MATCH_RESULT result;
    MatchLog* log;
public:
    MatchInfo();
    MatchInfo(string);
    MatchInfo(int, string, string);
    MatchInfo(const MatchInfo &m);
    ~MatchInfo();

    int getId() const;
    string getXPlayer() const;
    string getOPlayer() const;
    MatchLog *getLog() const;
    MATCH_RESULT getResult() const;
    void setId(int);
    void setXPlayer(string );
    void setOPlayer(string );
    void setTime();
    void setResult(MATCH_RESULT );

    friend ostream &operator<<(ostream &, const MatchInfo &);
    MatchInfo &operator=(const MatchInfo &);
    void displayWholeMatch();
    void displayMinimizedMatch();

    friend class Replay;
};

#endif