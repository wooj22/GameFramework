#pragma once
#include "../GameEngineLib/Object.h"
#include "../GameEngineLib/Vector2.h"
#include "../GameEngineLib/framework.h"
#include "GameManager.h"

class Enemy : public Object {
public:
	// transform
	Vector2 position;
	float width;
	float height;
	float h_width;
	float h_height;

private:
	// window
	int w_width = 1920;
	int w_height = 1080;

	// state
	enum EnemyState { IDLE, DIE };
	EnemyState curState = IDLE;

	// animations
	int animationIndex = 0;
	static const int IDLE_SIZE = 4;
	Bitmap* idleFrames[IDLE_SIZE];

	// cycle, timer
	float animationCycle = 0.2f;
	float animationTimer = 0.0f;

	// functions
	void LoadImages();
	void SaveScale();
	void UpdateTimer();
	void Animation();

public:
	Enemy();
	~Enemy() override { OutputDebugStringA("Enemy Die\n"); }

	void Start() override;   // scene manager called
	void Update() override;	 // scene manager called
	void Render() override;	 // scene manager called

	void SetPosition(Vector2 pos);
	bool isAABBCollision(Vector2 e_pos, float eh_width, float eh_height);
};