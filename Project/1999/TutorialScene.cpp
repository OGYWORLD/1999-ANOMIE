#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	ReturnMenu = -1;
	index = 1;
	Page = 1;

	Announce.push_back("�̰����� ���� ���̾�αװ� ǥ�õ˴ϴ�.");

	Announce.push_back("���� ������� ������ �˷��帳�ϴ�.");

	Announce.push_back("������� �ù�, ����, ������ ���� ������ ������ �˴ϴ�.");
	Announce.push_back("���� �糭 ��Ȳ�� ��ŭ �ڿ��� ������ �����Դϴ�.");
	Announce.push_back("����, ������ �߰� ¡���ϰų� �ٸ� ������ ������ Ȯ���� �� ������");
	Announce.push_back("������ �� �������� �������� ũ�� �����ϼ���.");
	Announce.push_back("�ݸ�, ����� ���� �ൿ�� �ϰԵǸ� ������ �������ϴ�.");
	Announce.push_back("������ �������� ��ŭ ���� ������ �����ؾ��Ѵٴ� �� �����ϼ���.");
	Announce.push_back("\"���� �����İ���\"�� �����ϰ� ������ ��� �����Դϴ�.");
	Announce.push_back("���� ������� ������ �漺���� ���� �� ������");
	Announce.push_back("�׻� �׵��� ������ �漺�� ���̶�� ����������.");
	Announce.push_back("����������, ���� ������ ���� ���� ������ ���ᰡ �Ǿ��ٰ� ������ ���� �Ǳ⵵�մϴ�.");
	Announce.push_back("���� Ȱ���� ���������ν� ������ ���� �漺���� ���� �� ������");
	Announce.push_back("�׸�ŭ�� ���ߵ� ���̿����� ���� ������ �������� �˰�輼��.");
	Announce.push_back("���� �������� �������� �ȴٰ� �����ϰ�����,");
	Announce.push_back("�׵��� ������ �ִ� �ڱ��� �����մϴ�. ���� �ɱ⸦ �ǵ��� ������.");

	Announce.push_back("�� ��°��, �ǹ� �Ǽ��� ���� �˷��帳�ϴ�.");

	Announce.push_back("�ǹ��� �ù�, ����, ������ ���� ���������ֽ��ϴ�.");
	Announce.push_back("�ǹ��� �Ǽ��� ������, �ǹ��� ������ ���� �������� ������ �߻��մϴ�.");
	Announce.push_back("�����ϼ���, �ı��� ���� �ǹ��� ���� ������ ������� �Ǽ��� ���� �ۿ� �������� ���մϴ�.");
	Announce.push_back("Ư��, ���� �糭 �� �߻��Ǵ� �ǹ� �ı��� ��� �Ǽ��� �������� ���մϴ�.");
	Announce.push_back("�ǹ��� ���� ���� ������ ���� ������ �ʽ��ϴ�.");
	Announce.push_back("���� �糭�� �߻������� ������ �������� �ε����ִ� ������ �մϴ�.");
	Announce.push_back("�� ��� �ǹ��� �׷� �� �ƴ϶�� �� ����ϼ���.");
	Announce.push_back("��������� �����غ��� ��, ���� �ü��� �����濡 �ִ� �� ���� �ʰ���?");
	Announce.push_back("����ɴԲ��� �������� ������ �����ϽŴٸ� �׷� ������ ������ �����ñ� �ٶ��ϴ�.");
	Announce.push_back("����, ... �� ���� �ǹ� ������ ����ɴ��� �濡 ���� �Ǽ��ǰ���.");
	Announce.push_back("�� �κп� ���ؼ��� ���� �����帮�� �ʰڽ��ϴ�.");
	Announce.push_back("��, ���ݱ����� ���翡 ����ϸ� ������ ����̸� �̴��� �׻� ���������.");
	Announce.push_back("��.. �������� ���翡 �����������.");

	Announce.push_back("����������, �ν�, �����, ���� ������ ���� �˷��帳�ϴ�.");

	Announce.push_back("�̿� ���ؼ��� ����� ����Ÿ�� ���� �����ϴ�.");
	Announce.push_back("�ٸ� Ȯ���� ���� �ν��� �پ����� ������ ����� �����ϴ� ������ ���� �پ��ٴ� ��,");
	Announce.push_back("�ν��� ���� ���� (��-)�� ������ �α����� �پ��� �� �Դϴ�.");
	Announce.push_back("�׸��� ����鿡�� ������ ���� �� �ƴϰ����� �̻��ϰԵ� ������ �����������");
	Announce.push_back("���� �糭�� Ƚ���� �����ϴ� �� �����ϴ�. �� �κ��� ��Ȯ���� ��������.");
	Announce.push_back("�ƹ��ɷ� ����ɴԲ��� �������� ������ �����ϽŴٸ� ����� �ູ�� ǥ���Ͻð���?");

	Announce.push_back("�׷� ���� � ������ ��ġ�ڽ��ϴ�.");


}

