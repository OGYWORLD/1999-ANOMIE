#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	ReturnMenu = -1;
	index = 0;

	Announce.push_back("먼저 대통령의 권한을 알려드립니다.");

	Announce.push_back("대통령은 시민, 국방, 종교에 관한 권한을 가지게 됩니다.");
	Announce.push_back("국가 재난 상황인 만큼 자원이 부족한 상태입니다.");
	Announce.push_back("따라서, 세금을 추가 징수하거나 다른 곳에서 예산을 확보할 수 있지만");
	Announce.push_back("여론이 안 좋아지면 불이익이 크니 조심하세요.");
	Announce.push_back("반면, 대상을 위한 행동을 하게되면 여론이 좋아집니다.");
	Announce.push_back("하지만 좋아지는 만큼 정부 예산을 지불해야한다는 점 주의하세요.");
	Announce.push_back("\"국방 프로파간다\"는 은밀하게 추진된 비밀 권한입니다.");
	Announce.push_back("적은 비용으로 국방의 충성심을 높일 수 있지만");
	Announce.push_back("항상 그들이 국가에 충성할 것이라고 믿지마세요.");
	Announce.push_back("마지막으로, 종교 집단은 때에 따라 국가의 동료가 되었다가 국가의 적이 되기도합니다.");
	Announce.push_back("종교 활동을 금지함으로써 국가에 대한 충성심을 높일 수 있지만");
	Announce.push_back("그만큼의 대중들 사이에서의 종교 권위는 떨어짐을 알고계세요.");
	Announce.push_back("종교 권위따위 떨어져도 된다고 생각하겠지만,");
	Announce.push_back("그들이 국가에 주는 자금은 막대합니다. 괜히 심기를 건들지 마세요.");

	Announce.push_back("두 번째로, 건물 건설에 대해 알려드립니다.");

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
	printf("국가 운영 교육을 시작합니다.");
	Sleep(3000);
}

