#include <iostream>
#include <vector>
#include <utility> 

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
int detectWin(int board[ROW][COL]);

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
        int i, j = -1;

        //validate i & j
        do{
            printf("Player %d enter [row] [col] you want to move to: ", currentPlayer);
            scanf("%d %d", &i, &j);
        }while((i < 0 || i >= ROW) || (j < 0 || j >= COL));

        board[i][j] = currentPlayer;
        
        printf("Player %c choose row %d col %d \n", PLAYER_MAP[currentPlayer], i, j);
        printBoard(board);

        int winner = detectWin(board);
        if(winner!=0) {
            printf("Winner is %d!!\n", winner);
            return 0;
        }

        //switch player & update movement counter
        currentPlayer = currentPlayer == PLAYER1 ? PLAYER2 : PLAYER1;
        moveCounter++;

    }

    printf("Tie!!\n");

     
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

int detectWin(int board[ROW][COL]){
    //check row
    for(int i = 0; i < ROW; i++){
        int start = board[i][0];
        bool isSame = true;
        for(int j = 0; j < COL; j++){
            if(board[i][j] != start){
                isSame = false;
                break;
            }
        }
        if(isSame) return start;
    }

    //check col
    for(int j = 0; j < COL; j++){
        int start = board[0][j];
        bool isSame = true;
        for(int i = 0; i < ROW; i++){
            if(board[i][j] != start) {
                isSame = false;
                break;
            }
        }

        if(isSame) return start;
    }

    //check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];

    return 0;
}
