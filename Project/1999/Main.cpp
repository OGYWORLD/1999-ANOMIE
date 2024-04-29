/*
##### 프로젝트 특이사항 #####
- 본 프로젝트의 콘솔창 크기는 가로: 202, 세로: 61입니다.
- 본 프로젝트는 MCI를 사용하므로 x86 환경에서 빌드되어야 합니다.
*/

#include "PlayGame.h"

void ConsoleSetting(); // 콘솔 설정
 
int main()
{
	ConsoleSetting();

	PlayGame* p = new PlayGame;

	p->PlayGameMode(); // 게임 실행

	delete p;

	return 0;
}

void ConsoleSetting()
{
	// 콘솔창 크기 설정
	system("mode con cols=202 lines=61 | title 1999");
	// 커서 숨기기 설정
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

}
