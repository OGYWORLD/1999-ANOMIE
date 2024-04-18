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

void SetPosition::SetColor(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
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

void SetPosition::PartClean(int x, int y, int bx, int by)
{
	for (int i = y; i < y + by; i++)
	{
		for (int j = x; j < x + bx; j++)
		{
			GoToXYPosition(j, i);
			printf(" ");
		}
	}
}
