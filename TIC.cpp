#include <iostream>
#include <vector>

class TicTacToe {
public:
    TicTacToe() {
        board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    void displayBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) std::cout << " | ";
            }
            std::cout << std::endl;
            if (i < 2) std::cout << "--|---|--" << std::endl;
        }
    }

    void playerMove() {
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        while (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            std::cout << "This move is not valid. Try again: ";
            std::cin >> row >> col;
        }

        board[row-1][col-1] = currentPlayer;
    }

    bool checkWin() {
        // Check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true;
            }
        }
        // Check columns
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true;
            }
        }
        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true;
        }
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void playGame() {
        bool gameOngoing = true;
        while (gameOngoing) {
            displayBoard();
            playerMove();
            if (checkWin()) {
                displayBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                gameOngoing = false;
            } else if (checkDraw()) {
                displayBoard();
                std::cout << "The game is a draw!" << std::endl;
                gameOngoing = false;
            } else {
                switchPlayer();
            }
        }
    }

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;
};

int main() {
    char playAgain;
    do {
        TicTacToe game;
        game.playGame();
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
