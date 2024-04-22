#include "BuildingInfo.h"

BuildingInfo::BuildingInfo()
{
}

BuildingInfo::~BuildingInfo()
{
}

std::pair<int, int> BuildingInfo::CalCulCenterCOORD(int size, int x, int y)
{
	return std::pair<int, int>(x - size - 1, y - size /  2);
}

std::pair<int, int> BuildingInfo::CalCulCenterCOORDMap(std::map<std::pair<int, int>, std::pair<int, int>> map)
{
	std::map<std::pair<int, int>, std::pair<int, int>>::iterator iter;

	double MapLen = map.size();

	double TotalX = 0;
	double TotalY = 0;
	for (iter = map.begin(); iter != map.end(); ++iter)
	{
		TotalX += iter->second.first;
		TotalY += iter->second.second;
	}

	TotalX /= MapLen;
	TotalY /= MapLen;

	return std::pair<int, int>((int)TotalX, (int)TotalY);
}

int BuildingInfo::CalCulDistance(int x1, int y1, int x2, int y2)
{
	int bx = x2 - x1;
	int by = y2 - y1;

	double d = sqrt(bx * bx + by * by);

	return (int) d;
}

void BuildingInfo::RemoveCOORDData(int x, int y, int building, int size)
{
	if (building == EKEYBOARD::NUM3_KEY) {
		PerCenterCOORDAPT.erase(std::pair<int, int>(x, y));
		CenterCOORDAPT = CalCulCenterCOORDMap(PerCenterCOORDAPT);
	}
	else if (building == EKEYBOARD::NUM5_KEY)
	{
		PerCenterCOORDReligion.erase(std::pair<int, int>(x, y));
		CenterCOORDReligion = CalCulCenterCOORDMap(PerCenterCOORDReligion);
	}
	else if (building == EKEYBOARD::NUM6_KEY)
	{
		PerCenterCOORDReligion.erase(std::pair<int, int>(x, y));
		CenterCOORDReligion = CalCulCenterCOORDMap(PerCenterCOORDReligion);
	}
	else if (building == EKEYBOARD::NUM7_KEY)
	{
		PerCenterCOORDPark.erase(std::pair<int, int>(x, y));
		CenterCOORDPark = CalCulCenterCOORDMap(PerCenterCOORDPark);
	}
}

void BuildingInfo::AddCOORDData(int x, int y, int building, int size)
{
	if (building == EKEYBOARD::NUM3_KEY) {
		PerCenterCOORDAPT[std::pair<int,int>(x, y)] = std::pair<int,int>(CalCulCenterCOORD(size, x, y)); 
		CenterCOORDAPT = CalCulCenterCOORDMap(PerCenterCOORDAPT);
	}
	else if (building == EKEYBOARD::NUM5_KEY)
	{ 
		PerCenterCOORDReligion[std::pair<int, int>(x, y)] = std::pair<int, int>(CalCulCenterCOORD(size, x, y));
		CenterCOORDReligion = CalCulCenterCOORDMap(PerCenterCOORDReligion);
	}
	else if (building == EKEYBOARD::NUM6_KEY)
	{ 
		PerCenterCOORDReligion[std::pair<int, int>(x, y)] = std::pair<int, int>(CalCulCenterCOORD(size, x, y));
		CenterCOORDReligion = CalCulCenterCOORDMap(PerCenterCOORDReligion);
	}
	else if (building == EKEYBOARD::NUM7_KEY)
	{ 
		PerCenterCOORDPark[std::pair<int, int>(x, y)] = std::pair<int, int>(CalCulCenterCOORD(size, x, y));
		CenterCOORDPark = CalCulCenterCOORDMap(PerCenterCOORDPark);
	}
}
