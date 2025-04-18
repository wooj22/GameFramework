#pragma once
#include "gdiplus.h"
#pragma comment(lib, "gdiplus.lib")
#include "Singleton.h"
using namespace Gdiplus;

class RenderManager : public Singleton<RenderManager>
{
private:
	// Window Handle
	HWND hwnd;
	int width, height;

	// Device Context
	HDC frontBufferDC;
	HDC backBufferDC;

	// Graphics
	Graphics* backBufferGraphics;
	HBITMAP backBufferBitmap;
	ULONG_PTR gdiPlusToken;

	RenderManager() = default;
	~RenderManager() override = default;

public:
	void Init(HWND hwnd, int width, int height);
	void Update() {};
	void Release();

	void LoadImageFile(Bitmap*& bitmap, wchar_t* filePath);
	void DrawBackground();
	void DrawImage(Bitmap* bitmap, int posX, int posY);
	void DrawBackToFront();
};

