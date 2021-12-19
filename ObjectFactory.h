#pragma once
#include "GameManager.h"
class GameObject;

class ObjectFactory : std::enable_shared_from_this<ObjectFactory>
{
    GameEngine::GameDataRef m_data;
public:
    ObjectFactory(GameEngine::GameDataRef data);

    // Object builder functions
    ///////////////////////////////////////////////////////////////////

};

