#pragma once
#include "SetPosition.h"
#include "PrintImage.h"
#include "Music.h"

class StartKeyboard
{
private:
	SetPosition* to = new SetPosition;
	PrintImage* print = new PrintImage;
	Music* music = new Music;

public:
	StartKeyboard();
	~StartKeyboard();

	void GetPlayerInput();
};

