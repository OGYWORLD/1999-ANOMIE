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
	to->GoToXYPosition(0, 0);

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

	to->GoToXYPosition(MENU_IMAGE_POSITION_X + 13, MENU_IMAGE_POSITION_Y + 33);
	to->SetColor(223);
	printf("새로운 내일은 p버튼");
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

void PrintImage::ConverDisapproveImage(int y, int Image[][DISAPPROVE_X])
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < DISAPPROVE_X; j++)
		{
			to->GoToXYPosition(DISAPPROVE_POSITION_X + j, DISAPPROVE_POSITION_Y + i);
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

void PrintImage::PrintPre2Text()
{
	to->PartClean(0, 0, WHOLE_IMAGE_X, PRIVIEW_Y);
	char Line1[2][100] =
	{
		{"그리고 내일은, 보궐 선거로 당선된 제 15대 대통령의"},
		{"공식 임기가 시작되는 날입니다."}
	};

	to->SetColor(10);
	int CurY = 0;
	for (int i = 0; i < 2; i++, CurY += 2)
	{
		to->GoToXYPosition(PREVIEW_TEXT_POSITION_X, PREVIEW_TEXT_POSITION_Y + i + CurY);
		printf("%s", Line1[i]);
	}
}

void PrintImage::PrintPre3Text()
{
	to->PartClean(0, 0, WHOLE_IMAGE_X, WHOLE_IMAGE_Y/2);
	char Line1[2][100] =
	{
		{"1998년 12월 31일 뉴스를 마치겠습니다."},
		{"고맙습니다."}
	};

	int CurY = 0;
	to->SetColor(10);
	for (int i = 0; i < 2; i++, CurY += 2)
	{
		to->GoToXYPosition(PREVIEW_TEXT_POSITION_X, PREVIEW_TEXT_POSITION_Y + i + CurY);
		printf("%s", Line1[i]);
	}
}

void PrintImage::PrintPre1Text()
{
	to->PartClean(0, 0, WHOLE_IMAGE_X, PRIVIEW_Y);
	char Line1[2][50] =
	{
		{"리벌 바이러스. 일명, 좀비 바이러스가 발생한지"},
		{"오늘부로 13년이 지났습니다."}
	};

	int CurY = 0;
	to->SetColor(10);
	for (int i = 0; i < 2; i++, CurY += 2)
	{
		to->GoToXYPosition(PREVIEW_TEXT_POSITION_X, PREVIEW_TEXT_POSITION_Y + i + CurY);
		printf("%s", Line1[i]);
	}
}


int PrintImage::PrintSelectText()
{
	char MenuText[3][10] =
	{
		{"게임 시작"},
		{"튜토리얼"},
		{"게임 종료"},
	};

	to->SetColor(10);
	int yCoord = 0;
	for (int i = 0; i < 3; i++, yCoord += 7)
	{
		to->GoToXYPosition(SELECT_POSITION_X, SELECT_POSITION_Y + yCoord);
		printf("%s\n", MenuText[i]);
	}

	int CurY = 0;
	while (1)
	{
		// Blink Point
		to->SetColor(10);
		to->GoToXYPosition(SELECT_POSITION_X - 5, SELECT_POSITION_Y + CurY);
		printf("▶");
		Sleep(300);
		to->GoToXYPosition(SELECT_POSITION_X - 5, SELECT_POSITION_Y + CurY);
		printf("  ");
		Sleep(300);

		if (_kbhit())
		{
			int nKey = _getch();
			if (nKey == EKEYBOARD::SPACE)
			{
				return CurY;
			}
			else if (nKey == EKEYBOARD::DIRECTION)
			{
				nKey = _getch();
				if (nKey == EKEYBOARD::KEY_UP)
				{
					CurY -= 7;
					if (CurY < 0)
					{
						CurY = 14;
					}

				}
				else if (nKey == EKEYBOARD::KEY_DOWN)
				{
					CurY += 7;
					if (CurY > 14)
					{
						CurY = 0;
					}
				}
			}

			to->CleanInputBuffer();
		}
	}
}

void PrintImage::PrintNewsImage()
{
	for (int i = 0; i < NEWS_Y; i++)
	{
		for (int j = 0; j < NEWS_X; j++)
		{
			if (NewsImage[i][j] != 0)
			{
				to->GoToXYPosition(NEWS_POSITION_X + j, NEWS_POSITION_Y + i);
				to->SetColor(NewsImage[i][j]);
				printf(" ");
			}
		}
	}

	to->SetColor(96);
	to->GoToXYPosition(NEWS_POSITION_X + 12, NEWS_POSITION_Y + 2);
	printf("♣ 오늘의 뉴우스 ♣");
}

void PrintImage::PrintZombieMenu()
{
	to->GoToXYPosition(MENU_POINT_POSITION_X - 6, MENU_POINT_POSITION_Y - 3);
	to->SetColor(16);
	for (int i = 0; i < ZOMBIE_MENU_Y; i++)
	{
		for (int j = 0; j < ZOMBIE_MENU_X; j++)
		{
			to->GoToXYPosition(MENU_POINT_POSITION_X - 6 + j, MENU_POINT_POSITION_Y - 3 + i);
			printf(" ");
		}
	}

	to->GoToXYPosition(MENU_POINT_POSITION_X + 5, MENU_POINT_POSITION_Y + 5);
	to->SetColor(241);
	printf(" Windows ");
	to->GoToXYPosition(MENU_POINT_POSITION_X - 4, MENU_POINT_POSITION_Y + 7);
	to->SetColor(23);
	printf("시스템에 응답하지 않는 응용");
	to->GoToXYPosition(MENU_POINT_POSITION_X - 4, MENU_POINT_POSITION_Y + 8);
	printf("프로그램을 중지시키는 방법이");
	to->GoToXYPosition(MENU_POINT_POSITION_X - 4, MENU_POINT_POSITION_Y + 9);
	printf("있지만, 이 상태에서는 그러한");
	to->GoToXYPosition(MENU_POINT_POSITION_X - 4, MENU_POINT_POSITION_Y + 10);
	printf("응용프로그램이 없습니다.");

	to->GoToXYPosition(MENU_POINT_POSITION_X - 4, MENU_POINT_POSITION_Y + 15);
	printf("Please Wait the Windows...");
}
