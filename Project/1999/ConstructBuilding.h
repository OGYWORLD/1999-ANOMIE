#pragma once
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

class ConstructBuilding : Map, BuildingImage, BuildingInfo
{
private:
	SetPosition* to = new SetPosition;
	Music* music = new Music;

	int ExitNum;

	std::map<int, int> BuildingSize;
	std::map<int, int> BuildingPrice;

public:
	ConstructBuilding();
	~ConstructBuilding();

	// Initializer
	void BuildingIntializer();

	int GetExitNum()
	{
		return this->ExitNum;
	}

	void PrintWholeMap();
	void GetPlayerExitNum();
	void MakeRandomExit();

	int BuildBuilding(int building, InfoHandler* info);
	void ShowBuildShadow(int size, int x, int y, int direction);
	void CleanBuildShadow(int size, int x, int y);

	void NewBuild(int building, int x, int y, InfoHandler* info);
	void DestroyBuilding(int building, int size, int x, int y, InfoHandler* info, int Zombie);

	void PlusCntBuilding(int building, InfoHandler* info);
	void MinusCntBuilding(int building, InfoHandler* info);

	void Religon42BMaker(InfoHandler* info, NewsHandler* news);

	// Zombie About Building
	int ReligionCntSave(InfoHandler* info, NewsHandler* news);
	int CitizenCntSave(InfoHandler* info, NewsHandler* news);
	int ArmyCntSave(InfoHandler* info, NewsHandler* news);

	// Zombie About Distance
	int DistanceBetweenAPTReligion();
	int DistanceBetweenAPTExit();

	// Zoimbie Day Random Destroy
	void ZombieDayRandomDestory(InfoHandler* info, NewsHandler* news);
};

