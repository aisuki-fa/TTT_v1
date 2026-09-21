#include <stdio.h>
#include "menu.h"
#include "game.h"
#include "board.h"

void postModePicked(int mode);
void startGame(int mode);

int main(){
    int mode = showUrself();
    postModePicked(mode);
    startGame(mode);
    return 0;
}

void postModePicked(int mode){
    if(mode == 1){
        printf("You have selected Player vs. Player mode.\n");
    } else if(mode == 2){
        printf("You have selected Player vs. AI1 mode.\n");
    } else if(mode == 3){
        printf("You have selected Player vs. AI2 mode.\n");
    } else if(mode == 4){
        printf("You have selected Player vs. AI3 mode.\n");
    } else {
        printf("Invalid mode selected.\n");
    }
}

void startGame(mode){

}