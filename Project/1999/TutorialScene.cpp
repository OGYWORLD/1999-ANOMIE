#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	ReturnMenu = -1;
	index = 0;

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

}

TutorialScene::~TutorialScene()
{
	delete print;
	delete to;
}

void TutorialScene::PlayTutorial()
{
	ReturnMenu = -1;
	//PrintIntro();
	PrintMenuTutorial();
}

void TutorialScene::PrintIntro()
{
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
	system("cls");

	print->ConvertWholeImage(WHOLE_IMAGE_HALF_Y, print->GetVideoMainImage());
	
	to->SetColor(14);
	to->GoToXYPosition(125, 37);
	printf("���� space bar | �޴��� m");

	to->SetColor(31);
	to->GoToXYPosition(125, 18);
	printf("1. ����� ���� �ȳ�");

	SetAnnouncePosition(Announce, 10);

	PrintMenuInfo();

	for (int i = 0; i < TUTORIAL_INTRODUCE_MENU_ANNOUNCE_NUM; i++)
	{
		SetAnnouncePosition(Announce, 10);
	}

	to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);
	to->SetColor(31);
	to->GoToXYPosition(125, 18);
	printf("2. �ǹ� �Ǽ� �ȳ�");

	SetAnnouncePosition(Announce, 10);

	PrintConstructInfo();
	while (1)
	{

	}
}

void TutorialScene::PrintMenuInfo()
{
	to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);
	to->SetColor(95);
	to->GoToXYPosition(92, 4);
	printf("�� �ù� ���� ��");

	to->SetColor(79);
	to->GoToXYPosition(85, 7);
	printf("���� ���� ¡��");
	to->SetColor(207);
	to->GoToXYPosition(100, 7);
	printf("���� ���� ¡��");
	to->SetColor(15);
	to->GoToXYPosition(85, 9);
	printf("���ε鿡�� ������ �߰� ¡���մϴ�.");

	to->SetColor(47);
	to->GoToXYPosition(90, 12);
	printf("���� ���� ��å ����");
	to->SetColor(15);
	to->GoToXYPosition(88, 14);
	printf("����κ��� ��ģ ���ο���");
	to->GoToXYPosition(88, 15);
	printf("���� ��å�� �����մϴ�.");

	to->SetColor(47);
	to->GoToXYPosition(130, 4);
	printf("�� ���� ���� ��");

	to->SetColor(79);
	to->GoToXYPosition(130, 7);
	printf("���� ���� �谨");
	to->SetColor(15);
	to->GoToXYPosition(127, 9);
	printf("������ ������ �谨�Ͽ�");
	to->GoToXYPosition(127, 10);
	printf("���� �������� ����մϴ�.");

	to->SetColor(31);
	to->GoToXYPosition(130, 13);
	printf("���� ������-����");
	to->SetColor(12);
	to->GoToXYPosition(127, 15);
	printf("�� ��� ���� ��� ��");
	to->SetColor(15);
	to->GoToXYPosition(127, 16);
	printf("��н����� ������ ����");
	to->GoToXYPosition(127, 17);
	printf("���� �漺���� ���Դϴ�.");

	to->SetColor(47);
	to->GoToXYPosition(130, 20);
	printf("����� ���� Ȯ��");
	to->SetColor(15);
	to->GoToXYPosition(127, 22);
	printf("������� ������ Ȯ���Ͽ�");
	to->GoToXYPosition(127, 23);
	printf("������ ������ ����ϴ�.");


	to->SetColor(63);
	to->GoToXYPosition(165, 4);
	printf("�� ���� ���� ��");

	to->SetColor(79);
	to->GoToXYPosition(163, 7);
	printf("����Ȱ�� ���� (����)");
	to->SetColor(15);
	to->GoToXYPosition(160, 9);
	printf("������ ����Ȱ���� �����Ͽ�");
	to->GoToXYPosition(160, 10);
	printf("������ ���� ������ ���Դϴ�.");

	to->SetColor(79);
	to->GoToXYPosition(163, 13);
	printf("����Ȱ�� ���� (����)");
	to->SetColor(15);
	to->GoToXYPosition(160, 15);
	printf("������ ����Ȱ���� �����Ͽ�");
	to->SetColor(15);
	to->GoToXYPosition(160, 16);
	printf("������ ���� ������ ���Դϴ�.");

	to->SetColor(47);
	to->GoToXYPosition(166, 19);
	printf("����Ȱ�� ����");
	to->SetColor(15);
	to->GoToXYPosition(164, 21);
	printf("����Ȱ���� �����Ͽ�");
	to->GoToXYPosition(160, 22);
	printf("������ ���� ������ ���Դϴ�.");
}

