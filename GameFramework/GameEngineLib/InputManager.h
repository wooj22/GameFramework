#pragma once
#include "Singleton.h"
#include "Windows.h"

class InputManager : public Singleton<InputManager>
{
private:
	InputManager() = default;
	~InputManager() = default;

	HWND m_hWnd;			// 윈도우 핸들
	POINT m_mouseClient;	// 마우스 좌표
	SHORT m_prevState[256] = { 0 };
	SHORT m_currState[256] = { 0 };

public:
	void Init(HWND hWnd);
	void Update();
	void Release() {};

	bool IsKeyDown(int vKey);
	bool IsKeyPressed(int vKey);
	bool IsKeyReleased(int vKey);

	friend class Singleton<InputManager>;
};