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
	int GetCountryName() { return this->CountryName[30]; }
	void SetCountryName(std::string s) { this->CountryName = s; }

	int GetPresidentName() { return this->PresidentName[30]; }
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
	void SetCitizenPower(int n) { this->CitizenPower = n; }

	int GetReligionPower() { return this->ReligionPower; }
	void SetReligionPower(int n) { this->ReligionPower = n; }

	int GetArmyPower() { return this->ArmyPower; }
	void SetArmyPower(int n) { this->ArmyPower = n; }

	// Citizen Menu
	void ForceMoney(int level);
	void Welfare();
};

