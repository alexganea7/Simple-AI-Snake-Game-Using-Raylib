#include "include/constants.h"
#include "include/game.h"
#include <iostream>

int main(){
    
    InitWindow(screenWidth, screenHeight, "Snake AI");
    SetTargetFPS(60);  
    int framesCounter = 0;

    Game game = Game();
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        game.update(framesCounter);
        game.draw();
        EndDrawing();
        framesCounter++;
    }

    CloseWindow();

    return 0;
}
