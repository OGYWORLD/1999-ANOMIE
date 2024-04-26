#pragma once
#include "PrintImage.h"
#include "SetPosition.h"
#include "InfoHandler.h"
#include "Music.h"

class EndingScene
{
private:
	PrintImage* print = new PrintImage;
	SetPosition* to = new SetPosition;
	Music* music = new Music;

public:
	EndingScene();
	~EndingScene();

	void CitizenEnding(InfoHandler* info);
	void ArmyEnding(InfoHandler* info);
	void ReligionEnding(InfoHandler* info);
	void AllDieEnding(InfoHandler* info);

	void PrintResult(InfoHandler* info);
};

