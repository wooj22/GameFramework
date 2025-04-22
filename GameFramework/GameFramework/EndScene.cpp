#include "EndScene.h"
#include "GameManager.h"
#include "GameData.h"
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
	RenderManager::Get().DrawTextW(L"[End Scene] Pressed Spacebar >> Exit", 50, 50);
	RenderManager::Get().DrawTextS("Player Kill Count : " + to_string(GameData::Get().playerKillCount), 50, 100);
}

/// Exit
void EndScene::Exit() {
	__super::Exit();

}