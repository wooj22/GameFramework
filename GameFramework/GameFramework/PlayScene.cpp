#include "PlayScene.h"
#include "Player.h"
#include "../GameEngineLib/framework.h"

/// Start
void PlayScene::Start() {
	__super::Start();

	OutputDebugStringA("PlayScene Start\n");
}

/// Update
void PlayScene::Update() {
	__super::Update();

	OutputDebugStringA("PlayScene Update\n");
}

/// Render
void PlayScene::Render() {
	__super::Render();

	OutputDebugStringA("PlayScene Render\n");
}

/// Exit
void PlayScene::Exit() {
	__super::Exit();

	OutputDebugStringA("PlayScene Exit\n");
}