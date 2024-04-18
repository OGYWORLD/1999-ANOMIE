#pragma once
#include "EKEYBOARD.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

#define CONSOLE_SIZE_X	202
#define CONSOLE_SIZE_Y	61

class SetPosition
{
private:

public:
	SetPosition();
	~SetPosition();

	void GoToXYPosition(int x, int y);
	void SetColor(int c);
	
	void CleanInputBuffer();
	void SystemClean();
	void PartClean(int x, int y, int bx, int by);
};

