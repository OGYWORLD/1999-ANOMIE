#pragma once
#include <time.h>
#include <queue>
#include "News.h"
#include "SetPosition.h"


class NewsHandler : News
{
private:
	SetPosition* to = new SetPosition;

	std::queue<const char*> NewsQ;

public:
	NewsHandler();
	~NewsHandler();

	void ShowNewNews();

	void PushNewsQueue(int category);

};

