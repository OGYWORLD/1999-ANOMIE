#include "ConstructBuilding.h"

ConstructBuilding::ConstructBuilding()
{
}

ConstructBuilding::~ConstructBuilding()
{
	delete to;
}

void ConstructBuilding::PrintWholeMap()
{
	to->SystemClean();
	to->GoToXYPosition(0, 0);
	Map::PrintWholeMap();
}
