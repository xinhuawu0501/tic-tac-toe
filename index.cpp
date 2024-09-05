#include <iostream>
using namespace std;


const int ROW = 3;
const int COL = 3;

void printBoard(int board[ROW][COL]);


int main(){
    int board[ROW][COL] = {0};
    const int PLAYER1 = 1;
    const int PLAYER2 = 2;

    int input = -1;
    int currentPlayer;

    printBoard(board);

    do{
        printf("Please enter first player:");
        scanf("%d", &input);
    }while(input == -1 || (input != PLAYER1 && input != PLAYER2));

    currentPlayer = input;

     
    return 0;
}

void printBoard(int board[ROW][COL]){
    for(int row = 0; row < ROW; row++){
        for(int col = 0; col < COL; col++){
        char c = (board[row][col] == 0) ? ' ' : (board[row][col] == 1) ? 'O' : 'X';
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