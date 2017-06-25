// RandomSolver.cpp
// Created by: Dmitry Boychenko, U06709583 ,DimitryDB@yandex.ru
// Last revision: 01.09.2015
// Operating system: Win10
// Compiler used: Visual Studio 2013 Professional Update 5
// Tic-tac-toe project
// RandomSolver class  implementation
#include <vector>
#include <stdlib.h>
#include <time.h>  
#include "RandomSolver.h"

int RandomSolver::nextMove() const {
    std::vector<int> tmp = Solver::getBoard()->getCurrentState();
    int randRange = tmp.size();
    srand(static_cast<int>(time(NULL)));
    int ind = rand() % randRange;
    return tmp[ind];
}