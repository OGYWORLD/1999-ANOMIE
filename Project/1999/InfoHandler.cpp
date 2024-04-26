#include "InfoHandler.h"

InfoHandler::InfoHandler()
{
	srand(time(NULL));
}

InfoHandler::~InfoHandler()
{
	delete to;
}

void InfoHandler::PrintInfo()
{
	DrawLine();

	// Country Info
	to->SetColor(14);
	to->GoToXYPosition(INFO_POSITION_X + 4, INFO_POSITION_Y + 3);
	std::cout << CountryName << " 국가";

	to->GoToXYPosition(INFO_POSITION_X + 4, INFO_POSITION_Y + 5);
	std::cout << PresidentName << " 대통령";

	// Date Info
	to->GoToXYPosition(INFO_POSITION_X + 60, INFO_POSITION_Y + 2);
	printf("%d년", Year);
	to->GoToXYPosition(INFO_POSITION_X + 67, INFO_POSITION_Y + 2);
	printf("%d월", Month);
	to->GoToXYPosition(INFO_POSITION_X + 72, INFO_POSITION_Y + 2);
	printf("%d일", Day);

	// PeopleNum Info
	PrintDate(14);

	// Money Info
	PrintMoney(14);

	// Power Info
	PrintPower(14);
}

void InfoHandler::DrawLine()
{
	for (int i = 0; i < INFO_Y; i++)
	{
		for (int j = 0; j < INFO_X; j++)
		{
			to->GoToXYPosition(INFO_POSITION_X + j, INFO_POSITION_Y + i);
			if (InfoImage[i][j] != 0)
			{
				to->SetColor(InfoImage[i][j]);
				printf(" ");
			}
		}
	}
}

void InfoHandler::PrintDate(int color)
{
	to->SetColor(color);
	to->GoToXYPosition(INFO_POSITION_X + 53, INFO_POSITION_Y + 5);
	int PeopleNumLen = 0;
	for (int i = 1; ; i *= 10)
	{
		if (PeopleNum / i == 0)
		{
			break;
		}
		PeopleNumLen++;
	}

	printf("인구 수 \t ");
	int PeopleNumCopy = PeopleNum;
	int PositionI = 5;
	for (int i = PeopleNumLen - 1; i > -1; i--)
	{
		to->GoToXYPosition(INFO_POSITION_X + 62 + PositionI, INFO_POSITION_Y + 5);
		printf("%d", PeopleNumCopy / (int)pow(10, i));
		PeopleNumCopy %= (int)pow(10, i);

		if ((i + 1) % 3 == 1 && i != 0)
		{
			PositionI++;
			to->GoToXYPosition(INFO_POSITION_X + 62 + PositionI, INFO_POSITION_Y + 5);
			printf(",");
		}

		PositionI++;
	}
}

void InfoHandler::PrintMoney(int color)
{
	to->PartClean(INFO_POSITION_X + 55, INFO_POSITION_Y + 6, 37, 2);

	to->SetColor(color);
	int MoneyLen = 0;
	for (int i = 1; ; i *= 10)
	{
		if (Money / i == 0)
		{
			break;
		}
		MoneyLen++;
	}

	to->GoToXYPosition(INFO_POSITION_X + 55, INFO_POSITION_Y + 7);
	printf("국유 재산 \t ");
	int PositionI = 5;
	if (Money == 0)
	{
		to->GoToXYPosition(INFO_POSITION_X + 62 + PositionI, INFO_POSITION_Y + 7);
		printf("0     ");

		return;
	}

	int MoneyNumCopy = Money;
	for (int i = MoneyLen - 1; i > -1; i--)
	{
		to->GoToXYPosition(INFO_POSITION_X + 62 + PositionI, INFO_POSITION_Y + 7);
		printf("%d", MoneyNumCopy / (int)pow(10, i));
		MoneyNumCopy %= (int)pow(10, i);

		if ((i + 1) % 3 == 1 && i != 0)
		{
			PositionI++;
			to->GoToXYPosition(INFO_POSITION_X + 62 + PositionI, INFO_POSITION_Y + 7);
			printf(",");
		}

		PositionI++;
	}
}

