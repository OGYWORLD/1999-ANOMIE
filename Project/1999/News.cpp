#include "News.h"

News::News()
{
	// Citizen
	CitizenLittleForceNews.push_back(std::pair < const char*, int>("[국민] \"차라리 좀비가 나아...\"", 12));
	CitizenLittleForceNews.push_back(std::pair < const char*, int>("[국민] \"라면도 비싸요.\" 흔들리...", 12));
	CitizenLittleForceNews.push_back(std::pair < const char*, int>("[국민] 대통령 혼자사는 국가? ", 12));

	CitizenManyForceNews.push_back(std::pair <const char*, int>("[국민] 극한으로 치닫는 경제", 12));
	CitizenManyForceNews.push_back(std::pair < const char*, int>("[국민] 사나마나 똑같다", 12));
	CitizenManyForceNews.push_back(std::pair < const char*, int>("[국민] 역대 생각없는 정부?", 12));

	CitizenWelfareNews.push_back(std::pair < const char*, int>("[국민] 대통령 \"나는 국민의 것\"", 10));
	CitizenWelfareNews.push_back(std::pair < const char*, int>("[국민] 활기를 보이는 민심", 10));
	CitizenWelfareNews.push_back(std::pair < const char*, int>("[국민] 어려워도 일어나는 국민", 10));

	// Army
	ArmyForceNews.push_back(std::pair < const char*, int>("[국방] 이 시국에 군인 월급감소?", 12));
	ArmyForceNews.push_back(std::pair < const char*, int>("[국방] 조국은 날 향해있는가?", 12));
	ArmyForceNews.push_back(std::pair < const char*, int>("[국방] 무너져내리는 국방", 12));

	ArmyPropagandaGoodNews.push_back(std::pair < const char*, int>("[국방] 위대한 조국, 위대한 군인", 9));
	ArmyPropagandaGoodNews.push_back(std::pair < const char*, int>("[국방] 죽더라도 조국을 위해", 9));
	ArmyPropagandaGoodNews.push_back(std::pair < const char*, int>("[국방] 조국의 얼굴은 국방", 9));

	ArmyPropagandaBadNews.push_back(std::pair < const char*, int>("[국방] 지금이 60년대? 선전논란", 12));
	ArmyPropagandaBadNews.push_back(std::pair < const char*, int>("[국방] 의심스러운 국방 교육", 12));
	ArmyPropagandaBadNews.push_back(std::pair < const char*, int>("[국방] 군인이 멍청하다고 생각하는가?", 12));

	ArmyWelfareNews.push_back(std::pair < const char*, int>("[국방] 국방부 예산 확대. 조국 대통령", 10));
	ArmyWelfareNews.push_back(std::pair < const char*, int>("[국방] 국방부 예산 확대. 최고의 국방", 10));
	ArmyWelfareNews.push_back(std::pair < const char*, int>("[국방] 국방부 예산 확대. 희망 대통령", 10));

	// Religion
	ReligionProhibitCitizenNews.push_back(std::pair < const char*, int>("[종교] 대통령 \"실체를 믿어라\"", 12));
	ReligionProhibitCitizenNews.push_back(std::pair < const char*, int>("[종교] 국민종교활동금지, 서로 믿어라.", 12));
	ReligionProhibitCitizenNews.push_back(std::pair < const char*, int>("[종교] 기적은 국민이... 종교활동금지", 12));

	ReligionProhibitArmyNews.push_back(std::pair < const char*, int>("[종교] 신보다 국가를... 종교활동금지", 12));
	ReligionProhibitArmyNews.push_back(std::pair < const char*, int>("[종교] 국인은 조국을... 종교활동금지", 12));
	ReligionProhibitArmyNews.push_back(std::pair < const char*, int>("[종교] 조국을 신처럼... 종교활동금지", 12));

	ParticiateReligionNews.push_back(std::pair < const char*, int>("[종교] 대통령 \"신께서 함께 하시길\"", 11));
	ParticiateReligionNews.push_back(std::pair < const char*, int>("[종교] 대통령 종교행사 참가...", 11));
	ParticiateReligionNews.push_back(std::pair < const char*, int>("[종교] 대통령 명동 대예배 참여...", 11));

	// Religion Zombie News
	ZeroReligionZombieNews.push_back(std::pair < const char*, int>("[종교] 강목사 \"신이 국가를 버린 것\"", 12));
	ZeroReligionZombieNews.push_back(std::pair < const char*, int>("[종교] 천벌은 재앙과 함께 오듯이...", 12));
	ZeroReligionZombieNews.push_back(std::pair < const char*, int>("[종교] 이 사태는 예견된 것...", 12));

	SmallReligionZombieNews.push_back(std::pair < const char*, int>("[종교] 대전 교회에서 좀비진압 나서..", 10));
	SmallReligionZombieNews.push_back(std::pair < const char*, int>("[종교] 춘천성당, 작지만 큰 피해 막아..", 10));
	SmallReligionZombieNews.push_back(std::pair < const char*, int>("[종교] 신의 축복.. 인명 피해 적어..", 10));

	MediumReligionZombieNews.push_back(std::pair < const char*, int>("[종교] 기독교 연합단체, 체계적 진압", 10));
	MediumReligionZombieNews.push_back(std::pair < const char*, int>("[종교] 부천성당, 인명대피소로 운영", 10));
	MediumReligionZombieNews.push_back(std::pair < const char*, int>("[종교] 생각보다 컸던 종교의 도움", 10));

	LargeReligionZombieNews.push_back(std::pair < const char*, int>("[종교] 이번 습격의 영웅은 종교단체", 2));
	LargeReligionZombieNews.push_back(std::pair < const char*, int>("[종교] 기독교단체, 거액의 금액 기부", 2));
	LargeReligionZombieNews.push_back(std::pair < const char*, int>("[종교] 신께서 함께하시다. 구원의 국가", 2));

	// Hospital Zombie News
	ZeroHospitalZombieNews.push_back(std::pair < const char*, int>("[국민] 의료 시설 붕괴, 인명피해 커...", 12));
	ZeroHospitalZombieNews.push_back(std::pair < const char*, int>("[국민] 국민들의 절규, 의료 시설 위급", 12));
	ZeroHospitalZombieNews.push_back(std::pair < const char*, int>("[국민] 의료 부재, 일상이 좀비밭", 12));

	HospitalZombieNews.push_back(std::pair < const char*, int>("[국민] 의료진의 희생, 인명피해 적어", 10));
	HospitalZombieNews.push_back(std::pair < const char*, int>("[국민] 예상보다 적은 피해, 의료 덕분", 10));
	HospitalZombieNews.push_back(std::pair < const char*, int>("[국민] 정부의 의료 계획, 통했다", 10));

	// APT Zombie News
	ZeroAPTZombieNews.push_back(std::pair < const char*, int>("[국민] 주거시설의 부재, 큰 재난 불렀다", 12));
	ZeroAPTZombieNews.push_back(std::pair < const char*, int>("[국민] 집 조차 없다, 정부는 제정신?", 12));
	ZeroAPTZombieNews.push_back(std::pair < const char*, int>("[국민] 집도 없고 어차피 죽는게 나아...", 12));

	APTZombieNews.push_back(std::pair < const char*, int>("[국민] 아파트 대피, 수월했던 대피과정", 10));
	APTZombieNews.push_back(std::pair < const char*, int>("[국민] 건물 내 대피, 적은 인명피해", 10));
	APTZombieNews.push_back(std::pair < const char*, int>("[국민] 대부분 국민 아파트 내 대피", 10));

	// Army Zombie News
	ZeroArmyZombieNews.push_back(std::pair < const char*, int>("[국방] 국방없는 국가가 불러온 재앙...", 12));
	ZeroArmyZombieNews.push_back(std::pair < const char*, int>("[국방] 무엇이 국민을 지키겠는가?", 12));
	ZeroArmyZombieNews.push_back(std::pair < const char*, int>("[국방] 좀비보다 못한 정부", 12));

	SmallArmyZombieNews.push_back(std::pair < const char*, int>("[국방] 빛을 발휘하기 시작한 국방", 10));
	SmallArmyZombieNews.push_back(std::pair < const char*, int>("[국방] 작지만 국방이 지켜낸 국민", 10));
	SmallArmyZombieNews.push_back(std::pair < const char*, int>("[국방] 작지만 보여준 국방의 힘", 10));

	MediumArmyZombieNews.push_back(std::pair < const char*, int>("[국방] 수월했던 대피과정, 군인들 덕분", 10));
	MediumArmyZombieNews.push_back(std::pair < const char*, int>("[국방] 군사들이 빛났던 이번 사태", 10));
	MediumArmyZombieNews.push_back(std::pair < const char*, int>("[국방] 수월한 좀비 진압, 국방의 힘", 10));

	LargeArmyZombieNews.push_back(std::pair < const char*, int>("[국방] 강인한 군, 인명피해 거의 없어", 2));
	LargeArmyZombieNews.push_back(std::pair < const char*, int>("[국방] 군사력이 보여준 강한 국가", 2));
	LargeArmyZombieNews.push_back(std::pair < const char*, int>("[국방] 최강국방부, 좀비가 두렵지 않다", 2));
}

News::~News()
{
}
