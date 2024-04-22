#include "GameInfo.h"

GameInfo::GameInfo()
{
	Money = 200000;
	PeopleNum = 1000000;
	Time = 540;
	Year = 1999;
	Month = 1;
	Day = 1;
	ZombieAttack = 0;
	CitizenPower = 50;
	ReligionPower = 50;
	ArmyPower = 50;

	CitizenEnding = 0;
	ArmyEnding = 0;
	ReligionEnding = 0;
}

GameInfo::~GameInfo()
{
}
