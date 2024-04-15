#include "PlayGame.h"
#include "SetPosition.h" // 추후 삭제

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13 | 1 << 4);

	return 0;
}