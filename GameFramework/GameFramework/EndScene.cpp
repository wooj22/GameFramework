#include "EndScene.h"
#include "../GameEngineLib/framework.h"

/// Start
void EndScene::Start() {
	__super::Start();

	OutputDebugStringA("EndScene Start\n");

}

/// Update
void EndScene::Update() {
	__super::Update();

	OutputDebugStringA("EndScene Update\n");
}

/// Render
void EndScene::Render() {
	__super::Render();

	OutputDebugStringA("EndScene Render\n");
}

/// Exit
void EndScene::Exit() {
	__super::Exit();

	OutputDebugStringA("EndScene Exit\n");
}