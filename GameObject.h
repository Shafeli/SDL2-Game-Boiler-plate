#pragma once
#include <vector>
#include "GameManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_video.h>

//class ISoundStrategy;
class IAppearanceStrategy;
class IControls;

class GameObject : std::enable_shared_from_this<GameObject>
{
    //GameEngine::Sprite m_sprite;
    //GameEngine::Clock m_rateOfFire;
    //GameEngine::Clock m_DeathTimer;

    GameEngine::GameDataRef m_data;
    float m_x;
    float m_y;
    SDL_Texture* m_texture;
    SDL_Rect m_currentFrame;
    std::shared_ptr<IControls> m_pControlType;
    std::vector<std::shared_ptr<IAppearanceStrategy>> m_pAppearanceStrategy;
    //std::vector<std::shared_ptr<ISoundStrategy>> m_pSoundStrategy;

    bool m_isAlive = true;

public:

    ///////////////////////////////////////////
    // Create Object
    ///////////////////////////////////////////
    GameObject() = default;
    GameObject(GameEngine::GameDataRef data, float x, float y, SDL_Texture* texture );
    void GameObjectInit();

    //////////////////////////////////////////////////////
    ///////////////////////////////////////////
    // Appearance Startegy
    ///////////////////////////////////////////
    void SetAppearanceStrategy(std::shared_ptr<IAppearanceStrategy>pAppearanceStrategy);
    void SetStartAppearance();
    void SetDeathAppearance();
    ///////////////////////////////////////////
    // Draws Sprite to Window 
    ///////////////////////////////////////////
    void Draw();
    //////////////////////////////////////////////////////

    /////////////////////////////////////////////////////
    ///////////////////////////////////////////
    // Control
    /////////////////////////////////////////////////
    void SetControls(std::shared_ptr<IControls> controls);
    void Update(float dt);
    ///////////////////////////////////////////
    // returns if pControl has used action button
    ///////////////////////////////////////////
    bool OnUse();
    /////////////////////////////////////////////////////

    ///////////////////////////////////////////
    // Sound
    ///////////////////////////////////////////
   // void SetSound(std::shared_ptr<ISoundStrategy> sound);
    //void MakeSound();
    
    ///////////////////////////////////////////
    // Current Hit dectection 
    ///////////////////////////////////////////
    //const sf::Vector2f& GetPOS();
    //sf::Sprite& GetSprite();
    SDL_Texture* GetTexture() { return m_texture; }
    SDL_Rect& GetRect() { return m_currentFrame; }
    float GetX() { return m_x; }
    float GetY() { return m_y; }
    void MarkedForDeath();
    bool isAlive() const { return m_isAlive; }

};
