#pragma once
#include "ConstructBuilding.h"
#include "MenuHandler.h"

class GameScene
{
private:
	ConstructBuilding* build = new ConstructBuilding;
	MenuHandler* menu = new MenuHandler;

public:
	GameScene();
	~GameScene();

	void PlayInGame();
};

