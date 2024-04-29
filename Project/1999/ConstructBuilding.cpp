#include "ConstructBuilding.h"

ConstructBuilding::ConstructBuilding()
{
	srand((unsigned int)time(NULL));

	ExitNum = 2;

	// Size Insert
	BuildingSize.insert(std::pair<int, int>(49, 3)); // Hospital
	BuildingSize.insert(std::pair<int, int>(50, 3)); // Army Small
	BuildingSize.insert(std::pair<int, int>(51, 5)); // APT
	BuildingSize.insert(std::pair<int, int>(52, 5)); // Army Medium
	BuildingSize.insert(std::pair<int, int>(53, 5)); // Curch
	BuildingSize.insert(std::pair<int, int>(54, 5)); // Cathedral
	BuildingSize.insert(std::pair<int, int>(55, 8)); // Park
	BuildingSize.insert(std::pair<int, int>(56, 8)); // Army Large

	//Price Insert
	BuildingPrice.insert(std::pair<int, int>(49, 10000)); // Hospital
	BuildingPrice.insert(std::pair<int, int>(50, 50000)); // Army Small
	BuildingPrice.insert(std::pair<int, int>(51, 70000)); // APT
	BuildingPrice.insert(std::pair<int, int>(52, 120000)); // Army Medium
	BuildingPrice.insert(std::pair<int, int>(53, 70000)); // Curch
	BuildingPrice.insert(std::pair<int, int>(54, 70000)); // Cathedral
	BuildingPrice.insert(std::pair<int, int>(55, 30000)); // Park
	BuildingPrice.insert(std::pair<int, int>(56, 200000)); // Army Large
}

ConstructBuilding::~ConstructBuilding()
{
	delete to;
	delete music;
}

void ConstructBuilding::BuildingIntializer()
{
	APTNum = 0;
	HospitalNum = 0;
	ParkNum = 0;
	ReligionNum = 0;
	ArmySmallNum = 0;
	ArmyMediumNum = 0;
	ArmyLargeNum = 0;

	PerCenterCOORDAPT.clear();
	PerCenterCOORDReligion.clear();
	PerCenterExit.clear();

	Map::InitMap();
}

void ConstructBuilding::PrintWholeMap()
{
	system("cls");
	MakeRandomExit();
	GetPlayerExitNum();
}

void ConstructBuilding::GetPlayerExitNum()
{
	to->SetColor(10);
	to->GoToXYPosition(RANDOM_POSITION_X, RANDOM_POSITION_Y);
	printf("출입구의 개수를 입력하시오(2개 ~ 4개) ");

	to->SetColor(15);
	to->GoToXYPosition(RANDOM_POSITION_X + 13, RANDOM_POSITION_Y+3);
	printf("◀  %d   ▶", ExitNum);

	to->SetColor(10);
	to->GoToXYPosition(RANDOM_POSITION_X + 5, RANDOM_POSITION_Y+6);
	printf("(생성 c | 결정 space bar)");

	while (1)
	{
		to->GoToXYPosition(0, 0);
		Map::PrintWholeMap();

		if (_kbhit())
		{
			int nKey = _getch();
			if (nKey == EKEYBOARD::SPACE)
			{
				music->PlayBigClick();
				break;
			}
			else if (nKey == EKEYBOARD::KOREAN)
			{
				nKey = _getch();
				if (nKey == 186) { nKey = EKEYBOARD::C_KEY; }
				to->CleanInputBuffer();
			}
			else if (nKey == EKEYBOARD::C_KEY)
			{
				music->PlayFinish();
				Map::InitMap();
				MakeRandomExit();
				to->PartClean(0, 0, MAP_X, MAP_Y);
				continue;
			}
			else if (nKey == EKEYBOARD::DIRECTION)
			{
				nKey = _getch();
				if (nKey == EKEYBOARD::KEY_LEFT)
				{
					music->PlayMoveBeep();
					ExitNum--;
					if (ExitNum < 2)
					{
						ExitNum = 2;
					}
					
					to->SetColor(15);
					to->GoToXYPosition(RANDOM_POSITION_X + 13, RANDOM_POSITION_Y + 3);
					printf("      ");
					to->GoToXYPosition(RANDOM_POSITION_X + 13, RANDOM_POSITION_Y + 3);
					printf("◀  %d   ▶", ExitNum);

				}
				else if (nKey == EKEYBOARD::KEY_RIGHT)
				{
					music->PlayMoveBeep();
					ExitNum++;
					if (ExitNum > 4)
					{
						ExitNum = 4;
					}

					to->SetColor(15);
					to->GoToXYPosition(RANDOM_POSITION_X + 13, RANDOM_POSITION_Y + 3);
					printf("      ");
					to->GoToXYPosition(RANDOM_POSITION_X + 13, RANDOM_POSITION_Y + 3);
					printf("◀  %d   ▶", ExitNum);
				}
			}

			to->CleanInputBuffer();
		}
	}
}

