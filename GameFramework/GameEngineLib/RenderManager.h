#pragma once
#include <Windows.h>
#include "gdiplus.h"
#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;

class RenderManager
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

public:
	void Init(HWND hwnd, int width, int height);
	void Update() {};
	void Release();

	void LoadImageFile(Bitmap*& bitmap, wchar_t* filePath);
	void DrawBackground();
	void DrawImage(Bitmap* bitmap, int posX, int posY);
	void DrawBackToFront();
};

