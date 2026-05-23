#include <complex.h>
#include <stdio.h>
#include "raylib.h"
#include <math.h>




void StartPosition(float *car_posX, float *car_posY,float *car_rotation,
                       float car_width, float car_height){

          *car_posX = 900/2.0 - car_width/2.0;
          *car_posY = 900/2.0 - car_height/2.0;
          *car_rotation = -90;
    }
void DrawOffRoadBackground(Camera2D camera, int screenWidth, int screenHeight);



int main(){

    
    int width = 900;
    int height = 900;
    
    InitWindow(width, height, "Hello World");
    
    float car_width = 60;
    float car_height = 30;
    float car_posX = width/2.0 - car_width/2.0;
    float car_posY = height/2.0 - car_height/2.0;
    float car_speed = 0;
    float car_max_speed = 1000;
    float car_rotation = -90;
    float acceleration = 900.0f;
    float rotation_acceleration = 180.0f;
    float car_break = 500.0f;
    int car_direction = -1; // 1 -> Down     2 -> Up
    
  Camera2D camera ={
            .offset = (Vector2){0, 0},
            .target = (Vector2){0, 0},
            .rotation = 0,
            .zoom = 1.0,
        };
        

    while(!WindowShouldClose()){
                float dt = GetFrameTime();    
              

                Rectangle resetButton = {
                    .x = 10,
                    .y = 20,
                    .width = 100,
                    .height = 30,
                };
                
// CONTROLS --------------------------------------------------------------------------
                if(IsKeyDown(KEY_UP)){
                    car_direction = -1;
                    car_speed +=  acceleration * dt;
                    if(car_speed > car_max_speed){
                        car_speed = car_max_speed;
                    }
                }
                else if(IsKeyDown(KEY_DOWN)){
                    car_direction = 1;
                    car_speed -= acceleration * dt;
                     if(car_speed > car_max_speed){
                        car_speed = car_max_speed;
                    }
                }
                else{
                    car_speed += car_break *dt * car_direction;
                      if(car_direction == -1 && car_speed < 0){
                        car_speed = 0;
                    } else if(car_direction == 1 && car_speed >0){
                        car_speed = 0;
                    }
                }

                
            if(IsKeyDown(KEY_LEFT)){
                  car_rotation -=  rotation_acceleration * dt;
                } else if(IsKeyDown(KEY_RIGHT)){
                    car_rotation += rotation_acceleration * dt;
                }
                
// END CONTROLS---------------------------------------------------------------------

                if(car_rotation > 360){
                    car_rotation = 0;
                }
               float radians = car_rotation * DEG2RAD;

              float x_move = cosf(radians) * car_speed * dt;
              float y_move = sinf(radians) * car_speed * dt;

                car_posX += x_move;
                car_posY += y_move;

              
                camera.target = (Vector2){
                    car_posX + car_width / 2.0f,
                    car_posY + car_height / 2.0f,
                };

                camera.offset = (Vector2){
                    width / 2.0f,
                    height / 2.0f,
                };

                BeginDrawing();
           

                // BeginMode2D(camera);


                // DrawOffRoadBackground(camera, width, height);
                ClearBackground(WHITE);

              Rectangle car_rec = {
                .x = car_posX,
                .y = car_posY,
                .width = car_width,
                .height = car_height,
            };

            Vector2 car_origin = {
                .x = car_width / 2.0f,
                .y = car_height / 2.0f,
            };

            DrawRectanglePro(car_rec, car_origin, car_rotation, DARKPURPLE);
                
                if(car_posX > width){
                    car_posX = -car_width;
                }
                else if(car_posX + car_width <0){
                    car_posX = width;
                }
                else if(car_posY > height){
                    car_posY = -car_height;
                }
                else if(car_posY + car_height < 0){
                    car_posY = height;
                }

                // EndMode2D();
                DrawRectangleRounded(resetButton,2, 4, LIGHTGRAY);
                DrawText("RESET", resetButton.x +24.5, resetButton.y + 7.5,  16, BLACK);
                
                DrawText(
                    TextFormat("FPS: %d", GetFPS()),
                    810, 
                    27,
                    16,
                    BLACK
                );

                IsMouseButtonPressed(MOUSE_LEFT_BUTTON); 
                  Vector2 mouseXY = GetMousePosition();
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mouseXY, resetButton) ||(IsKeyPressed(KEY_R))){
                       StartPosition(&car_posX, &car_posY, &car_rotation, car_width, car_height);
                    }

                EndDrawing();

    }
    CloseWindow();

    return 0;
}

void DrawOffRoadBackground(Camera2D camera, int screenWidth, int screenHeight)
{
    float tileSize = 300.0f;

    Vector2 topLeft = GetScreenToWorld2D((Vector2){0, 0}, camera);
    Vector2 bottomRight = GetScreenToWorld2D((Vector2){screenWidth, screenHeight}, camera);

    int startX = (int)(topLeft.x / tileSize) - 2;
    int endX = (int)(bottomRight.x / tileSize) + 2;

    int startY = (int)(topLeft.y / tileSize) - 2;
    int endY = (int)(bottomRight.y / tileSize) + 2;

    ClearBackground((Color){92, 68, 45, 255});

    for (int y = startY; y <= endY; y++)
    {
        for (int x = startX; x <= endX; x++)
        {
            float worldX = x * tileSize;
            float worldY = y * tileSize;

            DrawRectangle(
                worldX,
                worldY,
                tileSize,
                tileSize,
                (Color){92, 68, 45, 255}
            );

            // Lama
            DrawEllipse(
                worldX + 80 + ((x * 31 + y * 17) % 120),
                worldY + 90 + ((x * 19 + y * 43) % 100),
                55,
                32,
                (Color){70, 45, 25, 180}
            );

            // Pedra
            DrawCircle(
                worldX + 40 + ((x * 83 + y * 29) % 220),
                worldY + 50 + ((x * 47 + y * 61) % 220),
                6 + ((x + y) % 5),
                (Color){95, 95, 95, 255}
            );

            // Capim
            for (int i = 0; i < 8; i++)
            {
                float gx = worldX + 20 + ((i * 41 + x * 13 + y * 7) % 260);
                float gy = worldY + 20 + ((i * 67 + x * 11 + y * 5) % 260);

                DrawLine(gx, gy, gx - 2, gy - 8, DARKGREEN);
                DrawLine(gx, gy, gx + 2, gy - 10, DARKGREEN);
                DrawLine(gx, gy, gx + 4, gy - 6, DARKGREEN);
            }

            // Pequenas marcas de trilha
            DrawLineEx(
                (Vector2){worldX + 70, worldY},
                (Vector2){worldX + 130, worldY + tileSize},
                12,
                (Color){115, 80, 45, 180}
            );

            DrawLineEx(
                (Vector2){worldX + 190, worldY},
                (Vector2){worldX + 250, worldY + tileSize},
                12,
                (Color){115, 80, 45, 180}
            );
        }
    }
}