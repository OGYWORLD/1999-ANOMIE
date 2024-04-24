#include "ConstructBuilding.h"

ConstructBuilding::ConstructBuilding()
{
	srand(time(NULL));

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
	BuildingPrice.insert(std::pair<int, int>(55, 50000)); // Park
	BuildingPrice.insert(std::pair<int, int>(56, 200000)); // Army Large
}

ConstructBuilding::~ConstructBuilding()
{
	delete to;
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
				break;
			}
			else if (nKey == EKEYBOARD::KOREAN)
			{
				nKey = _getch();
				if (nKey == 186) { nKey = EKEYBOARD::C_KEY; }
			}
			else if (nKey == EKEYBOARD::C_KEY)
			{
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
		// 156 x 50, but 6 is for extra
		int DecideXPart = rand() % 3; // 0: x=0, 1: x = 155(EndLine), 2: x = 0 ~ 150(Along Line)
		int DecideYPart = rand() % 3;

		// Along Line Decide
		if (DecideXPart == 0)
		{
			DecideYPart = rand() % 40 + 5;

			// Block Check
			for (int i = 0; i < 4; i++)
			{
				if (Map::TotalMap[DecideYPart - i][DecideXPart]->GetInfo() == 0 || Map::TotalMap[DecideYPart - (3 - i)][DecideXPart]->GetInfo() == 0)
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
				if (Map::TotalMap[DecideYPart + i][DecideXPart]->GetInfo() == 0 || Map::TotalMap[DecideYPart - (4 - i)][DecideXPart]->GetInfo() == 0)
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
				if (Map::TotalMap[DecideYPart][DecideXPart + i]->GetInfo() == 0 || Map::TotalMap[DecideYPart][DecideXPart - (4 - i)]->GetInfo() == 0)
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
						Map::TotalMap[DecideYPart + i][DecideXPart + 1]->SetColor(0);
						Map::TotalMap[DecideYPart + i][DecideXPart + 1]->SetInfo(0);
					}
					else
					{
						Map::TotalMap[DecideYPart + i][DecideXPart - 1]->SetColor(0);
						Map::TotalMap[DecideYPart + i][DecideXPart - 1]->SetInfo(0);
					}

					Map::TotalMap[DecideYPart + i][DecideXPart]->SetColor(0);
					Map::TotalMap[DecideYPart + i][DecideXPart]->SetInfo(0);
				}
			}
			else
			{
				for (int i = 0; i < 3; i++)
				{
					if (DecideYPart == 0)
					{
						Map::TotalMap[DecideYPart + 1][DecideXPart + i]->SetColor(0);
						Map::TotalMap[DecideYPart + 1][DecideXPart + i]->SetInfo(0);
					}
					else
					{
						Map::TotalMap[DecideYPart - 1][DecideXPart + i]->SetColor(0);
						Map::TotalMap[DecideYPart - 1][DecideXPart + i]->SetInfo(0);
					}

					Map::TotalMap[DecideYPart][DecideXPart + i]->SetColor(0);
					Map::TotalMap[DecideYPart][DecideXPart + i]->SetInfo(0);
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
				NewBuild(building, CurX, CurY, info);

				to->GoToXYPosition(0, 0);
				Map::PrintWholeMap();
			}
			else if (nKey == EKEYBOARD::V_KEY)
			{
				// 건물 파괴 호출
				DestroyBuilding(building, BuildingSize[building], CurX, CurY, info);

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
					if (CurX > 154 - BuildingSize[building]*2)
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
			to->SetColor(Map::TotalMap[y + size][x + i]->GetColor());
			printf(" ");
			to->SetColor(0);
		}
	}
	else if (direction == EKEYBOARD::KEY_DOWN)
	{
		for (int i = 0; i < size * 2; i++)
		{
			to->GoToXYPosition(x + i, y-1);
			to->SetColor(Map::TotalMap[y - 1][x + i]->GetColor());
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
				to->SetColor(Map::TotalMap[y + i][x + size * 2 + j]->GetColor());
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
				to->SetColor(Map::TotalMap[y + i][x - j - 1]->GetColor());
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
			if (Map::TotalMap[y + i][x + j]->GetInfo() != 0)
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
			to->SetColor(Map::TotalMap[y + i][x + j]->GetColor());
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
			if (Map::TotalMap[y + i][x + j]->GetInfo() != 0)
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
				Map::TotalMap[y + i][x + j]->SetStartX(x);
				Map::TotalMap[y + i][x + j]->SetStartY(y);
				Map::TotalMap[y + i][x + j]->SetInfo(-1);
				Map::TotalMap[y + i][x + j]->SetSize(size);


				if (building == EKEYBOARD::NUM1_KEY)
				{ 
					Map::TotalMap[y + i][x + j]->SetInfo(EBUILDING::HOSPITAL);
					Map::TotalMap[y + i][x + j]->SetColor(Hospital[i][j]);
				}
				else if (building == EKEYBOARD::NUM2_KEY)
				{ 
					Map::TotalMap[y + i][x + j]->SetInfo(EBUILDING::ARMY_SAMLL);
					Map::TotalMap[y + i][x + j]->SetColor(ArmySmall[i][j]);
				}
				else if (building == EKEYBOARD::NUM3_KEY)
				{ 
					Map::TotalMap[y + i][x + j]->SetInfo(EBUILDING::APT);
					Map::TotalMap[y + i][x + j]->SetColor(APT[i][j]);
				}
				else if (building == EKEYBOARD::NUM4_KEY)
				{ 
					Map::TotalMap[y + i][x + j]->SetInfo(EBUILDING::ARMY_MEDIUM);
					Map::TotalMap[y + i][x + j]->SetColor(ArmyMedium[i][j]);
				}
				else if (building == EKEYBOARD::NUM5_KEY)
				{ 
					Map::TotalMap[y + i][x + j]->SetInfo(EBUILDING::CHURCH);
					Map::TotalMap[y + i][x + j]->SetColor(Church[i][j]);
				}
				else if (building == EKEYBOARD::NUM6_KEY)
				{ 
					Map::TotalMap[y + i][x + j]->SetInfo(EBUILDING::CATHEDRAL);
					Map::TotalMap[y + i][x + j]->SetColor(Cathedral[i][j]);
				}
				else if (building == EKEYBOARD::NUM7_KEY)
				{ 
					Map::TotalMap[y + i][x + j]->SetInfo(EBUILDING::PARK);
					Map::TotalMap[y + i][x + j]->SetColor(Park[i][j]);
				}
				else if (building == EKEYBOARD::NUM8_KEY)
				{ 
					Map::TotalMap[y + i][x + j]->SetInfo(EBUILDING::ARMY_LARGE);
					Map::TotalMap[y + i][x + j]->SetColor(ArmyLarge[i][j]);
				}

			}
		}
	}
}

