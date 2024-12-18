#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10
#define EMPTY_CELL '_'

// initialize_board
void initializeBoard(char board[MAX_SIZE][MAX_SIZE], int boardSize) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = EMPTY_CELL;
        }
    }
}

// print_boardp
void printBoard(char board[MAX_SIZE][MAX_SIZE], int boardSize) {
    printf("\n");
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            printf("%c", board[i][j]);
            if (j < boardSize - 1) printf(" ");
        }
        printf("\n");
    }
}

// if player has won
int checkWinner(char mark, char board[MAX_SIZE][MAX_SIZE], int boardSize) {
    for (int i = 0; i < boardSize; i++) {
        int rowCount = 0, colCount = 0;
        for (int j = 0; j < boardSize; j++) {
            rowCount += (board[i][j] == mark);
            colCount += (board[j][i] == mark);
        }
        if (rowCount == boardSize || colCount == boardSize) return 1;
    }

    // diagonals
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < boardSize; i++) {
        diag1 += (board[i][i] == mark);
        diag2 += (board[i][boardSize - i - 1] == mark);
    }
    return (diag1 == boardSize || diag2 == boardSize);
}

// if board is full
int isBoardFull(char board[MAX_SIZE][MAX_SIZE], int boardSize) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == EMPTY_CELL) return 0;
        }
    }
    return 1;
}

// isValidmove?
int isValidMove(int row, int col, char board[MAX_SIZE][MAX_SIZE], int boardSize) {
    row--;
    col--;

    if (row < 0 || row >= boardSize || col < 0 || col >= boardSize || board[row][col] != EMPTY_CELL) {
        return 0;
    }
    return 1;
}
void getPlayerMove(int player_num, char player_sym, char board[MAX_SIZE][MAX_SIZE], int boardSize) {
    int row, col;

    while (1) {
        printf("Player %d, please insert your move:", player_num);
        if (scanf(" %d , %d", &row, &col) != 2) {
            printf("Invalid indices, please choose your move again:\n");
            while (getchar() != '\n');
            continue;
        }

        if (!isValidMove(row, col, board, boardSize)) {
            printf("Invalid indices, please choose your move again:\n");
        } else {
            board[row - 1][col - 1] = player_sym;
            break;
        }
    }
}

int main() {
    char board[MAX_SIZE][MAX_SIZE];
    int boardSize;

    printf("Please enter the board size N [1-10]:");
    scanf("%d", &boardSize);

    initializeBoard(board, boardSize);
    printf("Welcome to %dx%d Tic-Tac-Toe:", boardSize, boardSize);
    printBoard(board, boardSize);

    int player_num = 1;
    char player_sym = 'X';

    while (1) {
        getPlayerMove(player_num, player_sym, board, boardSize);
        printBoard(board, boardSize);

        // Check for winner
        if (checkWinner(player_sym, board, boardSize)) {
            printf("Player %d is the winner!\n", player_num);
            return 0;
        }

        // Check for tie
        if (isBoardFull(board, boardSize)) {
            printf("There is a Tie!\n");
            return 0;
        }

        // Switch player
        player_num = (player_num == 1) ? 2 : 1;
        player_sym = (player_sym == 'X') ? 'O' : 'X';
    }

    return 0;
}
