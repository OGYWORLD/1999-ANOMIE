#pragma once
#include "PrintImage.h"

class SelectScene
{
private:
	PrintImage* print = new PrintImage;

public:
	SelectScene();
	~SelectScene();

	int PlaySelectScene();
};

