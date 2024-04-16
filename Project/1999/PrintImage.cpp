#include "PrintImage.h"

PrintImage::PrintImage()
{
}

PrintImage::~PrintImage()
{
}

void PrintImage::ConvertWholeImage()
{
	for (int i = 0; i < START_IMAGE_Y; i++)
	{
		for (int j = 0; j < START_IMAGE_X; j++)
		{
			if (StartImage[i][j].first == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), StartImage[i][j].second);
				printf(" ");
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf(" ");
			}
		}
		printf("\n");
	}
}
