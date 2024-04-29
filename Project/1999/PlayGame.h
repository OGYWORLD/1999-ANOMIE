/* MainGameManager 클래스 */
#pragma once
#include "PreviewScene.h"
#include "SelectScene.h"
#include "TutorialScene.h"
#include "StartScene.h"
#include "GameScene.h"

class PlayGame // MainGame Manager
{
private:
	PreviewScene* pre = new PreviewScene; // Preview Scene
	StartScene* start = new StartScene; // Start Scene
	SelectScene* select = new SelectScene; // Select Scene
	TutorialScene* tutorial = new TutorialScene; // Tutorial Scene
	GameScene* game = new GameScene; // Game Scene

public:
	PlayGame();
	~PlayGame();

	void PlayGameMode(); // 전체 게임 실행

};

