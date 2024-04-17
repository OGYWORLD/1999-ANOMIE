#include "StartScene.h"

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
	delete print;
	delete input;
}

void StartScene::PlayStartScene()
{

	print->ConvertWholeImage(WHOLE_IMAGE_Y, print->GetStartImage());
	input->GetPlayerInput();

}

