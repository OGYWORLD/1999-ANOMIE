#pragma once
#include "SetPosition.h"

class StartKeyboard
{
private:
	SetPosition* to = new SetPosition;

public:
	StartKeyboard();
	~StartKeyboard();

	void GetPlayerInput();
};

