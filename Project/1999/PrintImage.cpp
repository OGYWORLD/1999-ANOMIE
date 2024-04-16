#include "PrintImage.h"

PrintImage::PrintImage()
{
}

PrintImage::~PrintImage()
{
}

void PrintImage::ConvertWholeImage(int WhichImage)
{
	for (int i = 0; i < START_IMAGE_Y; i++)
	{
		for (int j = 0; j < START_IMAGE_X; j++)
		{
			if (WhichImage == EIMAGE::START_IMAGE)
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
		}
		printf("\n");
	}
}

void PrintImage::ConverSmallImage(int WhichImage)
{
	for (int i = 0; i < SMALL_Y; i++)
	{
		for (int j = 0; j < SMALL_X; j++)
		{
			if (WhichImage == EIMAGE::HOSPITAM_IMAGE)
			{
				if (Hospital[i][j].first == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Hospital[i][j].second);
					printf(" ");
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					printf(" ");
				}
			}
			else if (WhichImage == EIMAGE::ARMY_SAMLL_IMAGE)
			{
				if (ArmySmall[i][j].first == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ArmySmall[i][j].second);
					printf(" ");
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}

void PrintImage::ConverMediumImage(int WhichImage)
{
	for (int i = 0; i < MEDIUM_Y; i++)
	{
		for (int j = 0; j < MEDIUM_X; j++)
		{
			if (WhichImage == EIMAGE::APT_IMAGE)
			{
				if (APT[i][j].first == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), APT[i][j].second);
					printf(" ");
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					printf(" ");
				}
			}
			else if (WhichImage == EIMAGE::ARMY_MEDIUM_IMAGE)
			{
				if (ArmyMedium[i][j].first == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ArmyMedium[i][j].second);
					printf(" ");
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					printf(" ");
				}
			}
			else if (WhichImage == EIMAGE::CHURCH_IMAGE)
			{
				if (Church[i][j].first == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Church[i][j].second);
					printf(" ");
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					printf(" ");
				}
			}
			else if (WhichImage == EIMAGE::CATHEDRAL)
			{
				if (Cathedral[i][j].first == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cathedral[i][j].second);
					printf(" ");
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}

void PrintImage::ConverLargeImage(int WhichImage)
{
	for (int i = 0; i < LARGE_Y; i++)
	{
		for (int j = 0; j < LARGE_X; j++)
		{
			if (WhichImage == EIMAGE::PARK_IMAGE)
			{
				if (Park[i][j].first == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Park[i][j].second);
					printf(" ");
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					printf(" ");
				}
			}
			else if (WhichImage == EIMAGE::ARMY_LARGE_IMAGE)
			{
				if (ArmyLarge[i][j].first == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ArmyLarge[i][j].second);
					printf(" ");
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}