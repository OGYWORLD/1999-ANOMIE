#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete build;
	delete menu;
	delete to;
}

void GameScene::PlayInGame()
{
	build->PrintWholeMap();
	int page = 0;
	int DefaultMenuFlag = 0;

	while (1)
	{
		to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
		int MenuSelect = menu->ShowDefaultMenu(MENU_POINT_POSITION_X, MENU_POINT_POSITION_Y, DEFAULT_MENU_BETWEEN);

		if (MenuSelect == EMENU_SELECT::CONSTRUCT)
		{
			menu->ShowConstructMenu();
		}

	}
}





