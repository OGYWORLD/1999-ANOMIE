/* 튜토리얼 화면 클래스 */
#pragma once
#pragma region HeaderFiles
#include "PrintImage.h"
#include "SetPosition.h"
#include "Music.h"
#include <string>
#include <vector>
#include <queue>
#pragma endregion

class TutorialScene
{
private:
	PrintImage* print = new PrintImage;
	SetPosition* to = new SetPosition;
	Music* music = new Music;

	int ReturnMenu; // 메뉴 플래그
	int index; // 자막 출력 인덱스
	int Page; // 튜토리얼 페이지

	std::vector<const char*> Announce; // 자막

public:
	TutorialScene();
	~TutorialScene();

	void PlayTutorial(); // 튜토리얼 실행

	void PrintIntro(); // 튜토리얼 인트로 출력
	void PrintMenuTutorial(); // 튜토리얼 메뉴
	void PrintMenuInfo(); // 튜토리얼 - 대통령의 권한 부분 출력
	void PrintConstructInfo(); // 튜토리얼 - 건설 부분 출력
	void PrintPowerInfo(); // 튜토리얼 - 파워 부분 출력
	void PrintCategory(int p1, int p2, int p3); // 튜토리얼 카데고리 출력

	int NextKey(); // 사용자 입력 받기
	

	int SetAnnouncePosition(std::vector<const char*> s, int color); // 자막 중앙 위치 지정 및 출력


};