void ConstructBuilding::MakeRandomExit()
{
	PerCenterExit.clear();

	int BlockValidCheck = 0;

	std::set<int> PositionX;
	std::set<int> PositionY;

	int index = 0;
	while (index < ExitNum)
	{
		// 156 x 50, but 5 is for extra
		int DecideXPart = rand() % 3; // 0: x=0, 1: x = 155(EndLine), 2: x = 5 ~ 150(Along Line)
		int DecideYPart = rand() % 2;

		// Along Line Decide
		if (DecideXPart == 0)
		{
			DecideYPart = rand() % 40 + 5;

			// Block Check
			for (int i = 0; i < 4; i++)
			{
				if (TotalMap[DecideYPart - i][DecideXPart]->GetInfo() == 0 || TotalMap[DecideYPart - (3 - i)][DecideXPart]->GetInfo() == 0)
				{
					BlockValidCheck = 1;
					break;
				}
			}

			if (BlockValidCheck == 1)
			{
				BlockValidCheck = 0;
				continue;
			}
		}
		else if (DecideXPart == 1)
		{
			DecideXPart = 155;
			DecideYPart = rand() % 40 + 5;

			// Block Check
			for (int i = 0; i < 4; i++)
			{
				if (TotalMap[DecideYPart + i][DecideXPart]->GetInfo() == 0 || TotalMap[DecideYPart - (3 - i)][DecideXPart]->GetInfo() == 0)
				{
					BlockValidCheck = 1;
					break;
				}
			}

			if (BlockValidCheck == 1)
			{
				BlockValidCheck = 0;
				continue;
			}
		}
		else if (DecideXPart == 2)
		{
			DecideXPart = rand() % 145 + 5;
			DecideYPart = rand() % 2;
			if (DecideYPart == 1)
			{
				DecideYPart = 49;
			}
			else
			{
				DecideYPart = 0;
			}

			// Block Check
			for (int i = 0; i < 4; i++)
			{
				if (TotalMap[DecideYPart][DecideXPart + i]->GetInfo() == 0 || TotalMap[DecideYPart][DecideXPart - (3 - i)]->GetInfo() == 0)
				{
					BlockValidCheck = 1;
					break;
				}
			}

			if (BlockValidCheck == 1)
			{
				BlockValidCheck = 0;
				continue;
			}
		}

		// Duplication Check
		if (PositionX.find(DecideXPart) == PositionX.end() && PositionY.find(DecideYPart) == PositionY.end())
		{
			PositionX.insert(DecideXPart);
			PositionY.insert(DecideYPart);

			PerCenterExit.push_back(std::pair<int, int>{DecideXPart, DecideYPart});

			// Map Recoloring
			if (DecideXPart == 0 || DecideXPart == 155)
			{
				for (int i = 0; i < 3; i++)
				{
					if (DecideXPart == 0)
					{
						TotalMap[DecideYPart + i][DecideXPart + 1]->SetColor(0);
						TotalMap[DecideYPart + i][DecideXPart + 1]->SetInfo(0);
					}
					else
					{
						TotalMap[DecideYPart + i][DecideXPart - 1]->SetColor(0);
						TotalMap[DecideYPart + i][DecideXPart - 1]->SetInfo(0);
					}

					TotalMap[DecideYPart + i][DecideXPart]->SetColor(0);
					TotalMap[DecideYPart + i][DecideXPart]->SetInfo(0);
				}
			}
			else
			{
				for (int i = 0; i < 3; i++)
				{
					if (DecideYPart == 0)
					{
						TotalMap[DecideYPart + 1][DecideXPart + i]->SetColor(0);
						TotalMap[DecideYPart + 1][DecideXPart + i]->SetInfo(0);
					}
					else
					{
						TotalMap[DecideYPart - 1][DecideXPart + i]->SetColor(0);
						TotalMap[DecideYPart - 1][DecideXPart + i]->SetInfo(0);
					}

					TotalMap[DecideYPart][DecideXPart + i]->SetColor(0);
					TotalMap[DecideYPart][DecideXPart + i]->SetInfo(0);
				}
			}
		}
		else
		{
			continue;
		}

		index++;
	}

	PositionX.clear();
	PositionY.clear();

}

