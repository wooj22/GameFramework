#include "pch.h"
#include "Scene.h"
#include "Object.h"

/// ���� ��ϵ� ��� ������Ʈ ����
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

/// ���� ��ϵ� ��� ������Ʈ update ȣ��
void Scene::Update()
{
	for (auto& object : objects)
	{
		object->Update();
	}
}

/// ���� ��ϵ� ��� ������Ʈ render ȣ��
void Scene::Render()
{
	for (auto& object : objects)
	{
		object->Render();
	}
}