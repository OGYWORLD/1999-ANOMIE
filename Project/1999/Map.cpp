#include "Map.h"

Map::Map() : MapInfo(-1, -1, -1, -1, -1)
{
	// MakeMap
	// StartX, StartY, Info, Size, Color

	int info;
	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			if (Color[i][j] == 0)
			{
				info = 0;
			}
			else
			{
				info = -1;
			}

			TotalMap[i].push_back(new MapInfo({ -1, -1, info, -1, Color[i][j] }));
		}
	}
}

Map::~Map()
{
	// delete TotalMap
	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			delete TotalMap[i][j];
		}
	}

	// delete to
	delete to;
}

void Map::InitMap()
{
	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			if (j == 0 || j == MAP_X-1 || j == 1 || j == MAP_X - 2 || i == 0 || i == 1 || i == MAP_Y - 2 || i == MAP_Y - 1)
			{
				TotalMap[i][j]->SetColor(240);
				TotalMap[i][j]->SetInfo(-1);
			}
		}
	}
}

void Map::PrintWholeMap()
{
	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			if (TotalMap[i][j]->GetColor() != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), TotalMap[i][j]->GetColor());
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
