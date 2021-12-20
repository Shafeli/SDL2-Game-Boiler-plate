#include "SplashState.h"
//#include "Definition.h"
#include "MainMenuState.h"
#include "GameObject.h"


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
	GameObject object(m_data, 100, 100, m_data->window.LoadTexture("Resources/res/Player.png"));
	Object = object;
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
	m_data->window.Clear();
	m_data->window.Render(Object);
	m_data->window.Draw();


	


}
