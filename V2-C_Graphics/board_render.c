#include "board_render.h"

void drawGrid(){
    for(int i=1;i<=2;i++){
        int x= BOARD_W + i*CELL;
        DrawLineEx((Vector2){x, BOARD_H},(Vector2){x,BOARD_H+3*CELL}, 6.0f, BLACK);

        int y=BOARD_H+i*CELL;
        DrawLineEx((Vector2){BOARD_W,y},(Vector2){BOARD_W+3*CELL,y},6.0f,BLACK);
    }
}

void drawToken(int index, char token){
    if(token == ' ') return;
    int row = index / 3;
    int col = index % 3;
    float cx = BOARD_W + col*CELL + CELL/2.0f;
    float cy = BOARD_H + row*CELL + CELL/2.0f;
    float d  = CELL * 0.25f;

    if(token == 'X'){
        DrawLineEx((Vector2){cx-d, cy-d}, (Vector2){cx+d, cy+d}, 7.0f, RED);
        DrawLineEx((Vector2){cx-d, cy+d}, (Vector2){cx+d, cy-d}, 7.0f, RED);
    } else if(token == 'O'){
        for(int i=-3;i<=3;i++){
            DrawCircleLines((int)cx, (int)cy, d+i, BLUE);
        }
    }
}

void drawBoard(char board[3][3]){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != ' ')
                drawToken(i*3 + j, board[i][j]);
}
