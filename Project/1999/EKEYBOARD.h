#pragma once

enum EKEYBOARD
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

	KOREAN = 164,
};

enum EBUILDING
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

enum EMENU_SELECT
{
	CITIZEN = 0,
	ARMY = 7,
	RELIGION = 14,
	CONSTRUCT = 21
};

enum ESELECT_SCENE
{
	NEW_GAME = 0,
	TUTORIAL = 7,
	EXIT = 14
};

enum ENEWS_CATEGORY
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
	ReligionEndingNews
};