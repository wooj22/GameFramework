#include "Player.h"

void Player::Start() {
	LoadImages();
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

	// idle
	for (int i = 0; i < IDLE_SIZE; ++i) {
		swprintf_s(filePath, L"../Resource/PlayerAnimation/idle-%d.png", i + 1);
		RenderManager::Get().LoadImageFile(idleFrames[i], filePath);
	}

	// walk
	for (int i = 0; i < WALK_SIZE; ++i) {
		swprintf_s(filePath, L"../Resource/PlayerAnimation/walk-%d.png", i + 1);
		RenderManager::Get().LoadImageFile(walkFrames[i], filePath);
	}

	// attack
	for (int i = 0; i < ATTACK_SIZE; ++i) {
		swprintf_s(filePath, L"../Resource/PlayerAnimation/attack-A%d.png", i + 1);
		RenderManager::Get().LoadImageFile(attackFrames[i], filePath);
	}
}

/// Update Timer
void Player::UpdateTimer() {
	moveTimer += TimeManager::Get().GetDeltaTime();
	animationTimer += TimeManager::Get().GetDeltaTime();
}

/// Player state update (input)
void Player::StateUpdate() {
	// walk
	if (InputManager::Get().IsKeyDown(VK_LEFT)) {
		preState = curState;
		curState = WALK;
		curMoveState = LEFT;
	}
	if(InputManager::Get().IsKeyDown(VK_RIGHT)) {
		preState = curState;
		curState = WALK;
		curMoveState = RIGHT;
	}
	if (InputManager::Get().IsKeyDown(VK_UP)) {
		preState = curState;
		curState = WALK;
		curMoveState = UP;
	}
	if (InputManager::Get().IsKeyDown(VK_DOWN)) {
		preState = curState;
		curState = WALK;
		curMoveState = DOWN;
	}

	// attack
	if (InputManager::Get().IsKeyDown(VK_SPACE)) {
		preState = curState;
		curState = WALK;
	}

	// idle
	if (!InputManager::Get().IsKeyDown(VK_LEFT) &&
		!InputManager::Get().IsKeyDown(VK_RIGHT) &&
		!InputManager::Get().IsKeyDown(VK_UP)&&
		!InputManager::Get().IsKeyDown(VK_DOWN)&&
		!InputManager::Get().IsKeyDown(VK_SPACE)) {
		preState = curState;
		curState = ATTACK;
	}
}

/// Player move
void Player::Move() {
	if (moveTimer > moveCycle) {
		switch (curMoveState)
		{
		case Player::LEFT:
			this->pos.X--;
			break;
		case Player::RIGHT:
			this->pos.X++;
			break;
		case Player::UP:
			this->pos.Y--;
			break;
		case Player::DOWN:
			this->pos.Y++;
			break;
		default:
			break;
		}

		moveTimer = 0;
	}
}

/// Animation frame change
void Player::Animation() {
	if (animationTimer > animationCycle) {
		switch (curState)
		{
		case Player::IDLE:
			if (animationIndex > IDLE_SIZE - 1) animationIndex = 0;
			if(preState != curState) animationIndex = 0;

			RenderManager::Get().DrawImage(idleFrames[animationIndex], 
				pos.X - (int)idleFrames[animationIndex]->GetWidth()/2,
				pos.Y - (int)idleFrames[animationIndex]->GetHeight() / 2);

			break;
		case Player::WALK:
			if (animationIndex > WALK_SIZE - 1) animationIndex = 0;
			if (preState != curState) animationIndex = 0;

			RenderManager::Get().DrawImage(walkFrames[animationIndex],
				pos.X - (int)walkFrames[animationIndex]->GetWidth() / 2,
				pos.Y - (int)walkFrames[animationIndex]->GetHeight() / 2);

			break;
		case Player::ATTACK:
			if (animationIndex > ATTACK_SIZE - 1) animationIndex = 0;
			if (preState != curState) animationIndex = 0;

			RenderManager::Get().DrawImage(attackFrames[animationIndex],
				pos.X - (int)attackFrames[animationIndex]->GetWidth() / 2,
				pos.Y - (int)attackFrames[animationIndex]->GetHeight() / 2);

			break;
		default:
			break;
		}

		animationIndex++;
		animationTimer = 0;
	}
}

/// AABB Collision
bool Player::isCollision(COORD pos, int width, int height) {
	return false;
}