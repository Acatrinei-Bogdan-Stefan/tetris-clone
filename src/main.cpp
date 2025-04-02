#include <raylib.h>
#include "game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() 
{
    
    Color darkBlue = {44, 44, 127, 255};
    constexpr int screenWidth = 500;
    constexpr int screenHeight = 620;

    Game game = Game();
    
    InitWindow(screenWidth, screenHeight, "Raylib Tetris!");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    while (!WindowShouldClose())
    {
        game.HandleInput();
        if(EventTriggered(0.25))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
            ClearBackground(darkBlue);
            game.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}