int TutorialScene::NextKey()
{
	while (1)
	{
		int nKey = _getch();

		if (nKey == EKEYBOARD::SPACE)
		{
			break;
		}
		if (nKey == EKEYBOARD::M_KEY)
		{
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
	to->GoToXYPosition(92, 4);
	printf("�� �ù� ���� ��");

	to->SetColor(95);
	to->GoToXYPosition(84, 7);
	printf("���� (�ù�)");
	print->ConvertSmallImage(SMALL_Y, print->GetHosPitalImage(), 86, 9);

	to->SetColor(95);
	to->GoToXYPosition(100, 7);
	printf("����Ʈ (�ù�)");
	print->ConvertMediumImage(MEDIUM_Y, print->GetAPTImage(), 102, 9);

	to->SetColor(95);
	to->GoToXYPosition(92, 16);
	printf("���� (�ù�)");
	to->SetColor(0);
	print->ConvertLargeImage(LARGE_Y, print->GetParkImage(), 90, 18);

	to->SetColor(47);
	to->GoToXYPosition(127, 4);
	printf("�� ���� ���� ��");

	to->SetColor(47);
	to->GoToXYPosition(120, 7);
	printf("�δ�(��) (����)");
	print->ConvertSmallImage(SMALL_Y, print->GetArmySmallImage(), 125, 9);

	to->SetColor(47);
	to->GoToXYPosition(138, 7);
	printf("�δ�(��) (����)");
	print->ConvertMediumImage(MEDIUM_Y, print->GetArmyMediumImage(), 141, 9);

	to->SetColor(47);
	to->GoToXYPosition(130, 16);
	printf("�δ�(��) (����)");
	to->SetColor(0);
	print->ConvertLargeImage(LARGE_Y, print->GetArmyLargeImage(), 130, 18);


	to->SetColor(63);
	to->GoToXYPosition(165, 4);
	printf("�� ���� ���� ��");

	to->SetColor(79);
	to->GoToXYPosition(163, 7);
	printf("����Ȱ�� ���� (����)");
	to->SetColor(15);
	to->GoToXYPosition(160, 9);
	printf("������ ����Ȱ���� �����Ͽ�");
	to->GoToXYPosition(160, 10);
	printf("������ ���� ������ ���Դϴ�.");

	to->SetColor(79);
	to->GoToXYPosition(163, 13);
	printf("����Ȱ�� ���� (����)");
	to->SetColor(15);
	to->GoToXYPosition(160, 15);
	printf("������ ����Ȱ���� �����Ͽ�");
	to->SetColor(15);
	to->GoToXYPosition(160, 16);
	printf("������ ���� ������ ���Դϴ�.");

	to->SetColor(47);
	to->GoToXYPosition(166, 19);
	printf("����Ȱ�� ����");
	to->SetColor(15);
	to->GoToXYPosition(164, 21);
	printf("����Ȱ���� �����Ͽ�");
	to->GoToXYPosition(160, 22);
	printf("������ ���� ������ ���Դϴ�.");
}

void TutorialScene::SetAnnouncePosition(std::vector<const char*> s, int color)
{
	to->PartClean(78, 32, 115, 1);
	to->SetColor(color);

	int size = strlen(s[index])/2;

	to->GoToXYPosition(TUTORIAL_ANNOUNCE_X - size, TUTORIAL_ANNOUNCE_Y);
	std::cout << s[index];

	index++;

	if (NextKey() == 1) { return; }
}
