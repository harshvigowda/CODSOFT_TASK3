#include <iostream>

#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl << "---------" << endl;
    }
}

// Function to check if the current player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;  // Check row
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;  // Check column
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;  // Check top-left to bottom-right diagonal
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;  // Check top-right to bottom-left diagonal
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;  // There is an empty space, the game is not a draw
            }
        }
    }
    return true;  // All spaces are filled, the game is a draw
}

int main() {
    // Initialize the board
    vector<vector<char>> board(3, vector<char>(3, ' '));

    // Players
    char currentPlayer = 'X';
    char opponentPlayer = 'O';

    while (true) {
        // Display the current state of the board
        printBoard(board);
        // Player input
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column, e.g., 1 2): ";
        cin >> row >> col;
        // Check if the chosen position is valid
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            // Update the board with the player's move
            board[row - 1][col - 1] = currentPlayer;
            // Check for a win
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            // Check for a draw
            if (checkDraw(board)) {
                printBoard(board);
                cout << "It's a draw!" << endl;
                break;
            }
            // Switch players
            swap(currentPlayer, opponentPlayer);
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
    return 0;
}