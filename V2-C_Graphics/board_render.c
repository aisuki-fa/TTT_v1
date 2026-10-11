#include "board_render.h"

void drawGrid(){
    for(int i=1;i<=2;i++){
        int x= BOARD_W + i*CELL;
        DrawLineEx((Vector2){x, BOARD_H},(Vector2){x,BOARD_H+3*CELL}, 6.0f, BLACK);

        int y=BOARD_H+i*CELL;
        DrawLineEx((Vector2){BOARD_W,y},(Vector2){BOARD_W+3*CELL,y},6.0f,BLACK);
    }
}

void drawToken(){

}

void drawBoard(char board[3][3]){

}
