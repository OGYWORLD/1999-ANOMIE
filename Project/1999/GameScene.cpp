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
			// 여기서 끊고 DefaultMenuFlag 반환받는 함수로 빼기
			while (1)
			{
				if (page == 0)
				{
					to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
					menu->ShowConstructMenu1();

					while (1)
					{
						if (_kbhit())
						{
							int nKey = _getch();
							if (nKey == EKEYBOARD::Z_KEY)
							{
								to->CleanInputBuffer();
								page = 1;
								break;
							}
							else if (nKey == EKEYBOARD::M_KEY)
							{
								to->CleanInputBuffer();
								page = 0;
								DefaultMenuFlag = 1;
								break;
							}
							to->CleanInputBuffer();
						}
					}
				}
				else if (page == 1)
				{
					to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
					menu->ShowConstructMenu2();

					while (1)
					{
						if (_kbhit())
						{
							int nKey = _getch();
							if (nKey == EKEYBOARD::Z_KEY)
							{
								to->CleanInputBuffer();
								page = 0;
								break;
							}
							else if (nKey == EKEYBOARD::M_KEY)
							{
								to->CleanInputBuffer();
								page = 0;
								DefaultMenuFlag = 1;
								break;
							}
							to->CleanInputBuffer();
						}
					}
				}
				if (DefaultMenuFlag == 1)
				{
					DefaultMenuFlag = 0;
					break;
				}
			}
		}

	}
}





