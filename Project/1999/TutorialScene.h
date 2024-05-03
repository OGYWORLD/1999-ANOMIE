/* Ʃ�丮�� ȭ�� Ŭ���� */
#pragma once
#pragma region HeaderFiles
#include "PrintImage.h"
#include "SetPosition.h"
#include "Music.h"
#include <string>
#include <vector>
#include <queue>
#pragma endregion

class TutorialScene
{
private:
	PrintImage* print = new PrintImage;
	SetPosition* to = new SetPosition;
	Music* music = new Music;

	int ReturnMenu; // �޴� �÷���
	int index; // �ڸ� ��� �ε���
	int Page; // Ʃ�丮�� ������

	std::vector<const char*> Announce; // �ڸ�

public:
	TutorialScene();
	~TutorialScene();

	void PlayTutorial(); // Ʃ�丮�� ����

	void PrintIntro(); // Ʃ�丮�� ��Ʈ�� ���
	void PrintMenuTutorial(); // Ʃ�丮�� �޴�
	void PrintMenuInfo(); // Ʃ�丮�� - ������� ���� �κ� ���
	void PrintConstructInfo(); // Ʃ�丮�� - �Ǽ� �κ� ���
	void PrintPowerInfo(); // Ʃ�丮�� - �Ŀ� �κ� ���
	void PrintCategory(int p1, int p2, int p3); // Ʃ�丮�� ī���� ���

	int NextKey(); // ����� �Է� �ޱ�
	

	int SetAnnouncePosition(std::vector<const char*> s, int color); // �ڸ� �߾� ��ġ ���� �� ���


};

