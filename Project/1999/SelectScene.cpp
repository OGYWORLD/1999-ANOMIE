#include "SelectScene.h"

SelectScene::SelectScene()
{
}

SelectScene::~SelectScene()
{
	delete print;
}

int SelectScene::PlaySelectScene()
{
	print->ConvertWholeImage(WHOLE_IMAGE_Y / 2, print->GetSelectImage());
	return print->PrintSelectText();
}
