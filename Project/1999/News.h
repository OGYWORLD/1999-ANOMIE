/* �����ǿ� �Ǹ� ������ ����ִ� Ŭ���� */
#pragma once
#include <vector>
#include "ConstantGroup.h"
#include "EKEYBOARD.h"

class News
{
protected:

#pragma region News
	// Citizen News
	std::vector<std::pair<const char*, int>> CitizenLittleForceNews; // �ణ ���� �߰� ¡�� ����
	std::vector<std::pair<const char*, int>> CitizenManyForceNews; // ���� ���� �߰� ¡�� ����
	std::vector<std::pair<const char*, int>> CitizenWelfareNews; // ���� ��å ���� ����

	// Army News
	std::vector<std::pair<const char*, int>> ArmyForceNews; // ���� ���� ���� ����
	std::vector<std::pair<const char*, int>> ArmyPropagandaGoodNews; // ���� �����İ��� ���� ����
	std::vector<std::pair<const char*, int>> ArmyPropagandaBadNews; // ���� �����İ��� ���� ����
	std::vector<std::pair<const char*, int>> ArmyWelfareNews; // ����� ���� Ȯ�� ����

	// Religion News
	std::vector<std::pair<const char*, int>> ReligionProhibitCitizenNews; // ����Ȱ�� ����(����) ����
	std::vector<std::pair<const char*, int>> ReligionProhibitArmyNews;// ����Ȱ�� ���� (����) ����
	std::vector<std::pair<const char*, int>> ParticiateReligionNews; // ����Ȱ�� ���� ����

	// Religion Zombie News
	std::vector<std::pair<const char*, int>> ZeroReligionZombieNews; // ���� �߻� ��, ���� �ǹ��� ���� �� ����
	std::vector<std::pair<const char*, int>> SmallReligionZombieNews; // ���� �߻� ��, ���� �ǹ��� 1~3�� ���� �� ����
	std::vector<std::pair<const char*, int>> MediumReligionZombieNews; // ���� �߻� ��, ���� �ǹ��� 4~6�� ���� �� ����
	std::vector<std::pair<const char*, int>> LargeReligionZombieNews; // ���� �߻� ��, ���� �ǹ��� 7�� �̻� ���� �� ����

	// Hospital Zombie News
	std::vector<std::pair<const char*, int>> ZeroHospitalZombieNews; // ���� �߻� ��, ���� �ǹ��� ���� �� ����
	std::vector<std::pair<const char*, int>> HospitalZombieNews; // ���� �߻� ��, ���� �ǹ��� ���� �� ����

	// APT Zombie News
	std::vector<std::pair<const char*, int>> ZeroAPTZombieNews; // ���� �߻� ��, ����Ʈ�� ���� �� ����
	std::vector<std::pair<const char*, int>> APTZombieNews; // ���� �߻� ��, ����Ʈ�� ���� �� ����

	// Army Zombie News
	// ArmyGauge = ArmySmallNum + ArmyMediumNum * 2 + ArmyLargeNum * 5;
	std::vector<std::pair<const char*, int>> ZeroArmyZombieNews; // ���� �߻� ��, ArmyGauge�� 0�� �� ����
	std::vector<std::pair<const char*, int>> SmallArmyZombieNews; // ���� �߻� ��, ArmyGauge�� 1~9�� �� ����
	std::vector<std::pair<const char*, int>> MediumArmyZombieNews;  // ���� �߻� ��, ArmyGauge�� 10~19�� �� ����
	std::vector<std::pair<const char*, int>> LargeArmyZombieNews; // ���� �߻� ��, ArmyGauge�� 20�̻��� �� ����
#pragma endregion

public:
	News();
	~News();
	
};

