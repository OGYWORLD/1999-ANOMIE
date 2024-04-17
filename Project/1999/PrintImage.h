#pragma once
#include "WholeImage.h"
#include "BuildingImage.h"
#include "EImage.h"
#include "SetPosition.h"

class PrintImage : WholeImage, BuildingImage
{
private:

public:

	PrintImage();
	~PrintImage();

	void ConvertWholeImage(int WhichImage);
	void ConverSmallImage(int WhichImage);
	void ConverMediumImage(int WhichImage);
	void ConverLargeImage(int WhichImage);
};

