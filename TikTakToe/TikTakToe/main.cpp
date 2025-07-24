#include<iostream>

// board size
const int row = 3;
const int col = 3;
char arr[row][col];

void printboard() {
    std::cout << "Current board status: " << std::endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << " " << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int winnercheck() {
    // rows for P1
    if ((arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X') ||
        (arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X') ||
        (arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X')) {
        std::cout << "P1 wins! " << std::endl;
        return 1;
    }

    // rows for P2
    if ((arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O') ||
        (arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O') ||
        (arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O')) {
        std::cout << "P2 wins! " << std::endl;
        return 2;
    }

    // columns for P1
    if ((arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X') ||
        (arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X') ||
        (arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X')) {
        std::cout << "P1 wins! " << std::endl;
        return 1;
    }

    // columns for P2
    if ((arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O') ||
        (arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O') ||
        (arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O')) {
        std::cout << "P2 wins! " << std::endl;
        return 2;
    }


    // diagonal for P1
    if ((arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X') ||
        (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')) {
        std::cout << "P1 wins! " << std::endl;
        return 1;
    }

    // diagonals for P2
    if ((arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O') ||
        (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O')) {
        std::cout << "P2 wins! " << std::endl;
        return 2;
    }


}

int main() {
    // players
    int P_ONE_movement; // always starts 1st -> X
    int P_TWO_movement; // always starts 2nd -> O       note: not a digit, letter is

    // players
    bool P_one = true;
    bool P_two = false;

    // terms for playing
    int count = 1;
    std::cout << "Board selection for moves: " << std::endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << " " << count << " ";
            count++;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // initialize board
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            arr[i][j] = '-';
        }
    }

    // current pos + moves
    int pos;
    int moves = 0;
    int invalid_moves = 0;

    // move handling
    while (moves < 9) {

        // draw board
        printboard();

        // input move
        if (P_one) {
            std::cout << "P1 (X). Input a move(1-9): ";
            std::cin >> P_ONE_movement;
            pos = P_ONE_movement;
        }
        else if (P_two) {
            std::cout << "P2 (O). Input a move(1-9): ";
            std::cin >> P_TWO_movement;
            pos = P_TWO_movement;
        }

        // position handling
        int pos_row = (pos - 1) / 3;
        int pos_col = (pos - 1) % 3;

        // valid move checker
        if (pos < 1 || pos > 9 || arr[pos_row][pos_col] != '-') {
            std::cout << std::endl;
            std::cerr << "INVALID MOVE! ";
            std::cout << std::endl;
            invalid_moves++;

            if (invalid_moves > 10) {
                std::cout << "TOO MANY INVALID MOVES! GAME OVER! ";
                return 0;
            }
            continue;
        }

        // apply move
        if (P_one) {
            arr[pos_row][pos_col] = 'X';
        }
        else if (P_two) {
            arr[pos_row][pos_col] = 'O';
        }
        moves++;


        // winning conditions
        bool no_winner = true;
        int result = winnercheck();
        if (result == 1 || result == 2) {
            printboard();
            no_winner = false;
            return 0;

        }

        // draw conditions
        if (moves == 9 && no_winner) {
            printboard();
            std::cout << "DRAW! " << std::endl;
            return 0;
        }

        // player switching
        P_one = !P_one;
        P_two = !P_two;
    }
}