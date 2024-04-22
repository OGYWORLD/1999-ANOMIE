#pragma once
#include <vector>
#include "ConstantGroup.h"
#include "EKEYBOARD.h"

class News
{
protected:

	// Citizen
	std::vector<const char*> CitizenLittleForceNews;
	std::vector<const char*> CitizenManyForceNews;
	std::vector<const char*> CitizenWelfareNews;

	// Army
	std::vector<const char*> ArmyForceNews;
	std::vector<const char*> ArmyPropagandaGoodNews;
	std::vector<const char*> ArmyPropagandaBadNews;
	std::vector<const char*> ArmyWelfareNews;

	// Religion
	std::vector<const char*> ReligionProhibitCitizenNews;
	std::vector<const char*> ReligionProhibitArmyNews;
	std::vector<const char*> ParticiateReligionNews;

public:
	News();
	~News();
};

