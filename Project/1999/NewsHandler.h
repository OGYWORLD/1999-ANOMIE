/* ������ ��� ����ť�� �����ϴ� Ŭ���� */
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

	std::queue<std::pair <const char*, int>> NewsQ; // ������ ����ִ� ����ť

public:
	NewsHandler();
	~NewsHandler();

	void NewsInitializer(); // ����ť ��� �� �ʱ� �޼��� push

	void ShowNewNews(); // ���ο� ���� ���
	void ShowZombieNews(); // ���� �߻� �� ���� ���

	void PushNewsQueue(int category); // ����ť�� ���� push
	void MakeQueueEmpty(); // ����ť ����

};