int ConstructBuilding::BuildBuilding(int building, InfoHandler* info)
{

	int CurX = 80; // default COORD
	int CurY = 20; // default COORD

	int b = building;

	ShowBuildShadow(BuildingSize[building], CurX, CurY, -1);

	while (1)
	{	
		if (_kbhit())
		{
			int nKey = _getch();

			if (nKey == EKEYBOARD::KOREAN)
			{
				nKey = _getch();
				if (nKey == 189) { nKey = EKEYBOARD::V_KEY; }
				else if (nKey == 186) { nKey = EKEYBOARD::C_KEY; }
				else if (nKey == 209) { nKey = EKEYBOARD::M_KEY; }
				else if (nKey == 196) { nKey = EKEYBOARD::P_KEY; }
				else if (nKey == 187) { nKey = EKEYBOARD::Z_KEY; }
			}

			if (nKey == EKEYBOARD::SPACE)
			{
				// 건물짓기 호출
				music->PlayBuildSound();
				NewBuild(building, CurX, CurY, info);

				to->GoToXYPosition(0, 0);
				Map::PrintWholeMap();
			}
			else if (nKey == EKEYBOARD::V_KEY)
			{
				// 건물 파괴 호출
				music->PlayDestroySound();
				DestroyBuilding(building, BuildingSize[building], CurX, CurY, info, 0);

				to->GoToXYPosition(0, 0);
				Map::PrintWholeMap();
			}
			else if (nKey == EKEYBOARD::DIRECTION)
			{
				nKey = _getch();
				if (nKey == EKEYBOARD::KEY_UP)
				{
					CurY--;
					if (CurY < 1)
					{
						CurY = 1;
					}
					ShowBuildShadow(BuildingSize[building], CurX, CurY, EKEYBOARD::KEY_UP);
				}
				else if (nKey == EKEYBOARD::KEY_DOWN)
				{
					CurY++;

					if (CurY > 49 - BuildingSize[building])
					{
						CurY = 49 - BuildingSize[building];
					}
					ShowBuildShadow(BuildingSize[building], CurX, CurY, EKEYBOARD::KEY_DOWN);
				}
				else if (nKey == EKEYBOARD::KEY_LEFT)
				{
					CurX-=2;
					if (CurX < 2)
					{
						CurX = 2;
					}
					ShowBuildShadow(BuildingSize[building], CurX, CurY, EKEYBOARD::KEY_LEFT);
				}
				else if (nKey == EKEYBOARD::KEY_RIGHT)
				{
					CurX+=2;
					if (CurX > 154 - BuildingSize[building] * 2)
					{
						CurX = 154 - BuildingSize[building] * 2;
					}
					ShowBuildShadow(BuildingSize[building], CurX, CurY, EKEYBOARD::KEY_RIGHT);
				}
			}
			else if (nKey >= EKEYBOARD::NUM1_KEY && nKey <= EKEYBOARD::NUM8_KEY)
			{
				CleanBuildShadow(BuildingSize[building], CurX, CurY);
				building = nKey;
			}
			else if (nKey == EKEYBOARD::M_KEY)
			{
				CleanBuildShadow(BuildingSize[building], CurX, CurY);
				return EKEYBOARD::M_KEY;
			}
			else if (nKey == EKEYBOARD::Z_KEY)
			{
				CleanBuildShadow(BuildingSize[building], CurX, CurY);
				return EKEYBOARD::Z_KEY;
			}

			to->CleanInputBuffer();
		}
	}
	
}

