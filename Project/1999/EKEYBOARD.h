/* 키보드 입력 및 건물 번호, 엔딩 구분 enum 선언 클래스*/
#pragma once

enum EKEYBOARD // 키보드 입력
{
	DIRECTION = 224,
	KEY_UP = 72,
	KEY_DOWN = 80,
	KEY_LEFT = 75,
	KEY_RIGHT = 77,
	SPACE = 32,
	Z_KEY = 122,
	V_KEY = 118,
	M_KEY = 109,
	C_KEY = 99,
	P_KEY = 112,
	NUM1_KEY = 49, // Hospital
	NUM2_KEY = 50, // ArmySmall
	NUM3_KEY = 51, // APT
	NUM4_KEY = 52, // ArmyMedium
	NUM5_KEY = 53, // Church
	NUM6_KEY = 54, // Cathedral
	NUM7_KEY = 55, // Park
	NUM8_KEY = 56, // ArmyLarge
	RELIGION_42B_KEY = 57,

	KOREAN = 164,
};

enum EBUILDING // 건물 번호
{
	HOSPITAL = 49,
	ARMY_SAMLL = 50,
	APT = 51,
	ARMY_MEDIUM = 52,
	CHURCH = 53,
	CATHEDRAL = 54,
	PARK = 55,
	ARMY_LARGE = 56
};

enum EMENU_SELECT // 인게임 메뉴 선택(y축값)
{
	CITIZEN = 0,
	ARMY = 7,
	RELIGION = 14,
	CONSTRUCT = 21
};

enum ESELECT_SCENE // 선택화면 및 엔딩 종류
{
	NEW_GAME = 0,
	TUTORIAL = 7,
	EXIT = 14,
	CITIZEN_ENDING = 1,
	ARMY_ENDING = 2,
	RELIGION_ENDING = 3,
	ALLDIE_ENDING = 4
};

enum ENEWS_CATEGORY // 뉴스탭의 뉴스 카테고리
{
	CitizenLittleForceNews,
	CitizenManyForceNews,
	CitizenWelfareNews,
	ArmyForceNews,
	ArmyPropagandaGoodNews,
	ArmyPropagandaBadNews,
	ArmyWelfareNews,
	ReligionProhibitCitizenNews,
	ReligionProhibitArmyNews,
	ParticiateReligionNews,
	CitizenEndingNews,
	ArmyEndingNews,
	ReligionEndingNews,
	ZeroReligionZombieNews,
	SmallReligionZombieNews,
	MediumReligionZombieNews,
	LargeReligionZombieNews,
	ZeroHospitalZombieNews,
	HospitalZombieNews,
	ZeroAPTZombieNews,
	APTZombieNews,
	ParkZombieNews,
	ZeroArmyZombieNews,
	SmallArmyZombieNews,
	MediumArmyZombieNews,
	LargeArmyZombieNews,
	ReligionPay,
	ReligionNotPay,
	AfterZombieGood,
	AfterZombieBad,
	PunishmentFromGod,
	ZombieAppear,
	Maker42B
};

enum ECOUNT // 엔딩에 출력할 변수를 배열로 관리하기 위한 인덱스로 사용될 enum
{
	DAYCOUNT,
	CITIZEN_L_FORCE_CNT,
	CITIZEN_M_FORCE_CNT,
	CITIZEN_WALFARE_CNT,
	ARMY_FORCE_CNT,
	ARMY_PROPAGANDA_CNT,
	ARMY_WELFARE_CNT,
	PROHIBIT_R_C_CNT,
	PROHIBIT_R_A_CNT,
	RELIGION_WELFARE_CNT,
	ZOMBIE_ATTACK_CNT,
	ZOMBIE_DESTROY_CNT,
	SAFE_ZOMBIE_CNT,
	NONSAFE_ZOMBIE_CNT
};

enum EMUSIC // 인게임 음악 재생 중복을 위한 enum
{
	INFINI,
	DAEDULUS
};