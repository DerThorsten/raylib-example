/*******************************************************************************************
*
*   raylib [shapes] example - Draw basic shapes 2d (rectangle, circle, line...)
*
*   Example originally created with raylib 1.0, last time updated with raylib 4.2
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include <iostream>

#include <pg/ray_main.hpp>
#include <pg/main_loop.hpp>
#include <pg/window.hpp>
#include <pg/platform.hpp>


struct MyMainLoop : public pg::MainLoop<MyMainLoop>
{


    void update()
    {


        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        // Check walls collision for bouncing
        if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius)) ballSpeed.x *= -1.0f;
        if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) ballSpeed.y *= -1.0f;

        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        else if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
        else if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;

        BeginDrawing();
        ClearBackground(BLACK);


         DrawCircleV(ballPosition, (float)ballRadius, MAROON);
            static     float width = 200.0f;

            auto r = GuiSliderBar(
                (Rectangle){ 640, 40, 105, 20 }, 
                "Width", TextFormat("%.2f", width), 
                &width, 
                0, 
                (float)GetScreenWidth() - 300
            );

        EndDrawing();
    }
    bool should_stop()
    {
        return WindowShouldClose();
    }
    

    Vector2 ballPosition = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    Vector2 ballSpeed = { 5.0f, 4.0f };
    int ballRadius = 20;

    bool pause = 0;
    int framesCounter = 0;
};


int main(void)
{   
    


    // Initialization
    //--------------------------------------------------------------------------------------
    const std::size_t screenWidth = 800;
    const std::size_t screenHeight = 450;
    pg::Window window(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing");


    MyMainLoop loop;
    loop.run(60);

    return 0;
}