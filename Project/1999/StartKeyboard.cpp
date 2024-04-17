#include "StartKeyboard.h"

StartKeyboard::StartKeyboard()
{
}

StartKeyboard::~StartKeyboard()
{
	delete to;
}

void StartKeyboard::GetPlayerInput()
{
	while (1)
	{
		if (_kbhit())
		{
			to->CleanInputBuffer();

			break;
		}
	}
}
