#include "MapInfo.h"

MapInfo::MapInfo(int sx, int sy, int i, int s, int c)
{
	this->StartX = sx;
	this->StartY = sy;
	this->Info = i;
	this->Size = s;
	this->Color = c;
}

MapInfo::~MapInfo()
{
}
