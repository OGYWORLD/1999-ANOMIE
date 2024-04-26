#include "NewsHandler.h"

NewsHandler::NewsHandler()
{
	srand((unsigned int)time(NULL));

	NewsQ.push(std::pair < const char*, int>("�� 15�� ����� �ӱ����.. ����..", 14));
}

NewsHandler::~NewsHandler()
{
	delete to;
}

void NewsHandler::ShowNewNews()
{
	to->PartClean(NEWS_POSITION_X+2, NEWS_POSITION_Y+4, 40, 15);
	int Size = NewsQ.size();

	int index = 0;
	while (NewsQ.size())
	{
		to->GoToXYPosition(NEWS_POSITION_X + 4, NEWS_POSITION_Y + 4 + index);
		to->SetColor(NewsQ.front().second);
		printf("%s", NewsQ.front().first);

		NewsQ.pop();

		index+=2;
	}

}

void NewsHandler::ShowZombieNews()
{
	to->PartClean(NEWS_POSITION_X + 2, NEWS_POSITION_Y + 4, 40, 15);
	to->SetColor(14);
	int Size = NewsQ.size();

	int index = 0;
	while (NewsQ.size())
	{
		to->GoToXYPosition(NEWS_POSITION_X + 4, NEWS_POSITION_Y + 4 + index);
		to->SetColor(NewsQ.front().second);
		printf("%s", NewsQ.front().first);
		Sleep(1000);

		NewsQ.pop();

		index += 2;
	}
}

void NewsHandler::PushNewsQueue(int category)
{
	int r;
	if (category == ENEWS_CATEGORY::CitizenLittleForceNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(CitizenLittleForceNews[r]);
	}
	else if (category == ENEWS_CATEGORY::CitizenManyForceNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(CitizenManyForceNews[r]);
	}
	else if (category == ENEWS_CATEGORY::CitizenWelfareNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(CitizenWelfareNews[r]);
	}
	else if (category == ENEWS_CATEGORY::ArmyForceNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(ArmyForceNews[r]);
	}
	else if (category == ENEWS_CATEGORY::ArmyPropagandaBadNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(ArmyPropagandaBadNews[r]);
	}
	else if (category == ENEWS_CATEGORY::ArmyPropagandaGoodNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(ArmyPropagandaGoodNews[r]);
	}
	else if (category == ENEWS_CATEGORY::ArmyWelfareNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(ArmyWelfareNews[r]);
	}
	else if (category == ENEWS_CATEGORY::ReligionProhibitCitizenNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(ReligionProhibitCitizenNews[r]);
	}
	else if (category == ENEWS_CATEGORY::ReligionProhibitArmyNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(ReligionProhibitArmyNews[r]);
	}
	else if (category == ENEWS_CATEGORY::ParticiateReligionNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(ParticiateReligionNews[r]);
	}
	else if (category == ENEWS_CATEGORY::CitizenEndingNews)
	{
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(std::pair < const char*, int>("[����] �츰 �̹� �����λ���", 95));
	}
	else if (category == ENEWS_CATEGORY::ArmyEndingNews)
	{
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(std::pair < const char*, int>("[����] ����, ������ �ʿ������ʴ°�", 176));
	}
	else if (category == ENEWS_CATEGORY::ReligionEndingNews)
	{
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
			NewsQ.push(std::pair < const char*, int>("[����] ���� ������ ������ �ʾ�����...", 160));
	}
	else if (category == ENEWS_CATEGORY::ZeroReligionZombieNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(ZeroReligionZombieNews[r]);
	}
	else if (category == ENEWS_CATEGORY::SmallReligionZombieNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(SmallReligionZombieNews[r]);
	}
	else if (category == ENEWS_CATEGORY::MediumReligionZombieNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(MediumReligionZombieNews[r]);
	}
	else if (category == ENEWS_CATEGORY::LargeReligionZombieNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(LargeReligionZombieNews[r]);
	}
	else if (category == ENEWS_CATEGORY::ZeroAPTZombieNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(ZeroAPTZombieNews[r]);
	}
	else if (category == ENEWS_CATEGORY::APTZombieNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(APTZombieNews[r]);
	}
	else if (category == ENEWS_CATEGORY::ParkZombieNews)
	{
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(std::pair < const char*, int>("[����] ���� �߻���, ������ ��� ����..", 12));
	}
	else if (category == ENEWS_CATEGORY::SmallArmyZombieNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(SmallArmyZombieNews[r]);
	}
	else if (category == ENEWS_CATEGORY::MediumArmyZombieNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(MediumArmyZombieNews[r]);
	}
	else if (category == ENEWS_CATEGORY::LargeArmyZombieNews)
	{
		r = rand() % 3;
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(LargeArmyZombieNews[r]);
	}
	else if (category == ENEWS_CATEGORY::ReligionPay)
	{
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(std::pair <const char*, int>("[����] �������� ����, ������ ���� ��", 3));
	}
	else if (category == ENEWS_CATEGORY::ReligionNotPay)
	{
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(std::pair <const char*, int>("[����] �ż����� ���ݿ� ���ֹ��� �ʾ�", 12));
	}
	else if (category == ENEWS_CATEGORY::AfterZombieGood)
	{
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(std::pair <const char*, int>("[����] ������ �Ǹ��� ��ó, ������ ����", 10));
	}
	else if (category == ENEWS_CATEGORY::AfterZombieBad)
	{
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(std::pair <const char*, int>("[����] �������� ū ����, ��ΰ� ����", 12));
	}
	else if (category == ENEWS_CATEGORY::PunishmentFromGod)
	{
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(std::pair <const char*, int>("[����] ������·� ���� �ǹ� �ر�...", 4));
	}
	else if (category == ENEWS_CATEGORY::ZombieAppear)
	{
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(std::pair <const char*, int>("[���] ���� �߻�, ���ǿ��", 70));
	}
	else if (category == ENEWS_CATEGORY::Maker42B)
	{
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push(std::pair <const char*, int>("[����] ���� ��ȸ, ���̺�� ������...", 12));
	}
}

void NewsHandler::MakeQueueEmpty()
{
	while (!NewsQ.empty())
	{
		NewsQ.pop();
	}
}

