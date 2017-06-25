// GameBoard.h
// Created by: Dmitry Boychenko, U06709583 ,DimitryDB@yandex.ru
// Last revision: 26.08.2015
// Operating system: Win10
// Compiler used: Visual Studio 2013 Professional Update 5
// Tic-tac-toe project
// GameBorad class definition

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>

class GameBoard {
public:
    // for game status also used as payer selector 
    enum players {noOne, playerOne, playerTwo };
    GameBoard(int size = 3);
    ~GameBoard();
    void draw() const;
    void move(players player, int posX, int posY);
    void move(players player, int indx);
    int getBoardSize() const;
    // return winner 
    players getStatus() const;
    // return vector of indexes of possible movements (for ai solvers)
    std::vector<int> getCurrentState() const;
private:
    //disable copy constructor and copy assignment operator
    GameBoard(const GameBoard &){}
    GameBoard operator=(const GameBoard &){}
    // check current win status
    void checkStatus() const;
    // win check helper function
    players checkLine(const std::vector<players> &line) const;
    int size;
    mutable players status;
    std::vector<players> *board; 
};
#endif
