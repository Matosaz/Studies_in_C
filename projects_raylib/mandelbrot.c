#include <stdio.h>
#include "raylib.h"

int main() {
    InitWindow(600, 400, "Mandelbrot Set");

        while (!WindowShouldClose()){
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Mandelbrot Set Visualization", 10, 10, 20, DARKGRAY);
        }
    return 0;
}