void ConstructBuilding::ShowBuildShadow(int size, int x, int y, int direction)
{
	// 이전 Map을 다시 칠하고
	if (direction == EKEYBOARD::KEY_UP)
	{
		for (int i = 0; i < size * 2; i++)
		{
			to->GoToXYPosition(x + i, y + size);
			to->SetColor(TotalMap[y + size][x + i]->GetColor());
			printf(" ");
			to->SetColor(0);
		}
	}
	else if (direction == EKEYBOARD::KEY_DOWN)
	{
		for (int i = 0; i < size * 2; i++)
		{
			to->GoToXYPosition(x + i, y-1);
			to->SetColor(TotalMap[y - 1][x + i]->GetColor());
			printf(" ");
			to->SetColor(0);
		}
	}
	else if (direction == EKEYBOARD::KEY_LEFT)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				to->GoToXYPosition(x + size * 2 + j, y + i);
				to->SetColor(TotalMap[y + i][x + size * 2 + j]->GetColor());
				printf(" ");
				to->SetColor(0);
			}
		}
	}
	else if (direction == EKEYBOARD::KEY_RIGHT)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				to->GoToXYPosition(x - j - 1, y + i);
				to->SetColor(TotalMap[y + i][x - j - 1]->GetColor());
				printf(" ");
				to->SetColor(0);
			}
		}
	}

	// 새 커서배경을 칠해야됨
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size * 2; j++)
		{
			to->GoToXYPosition(x + j, y + i);
			if (TotalMap[y + i][x + j]->GetInfo() != 0)
			{
				to->SetColor(193);
				printf(" ");
			}
			else if (i == (size / 2) && (j == size - 1 || j == size))
			{
				to->SetColor(32);
				printf(" ");
			}
			else
			{
				to->SetColor(129);
				printf(" ");
			}
		}
	}
}

void ConstructBuilding::CleanBuildShadow(int size, int x, int y)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size * 2; j++)
		{
			to->GoToXYPosition(x + j, y + i);
			to->SetColor(TotalMap[y + i][x + j]->GetColor());
			printf(" ");
			to->SetColor(0);
		}
	}
}

