#include "PrintImage.h"

PrintImage::PrintImage()
{
}

PrintImage::~PrintImage()
{
	delete to;
}

void PrintImage::ConvertWholeImage(int y, int Image[][WHOLE_IMAGE_X])
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < WHOLE_IMAGE_X; j++)
		{
			if (Image[i][j] != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Image[i][j]);
				printf(" ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void PrintImage::ConvertSmallImage(int y, int Image[][SMALL_X])
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < SMALL_X; j++)
		{
			if (Image[i][j] != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Image[i][j]);
				printf(" ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void PrintImage::ConvertMediumImage(int y, int Image[][MEDIUM_X])
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < MEDIUM_X; j++)
		{
			if (Image[i][j] != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Image[i][j]);
				printf(" ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void PrintImage::ConvertLargeImage(int y, int Image[][LARGE_X])
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < LARGE_X; j++)
		{
			if (Image[i][j] != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Image[i][j]);
				printf(" ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void PrintImage::ConvertMenuImage(int y, int Image[][MENU_IMAGE_X])
{

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < MENU_IMAGE_X; j++)
		{
			if (MenuImage[i][j] != 0)
			{
				to->GoToXYPosition(MENU_IMAGE_POSITION_X + j, MENU_IMAGE_POSITION_Y + i);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MenuImage[i][j]);
				printf(" ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	PrintMenuText();
}

void PrintImage::PrintMenuText()
{
	int X = 10;
	int Y = 4;

	char MenuText[4][10] =
	{
		{"시민 관련"},
		{"국방 관련"},
		{"종교 관련"},
		{"건물 건설"}
	};

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int i = 10; i < Y; i+=10)
	{
		to->GoToXYPosition(MENU_IMAGE_POSITION_X + 17, MENU_IMAGE_POSITION_Y + 10);
		printf("%s\n", MenuText[i]);
	}
}
