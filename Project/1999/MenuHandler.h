/* 인게임 메뉴창을 출력하는 클래스*/
#pragma once
#include "PrintImage.h"
#include "Music.h"

class InfoHandler;

class MenuHandler : public PrintImage
{
private:
	Music* music = new Music;

public:
	MenuHandler();
	~MenuHandler();


	// Default Menu
	int ShowDefaultMenu(int OriginX, int OriginY, int BetweenY);

	// Construct Menu
	void ShowConstructMenu1();
	void ShowConstructMenu2();

	// Citizen Menu
	void ShowCitizenMenu();

	// Army Menu
	void ShowArmyMenu();

	// Religion Menu
	void ShowReligionMenu();
	

};

