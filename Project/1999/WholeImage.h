#pragma once
#include "ConstantGroup.h"

class WholeImage
{
protected:
	int StartImage[START_LOGO_X][START_LOGO_Y];

	int IntroImage[WHOLE_IMAGE_X][WHOLE_IMAGE_Y];
	int EndingCitizenImage[WHOLE_IMAGE_X][WHOLE_IMAGE_Y];
	int EndingArmyImage[WHOLE_IMAGE_X][WHOLE_IMAGE_Y];
	int EndingReligionImage[WHOLE_IMAGE_X][WHOLE_IMAGE_Y];

public:
	WholeImage();
	~WholeImage();
};

