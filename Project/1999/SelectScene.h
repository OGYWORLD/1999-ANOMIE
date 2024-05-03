/* 선택화면 클래스 */
#pragma once
#include "PrintImage.h"
#include "Music.h"
#include "SetPosition.h"

class SelectScene
{
private:
	PrintImage* print = new PrintImage;
	Music* music = new Music;
	SetPosition* to = new SetPosition;

public:
	SelectScene();
	~SelectScene();

	int PlaySelectScene(); // 선택화면 출력

	int GetPlayerInput(); // 사용자 입력 받기
};

