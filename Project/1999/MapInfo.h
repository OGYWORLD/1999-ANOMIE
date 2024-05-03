/* TotalMap의 요소가 될 클래스*/
#pragma once

class MapInfo
{
private:
	int StartX; // 건물의 맨 좌측 상단의 x좌표
	int StartY; // 건물의 맨 좌측 상단의 y좌표
	int Info; // 0: 건설 가능, -1: 건설 불가능, 49: 병원 ~ 56: 부대(대)
	int Size; // 빌딩 사이즈
	int Color; // 도트 컬러

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

