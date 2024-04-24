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

	// Print
	void PrintDate(int color);
	void PrintMoney(int color);
	void PrintPower(int color);

	void PrintInfo();
	void DrawLine();

	//getset
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

	int GetTimeNum() { return this->Time; }
	void SetTimeNum(int n) { this->Time = n; }

	int GetZombieAttackNum() { return this->ZombieAttack; }
	void SetZombieAttackNum(int n) { this->ZombieAttack = n; }

	int GetCitizenPower() { return this->CitizenPower; }
	void SetCitizenPower(int n)
	{
		if (n > 100) { this->CitizenPower = 100; }
		else { this->CitizenPower = n; }
	}

	int GetReligionPower() { return this->ReligionPower; }
	void SetReligionPower(int n)
	{
		if (n > 100) { this->ReligionPower = 100; }
		else { this->ReligionPower = n; }
	}

	int GetArmyPower() { return this->ArmyPower; }
	void SetArmyPower(int n)
	{
		if(n > 100) { this->ArmyPower = 100; }
		else { this->ArmyPower = n; }
	}

	int GetCitizenEnding() { return this->CitizenEnding; }
	void SetCitizenEnding(int n)
	{
		if (n > 100) { this->CitizenEnding = 100; }
		else { this->CitizenEnding = n; }
	}

	int GetArmyEnding() { return this->ArmyEnding; }
	void SetArmyEnding(int n)
	{
		if (n > 100) { this->ArmyEnding = 100; }
		else { this->ArmyEnding = n; }
	}

	int GetReligionEnding() { return this->ReligionEnding; }
	void SetReligionEnding(int n)
	{
		if (n > 100) { this->ReligionEnding = 100; }
		else { this->ReligionEnding = n; }
	}

	int GetAllDieEnding() { return this->AllDieEnding; }
	void SetAllDieEnding(int n)
	{
		if (n > 100) { this->AllDieEnding = 100; }
		else { this->AllDieEnding = n; }
	}

	int* GetCntArr() { return this->CntArr; }
	void SetCntArr(int index, int n) { this->CntArr[index] = n; }

	// Citizen Menu
	void ForceMoney(int level);
	void Welfare();

	// Army Menu
	void ForceArmyMoney();
	int Propaganda();
	void ArmyWelfare();

	// Religion Menu
	void ProhibitReligionForCitizen();
	void ProhibitReligionForArmy();
	void ParticiateReligion();


};

