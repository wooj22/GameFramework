#include "pch.h"
#include "Scene.h"
#include "Object.h"

/// 씬에 등록된 모든 오브젝트 삭제
void Scene::Clear()
{
	for (auto& object : objects)
	{
		delete object;
	}
	objects.clear();

	for (auto& object : deletePendingObjects)
	{
		delete object;
	}
	deletePendingObjects.clear();
}

/// 씬에 등록된 모든 오브젝트 update 호출
void Scene::Update()
{
	for (auto& object : objects)
	{
		object->Update();
	}
}

/// 씬에 등록된 모든 오브젝트 render 호출
void Scene::Render()
{
	for (auto& object : objects)
	{
		object->Render();
	}
}