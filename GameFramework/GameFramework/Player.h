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
	int width = 50;
	int height = 80;
	int winWidth = 1920;
	int winHeight = 1080;

	// stat
	float speed = 10;

	// cycle
	float moveCycle = 0.1f;
	float animationCycle = 0.1f;

	// timer
	float moveTimer = 0.0f;
	float animationTimer = 0.0f;

	// state
	enum PlayerState { IDLE, WALK, ATTACK };
	enum PlayerWayState { LEFT, RIGHT,	UP,	DOWN, NONE };

	PlayerState curState = IDLE;
	PlayerState preState = IDLE;
	PlayerWayState playerWayState = NONE;

	// animations
	int animationIndex = 0;
	Bitmap* idleFrames_R[IDLE_SIZE];
	Bitmap* idleFrames_L[IDLE_SIZE];
	Bitmap* walkFrames_R[WALK_SIZE];
	Bitmap* walkFrames_L[WALK_SIZE];
	Bitmap* attackFrames_L[ATTACK_SIZE];
	Bitmap* attackFrames_R[ATTACK_SIZE];


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
	bool isCollision(Vector2 pos, int width, int height);
	void Animation();
};