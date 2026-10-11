#include <stdio.h>
#include "raylib.h"
// #include "raygui.h"
#include "TTT.h"
#include "menu.h"
#include "game.h"
#include "board.h"
#include "board_render.h"

// void postModePicked(int mode);

// int main(){
//     int mode = showUrself();
//     postModePicked(mode);
//     char board[3][3];
//     // createBoard(board);
//     // showBoard(board);
//     startGame(mode, board);
//     return 0;
// }

// void postModePicked(int mode){
//     if(mode == 1){
//         printf("You have selected Player vs. Player mode.\n");
//     } else if(mode == 2){
//         printf("You have selected Player vs. AI1 mode.\n");
//     } else if(mode == 3){
//         printf("You have selected Player vs. AI2 mode.\n");
//     } else if(mode == 4){
//         printf("You have selected Player vs. AI3 mode.\n");
//     } else {
//         printf("Invalid mode selected.\n");
//     }
// }

int main(){
    InitWindow(WINDOW_W, WINDOW_H, "Tic-Tac-Toe Game");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("TIC-TAC-TOE game is running, ugh nvm",100,200,30,DARKBLUE);
        drawGrid();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}