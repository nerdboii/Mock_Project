/*
    class MatchLog contains a list of move in a single match, each match has their own MatchLogs
*/

#ifndef MATCHLOG_H
#define MATCHLOG_H

#include <Move.h>
#include <LinkedList.h>

#include <iostream>
#include <fstream>
#include <string>

class MatchLog {
private:
    LinkedList<Move> moves;
    std::string folderPath;

public:
    MatchLog();
    // constructor to create a matchlog by reading from a file,
    // parameter is the file's name
    MatchLog(std::string);
    MatchLog(const MatchLog &);
    ~MatchLog();

    ListNode<Move> *getHead() const;
    int getSize() const;
    void printToFile(std::string);
    void displayMatch();
    void addMove(Move);
    void displayToConsole();
    MatchLog &operator=(const MatchLog &);
};

#endif