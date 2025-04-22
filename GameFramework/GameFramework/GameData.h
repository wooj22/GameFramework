#pragma once
#include "../GameEngineLib/Singleton.h"

class GameData : public Singleton<GameData>
{
public :
	int playerKillCount;

	GameData() = default;
	~GameData() override = default;
};

