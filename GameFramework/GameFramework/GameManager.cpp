#include "GameManager.h"

/// Game Init
void GameManager::Init() {
	__super::Init();

	// game scene ���
}

/// Game Release
void GameManager::Release() {
	__super::Release();

	// override
}

/// ������ ���ν��� �޽��� ó��
void GameManager::MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	__super::MessageProc(hwnd, uMsg, wParam, lParam);

	// game�� Ȱ���� message ó��
	switch (uMsg)
	{
	case WM_CREATE:
		break;
	}
}