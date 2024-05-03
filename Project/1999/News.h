/* 뉴스탭에 실릴 뉴스를 담고있는 클래스 */
#pragma once
#include <vector>
#include "ConstantGroup.h"
#include "EKEYBOARD.h"

class News
{
protected:

#pragma region News
	// Citizen News
	std::vector<std::pair<const char*, int>> CitizenLittleForceNews; // 약간 세금 추가 징수 뉴스
	std::vector<std::pair<const char*, int>> CitizenManyForceNews; // 강한 세금 추가 징수 뉴스
	std::vector<std::pair<const char*, int>> CitizenWelfareNews; // 복지 정책 실행 뉴스

	// Army News
	std::vector<std::pair<const char*, int>> ArmyForceNews; // 군인 월급 감소 뉴스
	std::vector<std::pair<const char*, int>> ArmyPropagandaGoodNews; // 군인 프로파간다 성공 뉴스
	std::vector<std::pair<const char*, int>> ArmyPropagandaBadNews; // 군인 프로파간다 실패 뉴스
	std::vector<std::pair<const char*, int>> ArmyWelfareNews; // 국방부 예산 확대 뉴스

	// Religion News
	std::vector<std::pair<const char*, int>> ReligionProhibitCitizenNews; // 종교활동 금지(국민) 뉴스
	std::vector<std::pair<const char*, int>> ReligionProhibitArmyNews;// 종교활동 금지 (국방) 뉴스
	std::vector<std::pair<const char*, int>> ParticiateReligionNews; // 종교활동 참여 뉴스

	// Religion Zombie News
	std::vector<std::pair<const char*, int>> ZeroReligionZombieNews; // 좀비 발생 시, 종교 건물이 없을 때 뉴스
	std::vector<std::pair<const char*, int>> SmallReligionZombieNews; // 좀비 발생 시, 종교 건물이 1~3개 있을 때 뉴스
	std::vector<std::pair<const char*, int>> MediumReligionZombieNews; // 좀비 발생 시, 종교 건물이 4~6개 있을 때 뉴스
	std::vector<std::pair<const char*, int>> LargeReligionZombieNews; // 좀비 발생 시, 종교 건물이 7개 이상 있을 때 뉴스

	// Hospital Zombie News
	std::vector<std::pair<const char*, int>> ZeroHospitalZombieNews; // 좀비 발생 시, 병원 건물이 없을 때 뉴스
	std::vector<std::pair<const char*, int>> HospitalZombieNews; // 좀비 발생 시, 병원 건물이 있을 때 뉴스

	// APT Zombie News
	std::vector<std::pair<const char*, int>> ZeroAPTZombieNews; // 좀비 발생 시, 아파트가 없을 때 뉴스
	std::vector<std::pair<const char*, int>> APTZombieNews; // 좀비 발생 시, 아파트가 있을 때 뉴스

	// Army Zombie News
	// ArmyGauge = ArmySmallNum + ArmyMediumNum * 2 + ArmyLargeNum * 5;
	std::vector<std::pair<const char*, int>> ZeroArmyZombieNews; // 좀비 발생 시, ArmyGauge가 0일 때 뉴스
	std::vector<std::pair<const char*, int>> SmallArmyZombieNews; // 좀비 발생 시, ArmyGauge가 1~9일 때 뉴스
	std::vector<std::pair<const char*, int>> MediumArmyZombieNews;  // 좀비 발생 시, ArmyGauge가 10~19일 때 뉴스
	std::vector<std::pair<const char*, int>> LargeArmyZombieNews; // 좀비 발생 시, ArmyGauge가 20이상일 때 뉴스
#pragma endregion

public:
	News();
	~News();
	
};

