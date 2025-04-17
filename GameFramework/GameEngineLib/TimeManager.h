#pragma once
#include "Singleton.h"

class TimeManager : public Singleton<TimeManager>
{
private:
	TimeManager() = default;
	~TimeManager() = default;

	LARGE_INTEGER frequency;
	LARGE_INTEGER prevCounter;
	LARGE_INTEGER currentCounter;
	LARGE_INTEGER initCounter;
	float deltaTime;

public:
	void Init();
	void Update();
	float GetDeltaTime();
	float GetTotalTime();
};