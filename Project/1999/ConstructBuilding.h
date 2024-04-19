#pragma once
#include "Map.h"
#include "SetPosition.h"
#include "PrintImage.h"
#include "BuildingImage.h"
#include <time.h>
#include <set>
#include <map>

class ConstructBuilding : Map, BuildingImage
{
private:
	SetPosition* to;
	PrintImage* print;

	int ExitNum;

	std::map<int, int> BuildingSize;

public:
	ConstructBuilding();
	~ConstructBuilding();

	int GetExitNum()
	{
		return this->ExitNum;
	}

	void PrintWholeMap();
	void GetPlayerExitNum();
	void MakeRandomExit();

	int BuildBuilding(int building);
	void ShowBuildShadow(int size, int x, int y, int direction);
	void CleanBuildShadow(int size, int x, int y);

	void NewBuild(int building, int x, int y);
	void DestroyBuilding(int size, int x, int y);
};

