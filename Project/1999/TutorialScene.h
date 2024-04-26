#pragma once
#include "PrintImage.h"
#include "SetPosition.h"
#include "Music.h"
#include "cstring"
#include <vector>
#include <queue>

class TutorialScene
{
private:
	PrintImage* print = new PrintImage;
	SetPosition* to = new SetPosition;
	Music* music = new Music;

	int ReturnMenu;
	int index;
	int Page;

	std::vector<const char*> Announce;

public:
	TutorialScene();
	~TutorialScene();

	void PlayTutorial();

	void PrintIntro();
	void PrintMenuTutorial();
	void PrintMenuInfo();
	void PrintConstructInfo();
	void PrintPowerInfo();
	void PrintCategory(int p1, int p2, int p3);

	int NextKey();
	

	int SetAnnouncePosition(std::vector<const char*> s, int color);


};

