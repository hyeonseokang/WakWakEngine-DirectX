#include <windows.h>
#include "..\\WakWakEngine\\\Engine.h"

WakWak::Engine engine;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    WNDCLASSW wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"WakWakEngine";
    RegisterClassW(&wc);

    UINT width = 1600;
    UINT height = 900;
    HWND hwnd = CreateWindowExW(
        0,
        L"WakWakEngine",
        L"WakWakEngine",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, width, height,
        nullptr, nullptr, hInstance, nullptr
    );

    if (!hwnd)
        return -1;


    ShowWindow(hwnd, nCmdShow);


    engine.Init(hwnd, width, height);

    MSG msg = {};
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;
        }
        else
        {
            engine.Run();
        }
    }

    return static_cast<int>(msg.wParam);
}
