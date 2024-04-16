#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete build;
}

void GameScene::PlayInGame()
{
	build->PrintWholeMap();
}

