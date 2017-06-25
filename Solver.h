// Solver.h
// Created by: Dmitry Boychenko, U06709583 ,DimitryDB@yandex.ru
// Last revision: 01.09.2015
// Operating system: Win10
// Compiler used: Visual Studio 2013 Professional Update 5
// Tic-tac-toe project
// Solver abstract class (interface) definition
// the idea was to use different solvers so user can chose different slgorithm for Ai.
// for example MonteCarlo solver or min/max but currently I only implement pure random solver

#ifndef SOLVER_H
#define SOLVER_H

#include <string>
#include "GameBoard.h"

class Solver {
public:
    Solver(GameBoard* board) : board(board) {}
    virtual ~Solver() { board = 0; }
    virtual std::string getName() const = 0;
    virtual int nextMove() const = 0;
protected:
    inline GameBoard* getBoard() const {
        return this->board;
    }
private:
    GameBoard* board;
};
#endif
