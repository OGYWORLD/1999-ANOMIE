/* 엔딩 화면 클래스*/
#pragma once
#pragma region HeaderFiles
#include <cstring>
#include "PrintImage.h"
#include "SetPosition.h"
#include "InfoHandler.h"
#include "Music.h"
#pragma endregion

class EndingScene
{
private:
	PrintImage* print = new PrintImage;
	SetPosition* to = new SetPosition;
	Music* music = new Music;

public:
	EndingScene();
	~EndingScene();

	void CitizenEnding(InfoHandler* info); // 탄핵 엔딩
	void ArmyEnding(InfoHandler* info); // 쿠데타 엔딩
	void ReligionEnding(InfoHandler* info); // 종교 개입 엔딩
	void AllDieEnding(InfoHandler* info); // 전멸 엔딩

	void PrintResult(InfoHandler* info); // 게임 결과 출력
};

