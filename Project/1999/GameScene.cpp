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
	delete news;
}

void GameScene::PlayInGame()
{
	PlayGetName();
	to->CleanInputBuffer();

	build->PrintWholeMap();
	info->PrintInfo();
	menu->PrintNewsImage();
	news->ShowNewNews();

	int page = 0;
	int DefaultMenuFlag = 0;

	int DayCount = 1;
	int EndingFlag = -1;
	while (1)
	{
		int ZombieDay = rand() % info->GetArmyPower();
		if ((ZombieDay < 10 || (DayCount % 10 == 0)) && DayCount > 5 && EndingFlag == -1)
		{
			// info update
			to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
			to->PartClean(INFO_POSITION_X + 45, INFO_POSITION_Y + 1, 96, 8);
			info->PrintInfo();

			ZombieAttack();
			menu->PrintZombieMenu();
			news->ShowZombieNews();
			Sleep(3000);

			// Day Update
			DayCount++;
			DateUpdate();
			EndOfTheDay();

			to->PartClean(INFO_POSITION_X + 45, INFO_POSITION_Y + 1, 96, 8);
			to->PartClean(NEWS_POSITION_X + 2, NEWS_POSITION_Y + 4, 40, 15);
			info->PrintInfo();

			to->CleanInputBuffer();
		}
		else
		{
			while (EndingFlag == -1)
			{
				to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
				int MenuSelect = menu->ShowDefaultMenu(MENU_POINT_POSITION_X, MENU_POINT_POSITION_Y, DEFAULT_MENU_BETWEEN);

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
					menu->ShowCitizenMenu();
					while (1)
					{
						if (_kbhit())
						{
							int nKey = _getch();
							if (nKey == EKEYBOARD::NUM1_KEY || nKey == EKEYBOARD::NUM2_KEY) // 세금 1
							{
								to->CleanInputBuffer();
								info->ForceMoney(EKEYBOARD::NUM1_KEY);
								if (nKey == EKEYBOARD::NUM1_KEY) { news->PushNewsQueue(ENEWS_CATEGORY::CitizenLittleForceNews); }
								else if (nKey == EKEYBOARD::NUM2_KEY) { news->PushNewsQueue(ENEWS_CATEGORY::CitizenManyForceNews); }

								info->PrintInfo();
								break;
							}
							else if (nKey == EKEYBOARD::NUM3_KEY) // 복지정책
							{
								to->CleanInputBuffer();
								info->Welfare();
								news->PushNewsQueue(ENEWS_CATEGORY::CitizenWelfareNews);

								info->PrintInfo();
								break;
							}
							else if (nKey == EKEYBOARD::M_KEY) // 메뉴로
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
					menu->ShowArmyMenu();
					while (1)
					{
						if (_kbhit())
						{
							int nKey = _getch();
							if (nKey == EKEYBOARD::NUM1_KEY) // 군인 월급 감소
							{
								to->CleanInputBuffer();
								info->ForceArmyMoney();
								news->PushNewsQueue(ENEWS_CATEGORY::ArmyForceNews);

								info->PrintInfo();
								break;
							}
							if (nKey == EKEYBOARD::NUM2_KEY) // 프로파간다
							{
								to->CleanInputBuffer();
								int Result = info->Propaganda();
								if (Result == 1) // Bad
								{
									news->PushNewsQueue(ENEWS_CATEGORY::ArmyPropagandaBadNews);
								}
								else if (Result == 0) // Good
								{
									news->PushNewsQueue(ENEWS_CATEGORY::ArmyPropagandaGoodNews);
								}

								info->PrintInfo();
								break;
							}
							else if (nKey == EKEYBOARD::NUM3_KEY) // 국방부 예산 확대
							{
								to->CleanInputBuffer();
								info->ArmyWelfare();
								news->PushNewsQueue(ENEWS_CATEGORY::ArmyWelfareNews);

								info->PrintInfo();
								break;
							}
							else if (nKey == EKEYBOARD::M_KEY) // 메뉴로
							{
								to->CleanInputBuffer();
								break;
							}

							to->CleanInputBuffer();
						}
					}
				}
				else if (MenuSelect == EMENU_SELECT::RELIGION)
				{
					menu->ShowReligionMenu();
					while (1)
					{
						if (_kbhit())
						{
							int nKey = _getch();
							if (nKey == EKEYBOARD::NUM1_KEY) // 국민 종교활동 금지
							{
								to->CleanInputBuffer();
								info->ProhibitReligionForCitizen();
								news->PushNewsQueue(ENEWS_CATEGORY::ReligionProhibitCitizenNews);

								info->PrintInfo();
								break;
							}
							if (nKey == EKEYBOARD::NUM2_KEY) // 군인 종교활동 금지
							{
								to->CleanInputBuffer();
								info->ProhibitReligionForArmy();
								news->PushNewsQueue(ENEWS_CATEGORY::ReligionProhibitArmyNews);

								info->PrintInfo();
								break;
							}
							else if (nKey == EKEYBOARD::NUM3_KEY) // 종교활동 참여
							{
								to->CleanInputBuffer();
								info->ParticiateReligion();
								news->PushNewsQueue(ENEWS_CATEGORY::ParticiateReligionNews);

								info->PrintInfo();
								break;
							}
							else if (nKey == EKEYBOARD::M_KEY) // 메뉴로
							{
								to->CleanInputBuffer();
								break;
							}

							to->CleanInputBuffer();
						}
					}
				}
				else if (MenuSelect == EKEYBOARD::P_KEY)
				{
					to->CleanInputBuffer();

					DateUpdate();
					EndingFlag = EndOfTheDay();
					DayCount++;

					to->PartClean(INFO_POSITION_X + 45, INFO_POSITION_Y + 1, 96, 8);
					news->ShowNewNews();
					info->PrintInfo();

					break;
				}
			}
			
		}

		if (EndingFlag != -1)
		{
			break;
		}

	}

	// Ending 작성
	if (EndingFlag == 1)
	{
		system("cls");
		printf("탄핵엔딩");
	}
	else if (EndingFlag == 2)
	{
		system("cls");
		printf("쿠데타엔딩");
	}
	else if (EndingFlag == 3)
	{
		system("cls");
		printf("종교의 국가 개입 엔딩");
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

int GameScene::EndOfTheDay() // Info Update When The End of the Day
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

	//Citizen Ending Checking
	if (info->GetCitizenPower() <= 10)
	{
		if (info->GetCitizenEnding() == 0)
		{
			news->PushNewsQueue(ENEWS_CATEGORY::CitizenEndingNews);
			info->SetCitizenEnding(1);
			return -1;
		}
		else if (info->GetCitizenEnding() == 1)
		{
			to->GoToXYPosition(0, 0);
			return 1; // Citizen Ending
		}
	}
	else
	{
		if (info->GetCitizenEnding() == 1)
		{
			info->SetCitizenEnding(0);
			return -1;
		}
	}

	// Army Ending Checking
	if (info->GetArmyPower() <= 10)
	{
		if (info->GetArmyEnding() == 0)
		{
			news->PushNewsQueue(ENEWS_CATEGORY::ArmyEndingNews);
			info->SetArmyEnding(1);
			return -1;
		}
		else if (info->GetArmyEnding() == 1)
		{
			return 2; // Army Ending
		}
	}
	else
	{
		if (info->GetArmyEnding() == 1)
		{
			info->SetArmyEnding(0);
			return -1;
		}
	}

	// Religion Ending Checking
	if (info->GetArmyPower() <= 20 && info->GetCitizenPower() <= 20)
	{
		if (info->GetReligionEnding() == 0)
		{
			news->PushNewsQueue(ENEWS_CATEGORY::ReligionEndingNews);
			info->SetReligionEnding(1);
			return -1;
		}
		else if (info->GetReligionEnding() == 1)
		{
			return 3; // Religion Ending
		}
	}
	else
	{
		if (info->GetReligionEnding() == 1)
		{
			info->SetReligionEnding(0);
			return -1;
		}
	}

	return -1;
}

void GameScene::ZombieAttack()
{
	// 사망률 계산
	int DeathNum = (int)((double)info->GetPeopleNum() * 0.2); // default death
	DeathNum += (int)((double)info->GetPeopleNum() * (double)build->DistanceBetweenAPTExit() * 0.1);

	int Save = 0;
	Save += build->ReligionCntSave(info, news);
	Save += build->CitizenCntSave(info, news);
	Save += build->ArmyCntSave(info, news);
	Save += (int)((double)info->GetPeopleNum() * (double)build->DistanceBetweenAPTReligion() * 0.1);

	to->GoToXYPosition(0, 0);
	printf("%d %d", Save, DeathNum);

	if (info->GetPeopleNum() + Save - DeathNum == 0)
	{
		//info->SetPeopleNum(0);
	}
	else
	{
		//info->SetPeopleNum(info->GetPeopleNum() + Save - DeathNum);
	}

}