TutorialScene::~TutorialScene()
{
	delete print;
	delete to;
	delete music;
}

void TutorialScene::PlayTutorial()
{
	ReturnMenu = -1;
	PrintIntro();
	PrintMenuTutorial();
}

void TutorialScene::PrintIntro()
{
	music->PlayMusicIzanami2();

	system("cls");

	print->ConvertWholeImage(WHOLE_IMAGE_HALF_Y, print->GetZeepImage());
	Sleep(2000);
	system("cls");
	Sleep(1000);

	print->ConvertWholeImage(WHOLE_IMAGE_HALF_Y, print->GetVideoTitleImage());
	to->GoToXYPosition(88, 55);
	to->SetColor(10);
	printf("���� � ������ �����մϴ�.");
	Sleep(3000);
}

void TutorialScene::PrintMenuTutorial()
{
	int EndTutorial = 0;
	ReturnMenu = -1;
	index = 1;
	Page = 1;

	system("cls");

	print->ConvertWholeImage(WHOLE_IMAGE_HALF_Y, print->GetVideoMainImage());
	
	to->CleanInputBuffer();
	to->SetColor(11);
	to->GoToXYPosition(88, 45);
	printf("���� space bar | �޴��� m");

	while (1)
	{
		if (Page == 1)
		{
			PrintCategory(14, 8, 8);
			Page = 2;
			index = 1;
			to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);
			to->SetColor(31);
			to->GoToXYPosition(90, 25);
			printf("1. ����� ���� �ȳ�");


			if (SetAnnouncePosition(Announce, 10) == 1) { return; }

			PrintMenuInfo();

			for (int i = 0; i < TUTORIAL_INTRODUCE_MENU_ANNOUNCE_NUM; i++)
			{
				int EndCheck = SetAnnouncePosition(Announce, 10);
				if (EndCheck == 1)
				{
					EndTutorial = 1;
					break;
				}
				else if (EndCheck == 2)
				{
					EndTutorial = 2;
					ReturnMenu = -1;
					break;
				}
			}
			if (EndTutorial == 1) { return; }
			else if (EndTutorial == 2)
			{
				EndTutorial = -1;
				continue;
			}
		}
		else if (Page == 2)
		{
			PrintCategory(8, 14, 8);
			Page = 3;
			index = 16;

			to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);
			to->SetColor(31);
			to->GoToXYPosition(90, 25);
			printf("2. �ǹ� �Ǽ� �ȳ�");

			if (SetAnnouncePosition(Announce, 10) == 1) { return; }

			PrintConstructInfo();

			for (int i = 0; i < TUTORIAL_INTRODUCE_CONSTRUCT_ANNOUNCE_NUM; i++)
			{
				int EndCheck = SetAnnouncePosition(Announce, 10);
				if (EndCheck == 1)
				{
					EndTutorial = 1;
					break;
				}
				else if (EndCheck == 2)
				{
					EndTutorial = 2;
					ReturnMenu = -1;
					break;
				}
			}
			if (EndTutorial == 1) { return; }
			else if (EndTutorial == 2)
			{
				EndTutorial = -1;
				continue;
			}
		}
		else
		{
			PrintCategory(8, 8, 14);
			index = 30;
			Page = 1;
			to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);
			to->SetColor(31);
			to->GoToXYPosition(83, 25);
			printf("3. �ν�, �����, ���� ���� �ȳ�");

			if (SetAnnouncePosition(Announce, 10) == 1) { return; }

			PrintPowerInfo();

			for (int i = 0; i < TUTORIAL_INTRODUCE_POWER_ANNOUNCE_NUM; i++)
			{
				int EndCheck = SetAnnouncePosition(Announce, 10);
				if (EndCheck == 1)
				{
					EndTutorial = 1;
					break;
				}
				else if (EndCheck == 2)
				{
					EndTutorial = 2;
					ReturnMenu = -1;
					break;
				}
			}
			if (EndTutorial == 1) { return; }
			else if (EndTutorial == 2)
			{
				EndTutorial = -1;
				continue;
			}

			to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);
			to->SetColor(47);
			to->GoToXYPosition(92, 25);
			printf("�����ϼ̽��ϴ�");

			if (SetAnnouncePosition(Announce, 10) == 1) { return; }

			index = 1;
		}
	}
}

