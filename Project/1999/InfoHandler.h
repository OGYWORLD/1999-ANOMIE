/* Game Info의 변수 조작 클래스*/
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
	void PrintDate(int color); // Info 탭 중 날짜 출력
	void PrintMoney(int color); // Info 탭 중 정부 예산 출력
	void PrintPower(int color); // Info 탭 중 파워 출력

	void PrintInfo(); // 전체 Info 탭 출력
	void DrawLine(); // Info Box 출력
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
	void SetCitizenPower(int n) // 파워의 최대값은 100, 최소값은 0 이므로 예외처리
	{
		if (n > 100) { this->CitizenPower = 100; }
		else if (n < 0) { this->CitizenPower = 0; }
		else { this->CitizenPower = n; }
	}

	int GetReligionPower() { return this->ReligionPower; }
	void SetReligionPower(int n) // 파워의 최대값은 100, 최소값은 0 이므로 예외처리
	{
		if (n > 100) { this->ReligionPower = 100; }
		else if (n < 0) { this->ReligionPower = 0; }
		else { this->ReligionPower = n; }
	}

	int GetArmyPower() { return this->ArmyPower; }
	void SetArmyPower(int n) // 파워의 최대값은 100, 최소값은 0 이므로 예외처리
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
	void ForceMoney(int level); // 세금 강제 징수로 인한 변수 update
	void Welfare(); // 국민 복지 정책으로 인한 변수 update

	// Army Menu
	void ForceArmyMoney(); // 군인 월급 감소로 인한 변수 update
	int Propaganda(); // 군인 프로파간다로 인한 변수 update
	void ArmyWelfare(); // 국방부 예산 학대로 인한 변수 update

	// Religion Menu
	void ProhibitReligionForCitizen(); // 종교 활동 금지(국민)으로 인한 변수 update
	void ProhibitReligionForArmy(); // 종교 활동 금지(군인)으로 인한 변수 update
	void ParticiateReligion(); // 종교 활동 참여로 인한 변수 update
#pragma endregion


};

