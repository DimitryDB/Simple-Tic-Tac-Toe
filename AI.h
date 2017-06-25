// AI.h
// Created by: Dmitry Boychenko, U06709583 ,DimitryDB@yandex.ru
// Last revision: 01.09.2015
// Operating system: Win10
// Compiler used: Visual Studio 2013 Professional Update 5
// Tic-tac-toe project
// Ai class definition

#ifndef AI_H
#define AI_H

#include "Player.h"
#include "Solver.h"

class Ai : public Player {
public:
    Ai(GameBoard* board, GameBoard::players id, Solver* solver) :
        Player(board, id), solver(solver) {}
    ~Ai();
    std::string getName() const;
    void nextMove() const;
private:
    Solver* solver;
    std::string name = "AI: ";
};
#endif
