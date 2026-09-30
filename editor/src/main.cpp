#include <windows.h>

#include "engine/window.hpp"

// NOLINTNEXTLINE
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    Engine::Window main_window(hInstance, nShowCmd, "Main Window", 1080, 720);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
