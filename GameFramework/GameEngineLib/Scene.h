#pragma once

using namespace std;
/*
* [Scene Ŭ����]
* Scene�� ��ü�� �������� Ȱ���Ѵ�.
* ���� ���� ������������ Scene�� ��ӹ޴� �پ��� �� Ŭ����(Menu, Stage1, Stage2 ..)�� ����� Ȱ���ϰ�,
* �� ���� CreateObject()�� ���� ���� Ȱ��� ������Ʈ���� objects�� ����Ͽ� ���� �����Ѵ�.
* SceneManager���� ���� ���� Updete�� ȣ�� -> Scene���� ������Ʈ���� update ȣ�� 
*/

class Object;
class Scene
{
private:
	vector<Object*> objects;				// ���� ��ϵ� object list
	vector<Object*> deletePendingObjects;	// ���� ������� object list

public:
	Scene() = default;
	virtual ~Scene(){ Clear(); }

	template<typename T>
	T* CreateObject()
	{
		T* pObject = new T();
		objects.push_back(pObject);
		return pObject;
	}

	void Clear();
	virtual void Enter() {};
	virtual void Update();
	virtual void Render();
	virtual void Exit() { Clear(); }
};

