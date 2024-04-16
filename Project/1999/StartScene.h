#pragma once
#include "PrintImage.h"

class StartScene
{
private:
	PrintImage* print = new PrintImage;

public:
	StartScene();
	~StartScene();

	void PlayStartScene();
};

