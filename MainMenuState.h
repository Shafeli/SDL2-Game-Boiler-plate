#pragma once
#include "GameManager.h"
#include "State.h"

class MainMenuState : public State
{
	//Ref to Game data local
	GameEngine::GameDataRef m_data;

	//sprites


	//Sounds
	////////////////////////////////////////////////

	////////////////////////////////////////////////

public:
	//c'tor takes in reference to Game Data struct
	MainMenuState(GameEngine::GameDataRef data);
	~MainMenuState();


	virtual void Init()override final;
	virtual void HandleInput()override final;
	virtual void Update(float dt)override final;
	virtual void Draw()override final;
};

