#pragma once
#include "../GameEngineLib/Object.h"
#include "../GameEngineLib/Vector2.h"
#include "../GameEngineLib/framework.h"
#include "GameManager.h"

// animations frame size
const int IDLE_SIZE = 4;
const int WALK_SIZE = 6;
const int ATTACK_SIZE = 8;

class Player :public Object {
private:
	// transform
	Vector2 position;
	float width;
	float height;
	float h_width;
	float h_height;

	// stat
	float speed = 10;

	// game stat
	int attackEnemyCount = 0;

	// window
	int w_width = 1920;
	int w_height = 1080;

	// state
	enum PlayerState { IDLE, WALK, ATTACK };
	enum PlayerWayState { LEFT, RIGHT, UP, DOWN, NONE };

	PlayerState curState = IDLE;
	PlayerState preState = IDLE;
	PlayerWayState wayState = NONE;

	// animations
	int animationIndex = 0;
	Bitmap* idleFrames_R[IDLE_SIZE];
	Bitmap* idleFrames_L[IDLE_SIZE];
	Bitmap* walkFrames_R[WALK_SIZE];
	Bitmap* walkFrames_L[WALK_SIZE];
	Bitmap* attackFrames_L[ATTACK_SIZE];
	Bitmap* attackFrames_R[ATTACK_SIZE];

	// cycle, timer
	float moveCycle = 0.1f;
	float moveTimer = 0.0f;
	float animationCycle = 0.1f;
	float animationTimer = 0.0f;

	// functions
	void LoadImages();
	void FilpImages();
	void SaveScale();
	void SetPosition(Vector2 pos);
	void Move();
	void Animation();

public:
	Player();
	~Player() override = default;

	void Start() override;   // scene manager called
	void Update() override;	 // scene manager called
	void Render() override;	 // scene manager called

	bool isAABBCollision(Vector2 pos, float h_width, float h_height);
	int GetAttackEnemyCount() { return attackEnemyCount; }
};