#include "Music.h"

Music::Music()
{
}

Music::~Music()
{
}

void Music::PlayMusicPrayer()
{
	PlaySound(TEXT("./Music/Prayer.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void Music::PlayMusicIzanami()
{
	PlaySound(TEXT("./Music/Izanami.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void Music::PlayMusicIzanami2()
{
	PlaySound(TEXT("./Music/Izanami2.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void Music::PlayMusicInfini()
{
	PlaySound(TEXT("./Music/Infini.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void Music::PlayMusicDaedulus()
{
	PlaySound(TEXT("./Music/Daedulus.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void Music::PlayMusicMazurka()
{
	PlaySound(TEXT("./Music/Mazurka.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void Music::PlayMusicXenial()
{
	PlaySound(TEXT("./Music/Xenial.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void Music::PlayZombieSiren()
{
	PlaySound(TEXT("./Music/ZombieSiren.wav"), NULL, SND_ASYNC);
}

void Music::PlayZombieNews()
{
	PlaySound(TEXT("./Music/ZombieNews.wav"), NULL, SND_ASYNC);
}

void Music::PlayBigClick()
{
	MCI_OPEN_PARMS OpenBigClick;
	MCI_PLAY_PARMS PlayBigClick;

	int dwID_BigClick;

	OpenBigClick.lpstrElementName = L"./Music/BigClick.mp3";
	OpenBigClick.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&OpenBigClick);
	dwID_BigClick = OpenBigClick.wDeviceID;
	mciSendCommand(dwID_BigClick, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&OpenBigClick);
	Sleep(250);
	mciSendCommandW(dwID_BigClick, MCI_CLOSE, 0, (DWORD)NULL);
}

void Music::PlayMoveBeep()
{
	MCI_OPEN_PARMS OpenMoveBeep;
	MCI_PLAY_PARMS PlayMoveBeep;

	int dwID_MoveBeep;

	OpenMoveBeep.lpstrElementName = L"./Music/MoveBeep.mp3";
	OpenMoveBeep.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&OpenMoveBeep);
	dwID_MoveBeep = OpenMoveBeep.wDeviceID;
	mciSendCommand(dwID_MoveBeep, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&OpenMoveBeep);
	Sleep(180);
	mciSendCommandW(dwID_MoveBeep, MCI_CLOSE, 0, (DWORD)NULL);
}

void Music::PlayFinish()
{
	MCI_OPEN_PARMS OpenFinish;
	MCI_PLAY_PARMS PlayFinish;

	int dwID_Finish;

	OpenFinish.lpstrElementName = L"./Music/Finish.mp3";
	OpenFinish.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&OpenFinish);
	dwID_Finish = OpenFinish.wDeviceID;
	mciSendCommand(dwID_Finish, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&OpenFinish);
	Sleep(470);
	mciSendCommandW(dwID_Finish, MCI_CLOSE, 0, (DWORD)NULL);
}

void Music::PlayBuildSound()
{
	MCI_OPEN_PARMS OpenBuildSound;
	MCI_PLAY_PARMS PlayBuildSound;

	int dwID_BuildSound;

	OpenBuildSound.lpstrElementName = L"./Music/BuildSound.mp3";
	OpenBuildSound.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&OpenBuildSound);
	dwID_BuildSound = OpenBuildSound.wDeviceID;
	mciSendCommand(dwID_BuildSound, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&OpenBuildSound);
	Sleep(200);
	mciSendCommandW(dwID_BuildSound, MCI_CLOSE, 0, (DWORD)NULL);
}

void Music::PlayDestroySound()
{
	MCI_OPEN_PARMS OpenDestroySound;
	MCI_PLAY_PARMS PlayDestroySound;

	int dwID_DestroySound;

	OpenDestroySound.lpstrElementName = L"./Music/DestroySound.mp3";
	OpenDestroySound.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&OpenDestroySound);
	dwID_DestroySound = OpenDestroySound.wDeviceID;
	mciSendCommand(dwID_DestroySound, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&OpenDestroySound);
	Sleep(250);
	mciSendCommandW(dwID_DestroySound, MCI_CLOSE, 0, (DWORD)NULL);
}

void Music::PlayProhibitSound()
{
	MCI_OPEN_PARMS OpenProhibitSound;
	MCI_PLAY_PARMS PlayProhibitSound;

	int dwID_ProhibitSound;

	OpenProhibitSound.lpstrElementName = L"./Music/Prohibit.mp3";
	OpenProhibitSound.lpstrDeviceType = L"mpegvideo";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&OpenProhibitSound);
	dwID_ProhibitSound = OpenProhibitSound.wDeviceID;
	mciSendCommand(dwID_ProhibitSound, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&OpenProhibitSound);
	Sleep(400);
	mciSendCommandW(dwID_ProhibitSound, MCI_CLOSE, 0, (DWORD)NULL);
}
