/* 콘솔 조작 관련 클래스 */
#pragma once
#pragma region HeaderFiles
#include "EKEYBOARD.h"
#include "ConstantGroup.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#pragma endregion

class SetPosition
{
private:

public:
	SetPosition();
	~SetPosition();

	void GoToXYPosition(SHORT x, SHORT y); // 커서 위치 조정
	void SetColor(int c); // 텍스트 색깔 조정
	
	void CleanInputBuffer(); // 입력 버퍼 비우기
	void PartClean(int x, int y, int bx, int by); // 콘솔 부분 영역 지우기
};

