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
		printf("��");
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
	printf("�� �ǹ� ��ȣ�� �Է��ϼ��� ��");
	
	// Line 1
	// Print Hospital
	ConvertSmallImage(SMALL_Y, GetHosPitalImage(), CONSTRUCT_MENU_X+3, CONSTRUCT_MENU_Y+2);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 6);
	to->SetColor(14);
	printf("����: 1");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 7);
	to->SetColor(3);
	printf("10,000��");

	// Print Army(Small)
	ConvertSmallImage(SMALL_Y, GetArmySmallImage(), CONSTRUCT_MENU_X + 19, CONSTRUCT_MENU_Y + 2);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 16, CONSTRUCT_MENU_Y + 6);
	to->SetColor(14);
	printf("����(��): 2");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 16, CONSTRUCT_MENU_Y + 7);
	to->SetColor(3);
	printf("50,000��");

	// Line 2
	// Print APT
	ConvertMediumImage(MEDIUM_Y, GetAPTImage(), CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 9);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 15);
	to->SetColor(14);
	printf("����Ʈ: 3");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 16);
	to->SetColor(3);
	printf("70,000��");

	// Print Army(Medium)
	ConvertMediumImage(MEDIUM_Y, GetArmyMediumImage(), CONSTRUCT_MENU_X + 17, CONSTRUCT_MENU_Y + 9);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 16, CONSTRUCT_MENU_Y + 15);
	to->SetColor(14);
	printf("����(��): 4");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 16, CONSTRUCT_MENU_Y + 16);
	to->SetColor(3);
	printf("120,000��");

	// Line 3
	// Print Church
	ConvertMediumImage(MEDIUM_Y, GetChurchImage(), CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 18);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 3, CONSTRUCT_MENU_Y + 24);
	to->SetColor(14);
	printf("��ȸ: 5");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 3, CONSTRUCT_MENU_Y + 25);
	to->SetColor(3);
	printf("70,000��");

	// Print Cathedral
	ConvertMediumImage(MEDIUM_Y, GetCathedralImage(), CONSTRUCT_MENU_X + 17, CONSTRUCT_MENU_Y + 18);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 18, CONSTRUCT_MENU_Y + 24);
	to->SetColor(14);
	printf("����: 6");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 18, CONSTRUCT_MENU_Y + 25);
	to->SetColor(3);
	printf("70,000��");

	to->SetColor(6);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 12, CONSTRUCT_MENU_Y + 25);
	printf("<1/2>");

	to->GoToXYPosition(CONSTRUCT_MENU_X - 1, CONSTRUCT_MENU_Y + 27);
	printf("�ı� v | �������̵� z | �޴� m");
}

void MenuHandler::ShowConstructMenu2()
{
	to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);

	// Print Introduction Text
	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y);
	printf("�� �ǹ� ��ȣ�� �Է��ϼ��� ��");

	// Line 1
	// Print Park
	ConvertLargeImage(LARGE_Y, GetParkImage(), CONSTRUCT_MENU_X + 6, CONSTRUCT_MENU_Y + 2);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 11, CONSTRUCT_MENU_Y + 10);
	to->SetColor(14);
	printf("����: 7");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 11, CONSTRUCT_MENU_Y + 11);
	to->SetColor(3);
	printf("100,000��");

	// Print Army(Large)
	ConvertLargeImage(LARGE_Y, GetArmyLargeImage(), CONSTRUCT_MENU_X + 6, CONSTRUCT_MENU_Y + 13);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 9, CONSTRUCT_MENU_Y + 22);
	to->SetColor(14);
	printf("����(��): 8");
	to->GoToXYPosition(CONSTRUCT_MENU_X + 9, CONSTRUCT_MENU_Y + 23);
	to->SetColor(3);
	printf("200,000��");

	to->SetColor(6);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 12, CONSTRUCT_MENU_Y + 25);
	printf("<2/2>");

	to->GoToXYPosition(CONSTRUCT_MENU_X - 1, CONSTRUCT_MENU_Y + 27);
	printf("�ı� v | �������̵� z | �޴� m");
}

