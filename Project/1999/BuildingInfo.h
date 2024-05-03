/* �ǹ� ������ ���� ������ ����ִ� Ŭ����*/
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
	int APTNum; // ����Ʈ ����
	int HospitalNum; // ���� ����
	int ParkNum; // ���� ����

	int ReligionNum; // ���� �ǹ� ����

	int ArmySmallNum; // �δ�(��) ����
	int ArmyMediumNum; // �δ�(��) ����
	int ArmyLargeNum; // �δ�(��) ����
#pragma endregion

#pragma region Coordinate Variables
	// PerCenterMap
	std::map<std::pair<int, int>, std::pair<int, int>> PerCenterCOORDAPT; // �� ����Ʈ�� �߽� ��ǥ
	std::map<std::pair<int, int>, std::pair<int, int>> PerCenterCOORDReligion; // �� ���� �ǹ��� �߽� ��ǥ
	std::map<std::pair<int, int>, std::pair<int, int>> PerCenterCOORDPark; // �� ������ �߽� ��ǥ

	// PerCenterExit
	std::vector<std::pair<int, int>> PerCenterExit; // �� ���Ա��� ��ǥ

	// CenterCOORD
	std::pair<int, int> CenterCOORDAPT; // ��ü ����Ʈ�� �߽� ��ǥ
	std::pair<int, int> CenterCOORDReligion; // ��ü ���� �ǹ��� �߽� ��ǥ
#pragma endregion

public:
	BuildingInfo();
	~BuildingInfo();

#pragma region Calculation
	// Calculation Coordinate
	std::pair<int, int> CalCulCenterCOORD(int size, int x, int y); // �߽� ��ǥ ���
	std::pair<int, int> CalCulCenterCOORDMap(std::map<std::pair<int, int>, std::pair<int, int>> map); // ��ü �߽� ��ǥ ���
	int CalCulDistance(int x1, int y1, int x2, int y2); // �� �� ������ �Ÿ� ���

	// Add Data
	void AddCOORDData(int x, int y, int building, int size); // ��ǥ �߰� �� ��ü �߽���ǥ update
	void RemoveCOORDData(int x, int y, int building, int size); // ��ǥ ���� �� ��ü �߽���ǥ update
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

