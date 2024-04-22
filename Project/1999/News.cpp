#include "News.h"

News::News()
{
	// Citizen
	CitizenLittleForceNews.push_back("[����] \"���� ���� ����...\"");
	CitizenLittleForceNews.push_back("[����] \"��鵵 ��ο�.\" ��鸮...");
	CitizenLittleForceNews.push_back("[����] ����� ȥ�ڻ�� ����? ");

	CitizenManyForceNews.push_back("[����] �������� ġ�ݴ� ����");
	CitizenManyForceNews.push_back("[����] �糪���� �Ȱ���");
	CitizenManyForceNews.push_back("[����] ���� �������� ����?");

	CitizenWelfareNews.push_back("[����] ����� \"���� ������ ��\"");
	CitizenWelfareNews.push_back("[����] Ȱ�⸦ ���̴� �ν�");
	CitizenWelfareNews.push_back("[����] ������� �Ͼ�� ����");

	// Army
	ArmyForceNews.push_back("[����] �� �ñ��� ���� ���ް���?");
	ArmyForceNews.push_back("[����] ������ �� �����ִ°�?");
	ArmyForceNews.push_back("[����] ������������ ����");

	ArmyPropagandaGoodNews.push_back("[����] ������ ����, ������ ����");
	ArmyPropagandaGoodNews.push_back("[����] �״��� ������ ����");
	ArmyPropagandaGoodNews.push_back("[����] ������ ���� ����");

	ArmyPropagandaBadNews.push_back("[����] ������ 60���? �������");
	ArmyPropagandaBadNews.push_back("[����] �ǽɽ����� ���� ����");
	ArmyPropagandaBadNews.push_back("[����] ������ ��û�ϴٰ� �����ϴ°�?");

	ArmyWelfareNews.push_back("[����] ����� ���� Ȯ��. ���� �����");
	ArmyWelfareNews.push_back("[����] ����� ���� Ȯ��. �ְ��� ����");
	ArmyWelfareNews.push_back("[����] ����� ���� Ȯ��. ��� �����");

	// Religion
	ReligionProhibitCitizenNews.push_back("[����] ����� \"��ü�� �Ͼ��\"");
	ReligionProhibitCitizenNews.push_back("[����] ��������Ȱ������, ���� �Ͼ��.");
	ReligionProhibitCitizenNews.push_back("[����] ������ ������... ����Ȱ������");

	ReligionProhibitArmyNews.push_back("[����] �ź��� ������... ����Ȱ������");
	ReligionProhibitArmyNews.push_back("[����] ������ ������... ����Ȱ������");
	ReligionProhibitArmyNews.push_back("[����] ������ ��ó��... ����Ȱ������");

	ParticiateReligionNews.push_back("[����] ����� \"�Ų��� �Բ� �Ͻñ�\"");
	ParticiateReligionNews.push_back("[����] ����� ������� ����...");
	ParticiateReligionNews.push_back("[����] ����� �� �뿹�� ����...");
}

News::~News()
{
}
