#include "ConstructBuilding.h"

ConstructBuilding::ConstructBuilding()
{
	srand(time(NULL));
	ExitNum = 3;
}

ConstructBuilding::~ConstructBuilding()
{
	delete to;
	delete print;
}

void ConstructBuilding::PrintWholeMap()
{
	to->SystemClean();
	GetPlayerExitNum();
}

void ConstructBuilding::GetPlayerExitNum()
{
	to->SetColor(10);
	to->GoToXYPosition(RANDOM_POSITION_X, RANDOM_POSITION_Y);
	printf("출입구의 개수를 입력하시오(3개 ~ 6개) ");

	to->SetColor(15);
	to->GoToXYPosition(RANDOM_POSITION_X + 13, RANDOM_POSITION_Y+3);
	printf("◀  %d   ▶", ExitNum);

	to->SetColor(10);
	to->GoToXYPosition(RANDOM_POSITION_X + 5, RANDOM_POSITION_Y+6);
	printf("(생성 c | 결정 space bar)");

	while (1)
	{
		MakeRandomExit();
		to->GoToXYPosition(0, 0);
		Map::PrintWholeMap();

		if (_kbhit())
		{
			int nKey = _getch();
			if (nKey == EKEYBOARD::SPACE)
			{
				break;
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
					if (ExitNum < 3)
					{
						ExitNum = 3;
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
					if (ExitNum > 6)
					{
						ExitNum = 6;
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
		}
		else if (DecideXPart == 1)
		{
			DecideXPart = 155;
			DecideYPart = rand() % 40 + 5;
		}
		else if (DecideYPart == 2)
		{
			DecideYPart = rand() % 2;
			if (DecideYPart == 1)
			{
				DecideYPart = 45;
			}
			DecideXPart = rand() % 145 + 5;
		}

		// Duplication Check
		if (PositionX.find(DecideXPart) == PositionX.end() && PositionY.find(DecideYPart) == PositionY.end())
		{
			// Block Check
			// X = 0, X = 155
			for (int i = 0; i < 4; i++)
			{
				if(Map::TotalMap[DecideYPart][DecideXPart]->GetInfo() )
			}

			// Y = 0, Y = 49
			for (int i = 0; i < 4; i++)
			{
				if (Map::TotalMap[DecideYPart][DecideXPart]->GetInfo())
			}



			PositionX.insert(DecideXPart);
			PositionY.insert(DecideYPart);

			break;
		}
		else
		{
			continue;
		}

		index++;
	}














	int index = 0;
	while (index < ExitNum)
	{
		while(1)
		{
			to->SetColor(10);
			to->GoToXYPosition(0, 0 + index);
			printf("@@@@@@@\n");
			Sleep(1000);

			// 156 x 50, but 6 is for extra
			int DecideXPart = rand() % 3; // 0: x=0, 1: x = 155(EndLine), 2: x = 0 ~ 150(Along Line)
			int DecideYPart = rand() % 3;

			// Along Line Decide
			if (DecideXPart == 0)
			{
				DecideYPart = rand() % 40 + 5;
			}
			else if (DecideXPart == 1)
			{
				DecideXPart = 155;
				DecideYPart = rand() % 40 + 5;
			}
			else if (DecideYPart == 2)
			{
				DecideYPart = rand() % 2;
				if (DecideYPart == 1)
				{
					DecideYPart = 45;
				}
				DecideXPart = rand() % 145 + 5;
			}

			// Duplication Check
			if (PositionX.find(DecideXPart) == PositionX.end() && PositionY.find(DecideYPart) == PositionY.end())
			{
				PositionX.insert(DecideXPart);
				PositionY.insert(DecideYPart);

				break;
			}
			else
			{
				continue;
			}
		}

		// Check Already Exit
		// Checking X
		int delta[] = { -1, 0, 1 };
		
		/*
		if (DecideYPart == 0 || DecideYPart == 49)
		{
			int ValidIndexChecking = 0;
			// Block Checking
			for (int i = 0; i < 3; i++)
			{
				if (TotalMap[0][DecideXPart]->GetInfo() == 0 || TotalMap[0][DecideXPart-1]->GetInfo() == 0 || TotalMap[0][DecideXPart+1]->GetInfo() == 0 ||
					TotalMap[49][DecideXPart]->GetInfo() == 0 || TotalMap[49][DecideXPart - 1]->GetInfo() == 0 || TotalMap[49][DecideXPart + 1]->GetInfo() == 0)
				{
					ValidIndexChecking = 1;
					break;
				}
			}
			if (ValidIndexChecking == 1)
			{
				ValidIndexChecking = 0;
				continue;
			}

			// Map Recoloring
			for (int i = DecideXPart; i < 4; i++)
			{
				TotalMap[DecideYPart][i]->SetInfo(0);
				TotalMap[DecideYPart][i]->SetColor(15);
			}
		}
		else if (DecideXPart == 0 || DecideXPart == 155) // Cheking Y
		{
			int ValidIndexChecking = 0;
			// Block Checking
			for (int i = 0; i < 3; i++)
			{
				if (TotalMap[DecideYPart][0]->GetInfo() == 0 || TotalMap[DecideYPart][0]->GetInfo() == 0 || TotalMap[DecideYPart][0]->GetInfo() == 0 ||
					TotalMap[DecideYPart][155]->GetInfo() == 0 || TotalMap[DecideYPart][155]->GetInfo() == 0 || TotalMap[DecideYPart][155]->GetInfo() == 0)
				{
					ValidIndexChecking = 1;
					break;
				}
			}
			if (ValidIndexChecking == 1)
			{
				ValidIndexChecking = 0;
				continue;
			}

			// Map Recoloring
			for (int i = DecideYPart; i < 4; i++)
			{
				TotalMap[i][DecideXPart]->SetInfo(0);
				TotalMap[i][DecideXPart]->SetColor(15);
			}
		}
		*/

		int checkindex = 0;
		int CurX, CurY;
		std::set<int>::iterator iter;
		for (iter = PositionX.begin(); iter != PositionX.end(); iter++, checkindex++)
		{
			if (checkindex == index)
			{
				CurX = *iter;
			}
		}

		checkindex = 0;
		for (iter = PositionY.begin(); iter != PositionY.end(); iter++, checkindex++)
		{
			if (checkindex == index)
			{
				CurY = *iter;
			}
		}

		to->SetColor(10);
		to->GoToXYPosition(0, 0 + index);
		printf("%d %d\n", CurX, CurY);
		Sleep(1000);

		//Map::TotalMap[CurX][CurY]->SetInfo(0);
		//Map::TotalMap[CurX][CurY]->SetColor(15);

		/*
		if (DecideXPart > 0 && DecideXPart < 155)
		{
			// Map Recoloring
			for (int i = DecideXPart; i < 4; i++)
			{
				Map::TotalMap[DecideYPart][i]->SetInfo(0);
				Map::TotalMap[DecideYPart][i]->SetColor(15);
			}
		}
		else if (DecideYPart > 0 && DecideYPart < 49) // Cheking Y
		{
			// Map Recoloring
			for (int i = DecideYPart; i < 4; i++)
			{
				Map::TotalMap[i][DecideXPart]->SetInfo(0);
				Map::TotalMap[i][DecideXPart]->SetColor(15);
			}
		}
		*/
		index++;
	}

	PositionX.clear();
	PositionY.clear();

}
