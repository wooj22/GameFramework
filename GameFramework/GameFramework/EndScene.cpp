#include "EndScene.h"
#include "GameManager.h"
#include "../GameEngineLib/framework.h"

/// Start
void EndScene::Start() {
	__super::Start();

	OutputDebugStringA("EndScene Start\n");

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