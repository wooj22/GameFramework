#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "GameData.h"
#include "../GameEngineLib/framework.h"

/* ������ */
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
			// enemy delete
			delete (*enemy);				// enemy delete
			DeleteObject(*enemy);			// objectList pointer erase
			enemy = enemyList.erase(enemy); // enemyList pointer erase

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
	RenderManager::Get().DrawTextS("[Play Scene] " + to_string((int)(sceneChangeTime - sceneChangeTimer)) + 
		"�ʵ� �ڵ����� �Ѿ�ϴ�.", 50, 50);
}

/// Exit
void PlayScene::Exit() {
	OutputDebugStringA("PlayScene Exit\n");
	GameData::Get().playerKillCount = player->GetKillCount();

	__super::Exit();
}