void ConstructBuilding::NewBuild(int building, int x, int y, InfoHandler* info)
{
	int size = BuildingSize[building];
	int ValidCheck = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size * 2; j++)
		{
			if (TotalMap[y + i][x + j]->GetInfo() != 0)
			{
				ValidCheck = 1;
				break;
			}
		}
	}

	if (ValidCheck == 0)
	{
		if (info->GetMoney() < BuildingPrice[building])
		{
			info->PrintMoney(64);
			Sleep(500);

			info->PrintMoney(14);

			return;
		}

		info->SetMoney(info->GetMoney() - BuildingPrice[building]);
		info->PrintMoney(14);

		PlusCntBuilding(building, info);
		AddCOORDData(x, y, building, BuildingSize[building]);

		info->PrintPower(14);

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size * 2; j++)
			{
				TotalMap[y + i][x + j]->SetStartX(x);
				TotalMap[y + i][x + j]->SetStartY(y);
				TotalMap[y + i][x + j]->SetSize(size);


				if (building == EKEYBOARD::NUM1_KEY)
				{ 
					TotalMap[y + i][x + j]->SetInfo(EBUILDING::HOSPITAL);
					TotalMap[y + i][x + j]->SetColor(Hospital[i][j]);
				}
				else if (building == EKEYBOARD::NUM2_KEY)
				{ 
					TotalMap[y + i][x + j]->SetInfo(EBUILDING::ARMY_SAMLL);
					TotalMap[y + i][x + j]->SetColor(ArmySmall[i][j]);
				}
				else if (building == EKEYBOARD::NUM3_KEY)
				{ 
					TotalMap[y + i][x + j]->SetInfo(EBUILDING::APT);
					TotalMap[y + i][x + j]->SetColor(APT[i][j]);
				}
				else if (building == EKEYBOARD::NUM4_KEY)
				{ 
					TotalMap[y + i][x + j]->SetInfo(EBUILDING::ARMY_MEDIUM);
					TotalMap[y + i][x + j]->SetColor(ArmyMedium[i][j]);
				}
				else if (building == EKEYBOARD::NUM5_KEY)
				{ 
					TotalMap[y + i][x + j]->SetInfo(EBUILDING::CHURCH);
					TotalMap[y + i][x + j]->SetColor(Church[i][j]);
				}
				else if (building == EKEYBOARD::NUM6_KEY)
				{ 
					TotalMap[y + i][x + j]->SetInfo(EBUILDING::CATHEDRAL);
					TotalMap[y + i][x + j]->SetColor(Cathedral[i][j]);
				}
				else if (building == EKEYBOARD::NUM7_KEY)
				{ 
					TotalMap[y + i][x + j]->SetInfo(EBUILDING::PARK);
					TotalMap[y + i][x + j]->SetColor(Park[i][j]);
				}
				else if (building == EKEYBOARD::NUM8_KEY)
				{ 
					TotalMap[y + i][x + j]->SetInfo(EBUILDING::ARMY_LARGE);
					TotalMap[y + i][x + j]->SetColor(ArmyLarge[i][j]);
				}

			}
		}
	}
}

void ConstructBuilding::DestroyBuilding(int building, int size, int x, int y, InfoHandler* info, int Zombie)
{

	int DeleteX = 0;
	int DeleteY = 0;

	std::set<std::pair<int,int>> DeleteCOOR;

	// Checking for building on choosen place 
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size * 2 - Zombie; j++)
		{
			if (TotalMap[y + i][x + j]->GetInfo() != 0)
			{
				DeleteCOOR.insert(std::pair<int, int>{TotalMap[y + i][x + j]->GetStartX(), TotalMap[y + i][x + j]->GetStartY()});
			}
		}
	}

	int DLen = (int)DeleteCOOR.size();

	if (DLen != 0)
	{
		std::set<std::pair<int, int>>::iterator iter;
		for (iter = DeleteCOOR.begin(); iter != DeleteCOOR.end(); ++iter)
		{
			MinusCntBuilding(TotalMap[iter->second][iter->first]->GetInfo(), info);
			RemoveCOORDData(TotalMap[iter->second][iter->first]->GetStartX(), y, TotalMap[iter->second][iter->first]->GetStartY(), BuildingSize[TotalMap[iter->second][iter->first]->GetInfo()]);

			if (Zombie == 0 && TotalMap[iter->second][iter->first]->GetInfo() != EKEYBOARD::RELIGION_42B_KEY) // 평상시
			{
				info->SetMoney(info->GetMoney() + BuildingPrice[TotalMap[iter->second][iter->first]->GetInfo()] / 2);
			}
			else if (TotalMap[iter->second][iter->first]->GetInfo() == EKEYBOARD::RELIGION_42B_KEY) //42B Destroy
			{
				if (info->GetMoney() < 100000)
				{
					info->PrintMoney(64);
					Sleep(500);

					info->PrintMoney(14);

					continue;
				}

				info->SetCitizenPower(info->GetCitizenPower() + 10);
				info->SetReligionPower(info->GetReligionPower() + 10);
				info->SetMoney(info->GetMoney() - 100000);
			}
			info->PrintMoney(14);
			info->PrintPower(14);

			int CurSize = Map::TotalMap[iter->second][iter->first]->GetSize();
			for (int i = 0; i < CurSize; i++)
			{
				for (int j = 0; j < CurSize * 2; j++)
				{
					TotalMap[iter->second + i][iter->first + j]->SetStartX(-1);
					TotalMap[iter->second + i][iter->first + j]->SetStartY(-1);
					TotalMap[iter->second + i][iter->first + j]->SetInfo(0);
					TotalMap[iter->second + i][iter->first + j]->SetSize(-1);
					TotalMap[iter->second + i][iter->first + j]->SetColor(0);
				}
			}
		}

		DeleteCOOR.clear();
	}
}

