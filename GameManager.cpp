#include "GameManager.h"

#include <chrono>
#include <iostream>
#include <SDL.h>

#include "SplashState.h"

GameManager::GameManager()
{
    m_data->machine.AddState(std::make_unique<SplashState>(this->m_data));
}

void GameManager::Run()
{
  

    bool quit = false;


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


        this->m_data->machine.ProcessStateChanges();

   
        auto thisFrameTime = std::chrono::high_resolution_clock::now();


        std::chrono::duration<double> lastFrameDuration = thisFrameTime - lastFrameTime;

  
        this->m_data->deltaTime.SetTime(static_cast<float>(lastFrameDuration.count()));

     
        lastFrameTime = thisFrameTime;

        this->m_data->machine.GetActiveState()->HandleInput();
        this->m_data->machine.GetActiveState()->Update(m_data->deltaTime.GetSeconds());
        this->m_data->machine.GetActiveState()->Draw();

    }

}