void TutorialScene::PrintMenuTutorial()
{
	system("cls");

	print->ConvertWholeImage(WHOLE_IMAGE_HALF_Y, print->GetVideoMainImage());
	
	to->SetColor(14);
	to->GoToXYPosition(125, 37);
	printf("다음 space bar | 메뉴로 m");

	to->SetColor(31);
	to->GoToXYPosition(125, 18);
	printf("1. 대통령 권한 안내");

	SetAnnouncePosition(Announce, 10);

	PrintMenuInfo();

	for (int i = 0; i < TUTORIAL_INTRODUCE_MENU_ANNOUNCE_NUM; i++)
	{
		SetAnnouncePosition(Announce, 10);
	}

	to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);
	to->SetColor(31);
	to->GoToXYPosition(125, 18);
	printf("2. 건물 건설 안내");

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
	printf("◆ 시민 관련 ◆");

	to->SetColor(79);
	to->GoToXYPosition(85, 7);
	printf("강한 세금 징수");
	to->SetColor(207);
	to->GoToXYPosition(100, 7);
	printf("약한 세금 징수");
	to->SetColor(15);
	to->GoToXYPosition(85, 9);
	printf("국민들에게 세금을 추가 징수합니다.");

	to->SetColor(47);
	to->GoToXYPosition(90, 12);
	printf("국민 복지 정책 시행");
	to->SetColor(15);
	to->GoToXYPosition(88, 14);
	printf("좀비로부터 지친 국민에게");
	to->GoToXYPosition(88, 15);
	printf("복지 정책을 수행합니다.");

	to->SetColor(47);
	to->GoToXYPosition(130, 4);
	printf("◆ 국방 관련 ◆");

	to->SetColor(79);
	to->GoToXYPosition(130, 7);
	printf("군인 월급 삭감");
	to->SetColor(15);
	to->GoToXYPosition(127, 9);
	printf("군인의 월급을 삭감하여");
	to->GoToXYPosition(127, 10);
	printf("정부 예산으로 사용합니다.");

	to->SetColor(31);
	to->GoToXYPosition(130, 13);
	printf("국방 프로파-간다");
	to->SetColor(12);
	to->GoToXYPosition(127, 15);
	printf("※ 기밀 주의 요망 ※");
	to->SetColor(15);
	to->GoToXYPosition(127, 16);
	printf("비밀스러운 교육을 통해");
	to->GoToXYPosition(127, 17);
	printf("국가 충성심을 높입니다.");

	to->SetColor(47);
	to->GoToXYPosition(130, 20);
	printf("국방부 예산 확대");
	to->SetColor(15);
	to->GoToXYPosition(127, 22);
	printf("국방부의 에산을 확대하여");
	to->GoToXYPosition(127, 23);
	printf("강력한 국방을 만듭니다.");


	to->SetColor(63);
	to->GoToXYPosition(165, 4);
	printf("◆ 종교 관련 ◆");

	to->SetColor(79);
	to->GoToXYPosition(163, 7);
	printf("종교활동 금지 (국민)");
	to->SetColor(15);
	to->GoToXYPosition(160, 9);
	printf("국민의 종교활동을 금지하여");
	to->GoToXYPosition(160, 10);
	printf("국가에 대한 집중을 높입니다.");

	to->SetColor(79);
	to->GoToXYPosition(163, 13);
	printf("종교활동 금지 (군인)");
	to->SetColor(15);
	to->GoToXYPosition(160, 15);
	printf("국방의 종교활동을 금지하여");
	to->SetColor(15);
	to->GoToXYPosition(160, 16);
	printf("국가에 대한 집중을 높입니다.");

	to->SetColor(47);
	to->GoToXYPosition(166, 19);
	printf("종교활동 참여");
	to->SetColor(15);
	to->GoToXYPosition(164, 21);
	printf("종교활동에 참여하여");
	to->GoToXYPosition(160, 22);
	printf("종교에 대한 관심을 높입니다.");
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
	printf("◆ 시민 관련 ◆");

	to->SetColor(95);
	to->GoToXYPosition(84, 7);
	printf("병원 (시민)");
	print->ConvertSmallImage(SMALL_Y, print->GetHosPitalImage(), 86, 9);

	to->SetColor(95);
	to->GoToXYPosition(100, 7);
	printf("아파트 (시민)");
	print->ConvertMediumImage(MEDIUM_Y, print->GetAPTImage(), 102, 9);

	to->SetColor(95);
	to->GoToXYPosition(92, 16);
	printf("공원 (시민)");
	to->SetColor(0);
	print->ConvertLargeImage(LARGE_Y, print->GetParkImage(), 90, 18);

	to->SetColor(47);
	to->GoToXYPosition(127, 4);
	printf("◆ 국방 관련 ◆");

	to->SetColor(47);
	to->GoToXYPosition(120, 7);
	printf("부대(소) (국방)");
	print->ConvertSmallImage(SMALL_Y, print->GetArmySmallImage(), 125, 9);

	to->SetColor(47);
	to->GoToXYPosition(138, 7);
	printf("부대(중) (국방)");
	print->ConvertMediumImage(MEDIUM_Y, print->GetArmyMediumImage(), 141, 9);

	to->SetColor(47);
	to->GoToXYPosition(130, 16);
	printf("부대(대) (국방)");
	to->SetColor(0);
	print->ConvertLargeImage(LARGE_Y, print->GetArmyLargeImage(), 130, 18);


	to->SetColor(63);
	to->GoToXYPosition(165, 4);
	printf("◆ 종교 관련 ◆");

	to->SetColor(79);
	to->GoToXYPosition(163, 7);
	printf("종교활동 금지 (국민)");
	to->SetColor(15);
	to->GoToXYPosition(160, 9);
	printf("국민의 종교활동을 금지하여");
	to->GoToXYPosition(160, 10);
	printf("국가에 대한 집중을 높입니다.");

	to->SetColor(79);
	to->GoToXYPosition(163, 13);
	printf("종교활동 금지 (군인)");
	to->SetColor(15);
	to->GoToXYPosition(160, 15);
	printf("국방의 종교활동을 금지하여");
	to->SetColor(15);
	to->GoToXYPosition(160, 16);
	printf("국가에 대한 집중을 높입니다.");

	to->SetColor(47);
	to->GoToXYPosition(166, 19);
	printf("종교활동 참여");
	to->SetColor(15);
	to->GoToXYPosition(164, 21);
	printf("종교활동에 참여하여");
	to->GoToXYPosition(160, 22);
	printf("종교에 대한 관심을 높입니다.");
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
