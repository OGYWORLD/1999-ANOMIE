#pragma once
#include "WholeImage.h"
#include "BuildingImage.h"
#include "SetPosition.h"

// Image
typedef int(*WholeImagePtr)[WHOLE_IMAGE_X];
typedef int(*SmallImagePtr)[SMALL_X];
typedef int(*MediumImagePtr)[MEDIUM_X];
typedef int(*LargeImagePtr)[LARGE_X];

// Specific Image
typedef int(*LogoImagePtr)[START_LOGO_X];
typedef int(*MenuImagePtr)[MENU_IMAGE_X];
typedef int(*PTAKImagePtr)[PRESS_BUTTOM_X];

class PrintImage : WholeImage, BuildingImage
{
protected:
	SetPosition* to = new SetPosition;

public:

	PrintImage();
	~PrintImage();

	// Get Image Array
	// About Scene Image
	WholeImagePtr GetPre1Image() { return Pre1Image; }
	WholeImagePtr GetPre2Image() { return Pre2Image; }

	WholeImagePtr GetSelectImage() { return SelectImage; }

	WholeImagePtr GetStartImage() { return this->StartImage; }
	MenuImagePtr GetMenuImage() { return this->MenuImage; }
	LogoImagePtr GetLogoImage() { return this->LogoImage; }
	PTAKImagePtr GetPTAKImage() { return this->PTAKImage; }

	// About Icon Image
	SmallImagePtr GetHosPitalImage() { return this->Hospital; }
	SmallImagePtr GetArmySmallImage() { return this->ArmySmall;  }
	MediumImagePtr GetAPTImage() { return this->APT; }
	MediumImagePtr GetArmyMediumImage() { return this->ArmyMedium;  }
	MediumImagePtr GetChurchImage() { return this->Church; }
	MediumImagePtr GetCathedralImage() { return this->Cathedral; }
	LargeImagePtr GetParkImage() { return this->Park; }
	LargeImagePtr GetArmyLargeImage() { return this->ArmyLarge; }


	// Convert Image
	// Unique Size Image
	void ConvertLogoImage(int y, int Image[][START_LOGO_X]);
	void ConvertMenuImage(int y, int Image[][MENU_IMAGE_X]);
	void ConvertPTAKImage(int y, int Image[][PRESS_BUTTOM_X]);


	// Common Size Image
	void ConvertWholeImage(int y, int Image[][WHOLE_IMAGE_X]);
	void ConvertSmallImage(int y, int Image[][SMALL_X], int OriginX, int OriginY);
	void ConvertMediumImage(int y, int Image[][MEDIUM_X], int OriginX, int OriginY);
	void ConvertLargeImage(int y, int Image[][LARGE_X], int OriginX, int OriginY);

	// Rolling Image
	void RollingWholeImage(int y, int Image[][WHOLE_IMAGE_X], int index, int HalfX);

	// PrintText
	// Preview Scene
	void PrintPre1Text();
	void PrintPre2Text();
	void PrintPre3Text();

	// Select Scene
	int PrintSelectText();
	
	// Game Scene
	void PrintMenuText();


};

