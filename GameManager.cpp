#include "GameManager.h"

#include <chrono>
#include <iostream>
#include <SDL.h>

#include "SplashState.h"

GameManager::GameManager(int width, int height)
{
    m_data->window = SDL_CreateWindow("Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);
    m_data->machine.AddState(std::make_unique<SplashState>(this->m_data));
}

void GameManager::Run()
{
  

    bool quit = false;

    // Allocate a time_point outside that loop so that it is retained between frames.
    auto lastFrameTime = std::chrono::high_resolution_clock::now();

    SDL_Event windowEvent;

    while (!quit)
    {
        if(SDL_PollEvent(&windowEvent))
        {
            if(SDL_QUIT == windowEvent.type)
            {
                break;
            }
        }

        //Process State Changes
        this->m_data->machine.ProcessStateChanges();

        // Get current time_point.
        auto thisFrameTime = std::chrono::high_resolution_clock::now();

        // Subtract last frame's time_point from this frame's time_point to get the duration of the frame.
        std::chrono::duration<double> lastFrameDuration = thisFrameTime - lastFrameTime;

        // Convert the duration to a double.
        this->m_data->deltaTime.SetTime(static_cast<float>(lastFrameDuration.count()));

        // Don't forget to pass newFrameCounter into lastFrameCounter.
        lastFrameTime = thisFrameTime;

        this->m_data->machine.GetActiveState()->HandleInput();
        this->m_data->machine.GetActiveState()->Update(m_data->deltaTime.GetSeconds());
        this->m_data->machine.GetActiveState()->Draw();

    }

}

