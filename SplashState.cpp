#include "SplashState.h"
//#include "Definition.h"
#include "MainMenuState.h"



SplashState::SplashState(GameEngine::GameDataRef data)
	: m_data(data)
{
}
//unloads data from the maps that are no longger in use
SplashState::~SplashState()
{
	
}

// loads texture to asset manager & sets textures 
void SplashState::Init()
{

}


void SplashState::HandleInput()
{

}

//checks show time and after "show time go to main menu"
void SplashState::Update(float dt)
{

	//if (this->m_clock.getElapsedTime().asSeconds() > 2.5)
	//{
	//	m_data->machine.AddState(std::make_unique<MainMenuState>(m_data), true);
	//}
}

//renders state 
void SplashState::Draw()
{


}
