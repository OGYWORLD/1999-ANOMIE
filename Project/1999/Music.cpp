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

void Music::PlayerMusicIzanami()
{
	PlaySound(TEXT("./Music/Izanami.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void Music::PlayerMusicIzanami2()
{
	PlaySound(TEXT("./Music/Izanami2.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void Music::PlayerMusicInfini()
{
	PlaySound(TEXT("./Music/Infini.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void Music::PlayerMusicDaedulus()
{
	PlaySound(TEXT("./Music/Daedulus.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void Music::PlayerMusicMazurka()
{
	PlaySound(TEXT("./Music/Mazurka.wav"), NULL, SND_ASYNC | SND_LOOP);
}
