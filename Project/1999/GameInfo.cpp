#include "GameInfo.h"

GameInfo::GameInfo()
{
	Money = 2000000;
	PeopleNum = 1000000;
	Year = 1999;
	Month = 1;
	Day = 1;
	CitizenPower = 50;
	ReligionPower = 50;
	ArmyPower = 50;

	CitizenEnding = 0;
	ArmyEnding = 0;
	ReligionEnding = 0;
	AllDieEnding = 0;

	int size = sizeof(CntArr) / sizeof(CntArr[0]);
	for (int i = 0; i < size; i++)
	{
		CntArr[i] = 0;
	}

}

GameInfo::~GameInfo()
{
}
