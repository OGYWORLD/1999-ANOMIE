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
	WholeScreen();
	
}

void GameScene::WholeScreen()
{
	build->PrintWholeMap();
	menu->ShowDefaultMenu();

}

