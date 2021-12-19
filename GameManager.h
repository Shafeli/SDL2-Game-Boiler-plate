#pragma once
#include <memory>
#include <SDL_video.h>

#include "AssetManager.h"
#include "CollisionDection.h"
#include "DeltaTime.h"
#include "InputManager.h"
#include "ObjectCleaner.h"
#include "StateMachine.h"


struct GameData
{
    DeltaTime deltaTime;
    StateMachine machine;
    SDL_Window* window = nullptr;
    AssetManager assets;
    InputManager input;
    ObjectCleaner grabage;
    CollisionDection collisionDection;

//    SpawnManager Spawner;
//    SizeManager Resizer;
//    MusicManager jukebox;
//    UIDisplay GameUI;
//    FileManager FilingCabinet;
};


namespace GameEngine
{
    using GameDataRef = std::shared_ptr<GameData>;
}


class GameManager
{
    //GameEngine::Clock m_clock;
    GameEngine::GameDataRef m_data = std::make_shared<GameData>();
public:
    GameManager(int width, int hieght);

    SDL_Window* GetWindow() { return m_data->window; }
    void Run();
    void BuildWindow();
};

