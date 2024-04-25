#pragma once
#include "PrintImage.h"

class PreviewScene
{
private:
	PrintImage* print = new PrintImage;

public:
	PreviewScene();
	~PreviewScene();

	void PlayPreviewScene();
};

