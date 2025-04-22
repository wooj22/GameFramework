#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "GameData.h"
#include "../GameEngineLib/framework.h"

// 과제용
Player* player;
vector<Enemy*> enemyList;
float sceneChangeTime = 10.0f;
float sceneChangeTimer = 0.0f;

/// Start
void PlayScene::Start() {
	OutputDebugStringA("PlayScene Start\n");

	// object create
	player = (Player*)CreateObject<Player>();
	for (int i = 0; i < 50; i++) 
		enemyList.push_back((Enemy*)CreateObject<Enemy>());
	
	__super::Start();
}

/// Update
void PlayScene::Update() {
	__super::Update();

	// collision cheak
	for (auto enemy = enemyList.begin(); enemy != enemyList.end(); ) {
		if (player->isAABBCollision((*enemy)->position, (*enemy)->h_width, (*enemy)->h_height)) {
			// enemy 제거
			// 1. 제거할 enemy를 scene의 objectList에서 제거한다.
			DeleteObject(*enemy);
			
			// 2. enemy를 delete한다.
			delete (*enemy);
			enemy = enemyList.erase(enemy);

			player->Kill();
		}
		else {
			++enemy;
		}
	}

	// scene change
	sceneChangeTimer += TimeManager::Get().GetDeltaTime();
	if (sceneChangeTimer > sceneChangeTime) {
		SceneManager::Get().ChangeScene(GameManager::END);
		sceneChangeTimer = 0;
	}
}

/// Render
void PlayScene::Render() {
	__super::Render();
	RenderManager::Get().DrawTextW(L"[Play Scene] 10초 뒤 자동으로 넘어갑니다", 50, 50);
}

/// Exit
void PlayScene::Exit() {
	OutputDebugStringA("PlayScene Exit\n");
	GameData::Get().playerKillCount = player->GetKillCount();

	__super::Exit();
}