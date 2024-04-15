#pragma once
#include "ConstantGroup.h"
#include "MapInfo.h"
#include <vector>

class Map : MapInfo
{
protected:
	std::vector<MapInfo*> Map1[MAP_X][MAP_Y];
	std::vector<MapInfo*> Map2[MAP_X][MAP_Y];
	std::vector<MapInfo*> Map3[MAP_X][MAP_Y];
	std::vector<MapInfo*> Map4[MAP_X][MAP_Y];
};

