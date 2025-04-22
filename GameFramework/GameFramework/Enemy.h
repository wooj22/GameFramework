#pragma once
#include "../GameEngineLib/Object.h"
#include "../GameEngineLib/Vector2.h"
#include "../GameEngineLib/framework.h"
#include "GameManager.h"

// animations frame size
const int IDLE_SIZE = 4;

class Enemy :public Object {
	// transform
	Vector2 position;
	float width;
	float height;
	float h_width;
	float h_height;

	// window
	int w_width = 1920;
	int w_height = 1080;

	// state
	enum EnemyState { IDLE, DIE };
	EnemyState curState = IDLE;

	// animations
	int animationIndex = 0;
	Bitmap* idleFrames[IDLE_SIZE];
	Bitmap* idleFrames_L[IDLE_SIZE];

	// cycle, timer
	float animationCycle = 0.2f;
	float animationTimer = 0.0f;

	// functions
	void LoadImages();
	void SaveScale();
	void SetPosition(Vector2 pos);
	void UpdateTimer();
	void Animation();

public:
	Enemy();
	~Enemy() override = default;

	void Start() override;   // scene manager called
	void Update() override;	 // scene manager called
	void Render() override;	 // scene manager called

	bool isAABBCollision(Vector2 e_pos, float eh_width, float eh_height);
};