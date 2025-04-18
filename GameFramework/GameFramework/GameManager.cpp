#include "GameManager.h"

/// Game Init
void GameManager::Init() {
	__super::Init();

	// game scene 등록
}

/// Game Release
void GameManager::Release() {
	__super::Release();

	// override
}

/// 윈도우 프로시저 메시지 처리
void GameManager::MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	__super::MessageProc(hwnd, uMsg, wParam, lParam);

	// game에 활용할 message 처리
	switch (uMsg)
	{
	case WM_CREATE:
		break;
	}
}