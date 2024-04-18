#include "PreviewScene.h"

PreviewScene::PreviewScene()
{
}

PreviewScene::~PreviewScene()
{
	delete print;
}

void PreviewScene::PlayPreviewScene()
{
	print->PrintPre1Text();
	Sleep(4000);

	print->ConvertWholeImage(PRIVIEW_Y, print->GetPre1Image());
	Sleep(2000);

	print->PrintPre2Text();
	Sleep(4000);

	print->ConvertWholeImage(WHOLE_IMAGE_Y/2, print->GetPre2Image());
	Sleep(3000);

	print->PrintPre3Text();
	Sleep(4000);

	


}
