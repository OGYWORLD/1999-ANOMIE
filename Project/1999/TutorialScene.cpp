#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	ReturnMenu = -1;
	index = 1;
	Page = 1;

	Announce.push_back("이곳에는 이전 다이어로그가 표시됩니다.");

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

	Announce.push_back("건물은 시민, 국방, 종교에 따라 나누어져있습니다.");
	Announce.push_back("건물을 건설할 때마다, 건물의 종류에 따라 긍정적인 여론이 발생합니다.");
	Announce.push_back("조심하세요, 파괴할 때는 건물로 인한 여론이 사라지고 건설비도 절반 밖에 돌려받지 못합니다.");
	Announce.push_back("특히, 좀비 재난 시 발생되는 건물 파괴는 어떠한 건설비도 돌려받지 못합니다.");
	Announce.push_back("건물은 단지 여론 조성을 위해 사용되지 않습니다.");
	Announce.push_back("좀비 재난이 발생했을때 국민을 안전으로 인도해주는 역할을 합니다.");
	Announce.push_back("꼭 모든 건물이 그런 건 아니라는 걸 명심하세요.");
	Announce.push_back("상식적으로 생각해봤을 때, 거주 시설이 최전방에 있는 건 좋지 않겠죠?");
	Announce.push_back("대통령님께서 진심으로 국민을 생각하신다면 그런 센스는 가지고 있으시길 바랍니다.");
	Announce.push_back("또한, ... 뭐 종교 건물 정도야 대통령님의 뜻에 따라 건설되겠죠.");
	Announce.push_back("이 부분에 대해서는 따로 말씀드리지 않겠습니다.");
	Announce.push_back("아, 지금까지의 역사에 기반하면 종교가 기승이면 이단이 항상 생기더군요.");
	Announce.push_back("뭐.. 어디까지나 역사에 기반이지만요.");

	Announce.push_back("마지막으로, 민심, 군사력, 종교 권위에 대해 알려드립니다.");

	Announce.push_back("이에 대해서는 충분한 데이타가 아직 없습니다.");
	Announce.push_back("다만 확실한 것은 민심이 줄어들수록 세금을 제대로 지불하는 국민의 수가 줄어든다는 것,");
	Announce.push_back("민심이 낮을 수록 (삐-)의 이유로 인구수가 줄어드는 것 입니다.");
	Announce.push_back("그리고 좀비들에게 지능이 생긴 건 아니겠지만 이상하게도 국방이 쇠약해졌을때");
	Announce.push_back("좀비 재난의 횟수가 증가하는 것 같습니다. 이 부분은 정확하지 않지만요.");
	Announce.push_back("아무쪼록 대통령님께서 진심으로 국민을 생각하신다면 모두의 행복을 표방하시겠죠?");

	Announce.push_back("그럼 국가 운영 교육을 마치겠습니다.");


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
	printf("국가 운영 교육을 시작합니다.");
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
	printf("다음 space bar | 메뉴로 m");

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
			printf("1. 대통령 권한 안내");


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
			printf("2. 건물 건설 안내");

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
			printf("3. 민심, 군사력, 종교 권위 안내");

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
			printf("수고하셨습니다");

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
	printf("◆ 시민 관련 ◆");

	to->SetColor(79);
	to->GoToXYPosition(48, 14);
	printf("강한 세금 징수");
	to->SetColor(207);
	to->GoToXYPosition(63, 14);
	printf("약한 세금 징수");
	to->SetColor(15);
	to->GoToXYPosition(48, 16);
	printf("국민들에게 세금을 추가 징수합니다.");

	to->SetColor(47);
	to->GoToXYPosition(53, 19);
	printf("국민 복지 정책 시행");
	to->SetColor(15);
	to->GoToXYPosition(51, 21);
	printf("좀비로부터 지친 국민에게");
	to->GoToXYPosition(51, 22);
	printf("복지 정책을 수행합니다.");

	to->SetColor(47);
	to->GoToXYPosition(93, 11);
	printf("◆ 국방 관련 ◆");

	to->SetColor(79);
	to->GoToXYPosition(93, 14);
	printf("군인 월급 삭감");
	to->SetColor(15);
	to->GoToXYPosition(90, 16);
	printf("군인의 월급을 삭감하여");
	to->GoToXYPosition(90, 17);
	printf("정부 예산으로 사용합니다.");

	to->SetColor(31);
	to->GoToXYPosition(93, 20);
	printf("국방 프로파-간다");
	to->SetColor(12);
	to->GoToXYPosition(92, 22);
	printf("※ 기밀 주의 요망 ※");
	to->SetColor(15);
	to->GoToXYPosition(90, 23);
	printf("비밀스러운 교육을 통해");
	to->GoToXYPosition(90, 24);
	printf("국가 충성심을 높입니다.");

	to->SetColor(47);
	to->GoToXYPosition(93, 27);
	printf("국방부 예산 확대");
	to->SetColor(15);
	to->GoToXYPosition(90, 29);
	printf("국방부의 에산을 확대하여");
	to->GoToXYPosition(90, 30);
	printf("강력한 국방을 만듭니다.");


	to->SetColor(63);
	to->GoToXYPosition(128, 11);
	printf("◆ 종교 관련 ◆");

	to->SetColor(79);
	to->GoToXYPosition(126, 14);
	printf("종교활동 금지 (국민)");
	to->SetColor(15);
	to->GoToXYPosition(123, 16);
	printf("국민의 종교활동을 금지하여");
	to->GoToXYPosition(123, 17);
	printf("국가에 대한 집중을 높입니다.");

	to->SetColor(79);
	to->GoToXYPosition(126, 20);
	printf("종교활동 금지 (군인)");
	to->SetColor(15);
	to->GoToXYPosition(123, 22);
	printf("국방의 종교활동을 금지하여");
	to->SetColor(15);
	to->GoToXYPosition(123, 23);
	printf("국가에 대한 집중을 높입니다.");

	to->SetColor(47);
	to->GoToXYPosition(129, 26);
	printf("종교활동 참여");
	to->SetColor(15);
	to->GoToXYPosition(127, 28);
	printf("종교활동에 참여하여");
	to->GoToXYPosition(123, 29);
	printf("종교에 대한 관심을 높입니다.");
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
	printf("◆ 시민 관련 ◆");

	to->SetColor(95);
	to->GoToXYPosition(47, 14);
	printf("병원 (시민)");
	print->ConvertSmallImage(SMALL_Y, print->GetHosPitalImage(), 49, 16);

	to->SetColor(95);
	to->GoToXYPosition(61, 14);
	printf("아파트 (시민)");
	print->ConvertMediumImage(MEDIUM_Y, print->GetAPTImage(), 63, 16);

	to->SetColor(95);
	to->GoToXYPosition(55, 23);
	printf("공원 (시민)");
	to->SetColor(0);
	print->ConvertLargeImage(LARGE_Y, print->GetParkImage(), 53, 25);

	to->SetColor(47);
	to->GoToXYPosition(92, 11);
	printf("◆ 국방 관련 ◆");

	to->SetColor(47);
	to->GoToXYPosition(83, 14);
	printf("부대(소) (국방)");
	print->ConvertSmallImage(SMALL_Y, print->GetArmySmallImage(), 88, 16);

	to->SetColor(47);
	to->GoToXYPosition(101, 14);
	printf("부대(중) (국방)");
	print->ConvertMediumImage(MEDIUM_Y, print->GetArmyMediumImage(), 104, 16);

	to->SetColor(47);
	to->GoToXYPosition(93, 23);
	printf("부대(대) (국방)");
	to->SetColor(0);
	print->ConvertLargeImage(LARGE_Y, print->GetArmyLargeImage(), 92, 25);


	to->SetColor(63);
	to->GoToXYPosition(132, 11);
	printf("◆ 종교 관련 ◆");

	to->SetColor(63);
	to->GoToXYPosition(123, 14);
	printf("교회 (종교)");
	to->SetColor(0);
	print->ConvertMediumImage(MEDIUM_Y, print->GetChurchImage(), 124, 16);

	to->SetColor(63);
	to->GoToXYPosition(142, 14);
	printf("성당 (종교)");
	to->SetColor(0);
	print->ConvertMediumImage(MEDIUM_Y, print->GetCathedralImage(), 144, 16);
}

void TutorialScene::PrintPowerInfo()
{
	to->PartClean(TUTORIAL_BOX_POSITION_X, TUTORIAL_BOX_POSITION_Y, TUTORIAL_BOX_BX, TUTORIAL_BOX_BY);

	to->SetColor(78);
	to->GoToXYPosition(75, 22);
	printf("데이타 부족으로 인해 자료가 존재하지 않습니다.");

}

void TutorialScene::PrintCategory(int p1, int p2, int p3)
{
	to->SetColor(p1);
	to->GoToXYPosition(28, 55);
	printf("1. 대통령 권한 안내 (key 1)");

	to->SetColor(p2);
	to->GoToXYPosition(88, 55);
	printf("2. 건물 건설 안내 (key 2)");

	to->SetColor(p3);
	to->GoToXYPosition(148, 55);
	printf("3. 민심, 군사력, 종교 권위 안내 (key 3)");
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
