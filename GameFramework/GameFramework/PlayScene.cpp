#include "PlayScene.h"
#include "Player.h"
#include "../GameEngineLib/framework.h"

/// Start
void PlayScene::Start() {
	__super::Start();

	OutputDebugStringA("PlayScene Start\n");

	// 플레이어 만들고 맵 사이즈 전달하기
	// 윈게임앱에 Get, Set 만들고 그거 아래 넣기
	//Player* player = (Player*)CreateObject<Player>();
	
}

// 과제용 임시변수
float sceneChangeTime = 10.0f;
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