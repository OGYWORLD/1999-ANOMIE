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
	std::cout << "�� 15�� ������̾��� " << info->GetPresidentName() << "�� ź�� ������ ���� ���� 9�ÿ� �����Ǿ����ϴ�.";
	Sleep(2500);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 10, ENDING_TEXT_POSITION_Y + 3);
	std::cout << "������Ǽҿ��� ������ ź�� ������ \"����� ���� �������� ���� ���� �糭 ����\"�Դϴ�.";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 13, ENDING_TEXT_POSITION_Y + 6);
	std::cout << "���ε��� ���� ��Ʈ�� �������� ���� ����� �ټ� �߻� �� �λ� �Ҿ����� �ֿ� �������� ���� �ֽ��ϴ�.";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 8, ENDING_TEXT_POSITION_Y + 9);
	std::cout << "�̷� ����, �Ǵٽ� " << info->GetCountryName() << "��(��) ������ ���·� ���ư��ϴ�.";
	Sleep(3500);


	system("cls");
	print->ConverDisapproveImage(DISAPPROVE_Y, print->GetDisapproveImage());
	to->SetColor(95);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 21, ENDING_TEXT_POSITION_Y + 7);
	std::cout << "����� ź�ٴ��߽��ϴ�!";
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
	std::cout  << info->GetYear() <<"�� " << info->GetMonth() << "�� " << info->GetDay() << "��, ������ ������ ����� 91����� ������ �Ǿ�";
	Sleep(2500);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 17, ENDING_TEXT_POSITION_Y + 3);
	std::cout << "���� ����, ��ǻ� ��Ÿ�� �����׽��ϴ�. " << info->GetPresidentName() << "������� �� ���� 10�ð� ��������� ����������";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 6, ENDING_TEXT_POSITION_Y + 6);
	std::cout << "û�ʹ뿡�� ���������� �˸����ν� ���������� �����λ������� �˷Ƚ��ϴ�.";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 5, ENDING_TEXT_POSITION_Y + 9);
	std::cout << "�̷� ����, " << info->GetCountryName() << "��(��) ������������ ��� �����Դϴ�.";
	Sleep(3500);

	system("cls");
	print->ConverDisapproveImage(DISAPPROVE_Y, print->GetCoudetatImage());
	to->SetColor(47);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 3, ENDING_TEXT_POSITION_Y + 7);
	std::cout << "����� ������ �з����� ���� ��������� �����߽��ϴ�!";
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
	std::cout << "�Ͼϸ��� ����Ǿ��� �⵶���� ��ġ������, " << info->GetYear() << "�� " << info->GetMonth() << "�� " << info->GetDay() << "��, ���úη� ��Ƿ� ���������ϴ�.";
	Sleep(2500);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 17, ENDING_TEXT_POSITION_Y + 3);
	std::cout << "��ǻ�, ������ ������ ������ ������ ���� ��ü�� ���� ���� ��� �̷������ �ִ� ���Դϴ�.";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 18, ENDING_TEXT_POSITION_Y + 6);
	std::cout << "�̹� ��κ��� ���ε��� ������ �ŷڸ� ������ �����Ǿ��� ������ ����� ������ ����ϰ� �־����ϴ�.";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 5, ENDING_TEXT_POSITION_Y + 9);
	std::cout << "�̷� ����, " << info->GetCountryName() << "�� ���� � ������ �� ���Դϴ�.";
	Sleep(3500);

	system("cls");
	print->ConverDisapproveImage(DISAPPROVE_Y, print->GetInterventionImage());
	to->SetColor(176);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 11, ENDING_TEXT_POSITION_Y + 7);
	std::cout << "���� ���̻� ������ ����� ������ �ʽ��ϴ�!";
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
	std::cout << "(" << info->GetYear() << "�� " << info->GetMonth()+1 << "�� " << info->GetDay() << "��. ������ " << info->GetCountryName() << "�� �Ҹ��� ���������� �����Ͽ����ϴ�.)";
	Sleep(2500);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 12, ENDING_TEXT_POSITION_Y + 3);
	std::cout << info->GetCountryName() << "has lot of disaster of Zombie(Rebirth Virus) and Finally All of People include President " << info->GetPresidentName() << ".";
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 14, ENDING_TEXT_POSITION_Y + 4);
	std::cout << "(" << info->GetCountryName() << "(��)�� ���� ����(���� ���̷���) ���ظ� �޾��� ������� " << info->GetPresidentName() << "(��)�� �����ؼ� ��� ������ ����߽��ϴ�.)";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 13, ENDING_TEXT_POSITION_Y + 6);
	std::cout << "United Nations peacekeeping found a survior for a month, But they couldn't find any survior in " << info->GetCountryName();
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 5, ENDING_TEXT_POSITION_Y + 7);
	std::cout << "(�������� �� �޵��� " << info->GetCountryName() << "���� �����ڸ� ã������ ��� �����ڵ� ã�� �� �������ϴ�.)";
	Sleep(3000);

	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 10, ENDING_TEXT_POSITION_Y + 9);
	std::cout << "So, UN judge " << info->GetCountryName() << "was destory by rebirth virus.";
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 2, ENDING_TEXT_POSITION_Y + 10);
	std::cout << "(����, ������ " << info->GetCountryName() << "(��)�� ���� ���̷����� ���� �ı��Ǿ��ٰ� �Ǵ��Ͽ����ϴ�.)";
	Sleep(3500);

	system("cls");
	print->ConverDisapproveImage(DISAPPROVE_Y, print->GetExtinctionImage());
	to->SetColor(79);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 23, ENDING_TEXT_POSITION_Y + 7);
	std::cout << "����� �׾����ϴ�!";
	Sleep(1000);

	PrintResult(info);

}

