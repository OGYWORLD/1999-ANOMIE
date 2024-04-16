#include "StartScene.h"

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
	delete print;
}

void StartScene::PlayStartScene()
{
	print->ConvertWholeImage(EIMAGE::START_IMAGE);
	//print->ConvertCitizenEndingImage(ENDING_IMAGE_X, ENDING_IMAGE_Y);
}
