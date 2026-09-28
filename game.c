#define WIN 1

void startGame(int mode){
    char board[3][3];
    createBoard(board);
    showBoard(board);
    if(mode==1){
        playerVsPlayer(board);
    }
    else if(mode==2){
        playerVsAI1(board);
    }
    else if(mode==3){
        playerVsAI2(board);
    }
    else if(mode==4){
        playerVsAI3(board);
    }
}

int playerMove(){
    int row, col;
    printf("Enter your move (row and column): ");
    scanf("%d %d", &row, &col);
    if(1>row || row>3 || 1>col || col>3){
        printf("Invalid row column input\n");
        int a = playerMove(); // 0;
        return a;
    }
    return ((row-1)*3 + col - 1);

    // int num = (row-1)*3 + col - 1;
    // if(num<0 || num>8){
    //     return playerMove();
    // }
    // else{
    //     return num;
    // }

    // return (num=(row-1)*3 + col - 1) && (num<0 || num>8) ? playerMove() : num;
    
}

void validMoveInput(char board[3][3], int index, char token){
    int count = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != ' '){
                count++;
            }
        }
    }
    if(count == 9) return; 
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(index == ((i * 3) + j)){
                if(board[i][j] != ' '){
                    printf("Invalid move. Try again.\n");
                    index = playerMove();
                    validMoveInput(board, index, token);
                }
            }
        }
    }
}

void puttingInput(char board[3][3], int index, char token){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(index == (i * 3) + j){
                board[i][j] = token;
            }
        }
    }
}

void gameOver(char board[3][3], char token1, char token2){
    int flag = 0;
    // Row-wise check
    for(int i = 0; i < 3; i++){
        if(board[i][0]!=' ' && board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            flag = WIN;
            if(flag){
                if(board[i][0] == token1){
                    printf("Player 1 won\n");
                }
                else{
                    printf("Player 2 won\n");
                }
            }
            break;
        }
    }
    // Col-wise check
    for(int j = 0; j < 3; j++){
        if(board[0][j]!=' ' && board[0][j]==board[1][j] && board[1][j]==board[2][j]){
            flag = WIN;
            if(flag){
                if(board[0][j] == token1){
                    printf("Player 1 won\n");
                }
                else{
                    printf("Player 2 won\n");
                }
            }
            break;
        }
    }

    // Leading diagonal check
    if(board[0][0]!=' ' && board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        flag = WIN;
        if(flag){
            if(board[0][0] == token1){
                printf("Player 1 won\n");
            }
            else{
                printf("Player 2 won\n");
            }
        }
    }
    // Lagging diagonal check
    if(board[0][0]!=' ' && board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        flag = WIN;
        if(flag){
            if(board[0][0] == token1){
                printf("Player 1 won\n");
            }
            else{
                printf("Player 2 won\n");
            }
        }
    } 

    int count = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != ' '){
                count++;
            }
        }
    }
    if(count == 9 && !flag){
        printf("No one won. It is a draw.\n");
    }

}

void playerVsPlayer(char board[3][3]){
    int index1 = playerMove();
    char token1 = 'X';
    validMoveInput(board,index1,token1);
    puttingInput(board, index1, token1);

    int index2 = playerMove();
    char token2 = 'O';
    validMoveInput(board,index2,token2);
    puttingInput(board, index2, token2); 
}

void playerVsAI1(char board[3][3]){
    
}

void playerVsAI2(char board[3][3]){
    
}

void playerVsAI3(char board[3][3]){
    
}
