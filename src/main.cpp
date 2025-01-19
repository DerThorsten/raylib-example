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
#include <pg/engine.hpp>




enum class ScreenID : std::size_t
{
    Start,
    Menue
};



class StartScreen : public pg::Screen
{
public:

    StartScreen(pg::Engine & engine): pg::Screen(engine){
        m_font = LoadFontEx("resources/font/Monoton/Monoton-Regular.ttf", 100, 0, 250);
        // Generate mipmap levels to use trilinear filtering
        // NOTE: On 2D drawing it won't be noticeable, it looks like FILTER_BILINEAR
        GenTextureMipmaps(&m_font.texture);
    }

    void on_update() override{


        // is mouse clicked?
        auto m = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        if(m || this->time_since_enter() > 5.0){
            this->screen_manager().transition_to_screen((std::size_t)ScreenID::Menue);
        }
    }
    void on_render() override{

        ClearBackground(BLACK);

        float fontSize = (float)m_font.baseSize * 1.0f;

        const char *msg = "Start Screen";

        auto textSize = MeasureTextEx(m_font, msg, fontSize, 0);
        Vector2 fontPosition = { 40.0f, GetScreenHeight()/2.0f - 80.0f };
        DrawTextEx(m_font, msg, fontPosition, fontSize, 0, BLUE);

    }
private:
    Font m_font;
};

class MenueScreen : public pg::Screen
{
public:

    MenueScreen(pg::Engine & engine): pg::Screen(engine){
        m_font = LoadFontEx("resources/font/Monoton/Monoton-Regular.ttf", 100, 0, 250);
        // Generate mipmap levels to use trilinear filtering
        // NOTE: On 2D drawing it won't be noticeable, it looks like FILTER_BILINEAR
        GenTextureMipmaps(&m_font.texture);
    }

    void on_update() override{
        // is mouse clicked?
        auto m = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        if(m || this->time_since_enter() > 5.0){
            this->screen_manager().transition_to_screen((std::size_t)ScreenID::Start);
        }
    }
    void on_render() override{
        ClearBackground(BLACK);

        float fontSize = (float)m_font.baseSize * 1.0f;

        const char *msg = "Menue Screen";

        auto textSize = MeasureTextEx(m_font, msg, fontSize, 0);
        Vector2 fontPosition = { 40.0f, GetScreenHeight()/2.0f - 80.0f };
        DrawTextEx(m_font, msg, fontPosition, fontSize, 0, BLUE);
    }
private:
    Font m_font;
};






int main(void)
{   
    

    pg::EngineSettings settings;

    pg::Engine engine;
    auto & screen_manager = engine.screen_manager();
    screen_manager.add_screen(std::make_unique<StartScreen>(engine));
    screen_manager.add_screen(std::make_unique<MenueScreen>(engine));

    engine.run();

    return 0;
}