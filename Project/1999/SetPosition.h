/* �ܼ� ���� ���� Ŭ���� */
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

	void GoToXYPosition(SHORT x, SHORT y); // Ŀ�� ��ġ ����
	void SetColor(int c); // �ؽ�Ʈ ���� ����
	
	void CleanInputBuffer(); // �Է� ���� ����
	void PartClean(int x, int y, int bx, int by); // �ܼ� �κ� ���� �����
};

