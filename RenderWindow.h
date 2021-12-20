#pragma once

#include <SDL_render.h>
#include <SDL_video.h>

class GameObject;
class RenderWindow
{
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

public:
    RenderWindow();
    SDL_Texture* LoadTexture(const char* filePath);
    SDL_Window* GetWindow() { return m_window; }
    SDL_Renderer* GetRenderer() { return m_renderer; }

    void CleanUp();
    void Clear();
    void Render(GameObject& object);
    void Draw();

};

