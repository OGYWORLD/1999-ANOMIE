#pragma once
#include "Map.h"
#include "SetPosition.h"
#include "PrintImage.h"
#include <time.h>
#include <set>

class ConstructBuilding : Map
{
private:
	SetPosition* to;
	PrintImage* print;

	int ExitNum;

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
};

