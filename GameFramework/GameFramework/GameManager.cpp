#include "GameManager.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"

/// Game Init
void GameManager::Init() {
	__super::Init();

	// scene 등록
	SceneManager::Get().CreateScene<MenuScene>();
	SceneManager::Get().CreateScene<PlayScene>();
	SceneManager::Get().CreateScene<EndScene>();
	SceneManager::Get().SetCurrentScene(MENU);
	SceneManager::Get().GetCurrentScene()->Start();
}

/// Game Release
void GameManager::Release() {
	__super::Release();
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