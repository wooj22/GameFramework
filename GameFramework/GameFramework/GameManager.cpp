#include "GameManager.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"

enum sceneName {
	Menu,
	Play,
	End
};

/// Game Init
void GameManager::Init() {
	__super::Init();

	// scene ���
	SceneManager::Get().CreateScene<MenuScene>();
	SceneManager::Get().CreateScene<PlayScene>();
	SceneManager::Get().CreateScene<EndScene>();
	SceneManager::Get().SetCurrentScene(Menu);
	SceneManager::Get().ChangeScene(Play);
	SceneManager::Get().ChangeScene(End);
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