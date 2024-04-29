/* 시작화면 클래스 */
#pragma once
#include "PrintImage.h"
#include "SetPosition.h"
#include "Music.h"

class StartScene
{
private:
	SetPosition* to = new SetPosition;
	PrintImage* print = new PrintImage;
	Music* music = new Music;

public:
	StartScene();
	~StartScene();

	void PlayStartScene(); // 시작화면 출력
	void GetPlayerInput(); // 사용자 입력 받기

};