void ConstructBuilding::DestroyBuilding(int building, int size, int x, int y, InfoHandler* info)
{

	int DeleteX, DeleteY;

	std::set<std::pair<int,int>> DeleteCOOR;

	// Checking for building on choosen place 
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size * 2; j++)
		{
			if (Map::TotalMap[y + i][x + j]->GetInfo() != 0)
			{
				DeleteCOOR.insert(std::pair<int, int>{Map::TotalMap[y + i][x + j]->GetStartX(), Map::TotalMap[y + i][x + j]->GetStartY()});
			}
		}
	}

	int DLen = DeleteCOOR.size();

	if (DLen != 0)
	{
		std::set<std::pair<int, int>>::iterator iter;
		for (iter = DeleteCOOR.begin(); iter != DeleteCOOR.end(); ++iter)
		{
			MinusCntBuilding(Map::TotalMap[iter->second][iter->first]->GetInfo(), info);
			RemoveCOORDData(Map::TotalMap[iter->second][iter->first]->GetStartX(), y, Map::TotalMap[iter->second][iter->first]->GetStartY(), BuildingSize[Map::TotalMap[iter->second][iter->first]->GetInfo()]);

			info->SetMoney(info->GetMoney() + BuildingPrice[Map::TotalMap[iter->second][iter->first]->GetInfo()] / 2);
			info->PrintMoney(14);
			info->PrintPower(14);

			int CurSize = Map::TotalMap[iter->second][iter->first]->GetSize();
			for (int i = 0; i < CurSize; i++)
			{
				for (int j = 0; j < CurSize * 2; j++)
				{
					Map::TotalMap[iter->second + i][iter->first + j]->SetStartX(-1);
					Map::TotalMap[iter->second + i][iter->first + j]->SetStartY(-1);
					Map::TotalMap[iter->second + i][iter->first + j]->SetInfo(0);
					Map::TotalMap[iter->second + i][iter->first + j]->SetSize(-1);
					Map::TotalMap[iter->second + i][iter->first + j]->SetColor(0);
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
		if (power > 100)
		{
			power = 100;
		}
		info->SetCitizenPower(power);

		HospitalNum++;
	}
	else if (building == EKEYBOARD::NUM2_KEY)
	{
		power = info->GetArmyPower();
		power += 1;
		if (power > 100)
		{
			power = 100;
		}
		info->SetArmyPower(power);

		ArmySmallNum++;
	}
	else if (building == EKEYBOARD::NUM3_KEY)
	{
		power = info->GetCitizenPower();
		power += 2;
		if (power > 100)
		{
			power = 100;
		}
		info->SetCitizenPower(power);

		APTNum++;
	}
	else if (building == EKEYBOARD::NUM4_KEY)
	{
		power = info->GetArmyPower();
		power += 3;
		if (power > 100)
		{
			power = 100;
		}
		info->SetArmyPower(power);

		ArmyMediumNum++;
	}
	else if (building == EKEYBOARD::NUM5_KEY)
	{
		power = info->GetReligionPower();
		power += 1;
		if (power > 100)
		{
			power = 100;
		}
		info->SetReligionPower(power);

		ReligionNum++;
	}
	else if (building == EKEYBOARD::NUM6_KEY)
	{
		power = info->GetReligionPower();
		power += 1;
		if (power > 100)
		{
			power = 100;
		}
		info->SetReligionPower(power);

		ReligionNum++;
	}
	else if (building == EKEYBOARD::NUM7_KEY)
	{
		power = info->GetCitizenPower();
		power += 5;
		if (power > 100)
		{
			power = 100;
		}
		info->SetCitizenPower(power);

		ParkNum++;
	}
	else if (building == EKEYBOARD::NUM8_KEY)
	{
		power = info->GetArmyPower();
		power += 5;
		if (power > 100)
		{
			power = 100;
		}
		info->SetArmyPower(power);

		ArmyLargeNum++;
	}
}

void ConstructBuilding::MinusCntBuilding(int building, InfoHandler* info)
{
	int power;
	if (building == EKEYBOARD::NUM1_KEY)
	{
		power = info->GetCitizenPower();
		power -= 1;
		if (power > 100)
		{
			power = 100;
		}
		info->SetCitizenPower(power);
	}
	else if (building == EKEYBOARD::NUM2_KEY)
	{
		power = info->GetArmyPower();
		power -= 1;
		if (power > 100)
		{
			power = 100;
		}
		info->SetArmyPower(power);
	}
	else if (building == EKEYBOARD::NUM3_KEY)
	{
		power = info->GetCitizenPower();
		power -= 1;
		if (power > 100)
		{
			power = 100;
		}
		info->SetCitizenPower(power);
	}
	else if (building == EKEYBOARD::NUM4_KEY)
	{
		power = info->GetArmyPower();
		power -= 3;
		if (power > 100)
		{
			power = 100;
		}
		info->SetArmyPower(power);
	}
	else if (building == EKEYBOARD::NUM5_KEY)
	{
		power = info->GetReligionPower();
		power -= 1;
		if (power > 100)
		{
			power = 100;
		}
		info->SetReligionPower(power);
	}
	else if (building == EKEYBOARD::NUM6_KEY)
	{
		power = info->GetReligionPower();
		power -= 1;
		if (power > 100)
		{
			power = 100;
		}
		info->SetReligionPower(power);
	}
	else if (building == EKEYBOARD::NUM7_KEY)
	{
		power = info->GetCitizenPower();
		power -= 5;
		if (power > 100)
		{
			power = 100;
		}
		info->SetCitizenPower(power);
	}
	else if (building == EKEYBOARD::NUM8_KEY)
	{
		power = info->GetArmyPower();
		power -= 5;
		if (power > 100)
		{
			power = 100;
		}
		info->SetArmyPower(power);
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
	// 3 / (종교 건물 개수 + 종교권위/10) 확률로 건물을 뿌실지말지 정함
	int DecideDisaster = rand() % (ReligionNum + 1);
	if (DecideDisaster < 3)
	{
		info->SetCntArr(ECOUNT::ZOMBIE_DESTROY_CNT, info->GetCntArr()[ECOUNT::ZOMBIE_DESTROY_CNT] + 1);

		while (1)
		{
			// 건물 뿌시기
			// 랜덤 좌표 뽑기
			int x = rand() % 145 + 3;
			int y = rand() % 40 + 2;

			// 건물이 존재함
			if (Map::TotalMap[y][x]->GetInfo() != 0)
			{
				// news 삽입
				news->PushNewsQueue(ENEWS_CATEGORY::PunishmentFromGod);

				for (int i = 0; i < MEDIUM_Y; i++)
				{
					for (int j = 0; j < MEDIUM_X; j++)
					{
						if (Fire[i][j] != 0)
						{
							to->GoToXYPosition(x + j, y + i);
							to->SetColor(Fire[i][j]);
							printf(" ");
							to->SetColor(0);
						}
					}
					printf("\n");
				}

				DestroyBuilding(Map::TotalMap[y][x]->GetInfo(), 1, x, y, info);

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
