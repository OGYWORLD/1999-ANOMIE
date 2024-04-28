#pragma once
#include <time.h>
#include <queue>
#include "News.h"
#include "Music.h"
#include "SetPosition.h"


class NewsHandler : News
{
private:
	SetPosition* to = new SetPosition;
	Music* music = new Music;

	std::queue<std::pair <const char*, int>> NewsQ;

public:
	NewsHandler();
	~NewsHandler();

	void NewsInitializer();

	void ShowNewNews();
	void ShowZombieNews();

	void PushNewsQueue(int category);
	void MakeQueueEmpty();

};

