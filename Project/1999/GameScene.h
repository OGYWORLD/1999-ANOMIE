#pragma once
#include "ConstructBuilding.h"
#include "MenuHandler.h"
#include "SetPosition.h"
#include "InfoHandler.h"


class GameScene
{
private:
	ConstructBuilding* build = new ConstructBuilding;
	MenuHandler* menu = new MenuHandler;
	SetPosition* to = new SetPosition;
	InfoHandler* info = new InfoHandler;

public:
	GameScene();
	~GameScene();

	// Total GamePlay Func
	void PlayInGame();

	// Get Name
	void PlayGetName();

	// DayUpdate
	void DateUpdate();
	void EndOfTheDay();
	
};

