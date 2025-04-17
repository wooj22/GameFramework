#pragma once

template <typename T>
class Singleton
{
private:
	static T* Instance;

protected:
	Singleton() = default;
	virtual ~Singleton() = default;

	// 복사 및 이동 금지
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(Singleton&&) = delete;

public:
	// 명시적 초기화
	static void Create() {
		assert(Instance == nullptr && "Singleton already created!");
		if (!Instance)
			Instance = new T();
	}

	// 싱글톤 인스턴스 참조 반환
	static T& Get() {
		return *Instance;
	}

	// 명시적 해제
	static void Destroy() {
		assert(Instance != nullptr && "Singleton not created or already destroyed!");
		delete Instance;
		Instance = nullptr;
	}
};

template <typename T>
T* Singleton<T>::Instance = nullptr;