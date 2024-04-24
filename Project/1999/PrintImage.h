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
typedef int(*DisapproveImagePtr)[DISAPPROVE_X];

class PrintImage : WholeImage, BuildingImage
{
protected:
	SetPosition* to = new SetPosition;

public:

	PrintImage();
	~PrintImage();

	// Get Image Array
	// About Scene Image
	WholeImagePtr GetPre1Image() { return WholeImage::Pre1Image; }
	WholeImagePtr GetPre2Image() { return WholeImage::Pre2Image; }

	WholeImagePtr GetSelectImage() { return WholeImage::SelectImage; }

	WholeImagePtr GetStartImage() { return WholeImage::StartImage; }
	MenuImagePtr GetMenuImage() { return WholeImage::MenuImage; }
	LogoImagePtr GetLogoImage() { return WholeImage::LogoImage; }
	PTAKImagePtr GetPTAKImage() { return WholeImage::PTAKImage; }

	DisapproveImagePtr GetDisapproveImage() { return WholeImage::DisapproveImage; }
	DisapproveImagePtr GetCoudetatImage() { return WholeImage::CoupdetatImage; }
	DisapproveImagePtr GetInterventionImage() { return WholeImage::InterventionImage; }
	DisapproveImagePtr GetExtinctionImage() { return WholeImage::ExtinctionImage; }

	WholeImagePtr GetCitizenEndingImage() { return WholeImage::CitizenEndingImage; }
	WholeImagePtr GetArmyEndingImage() { return WholeImage::ArmyEndingImage; }
	WholeImagePtr GetReligionEndingImage() { return WholeImage::ReligionEndingImage; }
	WholeImagePtr GetAllDieEndingImage() { return WholeImage::AllDieEndingImage; }

	// About Icon Image
	SmallImagePtr GetHosPitalImage() { return BuildingImage::Hospital; }
	SmallImagePtr GetArmySmallImage() { return BuildingImage::ArmySmall;  }
	MediumImagePtr GetAPTImage() { return BuildingImage::APT; }
	MediumImagePtr GetArmyMediumImage() { return BuildingImage::ArmyMedium;  }
	MediumImagePtr GetChurchImage() { return BuildingImage::Church; }
	MediumImagePtr GetCathedralImage() { return BuildingImage::Cathedral; }
	MediumImagePtr GetFireImage() { return BuildingImage::Fire; }
	LargeImagePtr GetParkImage() { return BuildingImage::Park; }
	LargeImagePtr GetArmyLargeImage() { return BuildingImage::ArmyLarge; }


	// Convert Image
	// Unique Size Image
	void ConvertLogoImage(int y, int Image[][START_LOGO_X]);
	void ConvertMenuImage(int y, int Image[][MENU_IMAGE_X]);
	void ConvertPTAKImage(int y, int Image[][PRESS_BUTTOM_X]);
	void ConverDisapproveImage(int y, int Image[][DISAPPROVE_X]);


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

	// News
	void PrintNewsImage();

	// Zombie Day
	void PrintZombieMenu();

};

