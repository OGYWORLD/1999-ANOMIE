#include "SelectScene.h"

SelectScene::SelectScene()
{
}

SelectScene::~SelectScene()
{
	delete print;
	delete music;
}

int SelectScene::PlaySelectScene()
{
	music->PlayMusicIzanami();
	print->ConvertWholeImage(WHOLE_IMAGE_Y / 2, print->GetSelectImage());
	return print->PrintSelectText();
}
