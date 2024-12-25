#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <utility>  // For std::pair
using namespace std;

class Game {
private:
    char board[3][3];  // Game board
    char currentPlayer;  // 'X' for player, 'O' for AI
    bool isAI;  // Flag for AI move

    // Private helper functions
    void displayBoard();
    bool isValidMove(int row, int col);
    bool isDraw();
    char checkWinner();

public:
    Game();  // Constructor
    void start();  // Starts the game
};

#endif
