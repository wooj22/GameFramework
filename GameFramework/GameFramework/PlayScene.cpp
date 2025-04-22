#include "PlayScene.h"
#include "Player.h"
#include "../GameEngineLib/framework.h"

/// Start
void PlayScene::Start() {
	OutputDebugStringA("PlayScene Start\n");
	Player* player = (Player*)CreateObject<Player>();

	__super::Start();
}

// ������ �ӽú��� - �÷��̾� 10�� ���� �� �ڵ� ��ȯ
float sceneChangeTime = 30.0f;
float sceneChangeTimer = 0.0f;

/// Update
void PlayScene::Update() {
	__super::Update();
	sceneChangeTimer += TimeManager::Get().GetDeltaTime();
	if (sceneChangeTimer > sceneChangeTime) {
		SceneManager::Get().ChangeScene(GameManager::END);
		sceneChangeTimer = 0;
	}
}

/// Render
void PlayScene::Render() {
	__super::Render();
}

/// Exit
void PlayScene::Exit() {
	__super::Exit();

	OutputDebugStringA("PlayScene Exit\n");
}