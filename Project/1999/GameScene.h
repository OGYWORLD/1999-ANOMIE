#pragma once
#include "SetPosition.h"
#include "ConstructBuilding.h"
#include "MenuHandler.h"
#include "InfoHandler.h"
#include "NewsHandler.h"
#include "EndingScene.h"


class GameScene
{
private:
	ConstructBuilding* build = new ConstructBuilding;
	MenuHandler* menu = new MenuHandler;
	SetPosition* to = new SetPosition;
	InfoHandler* info = new InfoHandler;
	NewsHandler* news = new NewsHandler;
	EndingScene* ending = new EndingScene;

public:
	GameScene();
	~GameScene();

	// Total GamePlay Func
	void PlayInGame();

	// Get Name
	void PlayGetName();

	// DayUpdate
	void DateUpdate();
	int EndingCheck();
	int AllDieEndingCheck();
	void EndOfTheDay();

	// Zombie Day
	void ZombieAttack();
	
};

