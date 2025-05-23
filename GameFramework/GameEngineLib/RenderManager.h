#pragma once
#include "gdiplus.h"
#pragma comment(lib, "gdiplus.lib")
#include "Singleton.h"
#include "framework.h"
using namespace Gdiplus;
using namespace std;

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

public:
	RenderManager() = default;
	~RenderManager() override = default;

	void Init(HWND hwnd, int width, int height);
	void Update() {};
	void Release();

	void LoadImageFile(Bitmap*& bitmap, wchar_t* filePath);
	void CopyImage(Bitmap*& bitmapCopy, Bitmap*& bitmapOrigin);
	void FilpImage(Bitmap*& bitmap);
	void DrawBackground();
	void DrawImage(Bitmap* bitmap, int posX, int posY);
	void DrawTextC(const char* text, int posX, int posY);
	void DrawTextW(const wchar_t* text, int posX, int posY);
	void DrawTextS(const string& text, int posX, int posY);
	void DrawBackToFront();
};

