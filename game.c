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
    int count = 1;
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

void playerVsPlayer(char board[3][3]){
    // int index = playerMove();
    // char c1 = 'X';
    // validMoveInput(board,index,c1);
    // puttingInput(board, index, c1);
}

void playerVsAI1(char board[3][3]){
    
}

void playerVsAI2(char board[3][3]){
    
}

void playerVsAI3(char board[3][3]){
    
}
