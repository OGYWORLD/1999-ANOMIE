#include "PlayGame.h"
#include "SetPosition.h" // ���� ����

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13 | 1 << 4);

	return 0;
}