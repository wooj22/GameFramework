#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"

/// SceneManager 초기화
void SceneManager::Init()
{

}

/// SceneManager 종료
void SceneManager::Release()
{
	for (auto& scene : sceneList)
	{
		delete scene;
	}
	sceneList.clear();
}

/// currentScene의 Update 호출
void SceneManager::Update()
{
	if (nextScene)
	{
		if (currentScene)
			currentScene->Exit();

		currentScene = nextScene;
		nextScene = nullptr;

		currentScene->Start();
	}

	if (currentScene)
		currentScene->Update();
}

/// currentScene의 Render 호출
void SceneManager::Render()
{
	if (currentScene)
		currentScene->Render();
}

/// Scene Change
void SceneManager::ChangeScene(size_t index)
{
	if (index >= sceneList.size())
		return;

	nextScene = sceneList[index];
}

/// Current Scene get
Scene* SceneManager::GetCurrentScene() {
	return currentScene;
}
