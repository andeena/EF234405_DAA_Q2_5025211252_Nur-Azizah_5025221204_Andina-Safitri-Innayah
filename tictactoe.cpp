#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

char arr[3][3];

void init() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            arr[i][j] = '.';
}

void mainScreen() {
    printf("================= Tic Tac Toe =================\n\n");
    printf("\tPlayer vs Bot\n");
    printf("===============================================\n");
}

void gameBoard(const char* P1, const char* P2) {
    printf("=============== Tic Tac Toe ===============\n\n");
    printf("\t\t %c | %c | %c \n", arr[0][0], arr[0][1], arr[0][2]);
    printf("\t\t---+---+---\n");
    printf("\t\t %c | %c | %c \n", arr[1][0], arr[1][1], arr[1][2]);
    printf("\t\t---+---+---\n");
    printf("\t\t %c | %c | %c \n", arr[2][0], arr[2][1], arr[2][2]);
    printf("\n\t %s : 'X'\t %s : 'O'\n", P1, P2);
    printf("===========================================\n");
}

char result() {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != '.')
            return arr[i][0];
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != '.')
            return arr[0][i];
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != '.')
        return arr[0][0];
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != '.')
        return arr[0][2];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (arr[i][j] == '.')
                return '-';

    return 'T';
}

bool isMovesLeft() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (arr[i][j] == '.')
                return true;
    return false;
}

int minimax(bool isBotTurn) {
    char res = result();
    if (res == 'O') return +10;
    if (res == 'X') return -10;
    if (res == 'T') return 0;

    if (isBotTurn) {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] == '.') {
                    arr[i][j] = 'O';
                    int score = minimax(false);
                    arr[i][j] = '.';
                    if (score > bestScore) bestScore = score;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] == '.') {
                    arr[i][j] = 'X';
                    int score = minimax(true);
                    arr[i][j] = '.';
                    if (score < bestScore) bestScore = score;
                }
            }
        }
        return bestScore;
    }
}

void botMoveHard() {
    int bestScore = -1000;
    int moveX = -1, moveY = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == '.') {
                arr[i][j] = 'O';
                int score = minimax(false);
                arr[i][j] = '.';
                if (score > bestScore) {
                    bestScore = score;
                    moveX = i;
                    moveY = j;
                }
            }
        }
    }
    if (moveX != -1 && moveY != -1)
        arr[moveX][moveY] = 'O';
}

void botMoveEasy() {
    int x, y;
    srand((unsigned)time(NULL));
    while (1) {
        x = rand() % 3;
        y = rand() % 3;
        if (arr[x][y] == '.') {
            arr[x][y] = 'O';
            break;
        }
    }
}

bool tryMove(char player, int* moveX, int* moveY) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == '.') {
                arr[i][j] = player;
                if (result() == player) {
                    arr[i][j] = '.';
                    *moveX = i;
                    *moveY = j;
                    return true;
                }
                arr[i][j] = '.';
            }
        }
    }
    return false;
}

void botMoveMedium() {
    int x = -1, y = -1;

    if (tryMove('O', &x, &y)) {
        arr[x][y] = 'O';
        return;
    }
    if (tryMove('X', &x, &y)) {
        arr[x][y] = 'O';
        return;
    }
    botMoveEasy();
}

int main() {
    while (1) {
        system("cls");
        mainScreen();
        init();

        int cnt = 0;
        int turn;
        int difficulty;

        printf("Bot go first? (1/0) : ");
        scanf("%d", &turn);

        printf("Select difficulty (0=Easy, 1=Medium, 2=Hard): ");
        scanf("%d", &difficulty);

        if (turn) cnt++;

        while (1) {
            system("cls");
            gameBoard("Player", "Bot");

            if (cnt % 2 == 0) {
                printf("\n\t     Player your move: \n\t\t    ");
                int x, y;
                scanf("%d %d", &x, &y);
                if (x < 0 || x > 2 || y < 0 || y > 2 || arr[x][y] != '.') continue;
                arr[x][y] = 'X';
                cnt++;
            } else {
                printf("\nBot is thinking...\n");
                if (difficulty == 0) botMoveEasy();
                else if (difficulty == 1) botMoveMedium();
                else botMoveHard();
                cnt++;
            }

            char res = result();
            if (res != '-') {
                system("cls");
                gameBoard("Player", "Bot");
                if (res == 'O')
                    printf("\n\t\t  Bot Wins.\n");
                else if (res == 'X')
                    printf("\n\t\tPlayer Wins.\n");
                else if (res == 'T')
                    printf("\n\t\t   Draw.\n");
                break;
            }
        }

        int repeat;
        printf("\n===========================================\n\n");
        printf("\t   Play again? (1/0) : ");
        scanf("%d", &repeat);
        if (repeat == 0) break;
    }
    return 0;
}
