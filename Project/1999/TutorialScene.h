#pragma once
#include "PrintImage.h"
#include "SetPosition.h"
#include "cstring"
#include <vector>

class TutorialScene
{
private:
	PrintImage* print = new PrintImage;
	SetPosition* to = new SetPosition;

	int ReturnMenu;
	int index;

	std::vector<const char*> Announce;

public:
	TutorialScene();
	~TutorialScene();

	void PlayTutorial();

	void PrintIntro();
	void PrintMenuTutorial();
	void PrintMenuInfo();
	void PrintConstructInfo();

	int NextKey();

	void SetAnnouncePosition(std::vector<const char*> s, int color);


};

