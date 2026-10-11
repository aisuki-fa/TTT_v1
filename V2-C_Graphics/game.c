#include "game.h"
#include "stdio.h"
#include "board.h"
#include <stdlib.h>
#include <stdbool.h>

#define WIN 1
#define DRAW 2

int number = 43;

void startGame(int mode, char board[3][3]){
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

int validMoveInput(char board[3][3], int index){
    // int count = 0;
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         if(board[i][j] != ' '){
    //             count++;
    //         }
    //     }
    // }
    // if(count == 9) return; 
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         if(index == ((i * 3) + j)){
    //             if(board[i][j] != ' '){
    //                 printf("Invalid move. Try again.\n");
    //                 index = playerMove();
    //                 validMoveInput(board, index, token);
    //             }
    //         }
    //     }
    // }
    return board[index/3][index%3] == ' ';
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

void gameOverText(int number){
    if(number == 0){
        printf("Player 1 won\n"); 
    }else if(number == 1){
        printf("Player 2 won\n");
    }else if(number == 2){
        printf("Player won\n");
    }else if(number == 3){
        printf("AI1 won\n");
    }else if(number == 4){
        printf("AI2 won\n");
    }else if(number == 5){
        printf("AI3 won\n");
    }else if(number== 6){
        printf("No one won. It is a draw.\n");
    }
}

int gameOver(char board[3][3], char token1, char token2){
    int flag = 0;
    // Row-wise check
    for(int i = 0; i < 3; i++){
        if(board[i][0]!=' ' && board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            flag = WIN;
            // if(flag){
            //     if(board[i][0] == token1){
            //         gameOverText(0);
            //     }
            //     else{
            //         gameOverText(1);
            //     }
            // }
            break;
        }
    }
    // Col-wise check
    for(int j = 0; j < 3; j++){
        if(board[0][j]!=' ' && board[0][j]==board[1][j] && board[1][j]==board[2][j]){
            flag = WIN;
            // if(flag){
            //     if(board[0][j] == token1){
            //         printf("Player 1 won\n");
            //     }
            //     else{
            //         printf("Player 2 won\n");
            //     }
            // }
            break;
        }
    }

    // Leading diagonal check
    if(board[0][0]!=' ' && board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        flag = WIN;
        // if(flag){
        //     if(board[0][0] == token1){
        //         printf("Player 1 won\n");
        //     }
        //     else{
        //         printf("Player 2 won\n");
        //     }
        // }
    }
    // Lagging diagonal check
    if(board[0][2]!=' ' && board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        flag = WIN;
        // if(flag){
        //     if(board[0][0] == token1){
        //         printf("Player 1 won\n");
        //     }
        //     else{
        //         printf("Player 2 won\n");
        //     }
        // }
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
        flag = DRAW;
    }

    return flag;
}

void playerVsPlayer(char board[3][3]){
    while(1){
        char token1 = 'X';
        char token2 = 'O';

        int index1;
        do{
            index1 = playerMove();
        }while(!validMoveInput(board,index1));
        puttingInput(board, index1, token1);
        showBoard(board);
        if(gameOver(board, token1, token2)==WIN){
            gameOverText(0);
            break;
        }else if(gameOver(board, token1, token2)==DRAW){
            gameOverText(6);
            break;
        }
        
        int index2;
        do{
            index2 = playerMove();
        }while(!validMoveInput(board,index2));
        puttingInput(board, index2, token2);
        showBoard(board);

        if(gameOver(board, token1, token2)==WIN){
            gameOverText(1);
            break;
        }else if(gameOver(board, token1, token2)==DRAW){
            gameOverText(6);
            break;
        }
    } 
}

void playerVsAI1(char board[3][3]){
    while(1){
        char token1 = 'X';
        char token2 = 'O';

        int index1;
        do{
            index1 = playerMove();
        }while(!validMoveInput(board,index1));
        puttingInput(board, index1, token1);
        showBoard(board);
        if(gameOver(board, token1, token2)==WIN){
            gameOverText(2);
            break;
        }else if(gameOver(board, token1, token2)==DRAW){
            gameOverText(6);
            break;
        }
        
        int index2;
        do{
            index2 = rand() % 9;
        }while(!validMoveInput(board,index2));
        puttingInput(board, index2, token2);
        showBoard(board);

        if(gameOver(board, token1, token2)==WIN){
            gameOverText(3);
            break;
        }else if(gameOver(board, token1, token2)==DRAW){
            gameOverText(6);
            break;
        }
    } 
}

void playerVsAI2(char board[3][3]){
    while(1){
        char token1 = 'X';
        char token2 = 'O';

        int index1;
        do{
            index1 = playerMove();
        }while(!validMoveInput(board,index1));
        puttingInput(board, index1, token1);
        showBoard(board);
        if(gameOver(board, token1, token2)==WIN){
            gameOverText(2);
            break;
        }
        else if(gameOver(board, token1, token2)==DRAW){
            gameOverText(6);
            break;
        }
        
        int index2;
        int caseTrue = 0;

        if(!caseTrue){
            for(index2=0;index2<9;index2++){
                if(validMoveInput(board, index2)){
                    board[index2/3][index2%3]=token2;
                    if(gameOver(board, token1, token2)==WIN){
                        showBoard(board);
                        caseTrue = 1;
                        break;
                    }
                    else{
                        board[index2/3][index2%3]=' ';
                    }
                }
            }  
        }      

        if(!caseTrue){
            for(index2=0;index2<9;index2++){
                if(validMoveInput(board, index2)){
                    board[index2/3][index2%3]=token1;
                    if(gameOver(board, token1, token2)==WIN){
                        board[index2/3][index2%3]=token2;
                        showBoard(board);
                        caseTrue = 1;
                        break;
                    }
                    else{
                        board[index2/3][index2%3]=' ';
                    }
                }
            } 
        }

        if(!caseTrue){
            do{
                index2 = rand() % 9;
            }while(!validMoveInput(board,index2));
            puttingInput(board, index2, token2);
            showBoard(board);
        }

        if(gameOver(board, token1, token2)==WIN){
            gameOverText(4);
            break;
        }else if(gameOver(board, token1, token2)==DRAW){
            gameOverText(6);
            break;
        }
    
    } 
}

void playerVsAI3(char board[3][3]){
    int index1;
    int index2;
    char token1='X';
    char token2='O';
    bool firstMove=true;    
    while(1){
        if(firstMove){
            index2=4%9;
            puttingInput(board,index2,token2);
            showBoard(board);
            firstMove=false;
        }
        else{
            int caseTrue=0;
                if(!caseTrue){
                    for(index2=0;index2<9;index2++){
                    //1st case
                        if(validMoveInput(board,index2)){
                            board[index2/3][index2%3]=token2;
                            if(gameOver(board,token1,token2)==1){
                                showBoard(board);
                                caseTrue=1;
                                break;
                            }
                            else{
                                board[index2/3][index2%3]=' ';
                            }
                        }  
                    }
                }
                if(!caseTrue){
                    for(index2=0;index2<9;index2++){
                        //2nd case
                        if(validMoveInput(board,index2)){
                            board[index2/3][index2%3]=token1;
                            if(gameOver(board,token1,token2)==1){
                                board[index2/3][index2%3]=token2;
                                showBoard(board);
                                caseTrue=1;
                                break;
                            }
                        
                            else{
                                board[index2/3][index2%3]=' ';
                            }
                        }
                    }
                }
                //3rd case
                if(!caseTrue){
                    do{
                        index2=rand()%9;
                    }while(!validMoveInput(board,index2));

                    puttingInput(board,index2,token2);
                    showBoard(board);
                }
                
                //winner declare
                if(gameOver(board,token1,token2)==WIN){
                    gameOverText(5);
                    break;
                }else if(gameOver(board,token1,token2)==DRAW){
                    gameOverText(6);
                    break;
                }
            }
        do{
            index1=playerMove();
        }while(!validMoveInput(board,index1));
            
        puttingInput(board,index1,token1);
        showBoard(board);
        if(gameOver(board,token1,token2)==WIN){
            gameOverText(2);
            break;
        }
        else if(gameOver(board,token1,token2)==DRAW){
            gameOverText(6);
        }
    }
}
