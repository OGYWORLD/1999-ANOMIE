#include "PrintImage.h"

PrintImage::PrintImage()
{
}

PrintImage::~PrintImage()
{
	delete to;
}

void PrintImage::ConvertLogoImage(int y, int Image[][START_LOGO_X])
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < START_LOGO_X; j++)
		{
			to->GoToXYPosition(START_LOGO_POSITION_X + j, i);
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

void PrintImage::RollingWholeImage(int y, int Image[][WHOLE_IMAGE_X], int index, int HalfX)
{
	for (int i = 0 + index; i < y + index; i++)
	{
		for (int j = 0; j < WHOLE_IMAGE_X - HalfX; j++)
		{
			if (Image[i % WHOLE_IMAGE_Y][j] != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Image[i % WHOLE_IMAGE_Y][j]);
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
	char MenuText[4][10] =
	{
		{"시민 관련"},
		{"국방 관련"},
		{"종교 관련"},
		{"건물 건설"}
	};

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	int yCoord = 0;
	for (int i = 0; i < 4; i++, yCoord += 9)
	{
		to->GoToXYPosition(173, 22 + yCoord);
		printf("%s\n", MenuText[i]);
	}
}

void PrintImage::PrintPressText()
{
	to->GoToXYPosition(PRESS_BUTTOM_X, PRESS_BUTTOM_Y);
	printf("PRESS THE ANY KEY");
}
