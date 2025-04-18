#include "pch.h"
#include "Scene.h"
#include "Object.h"

/// ���� ��ϵ� ��� ������Ʈ ����
void Scene::Clear()
{
	for (auto& object : objectList)
	{
		delete object;
	}
	objectList.clear();

	for (auto& object : deletePendingObjectList)
	{
		delete object;
	}
	deletePendingObjectList.clear();
}

/// ���� ��ϵ� ��� ������Ʈ update ȣ��
void Scene::Update()
{
	for (auto& object : objectList)
	{
		object->Update();
	}
}

/// ���� ��ϵ� ��� ������Ʈ render ȣ��
void Scene::Render()
{
	for (auto& object : objectList)
	{
		object->Render();
	}
}