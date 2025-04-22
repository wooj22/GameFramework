#include "pch.h"
#include "RenderManager.h"

/// Renderer Initialize
void RenderManager::Init(HWND hwnd, int width, int height) {
	// 윈도우 핸들 초기화
	this->hwnd = hwnd;
	this->width = width;
	this->height = height;

	// 더블 버퍼링 초기화
	frontBufferDC = GetDC(hwnd);
	backBufferDC = CreateCompatibleDC(frontBufferDC);
	backBufferBitmap = CreateCompatibleBitmap(frontBufferDC, width, height);
	SelectObject(backBufferDC, backBufferBitmap);

	// GDI+ 초기화
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&gdiPlusToken, &gsi, nullptr);
	backBufferGraphics = Graphics::FromHDC(backBufferDC);
}

/// Load Image
void RenderManager::LoadImageFile(Bitmap*& bitmap, wchar_t* filePath) {
	bitmap = new Bitmap(filePath);
}

/// Copy Image
void RenderManager::CopyImage(Bitmap*& bitmapCopy, Bitmap*& bitmapOrigin) {
	if (bitmapOrigin == nullptr) return;		// why? GetPixelFormat이 nullptr이라서 추가한건데 이미지 로드 다 잘됨

	bitmapCopy = bitmapOrigin->Clone(0, 0,
		bitmapOrigin->GetWidth(),
		bitmapOrigin->GetHeight(),
		bitmapOrigin->GetPixelFormat());
}

/// Filp Image
void RenderManager::FilpImage(Bitmap*& bitmap) {
	if(bitmap)	bitmap->RotateFlip(RotateNoneFlipX);
}

/// Backgrond Draw
void RenderManager::DrawBackground() {
	PatBlt(backBufferDC, 0, 0, width, height, BLACKNESS);
}

/// Image Draw
void RenderManager::DrawImage(Bitmap* bitmap, int posX, int posY) {
	backBufferGraphics->DrawImage(bitmap, posX, posY);
}

/// Back -> Front copy
void RenderManager::DrawBackToFront() {
	BitBlt(frontBufferDC, 0, 0, width, height, backBufferDC, 0, 0, SRCCOPY);
}

/// GDIRenderer Release
void RenderManager::Release() {
	// GDI+ 해제
	delete backBufferGraphics;
	Gdiplus::GdiplusShutdown(gdiPlusToken);
	DeleteObject(backBufferBitmap);
	DeleteDC(backBufferDC);
	ReleaseDC(hwnd, frontBufferDC);
}