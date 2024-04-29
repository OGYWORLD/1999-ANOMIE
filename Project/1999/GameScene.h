/* ���� ȭ�� Ŭ���� */
#pragma once
#pragma region HeaderFiles
#include "SetPosition.h"
#include "ConstructBuilding.h"
#include "MenuHandler.h"
#include "InfoHandler.h"
#include "NewsHandler.h"
#include "EndingScene.h"
#include "Music.h"
#pragma endregion


class GameScene
{
private:
	ConstructBuilding* build = new ConstructBuilding;
	MenuHandler* menu = new MenuHandler;
	SetPosition* to = new SetPosition;
	InfoHandler* info = new InfoHandler;
	NewsHandler* news = new NewsHandler;
	EndingScene* ending = new EndingScene;
	Music* music = new Music;

	int WhichMusic : 2; // ���� ����� ���� flag

public:
	GameScene();
	~GameScene();

	// Total GamePlay Func
	void PlayInGame(); // ��ü ���� ���� �Լ�

	// Get Name
	void PlayGetName(); // ����� �Է� �� ���� �̸� �ޱ�

	// DayUpdate
	void DateUpdate(); // ��¥ ������Ʈ
	int EndingCheck(); // ���� ���� üũ
	int AllDieEndingCheck(); // ���� ���� ���� üũ
	void EndOfTheDay(); // �Ϸ簡 ����Ǿ��� ��, �α��� �� ���� ������Ʈ

	// Zombie Day
	void ZombieAttack(); // ���� �߻� ��, ����� ���

	// Music Check();
	void MusicCheck(int zombie); // �Ŀ��� �ϳ��� 50�̸��� ��, ������� ���� �Լ�
	
};

