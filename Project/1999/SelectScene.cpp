#include "SelectScene.h"

SelectScene::SelectScene()
{
}

SelectScene::~SelectScene()
{
	delete print;
	delete music;
	delete to;
}

int SelectScene::PlaySelectScene()
{
	music->PlayMusicIzanami();
	print->ConvertWholeImage(WHOLE_IMAGE_Y / 2, print->GetSelectImage());
	print->PrintSelectText();
	return GetPlayerInput();
}

int SelectScene::GetPlayerInput()
{
	int CurY = 0;
	while (1)
	{
		// Blink Point
		to->SetColor(10);
		to->GoToXYPosition(SELECT_POSITION_X - 5, SELECT_POSITION_Y + CurY);
		printf("¢º");
		Sleep(300);
		to->GoToXYPosition(SELECT_POSITION_X - 5, SELECT_POSITION_Y + CurY);
		printf("  ");
		Sleep(300);

		if (_kbhit())
		{
			int nKey = _getch();
			if (nKey == EKEYBOARD::SPACE)
			{
				music->PlayBigClick();
				return CurY;
			}
			else if (nKey == EKEYBOARD::DIRECTION)
			{
				nKey = _getch();
				if (nKey == EKEYBOARD::KEY_UP)
				{
					music->PlayMoveBeep();
					CurY -= 7;
					if (CurY < 0)
					{
						CurY = 14;
					}

				}
				else if (nKey == EKEYBOARD::KEY_DOWN)
				{
					music->PlayMoveBeep();
					CurY += 7;
					if (CurY > 14)
					{
						CurY = 0;
					}
				}
			}

			to->CleanInputBuffer();
		}
	}
}
