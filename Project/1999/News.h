#pragma once
#include <vector>
#include "ConstantGroup.h"
#include "EKEYBOARD.h"

class News
{
protected:

	// Citizen News
	std::vector<std::pair<const char*, int>> CitizenLittleForceNews;
	std::vector<std::pair<const char*, int>> CitizenManyForceNews;
	std::vector<std::pair<const char*, int>> CitizenWelfareNews;

	// Army News
	std::vector<std::pair<const char*, int>> ArmyForceNews;
	std::vector<std::pair<const char*, int>> ArmyPropagandaGoodNews;
	std::vector<std::pair<const char*, int>> ArmyPropagandaBadNews;
	std::vector<std::pair<const char*, int>> ArmyWelfareNews;

	// Religion News
	std::vector<std::pair<const char*, int>> ReligionProhibitCitizenNews;
	std::vector<std::pair<const char*, int>> ReligionProhibitArmyNews;
	std::vector<std::pair<const char*, int>> ParticiateReligionNews;

	// Religion Zombie News
	std::vector<std::pair<const char*, int>> ZeroReligionZombieNews;
	std::vector<std::pair<const char*, int>> SmallReligionZombieNews;
	std::vector<std::pair<const char*, int>> MediumReligionZombieNews;
	std::vector<std::pair<const char*, int>> LargeReligionZombieNews;

	// Hospital Zombie News
	std::vector<std::pair<const char*, int>> ZeroHospitalZombieNews;
	std::vector<std::pair<const char*, int>> HospitalZombieNews;

	// APT Zombie News
	std::vector<std::pair<const char*, int>> ZeroAPTZombieNews;
	std::vector<std::pair<const char*, int>> APTZombieNews;

	// Army Zombie News
	std::vector<std::pair<const char*, int>> ZeroArmyZombieNews;
	std::vector<std::pair<const char*, int>> SmallArmyZombieNews;
	std::vector<std::pair<const char*, int>> MediumArmyZombieNews;
	std::vector<std::pair<const char*, int>> LargeArmyZombieNews;

public:
	News();
	~News();
	
};