void TutorialScene::PrintMenuInfo()
{
	to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);
	to->SetColor(95);
	to->GoToXYPosition(55, 11);
	printf("�� �ù� ���� ��");

	to->SetColor(79);
	to->GoToXYPosition(48, 14);
	printf("���� ���� ¡��");
	to->SetColor(207);
	to->GoToXYPosition(63, 14);
	printf("���� ���� ¡��");
	to->SetColor(15);
	to->GoToXYPosition(48, 16);
	printf("���ε鿡�� ������ �߰� ¡���մϴ�.");

	to->SetColor(47);
	to->GoToXYPosition(53, 19);
	printf("���� ���� ��å ����");
	to->SetColor(15);
	to->GoToXYPosition(51, 21);
	printf("����κ��� ��ģ ���ο���");
	to->GoToXYPosition(51, 22);
	printf("���� ��å�� �����մϴ�.");

	to->SetColor(47);
	to->GoToXYPosition(93, 11);
	printf("�� ���� ���� ��");

	to->SetColor(79);
	to->GoToXYPosition(93, 14);
	printf("���� ���� �谨");
	to->SetColor(15);
	to->GoToXYPosition(90, 16);
	printf("������ ������ �谨�Ͽ�");
	to->GoToXYPosition(90, 17);
	printf("���� �������� ����մϴ�.");

	to->SetColor(31);
	to->GoToXYPosition(93, 20);
	printf("���� ������-����");
	to->SetColor(12);
	to->GoToXYPosition(92, 22);
	printf("�� ��� ���� ��� ��");
	to->SetColor(15);
	to->GoToXYPosition(90, 23);
	printf("��н����� ������ ����");
	to->GoToXYPosition(90, 24);
	printf("���� �漺���� ���Դϴ�.");

	to->SetColor(47);
	to->GoToXYPosition(93, 27);
	printf("����� ���� Ȯ��");
	to->SetColor(15);
	to->GoToXYPosition(90, 29);
	printf("������� ������ Ȯ���Ͽ�");
	to->GoToXYPosition(90, 30);
	printf("������ ������ ����ϴ�.");


	to->SetColor(63);
	to->GoToXYPosition(128, 11);
	printf("�� ���� ���� ��");

	to->SetColor(79);
	to->GoToXYPosition(126, 14);
	printf("����Ȱ�� ���� (����)");
	to->SetColor(15);
	to->GoToXYPosition(123, 16);
	printf("������ ����Ȱ���� �����Ͽ�");
	to->GoToXYPosition(123, 17);
	printf("������ ���� ������ ���Դϴ�.");

	to->SetColor(79);
	to->GoToXYPosition(126, 20);
	printf("����Ȱ�� ���� (����)");
	to->SetColor(15);
	to->GoToXYPosition(123, 22);
	printf("������ ����Ȱ���� �����Ͽ�");
	to->SetColor(15);
	to->GoToXYPosition(123, 23);
	printf("������ ���� ������ ���Դϴ�.");

	to->SetColor(47);
	to->GoToXYPosition(129, 26);
	printf("����Ȱ�� ����");
	to->SetColor(15);
	to->GoToXYPosition(127, 28);
	printf("����Ȱ���� �����Ͽ�");
	to->GoToXYPosition(123, 29);
	printf("������ ���� ������ ���Դϴ�.");
}

int TutorialScene::NextKey()
{
	while (1)
	{
		int nKey = _getch();

		if (nKey == EKEYBOARD::SPACE)
		{
			music->PlayMoveBeep();
			break;
		}
		else if (nKey == EKEYBOARD::NUM1_KEY)
		{
			music->PlayMoveBeep();
			Page = 1;
			ReturnMenu = 2;
			break;
		}
		else if (nKey == EKEYBOARD::NUM2_KEY)
		{
			music->PlayMoveBeep();
			Page = 2;
			ReturnMenu = 2;
			break;
		}
		else if (nKey == EKEYBOARD::NUM3_KEY)
		{
			music->PlayMoveBeep();
			Page = 3;
			ReturnMenu = 2;
			break;
		}
		if (nKey == EKEYBOARD::M_KEY)
		{
			music->PlayBigClick();
			to->SetColor(0);
			ReturnMenu = 1;
			break;
		}
	}

	to->CleanInputBuffer();
	return ReturnMenu;
}

