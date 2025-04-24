#include "Engine.h"

WakWak::Engine::Engine() :mHwnd(nullptr), mWidth(0), mHeight(0)
{
}

WakWak::Engine::~Engine()
{
}

void WakWak::Engine::Init(HWND hwnd, UINT width, UINT height)
{
	hwnd = hwnd;
	InitWindowRect(width, height);
}

void WakWak::Engine::Run()
{
	Update();
	Render();
}

void WakWak::Engine::Update()
{
}

void WakWak::Engine::Render()
{
}

void WakWak::Engine::InitWindowRect(UINT width, UINT height)
{
	RECT rect = { 0, 0, width, height };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	mWidth = rect.right - rect.left;
	mHeight = rect.bottom - rect.top;

	SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
	ShowWindow(mHwnd, true);
}
