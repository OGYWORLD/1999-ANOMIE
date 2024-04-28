#pragma once
#include "PrintImage.h"
#include "Music.h"

class SelectScene
{
private:
	PrintImage* print = new PrintImage;
	Music* music = new Music;

public:
	SelectScene();
	~SelectScene();

	int PlaySelectScene();
};

