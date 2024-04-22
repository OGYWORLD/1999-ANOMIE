#include "News.h"

News::News()
{
	// Citizen
	CitizenLittleForceNews.push_back("[국민] \"차라리 좀비가 나아...\"");
	CitizenLittleForceNews.push_back("[국민] \"라면도 비싸요.\" 흔들리...");
	CitizenLittleForceNews.push_back("[국민] 대통령 혼자사는 국가? ");

	CitizenManyForceNews.push_back("[국민] 극한으로 치닫는 경제");
	CitizenManyForceNews.push_back("[국민] 사나마나 똑같다");
	CitizenManyForceNews.push_back("[국민] 역대 생각없는 정부?");

	CitizenWelfareNews.push_back("[국민] 대통령 \"나는 국민의 것\"");
	CitizenWelfareNews.push_back("[국민] 활기를 보이는 민심");
	CitizenWelfareNews.push_back("[국민] 어려워도 일어나는 국민");

	// Army
	ArmyForceNews.push_back("[국방] 이 시국에 군인 월급감소?");
	ArmyForceNews.push_back("[국방] 조국은 날 향해있는가?");
	ArmyForceNews.push_back("[국방] 무너져내리는 국방");

	ArmyPropagandaGoodNews.push_back("[국방] 위대한 조국, 위대한 군인");
	ArmyPropagandaGoodNews.push_back("[국방] 죽더라도 조국을 위해");
	ArmyPropagandaGoodNews.push_back("[국방] 조국의 얼굴은 국방");

	ArmyPropagandaBadNews.push_back("[국방] 지금이 60년대? 선전논란");
	ArmyPropagandaBadNews.push_back("[국방] 의심스러운 국방 교육");
	ArmyPropagandaBadNews.push_back("[국방] 군인이 멍청하다고 생각하는가?");

	ArmyWelfareNews.push_back("[국방] 국방부 예산 확대. 조국 대통령");
	ArmyWelfareNews.push_back("[국방] 국방부 예산 확대. 최고의 국방");
	ArmyWelfareNews.push_back("[국방] 국방부 예산 확대. 희망 대통령");

	// Religion
	ReligionProhibitCitizenNews.push_back("[종교] 대통령 \"실체를 믿어라\"");
	ReligionProhibitCitizenNews.push_back("[종교] 국민종교활동금지, 서로 믿어라.");
	ReligionProhibitCitizenNews.push_back("[종교] 기적은 국민이... 종교활동금지");

	ReligionProhibitArmyNews.push_back("[종교] 신보다 국가를... 종교활동금지");
	ReligionProhibitArmyNews.push_back("[종교] 국인은 조국을... 종교활동금지");
	ReligionProhibitArmyNews.push_back("[종교] 조국을 신처럼... 종교활동금지");

	ParticiateReligionNews.push_back("[종교] 대통령 \"신께서 함께 하시길\"");
	ParticiateReligionNews.push_back("[종교] 대통령 종교행사 참가...");
	ParticiateReligionNews.push_back("[종교] 대통령 명동 대예배 참여...");
}

News::~News()
{
}
