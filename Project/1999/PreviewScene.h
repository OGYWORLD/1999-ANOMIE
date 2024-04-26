#pragma once
#include "PrintImage.h"
#include "Music.h"

class PreviewScene
{
private:
	PrintImage* print = new PrintImage;
	Music* music = new Music;

public:
	PreviewScene();
	~PreviewScene();

	void PlayPreviewScene();
};

