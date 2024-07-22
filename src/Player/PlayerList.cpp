/*
    Implementation of class PlayerList to store, add and display Player's information
*/

#include <PlayerList.h>
#include <iostream>
#include <fstream>

using namespace std;

/*
    PlayerList constructor, in which the PlayerList will be initialized by reading from the data file
*/
PlayerList::PlayerList(string fileName = "resources/PlayerData.txt") {
    this->fileName = fileName;
    std::fstream pListInputStream(fileName);
    std::streambuf* cinbuf = cin.rdbuf();
    cin.rdbuf(pListInputStream.rdbuf());
    if (!pListInputStream) {
        cout << "Error opening file to initialize player data!\n";
        return;
    }

    string line;
    while (getline(pListInputStream, line)) {
        if (line == "") break;
        Player *p = new Player(line);
        if (p->getName() == "EasyBot" || p->getName() == "NormalBot" || p->getName() == "HardBot")
            continue;
        players.add(p);
    }

    pListInputStream.close();
    cin.rdbuf(cinbuf);
}

/*
    PlayerList destructor. When we end the program, this function will print all player data to storage file 
*/
PlayerList::~PlayerList() {
    //cout << "Player List Destructor called!\n";
    ofstream pListOutputStream(fileName, std::ios::trunc);
    if (!pListOutputStream) {
        cout << "Error Opening player storage file to print data!\n";
        return;
    }
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(pListOutputStream.rdbuf());
    for (auto t = players.getHead(); t != NULL; t = t->next) {
        string pName = t->getData()->getName();
        if (pName == "EasyBot" || pName == "Normal" || pName == "Hard") continue;
        cout << *(t->getData());
    }
    pListOutputStream.close();
    cout.rdbuf(coutbuf);

    ListNode<Player *> *current = players.getHead();
    while (current != NULL) {
        ListNode<Player *> *nextNode = current->next;
        delete current->data;
        delete current;
        current = nextNode;
    }
    //cout << "Player List Destructor done!\n";
}

PlayerList *PlayerList::getInstance() {
    static PlayerList instance;
    return &instance;
}

int PlayerList::getNumberPlayer() const {
    return players.getSize();
}

/*
    this function is called whenever a new player name is entered from keyboard, the player will be
    then add to the player list and write their information to the data file
*/
void PlayerList::addPlayer(Player *p) {
    players.add(p);
}

Player *PlayerList::findPlayerByName(const string &name) {
    for (auto temp = players.getHead(); temp != NULL; temp = temp->next) {
        if (temp->getData()->getName() == name) return temp->getData();
    }
    return NULL;
}

void PlayerList::printAllInfo() {
    cout << "Function printAllInfo called!\n";
    ListNode<Player *> *temp = players.getHead();
    while (temp != NULL) {
        cout << *(temp->getData());
        temp = temp->next;
    }
}