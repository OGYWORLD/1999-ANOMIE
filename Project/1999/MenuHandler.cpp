#include "MenuHandler.h"

MenuHandler::MenuHandler()
{
	PlayerInput = -1;
}

MenuHandler::~MenuHandler()
{
}

int MenuHandler::ShowDefaultMenu(int OriginX, int OriginY, int BetweenY)
{
	ConvertMenuImage(MENU_IMAGE_Y, GetMenuImage());

	int CurY = 0;

	while (1)
	{
		// Blink Point
		to->SetColor(10);
		to->GoToXYPosition(OriginX, OriginY + CurY);
		printf("▶");
		Sleep(300);
		to->GoToXYPosition(OriginX, OriginY + CurY);
		printf("  ");
		Sleep(300);

		// GetPlayerInput
		if (_kbhit())
		{
			int nKey = _getch();
			if (nKey == EKEYBOARD::SPACE)
			{
				to->CleanInputBuffer();
				return CurY;
			}
			else if (nKey == EKEYBOARD::DIRECTION)
			{
				nKey = _getch();
				if (nKey == EKEYBOARD::KEY_UP)
				{
					to->CleanInputBuffer();
					CurY -= 7;
					if (CurY < 0)
					{
						CurY = 21;
					}

				}
				else if (nKey == EKEYBOARD::KEY_DOWN)
				{
					to->CleanInputBuffer();
					CurY += 7;
					if (CurY > 21)
					{
						CurY = 0;
					}
				}
			}
			else if (nKey == EKEYBOARD::P_KEY)
			{
				to->CleanInputBuffer();
				return EKEYBOARD::P_KEY;
			}

			to->CleanInputBuffer();
		}

	}
}

void MenuHandler::ShowConstructMenu1()
{
	to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);

	// Print Introduction Text
	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y);
	printf("▶ 건물 번호를 입력하세요 ◀");
	
	// Line 1
	// Print Hospital
	ConvertSmallImage(SMALL_Y, GetHosPitalImage(), CONSTRUCT_MENU_X+3, CONSTRUCT_MENU_Y+2);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 6);
	to->SetColor(14);
	printf("병원: 1");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 7);
	to->SetColor(3);
	printf("10,000원");

	// Print Army(Small)
	ConvertSmallImage(SMALL_Y, GetArmySmallImage(), CONSTRUCT_MENU_X + 19, CONSTRUCT_MENU_Y + 2);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 16, CONSTRUCT_MENU_Y + 6);
	to->SetColor(14);
	printf("군대(소): 2");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 16, CONSTRUCT_MENU_Y + 7);
	to->SetColor(3);
	printf("50,000원");

	// Line 2
	// Print APT
	ConvertMediumImage(MEDIUM_Y, GetAPTImage(), CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 9);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 15);
	to->SetColor(14);
	printf("아파트: 3");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 16);
	to->SetColor(3);
	printf("70,000원");

	// Print Army(Medium)
	ConvertMediumImage(MEDIUM_Y, GetArmyMediumImage(), CONSTRUCT_MENU_X + 17, CONSTRUCT_MENU_Y + 9);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 16, CONSTRUCT_MENU_Y + 15);
	to->SetColor(14);
	printf("군대(중): 4");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 16, CONSTRUCT_MENU_Y + 16);
	to->SetColor(3);
	printf("120,000원");

	// Line 3
	// Print Church
	ConvertMediumImage(MEDIUM_Y, GetChurchImage(), CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 18);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 3, CONSTRUCT_MENU_Y + 24);
	to->SetColor(14);
	printf("교회: 5");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 3, CONSTRUCT_MENU_Y + 25);
	to->SetColor(3);
	printf("70,000원");

	// Print Cathedral
	ConvertMediumImage(MEDIUM_Y, GetCathedralImage(), CONSTRUCT_MENU_X + 17, CONSTRUCT_MENU_Y + 18);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 18, CONSTRUCT_MENU_Y + 24);
	to->SetColor(14);
	printf("성당: 6");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 18, CONSTRUCT_MENU_Y + 25);
	to->SetColor(3);
	printf("70,000원");

	to->SetColor(6);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 12, CONSTRUCT_MENU_Y + 25);
	printf("<1/2>");

	to->GoToXYPosition(CONSTRUCT_MENU_X - 1, CONSTRUCT_MENU_Y + 27);
	printf("파괴 v | 페이지이동 z | 메뉴 m");
}

