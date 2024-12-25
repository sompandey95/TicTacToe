#include "AI.h"
#include <algorithm> // Include this for min and max

using namespace std; // Optional: To avoid prefixing std:: with min and max

// Check if the game is a draw
bool AI::isDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

// Check for a winner
char AI::checkWinner(char board[3][3]) {
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

// Minimax algorithm
int AI::minimax(char board[3][3], bool isAI) {
    char winner = checkWinner(board);
    if (winner == 'X') return -10;  // Player wins
    if (winner == 'O') return 10;   // AI wins
    if (isDraw(board)) return 0;    // Draw

    int bestScore = isAI ? -1000 : 1000;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = isAI ? 'O' : 'X';
                int score = minimax(board, !isAI);
                board[i][j] = ' ';
                bestScore = isAI ? max(score, bestScore) : min(score, bestScore); // Use std::max and std::min
            }
        }
    }
    return bestScore;
}

// Find the best move for AI
pair<int, int> AI::findBestMove(char board[3][3]) {
    int bestScore = -1000;
    pair<int, int> bestMove = {-1, -1};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int score = minimax(board, false);
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {i, j};
                }
            }
        }
    }
    return bestMove;
}
