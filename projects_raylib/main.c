#include <stdio.h>
#include <raylib.h>

int main(void)
{
    InitWindow(900, 500, "Window Testing");

    Texture2D sprite = LoadTexture("./assets/gunter.png");

    float scale = 0.2f;

    float scaleAdjusted = sprite.width * scale;
    float posX = -scaleAdjusted;

    while (!WindowShouldClose())
    {
        posX -= GetFrameTime() * 300;

        if (posX <-scaleAdjusted)
        {
            posX = 900;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextureEx(
            sprite,
            (Vector2){posX,200},
            0.0f ,
            scale,
            WHITE
        );
        

        EndDrawing();
    }

    UnloadTexture(sprite);

    CloseWindow();

    return 0;
}