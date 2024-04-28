#pragma once

#include "EKEYBOARD.h"
#include <map>
#include <vector>
#include <cmath>

class BuildingInfo
{
protected:
	// Building Num
	int APTNum;
	int HospitalNum;
	int ParkNum;

	int ReligionNum;

	int ArmySmallNum;
	int ArmyMediumNum;
	int ArmyLargeNum;

	// PerCenterMap
	std::map<std::pair<int, int>, std::pair<int, int>> PerCenterCOORDAPT;
	std::map<std::pair<int, int>, std::pair<int, int>> PerCenterCOORDReligion;
	std::map<std::pair<int, int>, std::pair<int, int>> PerCenterCOORDPark;

	// PerCenterExit
	// It is made of Vector becase of deosn't need delete
	std::vector<std::pair<int, int>> PerCenterExit;

	// CenterCOORD
	std::pair<int, int> CenterCOORDAPT;
	std::pair<int, int> CenterCOORDReligion;

public:
	BuildingInfo();
	~BuildingInfo();

	// Calculation
	std::pair<int, int> CalCulCenterCOORD(int size, int x, int y); // 그냥 중심좌표
	std::pair<int,int> CalCulCenterCOORDMap(std::map<std::pair<int, int>, std::pair<int, int>> map); // 평균 중심 좌표
	int CalCulDistance(int x1, int y1, int x2, int y2); // 두 점 사이의 거리

	// Add Data
	void AddCOORDData(int x, int y, int building, int size);
	void RemoveCOORDData(int x, int y, int building, int size);

	// Getter Setter
	void SetAPTNum(int n) { this->APTNum = n; }
	int GetAPTNum() { return this->APTNum; }

	void SetHospitalNum(int n) { this->HospitalNum = n; }
	int GetHospitalNum() { return this->HospitalNum; }

	void SetParkNum(int n) { this->ParkNum = n; }
	int GetParkNum() { return this->ParkNum; }

	void SetReligionNum(int n) { this->ReligionNum = n; }
	int GetReligionNum() { return this->ReligionNum; }

	void SetArmySmallNum(int n) { this->ArmySmallNum = n; }
	int GetArmySmallNum() { return this->ArmySmallNum; }

	void SetArmyMediumNum(int n) { this->ArmyMediumNum = n; }
	int GetArmyMediumNum() { return this->ArmyMediumNum; }

	void SetArmyLargeNum(int n) { this->ArmyLargeNum = n; }
	int GetArmyLargeNum() { return this->ArmyLargeNum; }

};

