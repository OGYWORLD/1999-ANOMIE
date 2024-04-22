#pragma once
#include "PrintImage.h"

class InfoHandler;

class MenuHandler : public PrintImage
{
private:
	int PlayerInput;

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

	// Zombie Menu
	

};

