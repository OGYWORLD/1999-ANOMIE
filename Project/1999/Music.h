#pragma once

#include <windows.h>
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>
#include <Digitalv.h>   

class Music
{
private:

public:
	Music();
	~Music();


	//BGM
	void PlayMusicPrayer();
	void PlayMusicIzanami();
	void PlayMusicIzanami2();
	void PlayMusicInfini();
	void PlayMusicDaedulus();
	void PlayMusicMazurka();
	void PlayMusicXenial();

	// SoundEffect
	void PlayZombieSiren();
	void PlayZombieNews();
	void PlayBigClick();
	void PlayMoveBeep();
	void PlayFinish();
	void PlayBuildSound();
	void PlayDestroySound();
	void PlayProhibitSound();
 
};

