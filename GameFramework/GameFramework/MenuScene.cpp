#include "MenuScene.h"
#include "../GameEngineLib/framework.h"

/// Start
void MenuScene::Start() {
	__super::Start();

	OutputDebugStringA("MenuScene Start\n");
}

/// Update
void MenuScene::Update() {
	__super::Update();

	OutputDebugStringA("MenuScene Update\n");
}

/// Render
void MenuScene::Render() {
	__super::Render();

	OutputDebugStringA("MenuScene Render\n");
}

/// Exit
void MenuScene::Exit() {
	__super::Exit();

	OutputDebugStringA("MenuScene Exit\n");
}