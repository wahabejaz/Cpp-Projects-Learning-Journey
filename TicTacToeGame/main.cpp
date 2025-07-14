//TicTacToeGame
// a simple console-based Tic-Tac-Toe game for two players.
//Programmer Name: Wahab Ejaz
//Compiler: gcc
//Date: 14-Jul-2025
#include <iostream>
using namespace std;

char board[3][3]; 
char currentPlayer = 'X';

void initializeBoard() {
    char pos = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = pos++;
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---+---+---\n";
    }
    cout << "\n";
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool checkWin() {
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer))
            return true;

    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer))
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

bool makeMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        return false;  
    }
}

int main() {
    int choice;
    initializeBoard();

    cout << "=== Tic-Tac-Toe Game ===\n";
    displayBoard();

    while (true) {
        cout << "\nPlayer " << currentPlayer << ", enter your move (1–9): ";
        cin >> choice;

        if (choice < 1 || choice > 9) {
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (!makeMove(choice)) {
            cout << "Spot already taken. Try another.\n";
            continue;
        }

        displayBoard();

        if (checkWin()) {
            cout << "🎉 Player " << currentPlayer << " wins!\n";
            break;
        }

        if (checkDraw()) {
            cout << "🤝 It's a draw!\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}
