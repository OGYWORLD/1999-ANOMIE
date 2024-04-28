#pragma once

class MapInfo
{
private:
	int StartX; // Build's Start X position
	int StartY; // Build's Start Y position
	int Info; // 0: Build Avaliable, -1: Build Unvaliable, 49: hospital ~ 56: ArmyLarge
	int Size; // Building Size
	int Color; // Dot Color

public:
	MapInfo(int sx, int sy, int i, int s, int c);

	~MapInfo();

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
};

