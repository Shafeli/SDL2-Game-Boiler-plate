#include "MainMenuState.h"

#include <iostream>


#include "GameState.h"


MainMenuState::MainMenuState(GameEngine::GameDataRef data)
	: m_data(data)
{

}

MainMenuState::~MainMenuState()
{
    //off load assets
}

// loads texture to asset manager & sets textures 
void MainMenuState::Init()
{
	//Area to init state

}

void MainMenuState::HandleInput()
{

}
//not using dt here right now so disable warning for this one spot then default again right after
#pragma warning(disable : 4100)
void MainMenuState::Update(float dt)
{

}
#pragma warning(default : 4100)
//renders state 
void MainMenuState::Draw()
{

}
