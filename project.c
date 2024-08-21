#include<stdio.h>
#include<stdlib.h>  // For system("cls")

void printBoard();
int checkWin();
void clearScreen();

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main() {
    int player = 1, input, status = -1;

    printBoard();

    while (status == -1) {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O';

        printf("Player %d, please enter a number (1-9): ", player);
        scanf("%d", &input);

        if (input < 1 || input > 9) {
            printf("Invalid input. Please enter a number between 1 and 9.\n");
            continue;
        }

        if (board[input] != 'X' && board[input] != 'O') {
            board[input] = mark;
            printBoard();

            int result = checkWin();

            if (result == 1) {
                printf("Player %d is the Winner!\n", player);
                return 0;
            } else if (result == 0) {
                printf("It's a draw!\n");
                return 0;
            }

            player++;  // Toggle player
        } else {
            printf("The cell is already occupied. Choose another one.\n");
        }
    }

    return 0;
}

void printBoard() {
    clearScreen();
    printf("\n\n");
    printf("=== TIC TAC TOE ===\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[7], board[8], board[9]);
    printf("     |     |     \n");
    printf("\n\n");
}

void clearScreen() {
    // Clear the screen using the system command for Windows. Modify if using a different OS.
    system("cls");  // Use "clear" on Unix-based systems
}

int checkWin() {
    // Check for win conditions
    if (board[1] == board[2] && board[2] == board[3]) return 1;
    if (board[4] == board[5] && board[5] == board[6]) return 1;
    if (board[7] == board[8] && board[8] == board[9]) return 1;
    if (board[1] == board[4] && board[4] == board[7]) return 1;
    if (board[2] == board[5] && board[5] == board[8]) return 1;
    if (board[3] == board[6] && board[6] == board[9]) return 1;
    if (board[1] == board[5] && board[5] == board[9]) return 1;
    if (board[3] == board[5] && board[5] == board[7]) return 1;

    // Check for draw
    for (int i = 1; i <= 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return -1;  // The game is still ongoing
        }
    }

    return 0;  // The game is a draw
}
