#include "PlayGame.h"

PlayGame::PlayGame()
{

}

PlayGame::~PlayGame()
{
	delete start;
	delete game;
	delete pre;
	delete select;
}

void PlayGame::PlayGameMode()
{
	pre->PlayPreviewScene();
	start->PlayStartScene();

	int PlayerInput = select->PlaySelectScene();
	if (PlayerInput == ESELECT_SCENE::NEW_GAME)
	{
		game->PlayInGame();
	}
	else if (PlayerInput == ESELECT_SCENE::TUTORIAL)
	{
		//tutorial Scenen
	}
	else if (PlayerInput == ESELECT_SCENE::EXIT)
	{
		return;
	}

}

