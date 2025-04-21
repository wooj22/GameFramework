#pragma once
#include "../GameEngineLib/Object.h"
#include "../GameEngineLib/framework.h"
#include "GameManager.h"

// animations frame size
const int IDLE_SIZE = 4;
const int WALK_SIZE = 6;
const int ATTACK_SIZE = 8;

class Player :public Object {
private:
	// transform
	COORD pos = {1000,500};
	int width = 30;
	int height = 50;
	int winWidth = 1920;
	int winHeight = 1080;

	// stat
	int speed = 10;

	// cycle
	float moveCycle = 0.1f;
	float animationCycle = 0.1f;

	// timer
	float moveTimer = 0.0f;
	float animationTimer = 0.0f;

	// state
	enum PlayerState { IDLE, WALK, ATTACK };
	enum PlayerMoveState { LEFT, RIGHT,	UP,	DOWN, NONE };

	PlayerState curState = IDLE;
	PlayerState preState = IDLE;
	PlayerMoveState curMoveState = NONE;

	// animations
	int animationIndex = 0;
	Bitmap* idleFrames_R[IDLE_SIZE];
	Bitmap* idleFrames_L[IDLE_SIZE];
	Bitmap* walkFrames[WALK_SIZE];
	Bitmap* attackFrames[ATTACK_SIZE];

public:
	Player() = default;
	~Player() override = default;

	void Start() override; // scene manager called
	void Update() override;	 // scene manager called
	void Render() override;	 // scene manager called	

	void LoadImages();
	void FilpImages();
	void UpdateTimer();
	void StateUpdate();
	void Move();
	bool isCollision(COORD pos, int width, int height);
	void Animation();
};