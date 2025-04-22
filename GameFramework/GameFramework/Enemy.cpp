#include "Enemy.h"

void Enemy::Start() {
	// 랜덤한 위치 지정
	float x, y;
	x = rand() % 1920;
	y = rand() % 1080;
	SetPosition(Vector2(x, y));
}

void Enemy::Update() {
	UpdateTimer();
}

void Enemy::Render() {
	Animation();
}

/*-----------------------------------------------*/
Enemy::Enemy() {
	LoadImages();
	SaveScale();
}

void Enemy::LoadImages() {
	wchar_t filePath[256];

	// idle
	for (int i = 0; i < IDLE_SIZE; ++i) {
		swprintf_s(filePath, L"../Resource/EnemyAnimation/idle-%d.png", i + 1);
		RenderManager::Get().LoadImageFile(idleFrames[i], filePath);
	}
}

void Enemy::SaveScale() {
	this->width = idleFrames[0]->GetWidth()/2.5;
	this->height = idleFrames[0]->GetHeight()/2;
	this->h_width = this->width / 2;
	this->h_height = this->height / 2;
}

void Enemy::SetPosition(Vector2 pos) {
	this->position = pos;
}

void Enemy::UpdateTimer() {
	animationTimer += TimeManager::Get().GetDeltaTime();

	// animation frame index controll
	if (animationTimer > animationCycle) {
		animationIndex++;
		animationTimer = 0;
	}
}

void Enemy::Animation() {
	// index controll
	if (animationIndex >= IDLE_SIZE) animationIndex = 0;

	// draw image
	RenderManager::Get().DrawImage(idleFrames[animationIndex],
		position.x - h_width, position.y - h_height);
}

bool Enemy::isAABBCollision(Vector2 e_pos, float eh_width, float eh_height) {
	// this
	float p_minX = position.x - h_width;
	float p_maxX = position.x + h_width;
	float p_minY = position.y - h_height;
	float p_maxY = position.y + h_height;

	// other
	float e_minX = e_pos.x - eh_width;
	float e_maxX = e_pos.x + eh_width;
	float e_minY = e_pos.y - eh_height;
	float e_maxY = e_pos.y + eh_height;

	// AABB collision
	if (p_maxX < e_minX || p_minX > e_maxX || p_maxY < e_minY || p_minY > e_maxY)
		return false;
	else
		return true;
}