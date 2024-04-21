#define _CRT_SECURE_NO_WARNINGS

#include "GameScene.h"

GameScene::GameScene()
{
	srand(time(NULL));
}

GameScene::~GameScene()
{
	delete build;
	delete menu;
	delete to;
	delete info;
}

void GameScene::PlayInGame()
{
	PlayGetName();
	to->CleanInputBuffer();

	build->PrintWholeMap();
	info->PrintInfo();

	int page = 0;
	int DefaultMenuFlag = 0;

	int DayCount = 1;
	while (1)
	{
		to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
		int MenuSelect = menu->ShowDefaultMenu(MENU_POINT_POSITION_X, MENU_POINT_POSITION_Y, DEFAULT_MENU_BETWEEN);

		int ZombieDay = rand() % info->GetArmyPower();
		if ((ZombieDay < 15 || DayCount % 10 == 0) && DayCount > 7)
		{
			// 좀비데이~
			to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
			DateUpdate();
			EndOfTheDay();
		}
		else
		{
			if (MenuSelect == EMENU_SELECT::CONSTRUCT)
			{
				int page = 0;
				int DefaultMenuFlag = 0;

				while (1)
				{
					if (page == 0)
					{
						to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
						menu->ShowConstructMenu1();

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
								if (nKey == EKEYBOARD::Z_KEY)
								{
									to->CleanInputBuffer();
									page = 1;
									break;
								}
								else if (nKey == EKEYBOARD::M_KEY)
								{
									to->CleanInputBuffer();
									page = 0;
									DefaultMenuFlag = 1;
									break;
								}
								else if (nKey >= EKEYBOARD::NUM1_KEY && nKey <= EKEYBOARD::NUM6_KEY)
								{
									int ConstructInput = build->BuildBuilding(nKey, info);
									if (ConstructInput == EKEYBOARD::M_KEY)
									{
										to->CleanInputBuffer();
										page = 0;
										DefaultMenuFlag = 1;
										break;
									}
									else if (ConstructInput == EKEYBOARD::Z_KEY)
									{
										to->CleanInputBuffer();
										page = 1;
										break;
									}
								}
								to->CleanInputBuffer();
							}
						}
					}
					else if (page == 1)
					{
						to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
						menu->ShowConstructMenu2();

						while (1)
						{
							if (_kbhit())
							{
								int nKey = _getch();
								if (nKey == EKEYBOARD::Z_KEY)
								{
									to->CleanInputBuffer();
									page = 0;
									break;
								}
								else if (nKey == EKEYBOARD::M_KEY)
								{
									to->CleanInputBuffer();
									page = 0;
									DefaultMenuFlag = 1;
									break;
								}
								else if (nKey >= EKEYBOARD::NUM7_KEY && nKey <= EKEYBOARD::NUM8_KEY)
								{
									int ConstructInput = build->BuildBuilding(nKey, info);
									if (ConstructInput == EKEYBOARD::M_KEY)
									{
										to->CleanInputBuffer();
										page = 0;
										DefaultMenuFlag = 1;
										break;
									}
									else if (ConstructInput == EKEYBOARD::Z_KEY)
									{
										to->CleanInputBuffer();
										page = 0;
										break;
									}
								}
								to->CleanInputBuffer();
							}
						}
					}
					if (DefaultMenuFlag == 1)
					{
						DefaultMenuFlag = 0;
						break;
					}
				}
			}
			else if (MenuSelect == EMENU_SELECT::CITIZEN)
			{
				menu->ShowCitizenMenu(info);
				while (1)
				{
					if (_kbhit())
					{
						int nKey = _getch();
						if (nKey == EKEYBOARD::NUM1_KEY || nKey == EKEYBOARD::NUM2_KEY) // 세금 1
						{
							to->CleanInputBuffer();
							info->ForceMoney(EKEYBOARD::NUM1_KEY);
							info->PrintInfo();
							break;
						}
						else if (nKey == EKEYBOARD::NUM3_KEY) // 복지정책
						{
							to->CleanInputBuffer();
							info->Welfare();
							info->PrintInfo();
							break;
						}
						else if (nKey == EKEYBOARD::M_KEY)
						{
							to->CleanInputBuffer();
							break;
						}
						
						to->CleanInputBuffer();
					}
				}
			}
			else if (MenuSelect == EMENU_SELECT::ARMY)
			{
				// Army
			}
			else if (MenuSelect == EMENU_SELECT::RELIGION)
			{
				//Religion
			}
			else if (MenuSelect == EKEYBOARD::P_KEY)
			{
				to->CleanInputBuffer();

				DateUpdate();
				EndOfTheDay();

				to->PartClean(INFO_POSITION_X + 45, INFO_POSITION_Y + 1, 96, 8);

				info->PrintInfo();
			}
		}

		DayCount++;

	}
}

