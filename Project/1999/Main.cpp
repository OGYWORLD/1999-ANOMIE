#include "PlayGame.h"
#include "SetPosition.h" // ���� ����
#include <iostream> // ���� ����

int main()
{
	system("mode con cols=202 lines=60 | title 1999");
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	PlayGame* p = new PlayGame;

	p->PlayGameMode();

	delete p;
	

	return 0;
}