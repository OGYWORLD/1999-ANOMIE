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
		{"�ù� ����"},
		{"���� ����"},
		{"���� ����"},
		{"�ǹ� �Ǽ�"}
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
	printf("���ο� ������ p��ư");
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
		{"�׸��� ������, ���� ���ŷ� �缱�� �� 15�� �������"},
		{"���� �ӱⰡ ���۵Ǵ� ���Դϴ�."}
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
		{"1998�� 12�� 31�� ������ ��ġ�ڽ��ϴ�."},
		{"�����ϴ�."}
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
		{"���� ���̷���. �ϸ�, ���� ���̷����� �߻�����"},
		{"���úη� 13���� �������ϴ�."}
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
		{"���� ����"},
		{"Ʃ�丮��"},
		{"���� ����"},
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
		printf("��");
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
	printf("�� ������ ���콺 ��");
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
	printf("�ý��ۿ� �������� �ʴ� ����");
	to->GoToXYPosition(MENU_POINT_POSITION_X - 4, MENU_POINT_POSITION_Y + 8);
	printf("���α׷��� ������Ű�� �����");
	to->GoToXYPosition(MENU_POINT_POSITION_X - 4, MENU_POINT_POSITION_Y + 9);
	printf("������, �� ���¿����� �׷���");
	to->GoToXYPosition(MENU_POINT_POSITION_X - 4, MENU_POINT_POSITION_Y + 10);
	printf("�������α׷��� �����ϴ�.");

	to->GoToXYPosition(MENU_POINT_POSITION_X - 4, MENU_POINT_POSITION_Y + 15);
	printf("Please Wait the Windows...");
}
