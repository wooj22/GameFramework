#pragma once
#include "../GameEngineLib/Scene.h"

class EndScene : public Scene {
public:
	EndScene() = default;
	~EndScene() = default;

	void Start() override;
	void Update() override;
	void Render() override;
	void Exit() override;
};
