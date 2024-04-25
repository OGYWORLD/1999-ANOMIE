#pragma once
#include "PreviewScene.h"
#include "SelectScene.h"
#include "TutorialScene.h"
#include "StartScene.h"
#include "GameScene.h"

class PlayGame
{
private:
	PreviewScene* pre = new PreviewScene;
	SelectScene* select = new SelectScene;
	TutorialScene* tutorial = new TutorialScene;
	StartScene* start = new StartScene;
	GameScene* game = new GameScene;

public:
	PlayGame();
	~PlayGame();

	void PlayGameMode();

};