void ConstructBuilding::PlusCntBuilding(int building, InfoHandler* info)
{
	int power;
	if (building == EKEYBOARD::NUM1_KEY)
	{
		power = info->GetCitizenPower();
		power+=1;
		info->SetCitizenPower(power);

		HospitalNum++;
	}
	else if (building == EKEYBOARD::NUM2_KEY)
	{
		power = info->GetArmyPower();
		power += 1;
		info->SetArmyPower(power);

		ArmySmallNum++;
	}
	else if (building == EKEYBOARD::NUM3_KEY)
	{
		power = info->GetCitizenPower();
		power += 3;
		info->SetCitizenPower(power);

		APTNum++;
	}
	else if (building == EKEYBOARD::NUM4_KEY)
	{
		power = info->GetArmyPower();
		power += 3;
		info->SetArmyPower(power);

		ArmyMediumNum++;
	}
	else if (building == EKEYBOARD::NUM5_KEY)
	{
		power = info->GetReligionPower();
		power += 2;
		info->SetReligionPower(power);

		ReligionNum++;
	}
	else if (building == EKEYBOARD::NUM6_KEY)
	{
		power = info->GetReligionPower();
		power += 2;
		info->SetReligionPower(power);

		ReligionNum++;
	}
	else if (building == EKEYBOARD::NUM7_KEY)
	{
		power = info->GetCitizenPower();
		power += 5;
		info->SetCitizenPower(power);

		ParkNum++;
	}
	else if (building == EKEYBOARD::NUM8_KEY)
	{
		power = info->GetArmyPower();
		power += 5;
		info->SetArmyPower(power);

		ArmyLargeNum++;
	}
}

void ConstructBuilding::MinusCntBuilding(int building, InfoHandler* info)
{
	int power;
	if (building == EKEYBOARD::NUM1_KEY)
	{
		HospitalNum--;
		power = info->GetCitizenPower();
		power -= 1;
		info->SetCitizenPower(power);
	}
	else if (building == EKEYBOARD::NUM2_KEY)
	{
		ArmySmallNum--;
		power = info->GetArmyPower();
		power -= 1;
		info->SetArmyPower(power);
	}
	else if (building == EKEYBOARD::NUM3_KEY)
	{
		APTNum--;
		power = info->GetCitizenPower();
		power -= 1;
		info->SetCitizenPower(power);
	}
	else if (building == EKEYBOARD::NUM4_KEY)
	{
		ArmyMediumNum--;
		power = info->GetArmyPower();
		power -= 3;
		info->SetArmyPower(power);
	}
	else if (building == EKEYBOARD::NUM5_KEY)
	{
		ReligionNum--;
		power = info->GetReligionPower();
		power -= 1;
		info->SetReligionPower(power);
	}
	else if (building == EKEYBOARD::NUM6_KEY)
	{
		ReligionNum--;
		power = info->GetReligionPower();
		power -= 1;
		info->SetReligionPower(power);
	}
	else if (building == EKEYBOARD::NUM7_KEY)
	{
		ParkNum--;
		power = info->GetCitizenPower();
		power -= 5;
		info->SetCitizenPower(power);
	}
	else if (building == EKEYBOARD::NUM8_KEY)
	{
		ArmyLargeNum--;
		power = info->GetArmyPower();
		power -= 5;
		info->SetArmyPower(power);
	}
}

