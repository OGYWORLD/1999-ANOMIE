#pragma once

class MapInfo
{
protected:
	int StartX;
	int StartY;
	int Info;
	int Size;

public:
	MapInfo(int sx, int sy, int i, int s)
	{
		this->StartX = sx;
		this->StartY = sy;
		this->Info = i;
		this->Size = s;
	}

	~MapInfo();
};

