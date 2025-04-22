#pragma once
#include "../GameEngineLib/framework.h"
#include "../GameEngineLib/WinGameApp.h"
#include "../GameEngineLib/SceneManager.h"

class GameManager : public WinGameApp
{
public:
	int playerKillCount = 0;
	enum sceneName { MENU, PLAY, END };

	GameManager(int inputWidth = 1920, int inputHeight = 1080) : 
		WinGameApp(inputWidth, inputHeight) {};
	~GameManager() override = default;

	void Init() override;
	// update() : WinGameApp class���� currentScene�� Objects update, render ȣ����
	void Release() override;
	void MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
};

