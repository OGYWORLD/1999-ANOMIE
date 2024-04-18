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
	print->ConvertLogoImage(START_LOGO_Y, print->GetLogoImage());
	input->GetPlayerInput();

}

