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


// -Wdeprecated-declarations

// ignore warnings from raylib

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
extern "C" {
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"                 // Required for GUI controls

}
#pragma GCC diagnostic pop


#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif


struct GameState
{
    float rotation;
    Vector2 ballPosition = { -100.0f, -100.0f };
    Color ballColor = DARKBLUE;

};


void update(void * arg)
{

    auto state = (GameState*)arg;
    auto & ballPosition = state->ballPosition;
    auto & ballColor = state->ballColor;
    

    // Update
    //----------------------------------------------------------------------------------
    ballPosition = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) ballColor = MAROON;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) ballColor = LIME;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) ballColor = DARKBLUE;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_SIDE)) ballColor = PURPLE;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_EXTRA)) ballColor = YELLOW;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_FORWARD)) ballColor = ORANGE;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_BACK)) ballColor = BEIGE;
    //----------------------------- -----------------------------------------------------






    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircleV(ballPosition, 40, ballColor);

        DrawText("move ball with mouse and click mouse button to change color", 10, 10, 20, DARKGRAY);

        
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

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing");

    GameState state;
    state.rotation = 0.0f;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    #if defined(PLATFORM_WEB)
        void * state_ptr = &state;
        emscripten_set_main_loop_arg(update, state_ptr, 60, 1);
    #else

        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            update(&state);
        }
    #endif


    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}