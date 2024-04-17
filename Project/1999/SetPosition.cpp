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
