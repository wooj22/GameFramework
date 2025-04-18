#pragma once

using namespace std;
/*
* [Scene 클래스]
* Scene을 객체의 개념으로 활용한다.
* 실제 게임 콘텐츠에서는 Scene을 상속받는 다양한 씬 클래스(Menu, Stage1, Stage2 ..)을 만들어 활용하고,
* 각 씬에 CreateObject()를 통해 씬에 활용될 오브젝트들을 objects에 등록하여 쉽게 관리한다.
* SceneManager에서 현재 씬의 Updete를 호출 -> Scene에서 오브젝트들의 update 호출 
*/

class Object;
class Scene
{
private:
	vector<Object*> objects;				// 씬에 등록된 object list
	vector<Object*> deletePendingObjects;	// 삭제 대기중인 object list

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

