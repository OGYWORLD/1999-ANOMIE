#pragma once
#include "SetPosition.h"
#include "PrintImage.h"

class StartKeyboard
{
private:
	SetPosition* to = new SetPosition;
	PrintImage* print = new PrintImage;

public:
	StartKeyboard();
	~StartKeyboard();

	void GetPlayerInput();
};