void ConstructBuilding::Religon42BMaker(InfoHandler* info, NewsHandler* news)
{
	// 종교시설개수 * 2 / 100의 확률로 사이비 메이커 발동
	int Random = rand() % 100;
	if (ReligionNum * 2 > Random)
	{
		ReligionNum--;
		info->SetCitizenPower(info->GetCitizenPower() - 10);
		info->SetReligionPower(info->GetReligionPower() - 10);
		
		int MapSize = (int)PerCenterCOORDReligion.size();
		Random = rand() % MapSize;

		int OriginX, OriginY;
		std::map<std::pair<int, int>, std::pair<int, int>>::iterator iter;
		int index = 0;
		for (iter = PerCenterCOORDReligion.begin(); iter != PerCenterCOORDReligion.end(); ++iter, index++)
		{
			if (index == Random)
			{
				OriginX = iter->first.first;
				OriginY = iter->first.second;
			}

		}

		int BuildSize = TotalMap[OriginY][OriginX]->GetSize();
		RemoveCOORDData(OriginX, OriginY, TotalMap[OriginY][OriginX]->GetInfo(), BuildSize);
		for (int i = 0; i < BuildSize; i++)
		{
			for (int j = 0; j < BuildSize * 2; j++)
			{
				if (TotalMap[OriginY + i][OriginX + j]->GetColor() != 0)
				{
					TotalMap[OriginY + i][OriginX + j]->SetColor(32);
				}
				TotalMap[OriginY + i][OriginX + j]->SetInfo(EKEYBOARD::RELIGION_42B_KEY);
			}
		}


		to->GoToXYPosition(0, 0);
		Map::PrintWholeMap();

		news->PushNewsQueue(ENEWS_CATEGORY::Maker42B);
	}
}

int ConstructBuilding::ReligionCntSave(InfoHandler* info, NewsHandler* news)
{
	if (ReligionNum == 0)
	{
		news->PushNewsQueue(ENEWS_CATEGORY::ZeroReligionZombieNews);
	}
	else if (ReligionNum > 0 && ReligionNum < 4)
	{
		news->PushNewsQueue(ENEWS_CATEGORY::SmallReligionZombieNews);
	}
	else if (ReligionNum > 3 && ReligionNum < 7)
	{
		news->PushNewsQueue(ENEWS_CATEGORY::MediumReligionZombieNews);
	}
	else if (ReligionNum > 6)
	{
		news->PushNewsQueue(ENEWS_CATEGORY::LargeReligionZombieNews);
	}

	return (int)((double)info->GetPeopleNum() * 0.0001 * (double)ReligionNum);
}

int ConstructBuilding::CitizenCntSave(InfoHandler* info, NewsHandler* news)
{
	if (HospitalNum == 0)
	{
		news->PushNewsQueue(ENEWS_CATEGORY::ZeroHospitalZombieNews);
	}
	else if (HospitalNum > 0)
	{
		news->PushNewsQueue(ENEWS_CATEGORY::HospitalZombieNews);
	}

	if (APTNum == 0)
	{
		news->PushNewsQueue(ENEWS_CATEGORY::ZeroAPTZombieNews);
	}
	else if (APTNum > 0)
	{
		news->PushNewsQueue(ENEWS_CATEGORY::APTZombieNews);
	}

	if (ParkNum > 0)
	{
		news->PushNewsQueue(ENEWS_CATEGORY::ParkZombieNews);
	}

	int save = (int)((double)info->GetPeopleNum() * 0.0001 * (double)HospitalNum);
	save += (int)((double)info->GetPeopleNum() * 0.0002 * (double)APTNum);
	save -= (int)((double)info->GetPeopleNum() * 0.0003 * (double)ParkNum);

	return save;
}

