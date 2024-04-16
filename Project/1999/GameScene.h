#pragma once
#include "ConstructBuilding.h"

class GameScene
{
private:
	ConstructBuilding* build = new ConstructBuilding;

public:
	GameScene();
	~GameScene();

	void PlayInGame();
};

