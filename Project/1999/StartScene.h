#pragma once
#include "PrintImage.h"
#include "StartKeyboard.h"

class StartScene
{
private:
	PrintImage* print = new PrintImage;
	StartKeyboard* input = new StartKeyboard;

public:
	StartScene();
	~StartScene();

	void PlayStartScene();

};

