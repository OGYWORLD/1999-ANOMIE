#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete build;
	delete menu;
}

void GameScene::PlayInGame()
{
	build->PrintWholeMap();
	//menu->ConverSmallImage(EIMAGE::HOSPITAM_IMAGE);
	//menu->ConverLargeImage(EIMAGE::PARK_IMAGE);
	menu->ConverLargeImage(EIMAGE::ARMY_LARGE_IMAGE);
	
}

