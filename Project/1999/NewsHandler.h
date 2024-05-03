/* 뉴스가 담길 뉴스큐를 관리하는 클래스 */
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

	std::queue<std::pair <const char*, int>> NewsQ; // 뉴스가 담겨있는 뉴스큐

public:
	NewsHandler();
	~NewsHandler();

	void NewsInitializer(); // 뉴스큐 비운 후 초기 메세지 push

	void ShowNewNews(); // 새로운 뉴스 출력
	void ShowZombieNews(); // 좀비 발생 시 뉴스 출력

	void PushNewsQueue(int category); // 뉴스큐에 뉴스 push
	void MakeQueueEmpty(); // 뉴스큐 비우기

};

