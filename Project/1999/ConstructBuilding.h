/* �ǹ� �Ǽ� �� �ı� Ŭ����*/
#pragma once
#pragma region HeaderFiles
#include "Map.h"
#include "SetPosition.h"
#include "BuildingImage.h"
#include "BuildingInfo.h"
#include "InfoHandler.h"
#include "NewsHandler.h"
#include "Music.h"
#include <time.h>
#include <set>
#include <map>
#pragma endregion

class ConstructBuilding : Map, BuildingImage, BuildingInfo
{
private:
	SetPosition* to = new SetPosition;
	Music* music = new Music;

	int ExitNum; // ���Ա��� ����

	std::map<int, int> BuildingSize; // (�ǹ� ��ȣ, �ǹ� ������)
	std::map<int, int> BuildingPrice; // (�ǹ� ��ȣ, �ǹ� ����)

public:
	ConstructBuilding();
	~ConstructBuilding();

	void BuildingIntializer();// Initializer

	int GetExitNum() { return this->ExitNum; }

#pragma region MakeMap
	void PrintWholeMap(); // ��ü���� ���Ա��� ���� �Է� �� ��� ����
	void GetPlayerExitNum(); // ���Ա��� ���� �Է¹ޱ�
	void MakeRandomExit(); // ������ ����
#pragma endregion

#pragma region About Build
	int BuildBuilding(int building, InfoHandler* info); // �ǹ� �Է¹ް� �Ǽ� �� �ı� ����
	void ShowBuildShadow(int size, int x, int y, int direction); // �ǹ� Ŀ�� �׸��� ���
	void CleanBuildShadow(int size, int x, int y); // �ǹ� Ŀ�� �׸��� ����

	void NewBuild(int building, int x, int y, InfoHandler* info); // �ǹ� �Ǽ�
	void DestroyBuilding(int building, int size, int x, int y, InfoHandler* info, int Zombie); // �ǹ� �ı�

	void PlusCntBuilding(int building, InfoHandler* info); // �ǹ� ���� �߰�
	void MinusCntBuilding(int building, InfoHandler* info); // �ǹ� ���� ����

	void Religon42BMaker(InfoHandler* info, NewsHandler* news); // ���̺� ���� �ǹ� ����
#pragma endregion

#pragma region About Zombie Day
	// Zombie About Building
	int ReligionCntSave(InfoHandler* info, NewsHandler* news); // ���� �ǹ��� ���� �߰� ������ ���
	int CitizenCntSave(InfoHandler* info, NewsHandler* news); // �ù� �ǹ��� ���� �߰� ������ ���
	int ArmyCntSave(InfoHandler* info, NewsHandler* news); // ���� �ǹ��� ���� �߰� ������ ���

	// Zombie About Distance
	int DistanceBetweenAPTReligion(); // ����Ʈ�� �����ǹ� ������ �Ÿ� ���
	int DistanceBetweenAPTExit(); // ����Ʈ�� ���Ա� ������ �Ÿ� ���

	// Zoimbie Day Random Destroy
	void ZombieDayRandomDestory(InfoHandler* info, NewsHandler* news); // ���� �߻��� �������� �ǹ� 1�� �ı�
#pragma endregion
};

