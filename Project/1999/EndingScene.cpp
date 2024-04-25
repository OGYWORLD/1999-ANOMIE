#include "EndingScene.h"

EndingScene::EndingScene()
{
}

EndingScene::~EndingScene()
{
	delete print;
	delete to;
}

void EndingScene::CitizenEnding(InfoHandler* info)
{
	system("cls");
	print->ConvertWholeImage(WHOLE_IMAGE_HALF_Y, print->GetCitizenEndingImage());
	Sleep(2000);

	system("cls");
	to->SetColor(14);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X, ENDING_TEXT_POSITION_Y);
	std::cout << "제 15대 대통령이었던 " << info->GetPresidentName() << "의 탄핵 결정이 오늘 오전 9시에 결정되었습니다.";
	Sleep(2500);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 10, ENDING_TEXT_POSITION_Y + 3);
	std::cout << "헌법재판소에서 인정한 탄핵 사유는 \"대통령 권한 남용으로 인한 국가 재난 피해\"입니다.";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 13, ENDING_TEXT_POSITION_Y + 6);
	std::cout << "국민들은 국가 컨트롤 미흡으로 인한 사상자 다수 발생 및 민생 불안정을 주요 원인으로 보고 있습니다.";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 8, ENDING_TEXT_POSITION_Y + 9);
	std::cout << "이로 인해, 또다시 " << info->GetCountryName() << "는(은) 무정부 상태로 돌아갑니다.";
	Sleep(3500);


	system("cls");
	print->ConverDisapproveImage(DISAPPROVE_Y, print->GetDisapproveImage());
	to->SetColor(95);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 21, ENDING_TEXT_POSITION_Y + 7);
	std::cout << "당신은 탄핵당했습니다!";
	Sleep(1000);

	PrintResult(info);

}

void EndingScene::ArmyEnding(InfoHandler* info)
{
	system("cls");
	print->ConvertWholeImage(WHOLE_IMAGE_HALF_Y, print->GetArmyEndingImage());
	Sleep(2000);

	system("cls");
	to->SetColor(14);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X, ENDING_TEXT_POSITION_Y);
	std::cout  << info->GetYear() <<"년 " << info->GetMonth() << "월 " << info->GetDay() << "일, 김찬령 준장을 비롯한 91사단이 주축이 되어";
	Sleep(2500);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 17, ENDING_TEXT_POSITION_Y + 3);
	std::cout << "정권 점령, 사실상 쿠데타를 일으켰습니다. " << info->GetPresidentName() << "대통령은 약 오전 10시경 대통령직을 사퇴했음을";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 6, ENDING_TEXT_POSITION_Y + 6);
	std::cout << "청와대에서 공식적으로 알림으로써 실질적으로 무정부상태임을 알렸습니다.";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 5, ENDING_TEXT_POSITION_Y + 9);
	std::cout << "이로 인해, " << info->GetCountryName() << "는(은) 군사정권으로 운영될 예정입니다.";
	Sleep(3500);

	system("cls");
	print->ConverDisapproveImage(DISAPPROVE_Y, print->GetCoudetatImage());
	to->SetColor(47);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 3, ENDING_TEXT_POSITION_Y + 7);
	std::cout << "당신은 무언가의 압력으로 인해 대통령직을 사퇴했습니다!";
	Sleep(1000);

	PrintResult(info);

}

void EndingScene::ReligionEnding(InfoHandler* info)
{
	system("cls");
	print->ConvertWholeImage(WHOLE_IMAGE_HALF_Y, print->GetReligionEndingImage());
	Sleep(2000);

	system("cls");
	to->SetColor(14);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 10, ENDING_TEXT_POSITION_Y);
	std::cout << "암암리에 진행되었던 기독교의 정치개입이, " << info->GetYear() << "년 " << info->GetMonth() << "월 " << info->GetDay() << "일, 오늘부로 사실로 밝혀졌습니다.";
	Sleep(2500);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 17, ENDING_TEXT_POSITION_Y + 3);
	std::cout << "사실상, 정부의 권위는 잃은지 오래고 종교 단체에 의한 국가 운영이 이루어지고 있던 셈입니다.";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 18, ENDING_TEXT_POSITION_Y + 6);
	std::cout << "이미 대부분의 국민들은 국가의 신뢰를 잃은지 오래되었고 정부의 기능은 종교가 담당하고 있었습니다.";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 5, ENDING_TEXT_POSITION_Y + 9);
	std::cout << "이로 인해, " << info->GetCountryName() << "는 종교 운영 국가가 된 셈입니다.";
	Sleep(3500);

	system("cls");
	print->ConverDisapproveImage(DISAPPROVE_Y, print->GetInterventionImage());
	to->SetColor(176);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 11, ENDING_TEXT_POSITION_Y + 7);
	std::cout << "이제 더이상 국민은 당신을 따르지 않습니다!";
	Sleep(1000);

	PrintResult(info);

}

