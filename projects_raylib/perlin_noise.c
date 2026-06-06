#include "raylib.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// void drawRandomPoint(float cellX, float cellY, Vector2 points){
//     DrawCircleV(points, 2.0f, RED);
// }

void generateVector(float cellX, float cellY, Vector2 gradients, float vectorLength){
      DrawLineEx((Vector2){cellX, cellY},
                (Vector2){
                    cellX + gradients.x * vectorLength,
                    cellY + gradients.y * vectorLength
                },
                1.75, BLUE);
}

int main(){



    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Perlin Noise");

    const int cellsize = 40;
    const int columns = screenWidth / cellsize;
    const int rows = screenHeight / cellsize;

    SetTargetFPS(60);

    
    // Vector2 points[(columns * rows) + 1]; //Array to store random points within each cell
    // for(int i = 0; i < columns * rows; i++){
        

    //     points[i].x = (float)(GetRandomValue(0, cellsize - 1) + (i / rows) * cellsize); //Random x position within the cell
    //     points[i].y = (float)(GetRandomValue(0, cellsize - 1) + (i % columns) * cellsize); //Random y position within the cell
    //     }
    

    Vector2 gradients[columns + 1][rows + 1];

        for(int i  =  0; i <= columns; i++){
            for(int j = 0 ; j <= rows; j++){
                float randomangle = (float)GetRandomValue(0, 359) / 180.0f * PI;
                float angle = randomangle; //Random angle in radians (from 0 to 2PI (360 degrees)))
                gradients[i][j].x = cosf(angle);
                gradients[i][j].y = sinf(angle);
            }
        }


        

    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(RAYWHITE);


        float vectorLength = 20.0f;
        for(int i = 0; i < columns + 1; i++){
            for(int j = 0; j < rows + 1; j++){
                float cellX = i * cellsize;
                float cellY = j * cellsize;
                DrawRectangleLines(cellX, cellY, cellsize, cellsize, LIGHTGRAY);
                generateVector(cellX, cellY, gradients[i][j], vectorLength);
                DrawCircleV((Vector2){cellX, cellY}, 1.75, RED);
      
            }
            
        }

        EndDrawing();

    }
    CloseWindow();

    return 0;
}