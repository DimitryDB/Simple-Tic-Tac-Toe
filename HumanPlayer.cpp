// HumanPlayer.h
// Created by: Dmitry Boychenko, U06709583 ,DimitryDB@yandex.ru
// Last revision: 01.09.2015
// Operating system: Win10
// Compiler used: Visual Studio 2013 Professional Update 5
// Tic-tac-toe project
// HumanPlayer class implementation

#include <iostream>
#include"HumanPlayer.h"


void HumanPlayer::nextMove() const {
    using namespace std;
    cout << "Please enter your next move coordinate separated by space (x,y)\n";
    int xCoord, yCoord;
    cin >> xCoord;
    cin >> yCoord;
    Player::getBoard()->move(getId(), xCoord, yCoord);
}