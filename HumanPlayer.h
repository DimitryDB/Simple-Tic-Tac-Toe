// HumanPlayer.h
// Created by: Dmitry Boychenko, U06709583 ,DimitryDB@yandex.ru
// Last revision: 01.09.2015
// Operating system: Win10
// Compiler used: Visual Studio 2013 Professional Update 5
// Tic-tac-toe project
// HumanPlayer class definition

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include"Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(GameBoard* board, GameBoard::players id, std::string name) :
        Player(board, id), name(name){}
    ~HumanPlayer(){};
    inline std::string getName() const {
        return this->name;
    }
    void nextMove() const;
private:
    std::string name;
};
#endif
