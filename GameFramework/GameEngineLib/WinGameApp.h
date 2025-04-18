#pragma once
#include "InputManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "SoundManager.h"
#include "RenderManager.h"
#include "Singleton.h"
using namespace std;

class WinGameApp : public Singleton<WinGameApp>
{
private:
	// window
	HINSTANCE		hInstance;
	int				width = 1024;
	int				height = 768;
	wstring			winClassName = L"WinGameAppClass";
	wstring			titleName = L"Default Title Name";
	string			modulePath;
	string			workingPath;
	HWND			hWnd;

	// managers
	InputManager    inputManager;
	TimeManager     timeManager;
	SoundManager    soundManager;
	RenderManager   renderManager;
	SceneManager    sceneManager;

	void Update();
	void Render();

public:
	WinGameApp() = default;
	virtual ~WinGameApp() = default;

	virtual void Init();
	void Run();
	virtual void Release();
	virtual void MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

