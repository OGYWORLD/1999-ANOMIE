/* ���� ȭ�� Ŭ����*/
#pragma once
#pragma region HeaderFiles
#include <cstring>
#include "PrintImage.h"
#include "SetPosition.h"
#include "InfoHandler.h"
#include "Music.h"
#pragma endregion

class EndingScene
{
private:
	PrintImage* print = new PrintImage;
	SetPosition* to = new SetPosition;
	Music* music = new Music;

public:
	EndingScene();
	~EndingScene();

	void CitizenEnding(InfoHandler* info); // ź�� ����
	void ArmyEnding(InfoHandler* info); // ��Ÿ ����
	void ReligionEnding(InfoHandler* info); // ���� ���� ����
	void AllDieEnding(InfoHandler* info); // ���� ����

	void PrintResult(InfoHandler* info); // ���� ��� ���
};

