#include "GameManager.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"

/// Game Init
void GameManager::Init() {
	__super::Init();

	// scene ���
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