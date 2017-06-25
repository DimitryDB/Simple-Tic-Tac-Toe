// Game.cpp
// Created by: Dmitry Boychenko, U06709583 ,DimitryDB@yandex.ru
// Last revision: 01.09.2015
// Operating system: Win10
// Compiler used: Visual Studio 2013 Professional Update 5
// Tic-tac-toe project
// Game class implementation

#include <iostream>
#include <stdexcept>
#include "Game.h"
#include "HumanPlayer.h"
#include "RandomSolver.h"
#include "AI.h"

Game::Game() {
    initGame();
}
Game::~Game() {
    delete this->players[0];
    delete this->players[1];
    delete this->board;
}
void Game::initGame() {
    using namespace std;
    int tmp;
    string tempString;
    string name[2];
    int choises[2];
    // user interaction part
    cout << "Welcome To TIC-TAC-TOE\n" <<
        "Please enter Game board size (board can be any size)\n";
    int boardSize;
    cin >> boardSize;
    cout << "\n" << "Choose first player: enter 1 for Human Player, 2 for Computer player\n";
    cin >> tmp;
    choises[0] = tmp;
    if (choises[0] == 1) {
        cout << "\n" << "Please Enter Player name\n";
        cin >> tempString;
        name[0] = tempString;
    }
    cout << "\n" << "Choose second player: enter 1 for Human Player, 2 for Computer player\n";
    cin >> tmp;
    choises[1] = tmp;
    if (choises[1] == 1) {
        cout << "\n" << "Please Enter Player name\n";
        cin >> tempString;
        name[1] = tempString;
    }
    // initialization part
    try {
        this->turn = 0;
        this->board = new GameBoard(boardSize);
        GameBoard::players sign = GameBoard::noOne;
        for (int i = 0; i <= NUMBER_OF_PLAYERS; ++i) {
            if (i == 0)
                sign = GameBoard::playerOne;
            else
                sign = GameBoard::playerTwo;
            if (choises[i] == 1) {
                this->players[i] = new HumanPlayer(this->board, sign, name[i]);
            }
            if (choises[i] == 2) {
                Solver *solverPtr = new RandomSolver(this->board);
                this->players[i] = new Ai(this->board, sign, solverPtr);
            }
        }
    }
    catch (std::bad_alloc &ex)
    {
        std::cerr << ex.what() << "\n";
        abort;
    }
}

void Game::draw() {
    system("cls");
    using namespace std;
    cout << "Welcome To TIC-TAC-TOE\n";
    cout << "Player One: " << this->players[0]->getName() << "\n";
    cout << "Player Two: " << this->players[1]->getName() << "\n";
    board->draw();
}

void Game::playGame() {
    draw();
    do  {
        try {
            std::cout << "\n" << this->players[(this->turn % 2)]->getName() << " turn\n";
            this->players[(this->turn % 2)]->nextMove();
            turn++;
            draw();
        }
        catch (std::invalid_argument &ex) {
            std::cerr << "Invalid argument: " << ex.what() << '\n';
        }
        if (board->getStatus() != GameBoard::noOne)
            break;
    } while (board->getCurrentState().size() > 0);
    // output winners
    std::cout << "\nGame end after " << this->turn << " turns\n";
    if (board->getStatus() == GameBoard::playerOne)
        std::cout << "\n" << this->players[0]->getName() << " Won the game.\n";
    else if (board->getStatus() == GameBoard::playerTwo)
        std::cout << "\n" << this->players[1]->getName() << " Won the game.\n";
    else
        std::cout << "\nNo Winners this time.\n";
}