void MenuHandler::ShowCitizenMenu()
{
	to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 5, CONSTRUCT_MENU_Y);
	printf("�� �ù� ���� �޴� ��");

	to->SetColor(4);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 3);
	printf("�� ���� ���� �߰� ¡�� (key 1)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 5);
	printf("������ �߰������� ¡���մϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 6);
	printf("�δ�, 0.5���� ¡���մϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 7);
	printf("�������� ������ �߻���ŵ�ϴ�.");

	to->SetColor(12);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 11);
	printf("�� ���� ���� �߰� ¡�� (key 2)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 13);
	printf("������ �߰������� ¡���մϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 14);
	printf("�δ�, 0.3���� ¡���մϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 15);
	printf("�������� ������ �߻���ŵ�ϴ�.");

	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 19);
	printf("�� ���� ��å ���� (key 3)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 21);
	printf("���� ��å�� �����մϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 22);
	printf("10,000~30,000���� �ҿ�˴ϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 23);
	printf("�������� ������ �߻���ŵ�ϴ�.");



	to->SetColor(6);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 11, CONSTRUCT_MENU_Y + 27);
	printf("�޴� m");
}

void MenuHandler::ShowArmyMenu()
{
	to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 5, CONSTRUCT_MENU_Y);
	printf("�� ���� ���� �޴� ��");

	to->SetColor(4);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 3);
	printf("�� ���� ���� ���� (key 1)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 5);
	printf("���� ������ ���� ��ŵ�ϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 6);
	printf("�δ�, 1���� ¡���մϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 7);
	printf("������� �������ϴ�.");

	to->SetColor(9);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 11);
	printf("�� ���� �����İ��� (key 2)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 13);
	printf("������(?) ������ �����մϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 14);
	printf("10,000~30,000���� �ҿ�˴ϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 15);
	printf("������� �������ϴ�.");
	to->SetColor(8);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 16);
	printf("��! ������ ��û���� �ʽ��ϴ�.");

	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 19);
	printf("�� ����� ���� Ȯ�� (key 3)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 21);
	printf("����� ������ Ȯ���մϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 22);
	printf("60,000~90,000���� �ҿ�˴ϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 23);
	printf("������� �������ϴ�.");



	to->SetColor(6);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 11, CONSTRUCT_MENU_Y + 27);
	printf("�޴� m");
}

void MenuHandler::ShowReligionMenu()
{
	to->PartClean(MENU_CLEAN_X, MENU_CLEAN_Y, MENU_CLEAN_BX, MENU_CLEAN_BY);
	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 5, CONSTRUCT_MENU_Y);
	printf("�� ���� ���� �޴� ��");

	to->SetColor(11);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 3);
	printf("�� ����Ȱ�� ����(1) (key 1)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 5);
	printf("������ ����Ȱ���� �����մϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 6);
	printf("���������� �������ϴ�.");
	to->SetColor(8);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 7);
	printf("\"�׷�, ������ �������̾�.\"");

	to->SetColor(11);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 11);
	printf("�� ����Ȱ�� ����(2) (key 2)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 13);
	printf("������ ����Ȱ���� �����մϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 14);
	printf("���������� �������ϴ�.");
	to->SetColor(8);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 15);
	printf("\"�׷�, ������ �������̾�.\"");

	to->SetColor(10);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 2, CONSTRUCT_MENU_Y + 19);
	printf("�� ����Ȱ�� ���� (key 3)");
	to->SetColor(14);
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 21);
	printf("������翡 �����մϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 22);
	printf("10,000~20,000���� ����մϴ�.");
	to->GoToXYPosition(CONSTRUCT_MENU_X, CONSTRUCT_MENU_Y + 23);
	printf("���������� �������ϴ�.");



	to->SetColor(6);
	to->GoToXYPosition(CONSTRUCT_MENU_X + 11, CONSTRUCT_MENU_Y + 27);
	printf("�޴� m");
}
