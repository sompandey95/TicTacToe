#ifndef AI_H
#define AI_H

#include <utility>  // For std::pair
using namespace std;

class AI {
private:
//Could't understood this codebase??
    static int minimax(char board[3][3], bool isAI);
    static bool isDraw(char board[3][3]);
    static char checkWinner(char board[3][3]);

public:
    static pair<int, int> findBestMove(char board[3][3]);
};

#endif
