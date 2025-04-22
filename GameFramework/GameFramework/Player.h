#pragma once
#include "../GameEngineLib/Object.h"
#include "../GameEngineLib/Vector2.h"
#include "../GameEngineLib/framework.h"
#include "GameManager.h"

// TODO :: Chracter 클래스 만들어서 상속 -> 재사용

class Player :public Object {
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

	// stat
	float speed = 15;

	// game stat
	int killCount = 0;

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
	float animationCycle = 0.15f;
	float animationTimer = 0.0f;

	// functions
	void LoadImages();
	void FilpImages();
	void SaveScale();
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

	void SetPosition(Vector2 pos);
	bool isAABBCollision(Vector2 e_pos, float eh_width, float eh_height);
	void Kill() { killCount++; }
	int GetKillCount() { return killCount; }
};