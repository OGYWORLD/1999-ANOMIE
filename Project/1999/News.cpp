#include "News.h"

News::News()
{
	// Citizen
	CitizenLittleForceNews.push_back(std::pair < const char*, int>("[����] \"���� ���� ����...\"", 12));
	CitizenLittleForceNews.push_back(std::pair < const char*, int>("[����] \"��鵵 ��ο�.\" ��鸮...", 12));
	CitizenLittleForceNews.push_back(std::pair < const char*, int>("[����] ����� ȥ�ڻ�� ����? ", 12));

	CitizenManyForceNews.push_back(std::pair <const char*, int>("[����] �������� ġ�ݴ� ����", 12));
	CitizenManyForceNews.push_back(std::pair < const char*, int>("[����] �糪���� �Ȱ���", 12));
	CitizenManyForceNews.push_back(std::pair < const char*, int>("[����] ���� �������� ����?", 12));

	CitizenWelfareNews.push_back(std::pair < const char*, int>("[����] ����� \"���� ������ ��\"", 10));
	CitizenWelfareNews.push_back(std::pair < const char*, int>("[����] Ȱ�⸦ ���̴� �ν�", 10));
	CitizenWelfareNews.push_back(std::pair < const char*, int>("[����] ������� �Ͼ�� ����", 10));

	// Army
	ArmyForceNews.push_back(std::pair < const char*, int>("[����] �� �ñ��� ���� ���ް���?", 12));
	ArmyForceNews.push_back(std::pair < const char*, int>("[����] ������ �� �����ִ°�?", 12));
	ArmyForceNews.push_back(std::pair < const char*, int>("[����] ������������ ����", 12));

	ArmyPropagandaGoodNews.push_back(std::pair < const char*, int>("[����] ������ ����, ������ ����", 9));
	ArmyPropagandaGoodNews.push_back(std::pair < const char*, int>("[����] �״��� ������ ����", 9));
	ArmyPropagandaGoodNews.push_back(std::pair < const char*, int>("[����] ������ ���� ����", 9));

	ArmyPropagandaBadNews.push_back(std::pair < const char*, int>("[����] ������ 60���? �������", 12));
	ArmyPropagandaBadNews.push_back(std::pair < const char*, int>("[����] �ǽɽ����� ���� ����", 12));
	ArmyPropagandaBadNews.push_back(std::pair < const char*, int>("[����] ������ ��û�ϴٰ� �����ϴ°�?", 12));

	ArmyWelfareNews.push_back(std::pair < const char*, int>("[����] ����� ���� Ȯ��. ���� �����", 10));
	ArmyWelfareNews.push_back(std::pair < const char*, int>("[����] ����� ���� Ȯ��. �ְ��� ����", 10));
	ArmyWelfareNews.push_back(std::pair < const char*, int>("[����] ����� ���� Ȯ��. ��� �����", 10));

	// Religion
	ReligionProhibitCitizenNews.push_back(std::pair < const char*, int>("[����] ����� \"��ü�� �Ͼ��\"", 12));
	ReligionProhibitCitizenNews.push_back(std::pair < const char*, int>("[����] ��������Ȱ������, ���� �Ͼ��.", 12));
	ReligionProhibitCitizenNews.push_back(std::pair < const char*, int>("[����] ������ ������... ����Ȱ������", 12));

	ReligionProhibitArmyNews.push_back(std::pair < const char*, int>("[����] �ź��� ������... ����Ȱ������", 12));
	ReligionProhibitArmyNews.push_back(std::pair < const char*, int>("[����] ������ ������... ����Ȱ������", 12));
	ReligionProhibitArmyNews.push_back(std::pair < const char*, int>("[����] ������ ��ó��... ����Ȱ������", 12));

	ParticiateReligionNews.push_back(std::pair < const char*, int>("[����] ����� \"�Ų��� �Բ� �Ͻñ�\"", 11));
	ParticiateReligionNews.push_back(std::pair < const char*, int>("[����] ����� ������� ����...", 11));
	ParticiateReligionNews.push_back(std::pair < const char*, int>("[����] ����� �� �뿹�� ����...", 11));

	// Religion Zombie News
	ZeroReligionZombieNews.push_back(std::pair < const char*, int>("[����] ����� \"���� ������ ���� ��\"", 12));
	ZeroReligionZombieNews.push_back(std::pair < const char*, int>("[����] õ���� ��Ӱ� �Բ� ������...", 12));
	ZeroReligionZombieNews.push_back(std::pair < const char*, int>("[����] �� ���´� ���ߵ� ��...", 12));

	SmallReligionZombieNews.push_back(std::pair < const char*, int>("[����] ���� ��ȸ���� �������� ����..", 10));
	SmallReligionZombieNews.push_back(std::pair < const char*, int>("[����] ��õ����, ������ ū ���� ����..", 10));
	SmallReligionZombieNews.push_back(std::pair < const char*, int>("[����] ���� �ູ.. �θ� ���� ����..", 10));

	MediumReligionZombieNews.push_back(std::pair < const char*, int>("[����] �⵶�� ���մ�ü, ü���� ����", 10));
	MediumReligionZombieNews.push_back(std::pair < const char*, int>("[����] ��õ����, �θ���Ǽҷ� �", 10));
	MediumReligionZombieNews.push_back(std::pair < const char*, int>("[����] �������� �Ǵ� ������ ����", 10));

	LargeReligionZombieNews.push_back(std::pair < const char*, int>("[����] �̹� ������ ������ ������ü", 2));
	LargeReligionZombieNews.push_back(std::pair < const char*, int>("[����] �⵶����ü, �ž��� �ݾ� ���", 2));
	LargeReligionZombieNews.push_back(std::pair < const char*, int>("[����] �Ų��� �Բ��Ͻô�. ������ ����", 2));

	// Hospital Zombie News
	ZeroHospitalZombieNews.push_back(std::pair < const char*, int>("[����] �Ƿ� �ü� �ر�, �θ����� Ŀ...", 12));
	ZeroHospitalZombieNews.push_back(std::pair < const char*, int>("[����] ���ε��� ����, �Ƿ� �ü� ����", 12));
	ZeroHospitalZombieNews.push_back(std::pair < const char*, int>("[����] �Ƿ� ����, �ϻ��� �����", 12));

	HospitalZombieNews.push_back(std::pair < const char*, int>("[����] �Ƿ����� ���, �θ����� ����", 10));
	HospitalZombieNews.push_back(std::pair < const char*, int>("[����] ���󺸴� ���� ����, �Ƿ� ����", 10));
	HospitalZombieNews.push_back(std::pair < const char*, int>("[����] ������ �Ƿ� ��ȹ, ���ߴ�", 10));

	// APT Zombie News
	ZeroAPTZombieNews.push_back(std::pair < const char*, int>("[����] �ְŽü��� ����, ū �糭 �ҷ���", 12));
	ZeroAPTZombieNews.push_back(std::pair < const char*, int>("[����] �� ���� ����, ���δ� ������?", 12));
	ZeroAPTZombieNews.push_back(std::pair < const char*, int>("[����] ���� ���� ������ �״°� ����...", 12));

	APTZombieNews.push_back(std::pair < const char*, int>("[����] ����Ʈ ����, �����ߴ� ���ǰ���", 10));
	APTZombieNews.push_back(std::pair < const char*, int>("[����] �ǹ� �� ����, ���� �θ�����", 10));
	APTZombieNews.push_back(std::pair < const char*, int>("[����] ��κ� ���� ����Ʈ �� ����", 10));

	// Army Zombie News
	ZeroArmyZombieNews.push_back(std::pair < const char*, int>("[����] ������� ������ �ҷ��� ���...", 12));
	ZeroArmyZombieNews.push_back(std::pair < const char*, int>("[����] ������ ������ ��Ű�ڴ°�?", 12));
	ZeroArmyZombieNews.push_back(std::pair < const char*, int>("[����] ���񺸴� ���� ����", 12));

	SmallArmyZombieNews.push_back(std::pair < const char*, int>("[����] ���� �����ϱ� ������ ����", 10));
	SmallArmyZombieNews.push_back(std::pair < const char*, int>("[����] ������ ������ ���ѳ� ����", 10));
	SmallArmyZombieNews.push_back(std::pair < const char*, int>("[����] ������ ������ ������ ��", 10));

	MediumArmyZombieNews.push_back(std::pair < const char*, int>("[����] �����ߴ� ���ǰ���, ���ε� ����", 10));
	MediumArmyZombieNews.push_back(std::pair < const char*, int>("[����] ������� ������ �̹� ����", 10));
	MediumArmyZombieNews.push_back(std::pair < const char*, int>("[����] ������ ���� ����, ������ ��", 10));

	LargeArmyZombieNews.push_back(std::pair < const char*, int>("[����] ������ ��, �θ����� ���� ����", 2));
	LargeArmyZombieNews.push_back(std::pair < const char*, int>("[����] ������� ������ ���� ����", 2));
	LargeArmyZombieNews.push_back(std::pair < const char*, int>("[����] �ְ������, ���� �η��� �ʴ�", 2));
}

News::~News()
{
}
