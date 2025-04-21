#pragma once
#include "../GameEngineLib/framework.h"
#include "../GameEngineLib/WinGameApp.h"
#include "../GameEngineLib/SceneManager.h"

class GameManager : public WinGameApp
{
public:
	GameManager() = default;
	~GameManager() override = default;

	void Init() override;
	// update() : WinGameApp class에서 currentScene의 Objects update, render 호출중
	void Release() override;
	void MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
};