int ConstructBuilding::ArmyCntSave(InfoHandler* info, NewsHandler* news)
{
	int ArmyGauge = ArmySmallNum + ArmyMediumNum * 2 + ArmyLargeNum * 5;

	if (ArmyGauge == 0)
	{
		news->PushNewsQueue(ENEWS_CATEGORY::ZeroArmyZombieNews);
	}
	else if (ArmyGauge > 0 && ArmyGauge < 10)
	{
		news->PushNewsQueue(ENEWS_CATEGORY::SmallArmyZombieNews);
	}
	else if (ArmyGauge > 9 && ArmyGauge < 20)
	{
		news->PushNewsQueue(ENEWS_CATEGORY::MediumArmyZombieNews);
	}
	else if (ArmyGauge > 19)
	{
		news->PushNewsQueue(ENEWS_CATEGORY::LargeArmyZombieNews);
	}

	return (int)((double)info->GetPeopleNum() * 0.0007 * (double)ArmyGauge);
}

int ConstructBuilding::DistanceBetweenAPTReligion()
{
	if (APTNum != 0 && ReligionNum != 0)
	{
		return CalCulDistance(CenterCOORDReligion.first, CenterCOORDReligion.second, CenterCOORDAPT.first, CenterCOORDAPT.second);
	}
	else
	{
		return 0;
	}
}

int ConstructBuilding::DistanceBetweenAPTExit()
{
	if (APTNum != 0)
	{
		int Sum = 0;
		for (int i = 0; i < ExitNum; i++)
		{
			Sum += CalCulDistance(PerCenterExit[i].first, PerCenterExit[i].second, CenterCOORDAPT.first, CenterCOORDAPT.second);
		}

		return Sum;
	}
	else
	{
		return 0;
	}
}

void ConstructBuilding::ZombieDayRandomDestory(InfoHandler* info, NewsHandler* news)
{
	// 10 / (종교 건물 개수 + 1) 확률로 건물을 뿌실지말지 정함
	int DecideDisaster = rand() % (ReligionNum + 1);
	if (DecideDisaster < 10 && HospitalNum + APTNum + ParkNum + ArmySmallNum + ArmyMediumNum + ArmyLargeNum > 0)
	{
		info->SetCntArr(ECOUNT::ZOMBIE_DESTROY_CNT, info->GetCntArr()[ECOUNT::ZOMBIE_DESTROY_CNT] + 1);

		while (1)
		{
			// 건물 뿌시기
			// 랜덤 좌표 뽑기
			int x = rand() % 151 + 2;
			int y = rand() % 47 + 1;

			// 건물이 존재함
			if (Map::TotalMap[y][x]->GetInfo() != 0 && Map::TotalMap[y][x]->GetInfo() != -1 && HospitalNum + APTNum + ParkNum + ArmySmallNum + ArmyMediumNum + ArmyLargeNum > 0)
			{
				// news 삽입
				news->PushNewsQueue(ENEWS_CATEGORY::PunishmentFromGod);
				
				to->SetColor(64);
				int s = TotalMap[y][x]->GetSize();
				int OriginX = TotalMap[y][x]->GetStartX();
				int OriginY = TotalMap[y][x]->GetStartY();

				for (int i = 0; i < s; i++)
				{
					for (int j = 0; j < s * 2; j++)
					{
						to->GoToXYPosition(OriginX + j, OriginY + i);
						printf(" ");
					}
				}

				DestroyBuilding(TotalMap[y][x]->GetInfo(), 1, x, y, info, 1);

				Sleep(2000);
				break;
			}
			else
			{
				continue;
			}
		}
	}

	to->GoToXYPosition(0, 0);
	Map::PrintWholeMap();
}
