#include "Player.h"

void Player::Start() {
	SetPosition(Vector2(900, 400));
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
/// 생성자 
Player::Player() {
	LoadImages();
	FilpImages();
	SaveScale();
}

/// Player animation images load
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
		RenderManager::Get().LoadImageFile(attackFrames_R[i], filePath);
	}
}

/// Player images filp save
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

/// Save width & height
void Player::SaveScale() {
	this->width = attackFrames_L[0]->GetWidth();
	this->height = attackFrames_L[0]->GetHeight();
	this->h_width = this->width/2;
	this->h_height = this->height/2;
}

/// Set position
void Player::SetPosition(Vector2 pos) {
	this->position = pos;
}

/// Update Timer
void Player::UpdateTimer() {
	moveTimer += TimeManager::Get().GetDeltaTime();
	animationTimer += TimeManager::Get().GetDeltaTime();
}

/// Player state update (input)
void Player::StateUpdate() {
	// walk (공캔방지)
	if (curState != ATTACK) {
		if (InputManager::Get().IsKeyDown(VK_LEFT)) {
			preState = curState;
			curState = WALK;
			wayState = LEFT;
		}
		if (InputManager::Get().IsKeyDown(VK_RIGHT)) {
			preState = curState;
			curState = WALK;
			wayState = RIGHT;
		}
		if (InputManager::Get().IsKeyDown(VK_UP)) {
			preState = curState;
			curState = WALK;
			wayState = UP;
		}
		if (InputManager::Get().IsKeyDown(VK_DOWN)) {
			preState = curState;
			curState = WALK;
			wayState = DOWN;
		}
	}
	
	// attack
	if (InputManager::Get().IsKeyDown('F')) {
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
		switch (wayState)
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
		// index controll
		if (preState != curState) animationIndex = 0;
		if (animationIndex > IDLE_SIZE - 1) animationIndex = 0;

		// draw image
		if(wayState == RIGHT || wayState == UP || wayState == NONE)
			RenderManager::Get().DrawImage(idleFrames_R[animationIndex], 
				position.x - h_width, position.y - h_height);
		else
			RenderManager::Get().DrawImage(idleFrames_L[animationIndex],
				position.x - h_width, position.y - h_height);
		break;

	case Player::WALK:
		// index controll
		if (preState != curState) animationIndex = 0;
		if (animationIndex > WALK_SIZE - 1) animationIndex = 0;

		// draw image
		if (wayState == RIGHT || wayState == UP || wayState == NONE)
			RenderManager::Get().DrawImage(walkFrames_R[animationIndex],
				position.x - h_width, position.y - h_height);
		else
			RenderManager::Get().DrawImage(walkFrames_L[animationIndex],
				position.x - h_width, position.y - h_height);
		break;

	case Player::ATTACK:
		// index controll
		if (preState != curState) animationIndex = 0;

		// draw image
		if (wayState == RIGHT || wayState == UP || wayState == NONE)
			RenderManager::Get().DrawImage(attackFrames_R[animationIndex],
				position.x - h_width, position.y - h_height);
		else
			RenderManager::Get().DrawImage(attackFrames_L[animationIndex],
				position.x - h_width, position.y - h_height);

		// 반복 X
		if (animationIndex == ATTACK_SIZE - 1) curState = IDLE;
		break;

	default:
		break;
	}
}

/// AABB Collision
bool Player::isAABBCollision(Vector2 e_pos, float eh_width, float eh_height) {
	// 플레이어의 중심 좌표와 반너비/반높이
	float p_minX = position.x - h_width;
	float p_maxX = position.x + h_width;
	float p_minY = position.y - h_height;
	float p_maxY = position.y + h_height;

	// 외부 객체의 좌표
	float e_minX = e_pos.x - eh_width;
	float e_maxX = e_pos.x + eh_width;
	float e_minY = e_pos.y - eh_height;
	float e_maxY = e_pos.y + eh_height;

	// AABB 충돌 검사
	if (p_maxX < e_minX || p_minX > e_maxX || p_maxY < e_minY || p_minY > e_maxY)
		return false;
	else
		return true;
}