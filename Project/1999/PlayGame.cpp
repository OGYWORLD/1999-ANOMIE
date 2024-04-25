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
	delete tutorial;
}

void PlayGame::PlayGameMode()
{
	pre->PlayPreviewScene(); // Preview Scene
	start->PlayStartScene(); // Start Scene

	while (1)
	{
		int PlayerInput = select->PlaySelectScene();
		if (PlayerInput == ESELECT_SCENE::NEW_GAME)
		{
			// GamePlay
			game->PlayInGame();
		}
		else if (PlayerInput == ESELECT_SCENE::TUTORIAL)
		{
			//tutorial Scenen
			tutorial->PlayTutorial();
		}
		else if (PlayerInput == ESELECT_SCENE::EXIT)
		{
			return; // Exit Game
		}
	}

}

