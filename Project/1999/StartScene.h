/* ����ȭ�� Ŭ���� */
#pragma once
#include "PrintImage.h"
#include "SetPosition.h"
#include "Music.h"

class StartScene
{
private:
	SetPosition* to = new SetPosition;
	PrintImage* print = new PrintImage;
	Music* music = new Music;

public:
	StartScene();
	~StartScene();

	void PlayStartScene(); // ����ȭ�� ���
	void GetPlayerInput(); // ����� �Է� �ޱ�

};