void EndingScene::PrintResult(InfoHandler* info)
{
	to->SetColor(14);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 18, ENDING_TEXT_POSITION_Y + 12);
	std::cout << info->GetCountryName() << "�� ����� " << info->GetPresidentName() << "  (�����ϼ�: " << info->GetCntArr()[ECOUNT::DAYCOUNT] << ")";
	Sleep(1000);

	to->SetColor(15);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 37, ENDING_TEXT_POSITION_Y + 15);
	std::cout << "�ù����κ��� ���� ������ ¡���� Ƚ��: " << info->GetCntArr()[ECOUNT::CITIZEN_M_FORCE_CNT] << "\t\t�ù����κ��� ���� ������ ¡���� Ƚ��: " << info->GetCntArr()[ECOUNT::CITIZEN_M_FORCE_CNT] << "\t\t �ù� ���� ��å�� ������ Ƚ��: " << info->GetCntArr()[ECOUNT::CITIZEN_WALFARE_CNT];
	Sleep(1000);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 29, ENDING_TEXT_POSITION_Y + 18);
	std::cout << "������ ������ ������ Ƚ��: " << info->GetCntArr()[ECOUNT::ARMY_FORCE_CNT] << "\t\t���ο��� �����İ��ٸ� ������ Ƚ��: " << info->GetCntArr()[ECOUNT::ARMY_PROPAGANDA_CNT] << "\t\t����� ������ ������ Ƚ��: " << info->GetCntArr()[ECOUNT::ARMY_WELFARE_CNT];
	Sleep(1000);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 32, ENDING_TEXT_POSITION_Y + 21);
	std::cout << "������ ����Ȱ���� ������ Ƚ��: " << info->GetCntArr()[ECOUNT::PROHIBIT_R_C_CNT] << "\t\t������ ����Ȱ���� ������ Ƚ��: " << info->GetCntArr()[ECOUNT::PROHIBIT_R_A_CNT] << "\t\t������翡 ������ Ƚ��: " << info->GetCntArr()[ECOUNT::RELIGION_WELFARE_CNT];
	Sleep(1000);
	to->GoToXYPosition(ENDING_TEXT_POSITION_X - 1, ENDING_TEXT_POSITION_Y + 24);
	std::cout << "���񿡰� ���ݴ��� �ϼ�: " << info->GetCntArr()[ECOUNT::ZOMBIE_ATTACK_CNT] << "\t\t����� ���� �ر��� �ǹ� ����: " << info->GetCntArr()[ECOUNT::ZOMBIE_DESTROY_CNT];
	to->GoToXYPosition(ENDING_TEXT_POSITION_X + 1, ENDING_TEXT_POSITION_Y + 27);
	std::cout << "�Ϻ��� ���� ��ó Ƚ��: " << info->GetCntArr()[ECOUNT::SAFE_ZOMBIE_CNT] << "\t\t������ ���� ��ó Ƚ��: " << info->GetCntArr()[ECOUNT::NONSAFE_ZOMBIE_CNT];
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
