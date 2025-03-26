#include <raylib.h>
#include "game.h"

int main() 
{
    
    Color darkBlue = {44, 44, 127, 255};
    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;

    Game game = Game();
    
    InitWindow(screenWidth, screenHeight, "Raylib Tetris!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        game.HandleInput();
        BeginDrawing();
            ClearBackground(darkBlue);
            game.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}