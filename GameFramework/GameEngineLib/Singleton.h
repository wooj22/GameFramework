#pragma once

template <typename T>
class Singleton
{
private:
	static T* Instance;

protected:
	Singleton() = default;
	virtual ~Singleton() = default;

	// ���� �� �̵� ����
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(Singleton&&) = delete;

public:
	// ����� �ʱ�ȭ
	static void Create() {
		assert(Instance == nullptr && "Singleton already created!");
		if (!Instance)
			Instance = new T();
	}

	// �̱��� �ν��Ͻ� ���� ��ȯ
	static T& Get() {
		return *Instance;
	}

	// ����� ����
	static void Destroy() {
		assert(Instance != nullptr && "Singleton not created or already destroyed!");
		delete Instance;
		Instance = nullptr;
	}
};

template <typename T>
T* Singleton<T>::Instance = nullptr;