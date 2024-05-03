/* Game Info�� ���� ���� Ŭ����*/
#pragma once
#include "GameInfo.h"
#include "SetPosition.h"
#include <cmath>
#include <climits>
#include <cstring>
#include <iostream>
#include <time.h>


class InfoHandler : GameInfo
{
private:
	SetPosition* to = new SetPosition;

public:
	InfoHandler();
	~InfoHandler();

	// Initializer
	void GameInfoInitializer();

	// Print
#pragma region Print
	void PrintDate(int color); // Info �� �� ��¥ ���
	void PrintMoney(int color); // Info �� �� ���� ���� ���
	void PrintPower(int color); // Info �� �� �Ŀ� ���

	void PrintInfo(); // ��ü Info �� ���
	void DrawLine(); // Info Box ���
#pragma endregion

	//getter, stter
#pragma region GetterSetter
	std::string GetCountryName() { return this->CountryName; }
	void SetCountryName(std::string s) { this->CountryName = s; }

	std::string GetPresidentName() { return this->PresidentName; }
	void SetPresidentName(std::string s) { this->PresidentName = s; }

	int GetMoney() { return this->Money; }
	void SetMoney(int n) { this->Money = n; }

	int GetYear() { return this->Year; }
	void SetYear(int n) { this->Year = n; }

	int GetMonth() { return this->Month; }
	void SetMonth(int n) { this->Month = n; }

	int GetDay() { return this->Day; }
	void SetDay(int n) { this->Day = n; }

	int GetPeopleNum() { return this->PeopleNum; }
	void SetPeopleNum(int n) { this->PeopleNum = n; }

	int GetCitizenPower() { return this->CitizenPower; }
	void SetCitizenPower(int n) // �Ŀ��� �ִ밪�� 100, �ּҰ��� 0 �̹Ƿ� ����ó��
	{
		if (n > 100) { this->CitizenPower = 100; }
		else if (n < 0) { this->CitizenPower = 0; }
		else { this->CitizenPower = n; }
	}

	int GetReligionPower() { return this->ReligionPower; }
	void SetReligionPower(int n) // �Ŀ��� �ִ밪�� 100, �ּҰ��� 0 �̹Ƿ� ����ó��
	{
		if (n > 100) { this->ReligionPower = 100; }
		else if (n < 0) { this->ReligionPower = 0; }
		else { this->ReligionPower = n; }
	}

	int GetArmyPower() { return this->ArmyPower; }
	void SetArmyPower(int n) // �Ŀ��� �ִ밪�� 100, �ּҰ��� 0 �̹Ƿ� ����ó��
	{
		if (n > 100) { this->ArmyPower = 100; }
		else if (n < 0) { this->ArmyPower = 0; }
		else { this->ArmyPower = n; }
	}

	int GetCitizenEnding() { return this->CitizenEnding; }
	void SetCitizenEnding(int n) { this->CitizenEnding = n; }

	int GetArmyEnding() { return this->ArmyEnding; }
	void SetArmyEnding(int n) { this->ArmyEnding = n; }

	int GetReligionEnding() { return this->ReligionEnding; }
	void SetReligionEnding(int n) { this->ReligionEnding = n; }

	int GetAllDieEnding() { return this->AllDieEnding; }
	void SetAllDieEnding(int n) { this->AllDieEnding = n; }

	int* GetCntArr() { return this->CntArr; }
	void SetCntArr(int index, int n) { this->CntArr[index] = n; }
#pragma endregion

	// Menu
#pragma region menu
	// Citizen Menu
	void ForceMoney(int level); // ���� ���� ¡���� ���� ���� update
	void Welfare(); // ���� ���� ��å���� ���� ���� update

	// Army Menu
	void ForceArmyMoney(); // ���� ���� ���ҷ� ���� ���� update
	int Propaganda(); // ���� �����İ��ٷ� ���� ���� update
	void ArmyWelfare(); // ����� ���� �д�� ���� ���� update

	// Religion Menu
	void ProhibitReligionForCitizen(); // ���� Ȱ�� ����(����)���� ���� ���� update
	void ProhibitReligionForArmy(); // ���� Ȱ�� ����(����)���� ���� ���� update
	void ParticiateReligion(); // ���� Ȱ�� ������ ���� ���� update
#pragma endregion


};

