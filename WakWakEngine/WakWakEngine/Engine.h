#pragma once
#include <Windows.h>

namespace WakWak {
	class Engine {
	public:
		Engine();
		~Engine();

		void Init(HWND hwnd, UINT width, UINT height);
		void Run();

	private:
		void Update();
		void Render();

		HWND mHwnd;
		UINT mWidth;
		UINT mHeight;
	private:
		void InitWindowRect(UINT width, UINT height);
	};
}