#pragma once
#include "Map.h"
#include "SetPosition.h"

class ConstructBuilding : Map
{
private:
	SetPosition* to;

public:
	ConstructBuilding();
	~ConstructBuilding();

	void PrintWholeMap();
};

