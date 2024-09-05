#include <iostream>
using namespace std;

//constants
const int ROW = 3;
const int COL = 3;
const int PLAYER1 = 1;
const int PLAYER2 = 2;
const int MAX_MOVE = ROW * COL;
const char PLAYER_MAP[3] = {' ','O','X'};

//function prototype
void printBoard(int board[ROW][COL]);


int main(){
    int board[ROW][COL] = {0};
    int moveCounter = 0;

    int input = -1;
    int currentPlayer;

    printBoard(board);

    do{
        printf("Please enter first player (%d/%d):", PLAYER1, PLAYER2);
        scanf("%d", &input);
    }while(input == -1 || (input != PLAYER1 && input != PLAYER2));

    currentPlayer = input;

    printf("Game start!! Player %d enter movement \n", currentPlayer);

    while(moveCounter < MAX_MOVE){
        int i = 0, j = 0;
        printf("Player %d enter [row] [col] you want to move to: ", currentPlayer);
        scanf("%d %d", &i, &j);

        board[i][j] = currentPlayer;
        moveCounter++;

        printf("Player %c choose row %d col %d \n", PLAYER_MAP[currentPlayer], i, j);
        printBoard(board);

        currentPlayer = currentPlayer == PLAYER1 ? PLAYER2 : PLAYER1;
    }

    printf("Board filled!!");

     
    return 0;
}

void printBoard(int board[ROW][COL]){
    for(int row = 0; row < ROW; row++){
        for(int col = 0; col < COL; col++){
        char c = PLAYER_MAP[board[row][col]];
            if(col < COL - 1) {
                printf(" %c |", c);
            }
            else printf(" %c ", c);
        }
        cout << "\n";
        if(row < ROW - 1) {
            cout << "___ ___ ___";
            cout << "\n";

        }
    }
}