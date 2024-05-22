#include <bits/stdc++.h>

using namespace std;

// Function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell ? "Q " : "* ");
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check this column on the left side
    for (int i = 0; i < row; ++i) {
        if (board[i][col]) return false;
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) return false;
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (board[i][j]) return false;
    }

    return true;
}

// Recursive utility function to solve N Queen problem
bool solveNQueenUtil(vector<vector<int>>& board, int row, int n) {
    // If all queens are placed, return true
    if (row >= n) return true;

    // Iterate through columns
    int col = 0;
    while (col < n) {
        if (isSafe(board, row, col, n)) {
            // Place this queen in board[row][col]
            board[row][col] = 1;

            // Try placing the next queen
            if (solveNQueenUtil(board, row + 1, n)) return true;

            // If placing queen in board[row][col] doesn't lead to a solution,
            // backtrack by removing the queen from board[row][col]
            board[row][col] = 0;
        }
        // Move to the next column
        ++col;
    }

    // If queen cannot be placed in any column in this row, return false
    return false;
}

// Function to solve the N Queen problem
void solveNQueen(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQueenUtil(board, 0, n)) {
        cout << "Solution does not exist" << endl;
    }

    printBoard(board);
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    solveNQueen(n);

    return 0;
}
