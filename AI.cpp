// Ai.cpp
// Created by: Dmitry Boychenko, U06709583 ,DimitryDB@yandex.ru
// Last revision: 01.09.2015
// Operating system: Win10
// Compiler used: Visual Studio 2013 Professional Update 5
// Tic-tac-toe project
// Ai class implementation

#include "AI.h"
Ai::~Ai() {
    delete this->solver;
}

void Ai::nextMove() const {
    Player::getBoard()->move(getId(), solver->nextMove());
}
std::string Ai::getName() const {
    return this->name + solver->getName();
}