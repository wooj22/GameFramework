#include "MenuScene.h"
#include "GameManager.h"
#include "../GameEngineLib/framework.h"

/// Start
void MenuScene::Start() {
	__super::Start();

	OutputDebugStringA("MenuScene Start\n");
}

/// Update
void MenuScene::Update() {
	__super::Update();

	if (InputManager::Get().IsKeyPressed(VK_SPACE))
		SceneManager::Get().ChangeScene(GameManager::PLAY);
}

/// Render
void MenuScene::Render() {
	__super::Render();

}

/// Exit
void MenuScene::Exit() {
	__super::Exit();

	OutputDebugStringA("MenuScene Exit\n");
}