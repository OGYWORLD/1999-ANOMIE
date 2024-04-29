/* 배경음악 및 효과음 재생 클래스*/
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


#pragma region BackGroundMusic
	void PlayMusicPrayer();
	void PlayMusicIzanami();
	void PlayMusicIzanami2();
	void PlayMusicInfini();
	void PlayMusicDaedulus();
	void PlayMusicMazurka();
	void PlayMusicXenial();
#pragma endregion


#pragma region SoundEffect
	void PlayZombieSiren();
	void PlayZombieNews();
	void PlayBigClick();
	void PlayMoveBeep();
	void PlayFinish();
	void PlayBuildSound();
	void PlayDestroySound();
	void PlayProhibitSound();
#pragma endregion
 
};

