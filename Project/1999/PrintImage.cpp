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
				to->SetColor(Image[i][j]);
				printf(" ");
				to->SetColor(0);
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
				to->SetColor(Image[i][j]);
				printf(" ");
				to->SetColor(0);
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
				to->SetColor(Image[i % WHOLE_IMAGE_Y][j]);
				printf(" ");
				to->SetColor(0);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void PrintImage::ConvertSmallImage(int y, int Image[][SMALL_X], int OriginX, int OriginY)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < SMALL_X; j++)
		{
			if (Image[i][j] != 0)
			{
				to->GoToXYPosition(OriginX + j, OriginY + i);
				to->SetColor(Image[i][j]);
				printf(" ");
				to->SetColor(0);
			}
			else
			{
				to->GoToXYPosition(OriginX + j, OriginY + i);
				printf(" ");
			}
		}
		printf("\n");
	}
}

void PrintImage::ConvertMediumImage(int y, int Image[][MEDIUM_X], int OriginX, int OriginY)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < MEDIUM_X; j++)
		{
			if (Image[i][j] != 0)
			{
				to->GoToXYPosition(OriginX + j, OriginY + i);
				to->SetColor(Image[i][j]);
				printf(" ");
				to->SetColor(0);
			}
			else
			{
				to->GoToXYPosition(OriginX + j, OriginY + i);
				printf(" ");
			}
		}
		printf("\n");
	}
}

void PrintImage::ConvertLargeImage(int y, int Image[][LARGE_X], int OriginX, int OriginY)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < LARGE_X; j++)
		{
			if (Image[i][j] != 0)
			{
				to->GoToXYPosition(OriginX + j, OriginY + i);
				to->SetColor(Image[i][j]);
				printf(" ");
				to->SetColor(0);
			}
			else
			{
				to->GoToXYPosition(OriginX + j, OriginY + i);
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
			if (Image[i][j] != 0)
			{
				to->GoToXYPosition(MENU_IMAGE_POSITION_X + j, MENU_IMAGE_POSITION_Y + i);
				to->SetColor(Image[i][j]);
				printf(" ");
				to->SetColor(0);
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

	to->SetColor(10);
	int yCoord = 0;
	for (int i = 0; i < 4; i++, yCoord += 7)
	{
		to->GoToXYPosition(MENU_IMAGE_POSITION_X+18, MENU_IMAGE_POSITION_Y + 8 + yCoord);
		printf("%s\n", MenuText[i]);
	}
}

void PrintImage::ConvertPTAKImage(int y, int Image[][PRESS_BUTTOM_X])
{
	for (int i = 0; i < PRESS_BUTTOM_Y; i++)
	{
		for (int j = 0; j < PRESS_BUTTOM_X; j++)
		{
			if (Image[i][j] != 0)
			{
				to->GoToXYPosition(PRESS_BUTTOM_POSITION_X + j, PRESS_BUTTOM_POSITION_Y + i);
				to->SetColor(Image[i][j]);
				printf(" ");
				to->SetColor(0);
			}
			else
			{
				to->GoToXYPosition(PRESS_BUTTOM_POSITION_X + j, PRESS_BUTTOM_POSITION_Y + i);
				printf(" ");
			}
		}
		printf("\n");
	}
}
