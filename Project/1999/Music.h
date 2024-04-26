#pragma once

#include <windows.h>
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>;

class Music
{
private:

public:
	Music();
	~Music();

	//BGM
	void PlayMusicPrayer();
	void PlayerMusicIzanami();
	void PlayerMusicIzanami2();
	void PlayerMusicInfini();
	void PlayerMusicDaedulus();
	void PlayerMusicMazurka();
 
};

