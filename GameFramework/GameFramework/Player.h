#pragma once
#include "../GameEngineLib/Object.h"
#include "../GameEngineLib/Vector2.h"
#include "../GameEngineLib/framework.h"
#include "GameManager.h"

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
	enum PlayerMoveState { LEFT, RIGHT, UP, DOWN, NONE };
	enum PlayerWayState { W_LEFT, W_RIGHT };

	PlayerState curState = IDLE;
	PlayerState preState = IDLE;
	PlayerMoveState moveState = NONE;
	PlayerWayState wayState = W_RIGHT;

	// animations
	int animationIndex = 0;

	static const int IDLE_SIZE = 4;
	static const int WALK_SIZE = 6;
	static const int ATTACK_SIZE = 8;

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
	void UpdateTimer();
	void StateUpdate();
	void Move();
	void Animation();

public:
	Player();
	~Player() override = default;

	void Start() override;   // scene manager called
	void Update() override;	 // scene manager called
	void Render() override;	 // scene manager called

	bool isAABBCollision(Vector2 e_pos, float eh_width, float eh_height);
	int GetAttackEnemyCount() { return attackEnemyCount; }
};