void EndingScene::AllDieEnding(InfoHandler* info)
{
	system("cls");
	print->ConvertWholeImage(WHOLE_IMAGE_HALF_Y, print->GetAllDieEndingImage());
	Sleep(2000);

	system("cls");
	to->SetColor(14);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X, ENDING_TEXT_POSITION_Y);
	std::cout << info->GetMonth() + 1 << "M " << info->GetDay() << "D, " << info->GetYear() << ". The UN make a formal declaration about " << info->GetCountryName() << "'s collapse.";
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 2, ENDING_TEXT_POSITION_Y+1);
	std::cout << "(" << info->GetYear() << "년 " << info->GetMonth()+1 << "월 " << info->GetDay() << "일. 유엔은 " << info->GetCountryName() << "의 소멸을 공식적으로 선언하였습니다.)";
	Sleep(2500);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 12, ENDING_TEXT_POSITION_Y + 3);
	std::cout << info->GetCountryName() << "has lot of disaster of Zombie(Rebirth Virus) and Finally All of People include President " << info->GetPresidentName() << ".";
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 14, ENDING_TEXT_POSITION_Y + 4);
	std::cout << "(" << info->GetCountryName() << "(은)는 많은 좀비(리벌 바이러스) 재해를 겪었고 대통령인 " << info->GetPresidentName() << "(을)를 포함해서 모든 국민이 사망했습니다.)";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 13, ENDING_TEXT_POSITION_Y + 6);
	std::cout << "United Nations peacekeeping found a survior for a month, But they couldn't find any survior in " << info->GetCountryName();
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 5, ENDING_TEXT_POSITION_Y + 7);
	std::cout << "(유엔군은 한 달동안 " << info->GetCountryName() << "에서 생존자를 찾았지만 어떠한 생존자도 찾을 수 없었습니다.)";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 10, ENDING_TEXT_POSITION_Y + 9);
	std::cout << "So, UN judge " << info->GetCountryName() << "was destory by rebirth virus.";
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 2, ENDING_TEXT_POSITION_Y + 10);
	std::cout << "(따라서, 유엔은 " << info->GetCountryName() << "(이)가 리벌 바이러스에 의해 파괴되었다고 판단하였습니다.)";
	Sleep(3500);

	system("cls");
	print->ConverDisapproveImage(DISAPPROVE_Y, print->GetExtinctionImage());
	to->SetColor(79);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 23, ENDING_TEXT_POSITION_Y + 7);
	std::cout << "당신은 죽었습니다!";
	Sleep(1000);

	PrintResult(info);

}

void EndingScene::PrintResult(InfoHandler* info)
{
	to->SetColor(14);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 18, ENDING_TEXT_POSITION_Y + 12);
	std::cout << info->GetCountryName() << "의 대통령 " << info->GetPresidentName() << "  (재임일수: " << info->GetCntArr()[ECOUNT::DAYCOUNT] << ")";
	Sleep(1000);

	to->SetColor(15);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 37, ENDING_TEXT_POSITION_Y + 15);
	std::cout << "시민으로부터 강한 세금을 징수한 횟수: " << info->GetCntArr()[ECOUNT::CITIZEN_M_FORCE_CNT] << "\t\t시민으로부터 약한 세금을 징수한 횟수: " << info->GetCntArr()[ECOUNT::CITIZEN_M_FORCE_CNT] << "\t\t 시민 복지 정책을 시행한 횟수: " << info->GetCntArr()[ECOUNT::CITIZEN_WALFARE_CNT];
	Sleep(1000);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 29, ENDING_TEXT_POSITION_Y + 18);
	std::cout << "군인의 월급을 감소한 횟수: " << info->GetCntArr()[ECOUNT::ARMY_FORCE_CNT] << "\t\t군인에게 프로파간다를 시행한 횟수: " << info->GetCntArr()[ECOUNT::ARMY_PROPAGANDA_CNT] << "\t\t군방부 예산을 수행한 횟수: " << info->GetCntArr()[ECOUNT::ARMY_WELFARE_CNT];
	Sleep(1000);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 32, ENDING_TEXT_POSITION_Y + 21);
	std::cout << "국민의 종교활동을 금지한 횟수: " << info->GetCntArr()[ECOUNT::PROHIBIT_R_C_CNT] << "\t\t군인의 종교활동을 금지한 횟수: " << info->GetCntArr()[ECOUNT::PROHIBIT_R_A_CNT] << "\t\t종교행사에 참여한 횟수: " << info->GetCntArr()[ECOUNT::RELIGION_WELFARE_CNT];
	Sleep(1000);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 1, ENDING_TEXT_POSITION_Y + 24);
	std::cout << "좀비에게 습격당한 일수: " << info->GetCntArr()[ECOUNT::ZOMBIE_ATTACK_CNT] << "\t\t좀비로 인해 붕괴된 건물 개수: " << info->GetCntArr()[ECOUNT::ZOMBIE_DESTROY_CNT];
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 1, ENDING_TEXT_POSITION_Y + 27);
	std::cout << "완벽한 좀비 대처 횟수: " << info->GetCntArr()[ECOUNT::SAFE_ZOMBIE_CNT] << "\t\t미흡한 좀비 대처 횟수: " << info->GetCntArr()[ECOUNT::NONSAFE_ZOMBIE_CNT];
	Sleep(1000);

	to->SetColor(15);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 85, ENDING_TEXT_POSITION_Y + 38);
	std::cout << "press any key...";
	while (1)
	{
		if (_kbhit())
		{
			to->CleanInputBuffer();
			break;
		}
	}
}
