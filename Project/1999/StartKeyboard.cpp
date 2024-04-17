#include "StartKeyboard.h"

StartKeyboard::StartKeyboard()
{
}

StartKeyboard::~StartKeyboard()
{
	delete to;
	delete print;
}

void StartKeyboard::GetPlayerInput()
{
	int index = 0;

	while (1)
	{
		if (_kbhit())
		{
			to->CleanInputBuffer();

			break;
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
