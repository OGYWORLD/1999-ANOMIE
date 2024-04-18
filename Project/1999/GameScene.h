#pragma once
#include "ConstructBuilding.h"
#include "MenuHandler.h"
#include "SetPosition.h"

class GameScene
{
private:
	ConstructBuilding* build = new ConstructBuilding;
	MenuHandler* menu = new MenuHandler;
	SetPosition* to = new SetPosition;

public:
	GameScene();
	~GameScene();

	// Total GamePlay Func
	void PlayInGame();

	// Print 
	
	
};

