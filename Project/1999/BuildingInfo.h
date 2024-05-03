/* 건물 정보에 관한 변수를 담고있는 클래스*/
#pragma once

#include "EKEYBOARD.h"
#include <map>
#include <vector>
#include <cmath>

class BuildingInfo
{
protected:

#pragma region Num Variables
	// Building Num
	int APTNum; // 아파트 개수
	int HospitalNum; // 병원 개수
	int ParkNum; // 공원 개수

	int ReligionNum; // 종교 건물 개수

	int ArmySmallNum; // 부대(소) 개수
	int ArmyMediumNum; // 부대(중) 개수
	int ArmyLargeNum; // 부대(대) 개수
#pragma endregion

#pragma region Coordinate Variables
	// PerCenterMap
	std::map<std::pair<int, int>, std::pair<int, int>> PerCenterCOORDAPT; // 각 아파트의 중심 좌표
	std::map<std::pair<int, int>, std::pair<int, int>> PerCenterCOORDReligion; // 각 종교 건물의 중심 좌표
	std::map<std::pair<int, int>, std::pair<int, int>> PerCenterCOORDPark; // 각 공원의 중심 좌표

	// PerCenterExit
	std::vector<std::pair<int, int>> PerCenterExit; // 각 출입구의 좌표

	// CenterCOORD
	std::pair<int, int> CenterCOORDAPT; // 전체 아파트의 중심 좌표
	std::pair<int, int> CenterCOORDReligion; // 전체 종교 건물의 중심 좌표
#pragma endregion

public:
	BuildingInfo();
	~BuildingInfo();

#pragma region Calculation
	// Calculation Coordinate
	std::pair<int, int> CalCulCenterCOORD(int size, int x, int y); // 중심 좌표 계산
	std::pair<int, int> CalCulCenterCOORDMap(std::map<std::pair<int, int>, std::pair<int, int>> map); // 전체 중심 좌표 계산
	int CalCulDistance(int x1, int y1, int x2, int y2); // 두 점 사이의 거리 계산

	// Add Data
	void AddCOORDData(int x, int y, int building, int size); // 좌표 추가 및 전체 중심좌표 update
	void RemoveCOORDData(int x, int y, int building, int size); // 좌표 삭제 및 전체 중심좌표 update
#pragma endregion

#pragma region Getter Setter
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
#pragma endregion

};

