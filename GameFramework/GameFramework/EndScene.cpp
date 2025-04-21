#include "EndScene.h"
#include "GameManager.h"
#include "../GameEngineLib/framework.h"

/// Start
void EndScene::Start() {
	OutputDebugStringA("EndScene Start\n");

	__super::Start();
}

/// Update
void EndScene::Update() {
	__super::Update();

	if (InputManager::Get().IsKeyPressed(VK_SPACE))
		GameManager::Get().isLoop = false;
}

/// Render
void EndScene::Render() {
	__super::Render();

}

/// Exit
void EndScene::Exit() {
	__super::Exit();

}