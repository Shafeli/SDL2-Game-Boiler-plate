#pragma once


#include "GameManager.h"
#include "State.h"


class SplashState : public State
{
	//Ref to Game data local
	GameEngine::GameDataRef m_data;


	bool soundSwitch = true;

	/////////////////////////////////////////////////
	//clock to keep track of how much time has passed
	//after n time move to main menu state
	/////////////////////////////////////////////////
	/*sf::Clock m_clock;*/

	//background sprite


public:

	//c'tor takes in reference to Game Data struct
	SplashState(GameEngine::GameDataRef data);
	~SplashState();

	virtual void Init()override final;
	virtual void HandleInput()override final;
	virtual void Update(float dt)override final;
	virtual void Draw()override final;



};

