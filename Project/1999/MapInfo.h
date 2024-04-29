/* TotalMap�� ��Ұ� �� Ŭ����*/
#pragma once

class MapInfo
{
private:
	int StartX; // �ǹ��� �� ���� ����� x��ǥ
	int StartY; // �ǹ��� �� ���� ����� y��ǥ
	int Info; // 0: �Ǽ� ����, -1: �Ǽ� �Ұ���, 49: ���� ~ 56: �δ�(��)
	int Size; // ���� ������
	int Color; // ��Ʈ �÷�

public:
	MapInfo(int sx, int sy, int i, int s, int c);

	~MapInfo();

#pragma region Getter Setter
	void SetStartX(int sx)
	{
		this->StartX = sx;
	}
	int GetStartX()
	{
		return this->StartX;
	}

	void SetStartY(int sy)
	{
		this->StartY = sy;
	}
	int GetStartY()
	{
		return this->StartY;
	}

	void SetInfo(int i)
	{
		this->Info = i;
	}
	int GetInfo()
	{
		return this->Info;
	}

	void SetSize(int s)
	{
		this->Size = s;
	}
	int GetSize()
	{
		return this->Size;
	}

	void SetColor(int c)
	{
		this->Color = c;
	}
	int GetColor()
	{
		return this->Color;
	}
#pragma endregion

};

