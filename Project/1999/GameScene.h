/* 게임 화면 클래스 */
#pragma once
#pragma region HeaderFiles
#include "SetPosition.h"
#include "ConstructBuilding.h"
#include "MenuHandler.h"
#include "InfoHandler.h"
#include "NewsHandler.h"
#include "EndingScene.h"
#include "Music.h"
#pragma endregion


class GameScene
{
private:
	ConstructBuilding* build = new ConstructBuilding;
	MenuHandler* menu = new MenuHandler;
	SetPosition* to = new SetPosition;
	InfoHandler* info = new InfoHandler;
	NewsHandler* news = new NewsHandler;
	EndingScene* ending = new EndingScene;
	Music* music = new Music;

	int WhichMusic : 2; // 현재 재생할 음악 flag

public:
	GameScene();
	~GameScene();

	// Total GamePlay Func
	void PlayInGame(); // 전체 게임 실행 함수

	// Get Name
	void PlayGetName(); // 사용자 입력 및 국가 이름 받기

	// DayUpdate
	void DateUpdate(); // 날짜 업데이트
	int EndingCheck(); // 엔딩 조건 체크
	int AllDieEndingCheck(); // 전멸 엔딩 조건 체크
	void EndOfTheDay(); // 하루가 종료되었을 때, 인구수 및 세금 업데이트

	// Zombie Day
	void ZombieAttack(); // 좀비 발생 시, 사망자 계산

	// Music Check();
	void MusicCheck(int zombie); // 파워가 하나라도 50미만일 때, 배경음악 지정 함수
	
};