void MenuHandler::ShowConstructMenu2()
{
	to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);

	// Print Introduction Text
	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y);
	printf("▶ 건물 번호를 입력하세요 ◀");

	// Line 1
	// Print Park
	ConvertLargeImage(LARGE_Y, GetParkImage(), CONSTRUCT_MENU_X + 6, CONSTRUCT_MENU_Y + 2);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 11, CONSTRUCT_MENU_Y + 10);
	to->SetColor(14);
	printf("공원: 7");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 11, CONSTRUCT_MENU_Y + 11);
	to->SetColor(3);
	printf("100,000원");

	// Print Army(Large)
	ConvertLargeImage(LARGE_Y, GetArmyLargeImage(), CONSTRUCT_MENU_X + 6, CONSTRUCT_MENU_Y + 13);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 9, CONSTRUCT_MENU_Y + 22);
	to->SetColor(14);
	printf("군대(대): 8");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 9, CONSTRUCT_MENU_Y + 23);
	to->SetColor(3);
	printf("200,000원");

	to->SetColor(6);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 12, CONSTRUCT_MENU_Y + 25);
	printf("<2/2>");

	to->GoToXYPosition(CONSTRUCT_MENU_X - 1, CONSTRUCT_MENU_Y + 27);
	printf("파괴 v | 페이지이동 z | 메뉴 m");
}

void MenuHandler::ShowCitizenMenu()
{
	to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 5, CONSTRUCT_MENU_Y);
	printf("▶ 시민 관련 메뉴 ◀");

	to->SetColor(4);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 3);
	printf("▶ 강한 세금 추가 징수 (key 1)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 5);
	printf("세금을 추가적으로 징수합니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 6);
	printf("인당, 0.5원씩 징수합니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 7);
	printf("부정적인 여론을 발생시킵니다.");

	to->SetColor(12);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 11);
	printf("▶ 약한 세금 추가 징수 (key 2)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 13);
	printf("세금을 추가적으로 징수합니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 14);
	printf("인당, 0.3원씩 징수합니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 15);
	printf("부정적인 여론을 발생시킵니다.");

	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 19);
	printf("▶ 복지 정책 실행 (key 3)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 21);
	printf("복지 정책을 실행합니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 22);
	printf("10,000~30,000원이 소요됩니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 23);
	printf("긍정적인 여론을 발생시킵니다.");



	to->SetColor(6);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 11, CONSTRUCT_MENU_Y + 27);
	printf("메뉴 m");
}

void MenuHandler::ShowArmyMenu()
{
	to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 5, CONSTRUCT_MENU_Y);
	printf("▶ 국방 관련 메뉴 ◀");

	to->SetColor(4);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 3);
	printf("▶ 군인 월급 감소 (key 1)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 5);
	printf("군인 원급을 감소 시킵니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 6);
	printf("인당, 1원씩 징수합니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 7);
	printf("군사력이 약해집니다.");

	to->SetColor(9);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 11);
	printf("▶ 국방 프로파간다 (key 2)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 13);
	printf("위대한(?) 국가를 선전합니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 14);
	printf("10,000~30,000원이 소요됩니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 15);
	printf("군사력이 강해집니다.");
	to->SetColor(8);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 16);
	printf("팁! 국민은 멍청하지 않습니다.");

	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 19);
	printf("▶ 국방부 예산 확대 (key 3)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 21);
	printf("국방부 예산을 확대합니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 22);
	printf("60,000~90,000원이 소요됩니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 23);
	printf("군사력이 강해집니다.");



	to->SetColor(6);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 11, CONSTRUCT_MENU_Y + 27);
	printf("메뉴 m");
}

void MenuHandler::ShowReligionMenu()
{
	to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 5, CONSTRUCT_MENU_Y);
	printf("▶ 종교 관련 메뉴 ◀");

	to->SetColor(11);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 3);
	printf("▶ 종교활동 금지(1) (key 1)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 5);
	printf("국민의 종교활동을 금지합니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 6);
	printf("종교권위가 약해집니다.");
	to->SetColor(8);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 7);
	printf("\"그래, 나에겐 국가뿐이야.\"");

	to->SetColor(11);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 11);
	printf("▶ 종교활동 금지(2) (key 2)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 13);
	printf("군인의 종교활동을 금지합니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 14);
	printf("종교권위가 약해집니다.");
	to->SetColor(8);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 15);
	printf("\"그래, 나에겐 조국뿐이야.\"");

	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 19);
	printf("▶ 종교활동 참여 (key 3)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 21);
	printf("종교행사에 참여합니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 22);
	printf("10,000~20,000원을 기부합니다.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 23);
	printf("종교권위가 강해집니다.");



	to->SetColor(6);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 11, CONSTRUCT_MENU_Y + 27);
	printf("메뉴 m");
}
