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

	Announce.push_back("�ǹ��� �ù�, ����, ������ ���� ���������ֽ��ϴ�.");
	Announce.push_back("�ǹ��� �Ǽ��� ������, �ǹ��� ������ ���� �������� ������ �߻��մϴ�.");
	Announce.push_back("�����ϼ���, �ı��� ���� �ǹ��� ���� ������ ������� �Ǽ��� ���� �ۿ� �������� ���մϴ�.");
	Announce.push_back("Ư��, ���� �糭 �� �߻��Ǵ� �ǹ� �ı��� �ʱ� �Ǽ����� 1/4�� �������� ���մϴ�.");
	Announce.push_back("�ǹ��� ���� ���� ������ ���� ������ �ʽ��ϴ�.");
	Announce.push_back("���� �糭�� �߻������� ������ �������� �ε����ִ� ������ �մϴ�.");
	Announce.push_back("�� ��� �ǹ��� �׷� �� �ƴ϶�� �� ����ϼ���.");
	Announce.push_back("��������� �����غ��� ��, ���� �ü��� �����濡 �ִ� �� ���� �ʰ���?");
	Announce.push_back("����ɴԲ��� �������� ������ �����ϽŴٸ� �׷� ������ ������ �����ñ� �ٶ��ϴ�.");
	Announce.push_back("����, ... �� ���� �ǹ� ������ ����ɴ��� �濡 ���� �Ǽ��ǰ���.");
	Announce.push_back("�� �κп� ���ؼ��� ���� �����帮�� �ʰڽ��ϴ�.");

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
	
	to->CleanInputBuffer();
	to->SetColor(11);
	to->GoToXYPosition(88, 45);
	printf("���� space bar | �޴��� m");

	to->SetColor(31);
	to->GoToXYPosition(90, 25);
	printf("1. ����� ���� �ȳ�");

	SetAnnouncePosition(Announce, 10);

	PrintMenuInfo();

	for (int i = 0; i < TUTORIAL_INTRODUCE_MENU_ANNOUNCE_NUM; i++)
	{
		SetAnnouncePosition(Announce, 10);
	}

	to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);
	to->SetColor(31);
	to->GoToXYPosition(90, 25);
	printf("2. �ǹ� �Ǽ� �ȳ�");

	SetAnnouncePosition(Announce, 10);

	PrintConstructInfo();

	for (int i = 0; i < TUTORIAL_INTRODUCE_CONSTRUCT_ANNOUNCE_NUM; i++)
	{
		SetAnnouncePosition(Announce, 10);
	}

	to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);
	to->SetColor(31);
	to->GoToXYPosition(83, 25);
	printf("3. �ν�, �����, ���� ���� �ȳ�");
	
	SetAnnouncePosition(Announce, 10);

	PrintPowerInfo();

	for (int i = 0; i < TUTORIAL_INTRODUCE_POWER_ANNOUNCE_NUM; i++)
	{
		SetAnnouncePosition(Announce, 10);
	}

	to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);
	to->SetColor(47);
	to->GoToXYPosition(92, 25);
	printf("�����ϼ̽��ϴ�");

	SetAnnouncePosition(Announce, 10);
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

	to->SetColor(31);
	to->GoToXYPosition(75, 22);
	printf("����Ÿ �������� ���� �ڷᰡ �������� �ʽ��ϴ�.");

}

void TutorialScene::SetAnnouncePosition(std::vector<const char*> s, int color)
{
	to->PartClean(42, 39, 115, 1);
	to->SetColor(color);

	int size = strlen(s[index])/2;

	to->GoToXYPosition(TUTORIAL_ANNOUNCE_X - size, TUTORIAL_ANNOUNCE_Y);
	std::cout << s[index];

	//backlog
	if (index > 1)
	{
		to->PartClean(42, 49, 115, 1);
		int BackSize = strlen(s[index - 1])/2;
		to->GoToXYPosition(TUTORIAL_ANNOUNCE_X - BackSize, TUTORIAL_ANNOUNCE_Y + 10);
		to->SetColor(8);
		std::cout << s[index - 1];
	}

	index++;

	if (NextKey() == 1) { return; }
}