void TutorialScene::PrintConstructInfo()
{
	to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);
	to->SetColor(95);
	to->GoToXYPosition(55, 11);
	printf("�� �ù� ���� ��");

	to->SetColor(95);
	to->GoToXYPosition(47, 14);
	printf("���� (�ù�)");
	print->ConvertSmallImage(SMALL_Y, print->GetHosPitalImage(), 49, 16);

	to->SetColor(95);
	to->GoToXYPosition(61, 14);
	printf("����Ʈ (�ù�)");
	print->ConvertMediumImage(MEDIUM_Y, print->GetAPTImage(), 63, 16);

	to->SetColor(95);
	to->GoToXYPosition(55, 23);
	printf("���� (�ù�)");
	to->SetColor(0);
	print->ConvertLargeImage(LARGE_Y, print->GetParkImage(), 53, 25);

	to->SetColor(47);
	to->GoToXYPosition(92, 11);
	printf("�� ���� ���� ��");

	to->SetColor(47);
	to->GoToXYPosition(83, 14);
	printf("�δ�(��) (����)");
	print->ConvertSmallImage(SMALL_Y, print->GetArmySmallImage(), 88, 16);

	to->SetColor(47);
	to->GoToXYPosition(101, 14);
	printf("�δ�(��) (����)");
	print->ConvertMediumImage(MEDIUM_Y, print->GetArmyMediumImage(), 104, 16);

	to->SetColor(47);
	to->GoToXYPosition(93, 23);
	printf("�δ�(��) (����)");
	to->SetColor(0);
	print->ConvertLargeImage(LARGE_Y, print->GetArmyLargeImage(), 92, 25);


	to->SetColor(63);
	to->GoToXYPosition(132, 11);
	printf("�� ���� ���� ��");

	to->SetColor(63);
	to->GoToXYPosition(123, 14);
	printf("��ȸ (����)");
	to->SetColor(0);
	print->ConvertMediumImage(MEDIUM_Y, print->GetChurchImage(), 124, 16);

	to->SetColor(63);
	to->GoToXYPosition(142, 14);
	printf("���� (����)");
	to->SetColor(0);
	print->ConvertMediumImage(MEDIUM_Y, print->GetCathedralImage(), 144, 16);
}

void TutorialScene::PrintPowerInfo()
{
	to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);

	to->SetColor(78);
	to->GoToXYPosition(75, 22);
	printf("����Ÿ �������� ���� �ڷᰡ �������� �ʽ��ϴ�.");

}

void TutorialScene::PrintCategory(int p1, int p2, int p3)
{
	to->SetColor(p1);
	to->GoToXYPosition(28, 55);
	printf("1. ����� ���� �ȳ� (key 1)");

	to->SetColor(p2);
	to->GoToXYPosition(88, 55);
	printf("2. �ǹ� �Ǽ� �ȳ� (key 2)");

	to->SetColor(p3);
	to->GoToXYPosition(148, 55);
	printf("3. �ν�, �����, ���� ���� �ȳ� (key 3)");
}

int TutorialScene::SetAnnouncePosition(std::vector<const char*> s, int color)
{
	to->PartClean(42, 39, 115, 1);
	to->SetColor(color);

	int size = strlen(s[index])/2;

	to->GoToXYPosition(TUTORIAL_ANNOUNCE_X - size, TUTORIAL_ANNOUNCE_Y);
	std::cout << s[index];

	//backlog
	if (index >= 1)
	{
		to->PartClean(42, 49, 115, 1);
		int BackSize = strlen(s[index - 1])/2;
		to->GoToXYPosition(TUTORIAL_ANNOUNCE_X - BackSize, TUTORIAL_ANNOUNCE_Y + 10);

		// Before Dialog
		to->SetColor(8);
		std::cout << s[index - 1];
	}

	index++;

	int nk = NextKey();
	if(nk == 1) { return 1; }
	else if (nk == 2) { return 2; }
	else { return 0; }
}
