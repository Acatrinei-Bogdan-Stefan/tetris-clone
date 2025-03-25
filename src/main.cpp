#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main() 
{
    
    Color darkBlue = {44, 44, 127, 255};
    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Raylib Tetris!");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

    TBlock block = TBlock();
    
    
    while (!WindowShouldClose())
    {
        
        
        BeginDrawing();
            ClearBackground(darkBlue);
            grid.Draw();
            block.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}