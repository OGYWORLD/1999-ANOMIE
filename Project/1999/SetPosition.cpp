#include "SetPosition.h"

SetPosition::SetPosition()
{
}

SetPosition::~SetPosition()
{
}

void SetPosition::GoToXYPosition(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetPosition::CleanInputBuffer()
{
	while (_kbhit())
	{
		_getch();
	}
}

void SetPosition::SystemClean()
{
	for (int i = 0; i < CONSOLE_SIZE_Y; i++)
	{
		for (int j = 0; j < CONSOLE_SIZE_X; j++)
		{
			printf(" ");
		}
		printf(" ");
	}
}
