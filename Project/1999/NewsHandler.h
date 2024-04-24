#pragma once
#include <time.h>
#include <queue>
#include "News.h"
#include "SetPosition.h"


class NewsHandler : News
{
private:
	SetPosition* to = new SetPosition;

	std::queue<std::pair <const char*, int>> NewsQ;

public:
	NewsHandler();
	~NewsHandler();

	void ShowNewNews();
	void ShowZombieNews();

	void PushNewsQueue(int category);
	void MakeQueueEmpty();

};

