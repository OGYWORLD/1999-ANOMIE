/*
##### ������Ʈ Ư�̻��� #####
- �� ������Ʈ�� �ܼ�â ũ��� ����: 202, ����: 61�Դϴ�.
- �� ������Ʈ�� MCI�� ����ϹǷ� x86 ȯ�濡�� ����Ǿ�� �մϴ�.
*/

#include "PlayGame.h"

void ConsoleSetting(); // �ܼ� ����
 
int main()
{
	ConsoleSetting();

	PlayGame* p = new PlayGame;

	p->PlayGameMode(); // ���� ����

	delete p;

	return 0;
}

void ConsoleSetting()
{
	// �ܼ�â ũ�� ����
	system("mode con cols=202 lines=61 | title 1999");
	// Ŀ�� ����� ����
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

}
