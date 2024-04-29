/* 건물 건설 및 파괴 클래스*/
#pragma once
#pragma region HeaderFiles
#include "Map.h"
#include "SetPosition.h"
#include "BuildingImage.h"
#include "BuildingInfo.h"
#include "InfoHandler.h"
#include "NewsHandler.h"
#include "Music.h"
#include <time.h>
#include <set>
#include <map>
#pragma endregion

class ConstructBuilding : Map, BuildingImage, BuildingInfo
{
private:
	SetPosition* to = new SetPosition;
	Music* music = new Music;

	int ExitNum; // 출입구의 개수

	std::map<int, int> BuildingSize; // (건물 번호, 건물 사이즈)
	std::map<int, int> BuildingPrice; // (건물 번호, 건물 가격)

public:
	ConstructBuilding();
	~ConstructBuilding();

	void BuildingIntializer();// Initializer

	int GetExitNum() { return this->ExitNum; }

#pragma region MakeMap
	void PrintWholeMap(); // 전체적인 출입구의 개수 입력 및 출력 수행
	void GetPlayerExitNum(); // 출입구의 개수 입력받기
	void MakeRandomExit(); // 랜덤맵 생성
#pragma endregion

#pragma region About Build
	int BuildBuilding(int building, InfoHandler* info); // 건물 입력받고 건설 및 파괴 수행
	void ShowBuildShadow(int size, int x, int y, int direction); // 건물 커서 그림자 출력
	void CleanBuildShadow(int size, int x, int y); // 건물 커서 그림자 삭제

	void NewBuild(int building, int x, int y, InfoHandler* info); // 건물 건설
	void DestroyBuilding(int building, int size, int x, int y, InfoHandler* info, int Zombie); // 건물 파괴

	void PlusCntBuilding(int building, InfoHandler* info); // 건물 개수 추가
	void MinusCntBuilding(int building, InfoHandler* info); // 건물 개수 감소

	void Religon42BMaker(InfoHandler* info, NewsHandler* news); // 사이비 종교 건물 지정
#pragma endregion

#pragma region About Zombie Day
	// Zombie About Building
	int ReligionCntSave(InfoHandler* info, NewsHandler* news); // 종교 건물로 인한 추가 생존자 계산
	int CitizenCntSave(InfoHandler* info, NewsHandler* news); // 시민 건물로 인한 추가 생존자 계산
	int ArmyCntSave(InfoHandler* info, NewsHandler* news); // 국방 건물로 인한 추가 생존자 계산

	// Zombie About Distance
	int DistanceBetweenAPTReligion(); // 아파트와 종교건물 사이의 거리 계산
	int DistanceBetweenAPTExit(); // 아파트와 출입구 사이의 거리 계산

	// Zoimbie Day Random Destroy
	void ZombieDayRandomDestory(InfoHandler* info, NewsHandler* news); // 좀비 발생시 랜덤으로 건물 1개 파괴
#pragma endregion
};

