#include "RenderWindow.h"

#include <iostream>
#include <SDL_image.h>
#include "Definitions.h"
#include "GameObject.h"

RenderWindow::RenderWindow()
{
    m_window = SDL_CreateWindow(gGameTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gScreenWidth, gScreenHeight, SDL_WINDOW_ALLOW_HIGHDPI);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::LoadTexture(const char* filePath)
{
    SDL_Texture* texture = IMG_LoadTexture(m_renderer, filePath);

    if (texture == nullptr)
        std::cout << "Texture Failed: "  << SDL_GetError() << "\n";


    return texture;
}

void RenderWindow::Clear()
{
    SDL_RenderClear(m_renderer);
}

void RenderWindow::Render(GameObject& object)
{
    SDL_Rect src;
    src.x = object.GetRect().x;
    src.y = object.GetRect().y;
    src.w = object.GetRect().w;
    src.h = object.GetRect().h;

    SDL_Rect DST;
    DST.x = object.GetX();
    DST.y = object.GetY();
    DST.w = object.GetRect().w;
    DST.h = object.GetRect().h;
    
    SDL_RenderCopy(m_renderer, object.GetTexture(), nullptr, &DST);
}

void RenderWindow::Draw()
{
    SDL_RenderPresent(m_renderer);
}
