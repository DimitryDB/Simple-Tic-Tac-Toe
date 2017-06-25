// GameBoard.cpp
// Created by: Dmitry Boychenko, U06709583 ,DimitryDB@yandex.ru
// Last revision: 26.08.2015
// Operating system: Win10
// Compiler used: Visual Studio 2013 Professional Update 5
// Tic-tac-toe project
// GameBorad class implementation

#include <iostream>
#include <stdexcept>
#include "GameBoard.h"

GameBoard::GameBoard(int size) : size(size), status(noOne) {
    this->board = new std::vector<players>(size*size);
}
GameBoard::~GameBoard() {
    delete this->board;
}
void GameBoard::draw() const {
    using std::cout;
    int iter = 0;
    // top X numbers
    cout << "   ";
    for (int i = 0; i < size; ++i)
        cout << " " << i << "  ";
    cout << "\n";
    // top line
    cout << "  ";
    for (int i = 0; i < size; ++i)
        cout << "----";
    cout << "-";
    // top Y zero 
    cout << "\n" << 0;
    // main numbers grid
    for (std::vector<players>::const_iterator i = (*board).begin(); i != (*board).end(); ++i) {
        if (iter%size == 0 && iter !=0 ) {
            cout <<" | " << "\n" << "  ";
            for (int i = 0; i < size; ++i)
                cout << "----";
            cout << "-";
            cout << "\n";
            // Y numbers from 1
            cout << iter / size;
        }
        cout << " | ";
        // choose symbol 
        if (*i == playerOne)
            cout << "x";
        else if (*i == playerTwo)
            cout << "o";
        else
            cout << " ";
        ++iter;
    }
    cout << " | ";
    // bottom line
    cout << "\n" << "  ";
    for (int i = 0; i < size; ++i)
        cout << "----";
    cout << "-";
    cout << "\n";
}
void GameBoard::move(players player, int posX, int posY) {
    int pos = posX + (posY*this->size);
    if (posX >= this->size || posY >= this->size || (*this->board)[pos] != 0)
        throw std::invalid_argument("Invalid move");
    (*this->board)[pos] = player;
}
void GameBoard::move(players player, int indx) {
    if ( (*this->board)[indx] != 0)
        throw std::invalid_argument("Invalid move");
    (*this->board)[indx] = player;
}
// check current win status
void GameBoard::checkStatus() const {
    players winer = noOne;
    std::vector<players> temp;
    // check rows
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            int ind = row * size + col;
            temp.push_back((*this->board)[ind]);
        }
        winer = checkLine(temp);
        temp.clear();
        if (winer != noOne)
            break;   
    }
    // check columns
    if (winer == noOne) {
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                int ind = col*size+ row;
                temp.push_back((*this->board)[ind]);
            }
            winer = checkLine(temp);
            temp.clear();
            if (winer != noOne)
                break; 
        }
    }
    // check diagonals
    if (winer == noOne) {
        for (int i = 0; i < size; ++i) {
            int ind = i*size + i;
            temp.push_back((*this->board)[ind]);
        }
        winer = checkLine(temp);
        temp.clear();
        if (winer == noOne) {
            for (int i = 0; i < size; ++i) {
                int ind = i*size + (size-1) - i;
                temp.push_back((*this->board)[ind]);
            }
            winer = checkLine(temp);
            temp.clear();
        }
    }
    this->status = winer;
}
// win check helper function
GameBoard::players GameBoard::checkLine(const std::vector<GameBoard::players> &line) const{
    players winer = noOne;
    players control = *(line.begin());
    for (std::vector<players>::const_iterator i = line.begin(); i != line.end(); ++i) {
        if (control != *i) {
            winer = noOne;
            break;
        }
        else {
            winer = *i;
        }
    }
    return winer;
}
GameBoard::players GameBoard::getStatus() const {
    if (this->status == noOne)
        checkStatus();
    return this->status;
}
// return vector of indexes of possible movements (for ai solvers)
std::vector<int> GameBoard::getCurrentState() const {
    std::vector<int> temp;
    int ind = 0;
    for (std::vector<players>::const_iterator i = (*this->board).begin(); i != (*this->board).end(); ++i, ++ind) {
        if (*i == noOne)
            temp.push_back(ind);
    }
    return temp;
}
int GameBoard::getBoardSize() const {
    return this->size;
}