void InfoHandler::PrintPower(int color)
{
	to->PartClean(INFO_POSITION_X + 100, INFO_POSITION_Y+2, 54, 7);

	// 민심
	to->SetColor(color);
	to->GoToXYPosition(INFO_POSITION_X + 100, INFO_POSITION_Y + 2);
	printf("민심 ");

	for (int i = 0; i < CitizenPower / 10; i++)
	{
		if (CitizenPower >= 50)
		{
			to->SetColor(32);
		}
		else
		{
			to->SetColor(64);
		}
		for (int j = 0; j < 3; j++)
		{
			to->GoToXYPosition(INFO_POSITION_X + 110 + (i * 3) + j, INFO_POSITION_Y + 2);
			printf(" ");
		}
	}
	to->GoToXYPosition(INFO_POSITION_X + 141, INFO_POSITION_Y + 2);
	to->SetColor(14);
	printf("%d / 100", CitizenPower);

	// 군사력
	to->GoToXYPosition(INFO_POSITION_X + 100, INFO_POSITION_Y + 4);
	printf("군사력 ");

	for (int i = 0; i < ArmyPower / 10; i++)
	{
		if (ArmyPower >= 50)
		{
			to->SetColor(32);
		}
		else
		{
			to->SetColor(64);
		}
		for (int j = 0; j < 3; j++)
		{
			to->GoToXYPosition(INFO_POSITION_X + 110 + (i * 3) + j, INFO_POSITION_Y + 4);
			printf(" ");
		}
	}
	to->GoToXYPosition(INFO_POSITION_X + 141, INFO_POSITION_Y + 4);
	to->SetColor(14);
	printf("%d / 100", ArmyPower);

	// 종교권위
	to->GoToXYPosition(INFO_POSITION_X + 100, INFO_POSITION_Y + 6);
	printf("종교권위 ");

	for (int i = 0; i < ReligionPower / 10; i++)
	{
		if (ReligionPower >= 50)
		{
			to->SetColor(32);
		}
		else
		{
			to->SetColor(64);
		}
		for (int j = 0; j < 3; j++)
		{
			to->GoToXYPosition(INFO_POSITION_X + 110 + (i * 3) + j, INFO_POSITION_Y + 6);
			printf(" ");
		}
	}
	to->GoToXYPosition(INFO_POSITION_X + 141, INFO_POSITION_Y + 6);
	to->SetColor(14);
	printf("%d / 100", ReligionPower);

}

void InfoHandler::ForceMoney(int level)
{
	if (level == EKEYBOARD::NUM1_KEY)
	{
		Money += (int)((double)PeopleNum * 0.08);
		CitizenPower -= 10;
		if (CitizenPower < 0) { CitizenPower = 0; }
	}
	else if (level == EKEYBOARD::NUM2_KEY)
	{
		Money += (int)((double)PeopleNum * 0.05);
		CitizenPower -= 5;
		if (CitizenPower < 0) { CitizenPower = 0; }
	}
	
}

void InfoHandler::Welfare()
{
	
	int r = rand() % 20000 + 10000;

	if (Money < r)
	{
		PrintMoney(64);
		Sleep(200);
		PrintMoney(14);

		return;
	}

	Money -= r;
	if (Money < 0) { Money = 0; }

	CitizenPower += (r / 10000);
	if (CitizenPower > 100) { CitizenPower = 100; }

}

void InfoHandler::ForceArmyMoney()
{
	Money += (int)((double)PeopleNum * 0.5);
	ArmyPower -= 20;
	if (ArmyPower < 0) { ArmyPower = 0; }
}

int InfoHandler::Propaganda()
{
	int GoodOrBad = rand() % 100;
	if (GoodOrBad < 30)
	{
		ArmyPower -= 20;
		if (ArmyPower < 0) { ArmyPower = 0; }
		CitizenPower -= 20;
		if (CitizenPower < 0) { CitizenPower = 0; }

		return 1;
	}
	else
	{
		int r = rand() % 20000 + 10000;
		if (Money < r)
		{
			PrintMoney(64);
			Sleep(200);
			PrintMoney(14);

			return 2;

		}
		Money -= r;
		if (Money < 0) { Money = 0; }
		ArmyPower += (r / 5000);
		if (ArmyPower > 100) { ArmyPower = 100; }

		return 0;
	}
}

void InfoHandler::ArmyWelfare()
{
	int r = rand() % 30000 + 60000;
	if (Money < r)
	{
		PrintMoney(64);
		Sleep(200);
		PrintMoney(14);

		return;
	}
	Money -= r;
	if (Money < 0) { Money = 0; }

	ArmyPower += (r / 10000);
	if (ArmyPower > 100) { ArmyPower = 100; }
}

void InfoHandler::ProhibitReligionForCitizen()
{
	int r = rand() % 2 + 3;
	CitizenPower += r;
	ReligionPower -= r;

	if (CitizenPower > 100)
	{
		CitizenPower = 100;
	}
	if (ReligionPower < 0)
	{
		CitizenPower = 0;
	}
}

void InfoHandler::ProhibitReligionForArmy()
{
	int r = rand() % 2 + 3;
	ArmyPower += r;
	ReligionPower -= r;

	if (ArmyPower > 100)
	{
		ArmyPower = 100;
	}
	if (ReligionPower < 0)
	{
		ArmyPower = 0;
	}
}

void InfoHandler::ParticiateReligion()
{
	int r = rand() % 10000 + 10000;
	if (Money < r)
	{
		PrintMoney(64);
		Sleep(200);
		PrintMoney(14);

		return;
	}
	Money -= r;
	ReligionPower += (r / 10000);
	if (ReligionPower > 100) { ReligionPower = 100; }
}
