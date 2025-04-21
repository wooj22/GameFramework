#include "Player.h"

void Player::Start() {
	LoadImages();
	//FilpImages();
}

void Player::Update() {
	
	UpdateTimer();
	StateUpdate();
	Move();
}

void Player::Render() {
	Animation();
}


/* -------------------------------------------------------------------------- */
/// Player animation frames load
void Player::LoadImages() {
	wchar_t filePath[256];

	// idle - L
	for (int i = 0; i < IDLE_SIZE; ++i) {
		swprintf_s(filePath, L"../Resource/PlayerAnimation/idle-%d.png", i + 1);
		RenderManager::Get().LoadImageFile(idleFrames_R[i], filePath);
	}

	// walk - L
	for (int i = 0; i < WALK_SIZE; ++i) {
		swprintf_s(filePath, L"../Resource/PlayerAnimation/walk-%d.png", i + 1);
		RenderManager::Get().LoadImageFile(walkFrames_R[i], filePath);
	}

	// attack - L
	for (int i = 0; i < ATTACK_SIZE; ++i) {
		swprintf_s(filePath, L"../Resource/PlayerAnimation/attack-A%d.png", i + 1);
		RenderManager::Get().LoadImageFile(attackFrames_L[i], filePath);
	}
}

/// Player Images Filp
void Player::FilpImages() {
	// idle - R
	for (int i = 0; i < IDLE_SIZE; ++i) {
		RenderManager::Get().CopyImage(idleFrames_L[i], idleFrames_R[i]);
		RenderManager::Get().FilpImage(idleFrames_L[i]);
	}

	// walk - R
	for (int i = 0; i < WALK_SIZE; ++i) {
		RenderManager::Get().CopyImage(walkFrames_L[i], walkFrames_R[i]);
		RenderManager::Get().FilpImage(walkFrames_L[i]);
	}

	// attack - R
	for (int i = 0; i < ATTACK_SIZE; ++i) {
		RenderManager::Get().CopyImage(attackFrames_L[i], attackFrames_R[i]);
		RenderManager::Get().FilpImage(attackFrames_L[i]);
	}
}

/// Update Timer
void Player::UpdateTimer() {
	moveTimer += TimeManager::Get().GetDeltaTime();
	animationTimer += TimeManager::Get().GetDeltaTime();
}

/// Player state update (input)
void Player::StateUpdate() {
	// walk (°øÄµ¹æÁö)
	if (curState != ATTACK) {
		if (InputManager::Get().IsKeyDown(VK_LEFT)) {
			preState = curState;
			curState = WALK;
			playerWayState = LEFT;
		}
		if (InputManager::Get().IsKeyDown(VK_RIGHT)) {
			preState = curState;
			curState = WALK;
			playerWayState = RIGHT;
		}
		if (InputManager::Get().IsKeyDown(VK_UP)) {
			preState = curState;
			curState = WALK;
			playerWayState = UP;
		}
		if (InputManager::Get().IsKeyDown(VK_DOWN)) {
			preState = curState;
			curState = WALK;
			playerWayState = DOWN;
		}
	}
	
	// attack
	if (InputManager::Get().IsKeyDown(VK_SPACE)) {
		preState = curState;
		curState = ATTACK;
	}

	// idle
	if (curState != ATTACK &&
		!InputManager::Get().IsKeyDown(VK_LEFT) &&
		!InputManager::Get().IsKeyDown(VK_RIGHT) &&
		!InputManager::Get().IsKeyDown(VK_UP)&&
		!InputManager::Get().IsKeyDown(VK_DOWN)&&
		!InputManager::Get().IsKeyDown(VK_SPACE)) {
		preState = curState;
		curState = IDLE;
	}

	// animation index
	if (animationTimer > animationCycle) {
		animationIndex++;
		animationTimer = 0;
	}
}

/// Player move
void Player::Move() {
	if (moveTimer > moveCycle && curState == WALK) {
		switch (playerWayState)
		{
		case Player::LEFT:
			this->position.x -= speed;
			break;
		case Player::RIGHT:
			this->position.x += speed;
			break;
		case Player::UP:
			this->position.y -= speed;
			break;
		case Player::DOWN:
			this->position.y += speed;
			break;
		default:
			break;
		}

		moveTimer = 0;
	}
}

/// Animation frame change
void Player::Animation() {
	switch (curState)
	{
	case Player::IDLE:
		if (preState != curState) animationIndex = 0;
		if (animationIndex > IDLE_SIZE - 1) animationIndex = 0;
		RenderManager::Get().DrawImage(idleFrames_R[animationIndex], position.x, position.y);
		break;

	case Player::WALK:
		if (preState != curState) animationIndex = 0;
		if (animationIndex > WALK_SIZE - 1) animationIndex = 0;
		RenderManager::Get().DrawImage(walkFrames_R[animationIndex], position.x, position.y);
		break;

	case Player::ATTACK:
		if (preState != curState) animationIndex = 0;
		RenderManager::Get().DrawImage(attackFrames_L[animationIndex], position.x, position.y);
		if (animationIndex == ATTACK_SIZE - 1) curState = IDLE;
		break;

	default:
		break;
	}
}

/// AABB Collision
bool Player::isCollision(Vector2 pos, int width, int height) {
	return false;
}