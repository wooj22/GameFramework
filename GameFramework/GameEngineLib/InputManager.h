#pragma once
#include "Singleton.h"

class InputManager : public Singleton<InputManager>
{
private:
	HWND m_hWnd;			// ������ �ڵ�
	POINT m_mouseClient;	// ���콺 ��ǥ
	SHORT m_prevState[256] = { 0 };
	SHORT m_currState[256] = { 0 };

	InputManager() = default;
	~InputManager() override = default;

public:
	void Init(HWND hWnd);
	void Update();
	void Release() {};

	bool IsKeyDown(int vKey);
	bool IsKeyPressed(int vKey);
	bool IsKeyReleased(int vKey);

	friend class Singleton<InputManager>;
};