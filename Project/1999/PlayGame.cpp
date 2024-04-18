#include "PlayGame.h"

PlayGame::PlayGame()
{

}

PlayGame::~PlayGame()
{
	delete start;
	delete game;
}

void PlayGame::PlayGameMode()
{
	//start->PlayStartScene();
	game->PlayInGame();

}

