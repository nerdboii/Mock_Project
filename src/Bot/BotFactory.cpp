#include <Bot.h>
#include <EasyBot.h>
#include <NormalBot.h>
#include <HardBot.h>

#include <iostream>

Player *getBot(DIFFICULTY diff) {
    Player *bot;
    switch(diff) {
    case EASY:
        std::cout<<"Flow goes here!";
        bot = EasyBot::getInstance();
        break;
    case NORMAL:
        bot = NormalBot::getInstance();
        break;
    case HARD:
        bot = HardBot::getInstance();
        break;
    default:
        std::cout << "Invalid difficulty for bot! Choose another option!\n";
        break;
    }
    return bot;
}