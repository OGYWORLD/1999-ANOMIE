/* ����ȭ�� Ŭ���� */
#pragma once
#include "PrintImage.h"
#include "Music.h"
#include "SetPosition.h"

class SelectScene
{
private:
	PrintImage* print = new PrintImage;
	Music* music = new Music;
	SetPosition* to = new SetPosition;

public:
	SelectScene();
	~SelectScene();

	int PlaySelectScene(); // ����ȭ�� ���

	int GetPlayerInput(); // ����� �Է� �ޱ�
};

