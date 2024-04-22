#include "NewsHandler.h"

NewsHandler::NewsHandler()
{
	srand((unsigned int)time(NULL));

	NewsQ.push("�� 15�� ����� �ӱ����.. ����..");
}

NewsHandler::~NewsHandler()
{
	delete to;
}

void NewsHandler::ShowNewNews()
{
	to->PartClean(NEWS_POSITION_X+2, NEWS_POSITION_Y+4, 39, 15);
	to->SetColor(14);
	int Size = NewsQ.size();

	int index = 0;
	while (NewsQ.size())
	{
		to->GoToXYPosition(NEWS_POSITION_X + 4, NEWS_POSITION_Y + 4 + index);
		printf("%s", NewsQ.front());

		NewsQ.pop();

		index+=2;
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
		NewsQ.push("[����] �츰 �̹� �����λ���");
	}
	else if (category == ENEWS_CATEGORY::ArmyEndingNews)
	{
		if (NewsQ.size() == MAX_NEWS)
		{
			NewsQ.pop();
		}
		NewsQ.push("[����] ����, ������ �ʿ������ʴ°�");
	}
	else if (category == ENEWS_CATEGORY::ReligionEndingNews)
	{
	if (NewsQ.size() == MAX_NEWS)
	{
		NewsQ.pop();
	}
		NewsQ.push("[����] ���� ������ ������ �ʾ�����...");
	}
}

