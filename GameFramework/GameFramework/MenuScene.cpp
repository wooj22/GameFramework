#include "MenuScene.h"
#include "GameManager.h"
#include "../GameEngineLib/framework.h"

/// Start
void MenuScene::Start() {
	OutputDebugStringA("MenuScene Start\n");

	__super::Start();
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