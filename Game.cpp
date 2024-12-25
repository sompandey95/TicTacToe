#include "Game.h"
#include "AI.h"

// Constructor to initialize the board
Game::Game() {
    currentPlayer = 'X';  // Player starts first
    isAI = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';  // Empty spaces
        }
    }
}

// Display the game board
void Game::displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---------\n";
    }
    cout << "\n";
}

// Validate player move
bool Game::isValidMove(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Check if the game is a draw
bool Game::isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;  // Empty cell found
        }
    }
    return true;
}

// Check for a winner
char Game::checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' ';  // No winner yet
}

// Start the game
void Game::start() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    while (true) {
        displayBoard();

        // Check for winner
        char winner = checkWinner();
        if (winner != ' ') {
            displayBoard();
            cout << (winner == 'X' ? "Player wins!" : "AI wins!") << "\n";
            break;
        }

        // Check for draw
        if (isDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        if (currentPlayer == 'X') {
            // Player's turn
            int row, col;
            cout << "Enter your move (row and column): ";
            cin >> row >> col;
            while (!isValidMove(row, col)) {
                cout << "Invalid move. Try again: ";
                cin >> row >> col;
            }
            board[row][col] = currentPlayer;
        } else {
            // AI's turn
            cout << "AI is making its move...\n";
            pair<int, int> aiMove = AI::findBestMove(board);
            board[aiMove.first][aiMove.second] = currentPlayer;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}
