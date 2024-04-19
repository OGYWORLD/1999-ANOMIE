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
	pre->PlayPreviewScene(); // Preview Scene
	start->PlayStartScene(); // Start Scene

	int PlayerInput = select->PlaySelectScene();
	if (PlayerInput == ESELECT_SCENE::NEW_GAME)
	{
		game->PlayInGame(); // InGame Scence
	}
	else if (PlayerInput == ESELECT_SCENE::TUTORIAL)
	{
		//tutorial Scenen
	}
	else if (PlayerInput == ESELECT_SCENE::EXIT)
	{
		return; // Exit Game
	}

}

