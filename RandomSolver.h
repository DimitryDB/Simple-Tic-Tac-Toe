// RandomSolver.h
// Created by: Dmitry Boychenko, U06709583 ,DimitryDB@yandex.ru
// Last revision: 01.09.2015
// Operating system: Win10
// Compiler used: Visual Studio 2013 Professional Update 5
// Tic-tac-toe project
// RandomSolver class  definition

#ifndef RANDOMSOLVER_H
#define RANDOMSOLVER_H

#include "Solver.h"

class RandomSolver : public Solver {
public:
    RandomSolver(GameBoard* board) : Solver(board) {}
    ~RandomSolver() {}
    inline std::string getName() const {
        return this->name;
    }
    int nextMove() const;
private:
    std::string name = "RandomSolver";
};
#endif