void GameScene::PlayGetName()
{
	system("cls");
	std::string Name;
	std::string CountryName;

	std::string sName;
	std::string sCountryName;

	to->SetColor(10);
	to->GoToXYPosition(PREVIEW_TEXT_POSITION_X, PREVIEW_TEXT_POSITION_Y);
	printf("당신의 이름은?(최대 10글자): ");
	to->GoToXYPosition(PREVIEW_TEXT_POSITION_X + 30, PREVIEW_TEXT_POSITION_Y);
	std::cin >> sName;
	if (sName.size() > 20)
	{
		Name = sName.substr(20);
		info->SetPresidentName(Name);
	}
	else
	{
		info->SetPresidentName(sName);
	}

	to->GoToXYPosition(PREVIEW_TEXT_POSITION_X, PREVIEW_TEXT_POSITION_Y + 3);
	printf("당신의 나라의 이름은?(최대 10글자): ");
	to->GoToXYPosition(PREVIEW_TEXT_POSITION_X + 36, PREVIEW_TEXT_POSITION_Y + 3);
	std::cin >> sCountryName;
	if (sName.size() > 20)
	{
		CountryName = sCountryName.substr(20);
		info->SetCountryName(CountryName);
	}
	else
	{
		info->SetCountryName(sCountryName);
	}
}

void GameScene::DateUpdate()
{
	int Year = info->GetYear();
	int Month = info->GetMonth();
	int Day = info->GetDay();

	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
	{
		if (Day == 31)
		{
			info->SetMonth(++Month);
			info->SetDay(1);
		}
		else
		{
			Day++;
			info->SetDay(Day);
		}
	}
	else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
	{
		if (Day == 30)
		{
			info->SetMonth(++Month);
			info->SetDay(1);
		}
		else
		{
			Day++;
			info->SetDay(Day);
		}
	}
	else if (Month == 2)
	{
		if (Day == 29 && Year % 4 == 0)
		{
			info->SetMonth(++Month);
			info->SetDay(1);
		}
		else if (Day == 28 && Year % 4 != 0)
		{
			info->SetMonth(++Month);
			info->SetDay(1);
		}
		else
		{
			Day++;
			info->SetDay(Day);
		}
	}

	if (Month > 12)
	{
		info->SetYear(++Year);
		info->SetMonth(1);
	}
}

void GameScene::EndOfTheDay() // Info Update When The End of the Day
{
	// 민심이 절반보다 높을 때 전체 인구수 * 0.1 * 민심률 / 2 만큼 증가
	// 민심이 절반보다 낮을 때 전체 인구수 * 0.1 * 민심률 / 2 만큼 감소
	if (info->GetCitizenPower() < 50)
	{
		info->SetCitizenPower(info->GetCitizenPower() - (int)((double)info->GetCitizenPower() * 0.1 / 2));
	}
	else
	{
		info->SetCitizenPower(info->GetCitizenPower() + (int)((double)info->GetCitizenPower() * 0.1 / 2));
	}

}




