#include <cstdio>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Definitions.h"
#include "GameManager.h"

int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    GameManager game;
    game.Run();

    if(!game.GetWindow())
    {
        std::cout << "Could not Create Window: " << SDL_GetError() << "\n";

        return EXIT_FAILURE;
    }
    if(!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "Could not Init Image: " << SDL_GetError() << "\n";

        return EXIT_FAILURE;
    }




    SDL_DestroyWindow(game.GetWindow());
    SDL_Quit();
    return EXIT_SUCCESS;
}