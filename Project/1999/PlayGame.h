#pragma once
#include "StartScene.h"
#include "GameScene.h"

class PlayGame
{
private:
	StartScene* start = new StartScene;
	GameScene* game = new GameScene;

public:
	PlayGame();
	~PlayGame();

	void PlayGameMode();

};

