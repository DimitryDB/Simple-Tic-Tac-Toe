// Player.h
// Created by: Dmitry Boychenko, U06709583 ,DimitryDB@yandex.ru
// Last revision: 01.09.2015
// Operating system: Win10
// Compiler used: Visual Studio 2013 Professional Update 5
// Tic-tac-toe project
// Player class definition
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include"GameBoard.h"


class Player {
public:
    Player(GameBoard* board, GameBoard::players id = GameBoard::playerOne) : playerId(id), board(board){}

    GameBoard::players getId() const {
        return this->playerId;
    }
    virtual ~Player() { board = 0; };
    virtual std::string getName() const = 0;
    virtual void nextMove() const = 0;
protected:
    inline GameBoard* getBoard() const {
        return this->board;
    }
private:
    GameBoard* board;
    GameBoard::players playerId;
};
#endif
