#include "StartScene.h"

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
	delete to;
	delete print;
	delete music;
}

void StartScene::PlayStartScene()
{
	print->ConvertLogoImage(START_LOGO_Y, print->GetLogoImage());
	GetPlayerInput();

}

void StartScene::GetPlayerInput()
{
	int index = 0;

	while (1)
	{
		if (_kbhit())
		{
			music->PlayBigClick();
			to->CleanInputBuffer();
			break;
		}

		if (index % 8 == 0)
		{
			to->PartClean(PRESS_BUTTOM_POSITION_X, PRESS_BUTTOM_POSITION_Y, PRESS_BUTTOM_X, PRESS_BUTTOM_Y);
		}
		else
		{
			print->ConvertPTAKImage(PRESS_BUTTOM_Y, print->GetPTAKImage());
		}

		to->GoToXYPosition(0, 0);
		print->RollingWholeImage(WHOLE_IMAGE_Y / 2, print->GetStartImage(), index, 130);

		index++;
		if (index == 120)
		{
			index = 0;
		}
	}
}
