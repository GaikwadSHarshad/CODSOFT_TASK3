#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<vector<char>> &board);
bool makeMove(vector<vector<char>> &board, char player, int row, int col);
bool checkWin(const vector<vector<char>> &board, char player);
bool checkDraw(const vector<vector<char>> &board);
void switchPlayer(char &currentPlayer);
bool playAgain();

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); 
    char currentPlayer = 'X'; 

    do {
        displayBoard(board);

        int row, col;
        bool validMove = false;


        do {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            validMove = makeMove(board, currentPlayer, row, col);

            if (!validMove) {
                cout << "Invalid move. Try again." << endl;
            }

        } while (!validMove);


        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
        }

        else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
        }
      
        else {
            switchPlayer(currentPlayer);
        }

    } while (playAgain());

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;

    return 0;
}


void displayBoard(const vector<vector<char>> &board) {
    cout << "Tic-Tac-Toe Board:" << endl;
    for (const auto &row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}


bool makeMove(vector<vector<char>> &board, char player, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool checkWin(const vector<vector<char>> &board, char player) {
 
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; 
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; 
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; 
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;  
    }
    return false;
}


bool checkDraw(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;  
            }
        }
    }
    return true; 
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

