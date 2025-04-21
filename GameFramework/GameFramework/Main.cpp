#include "GameManager.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    GameManager gameManager;

    gameManager.Init();
    gameManager.Run();
    gameManager.Release();

    return (int)1;
}
