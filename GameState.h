#pragma once
#include <sstream>
#include <vector>

#include "GameManager.h"

#include "State.h"


class ObjectFactory;
class GameObject;


class GameState : public State
{
	//Ref to Game Data
	////////////////////////////////////////////////
	GameEngine::GameDataRef m_data;
	////////////////////////////////////////////////

	//Primitives
	////////////////////////////////////////////////
	bool m_giveLife = false;

	////////////////////////////////////////////////

	//Clocks
	////////////////////////////////////////////////
	//second timer for AI shots without this only the one in the
	//top of the list shoots

	//Spawn Shield for player

	////////////////////////////////////////////////

	//Sprites
	////////////////////////////////////////////////

	////////////////////////////////////////////////

	//Objects
	////////////////////////////////////////////////
	std::shared_ptr<ObjectFactory> m_factory;
	GameObject* m_player;


	std::vector<GameObject*> m_pTargetList;
	std::vector<GameObject*> m_pPlayerBulletList;
	std::vector<GameObject*> m_pAIBulletList;
	////////////////////////////////////////////////

public:

	//c'tor takes in reference to Game Data struct
	////////////////////////////////////////////////////////
	GameState(GameEngine::GameDataRef data);
	~GameState();

	// State calls
	////////////////////////////////////////////////////////
	virtual void Init() override final;
	virtual void HandleInput()override final;
	virtual void Update(float dt)override final;
	virtual void Draw()override final;

private:
	// Game calls
	////////////////////////////////////////////////////////
	void EndGameCheck();

	// UI 
	////////////////////////////////////////////////////////
	void DrawUI();

	// Object calls
	////////////////////////////////////////////////////////
	void ProjectileUpdate(float dt);
	void PlayerUpdate(float dt);
	void AIUpdate(float dt);
	void CollisionDetection();
	void MarkedTargetCleanUp();
	void ProjectileCleanUp();

};

