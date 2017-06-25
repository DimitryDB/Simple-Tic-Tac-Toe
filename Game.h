// Game.h
// Created by: Dmitry Boychenko, U06709583 ,DimitryDB@yandex.ru
// Last revision: 01.09.2015
// Operating system: Win10
// Compiler used: Visual Studio 2013 Professional Update 5
// Tic-tac-toe project
// Game class definition

#ifndef GAME_H
#define GAME_H

#include "GameBoard.h"
#include "Player.h"

class Game {
public:
    static const int NUMBER_OF_PLAYERS = 2;
    Game();
    ~Game();
    void initGame();
    void playGame();
private:
    int turn;
    void draw();
    GameBoard* board;
    Player *players[NUMBER_OF_PLAYERS];
};
#endif
