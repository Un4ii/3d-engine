#include "engine/window.hpp"

#include <windows.h>

struct Engine::Window::Impl {
    const wchar_t* class_name;
    HINSTANCE h_instance;
    HWND hwnd;
};

static LRESULT CALLBACK windowProc(HWND hwnd, UINT u_msg, WPARAM w_param, LPARAM l_param) {
    switch (u_msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hwnd, u_msg, w_param, l_param);
    }
}

Engine::Window::Window(
    HINSTANCE h_instance, int n_cmdshow, const char* title, uint32_t width, uint32_t height
)
    : impl(new Impl) {
    impl->class_name = L"Omega Engine Window Class";
    impl->h_instance = h_instance;

    WNDCLASSEX wndclass    = {};
    wndclass.cbSize        = sizeof(WNDCLASSEX);
    wndclass.style         = CS_VREDRAW | CS_HREDRAW;
    wndclass.lpfnWndProc   = windowProc;
    wndclass.hInstance     = h_instance;
    wndclass.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1); // TODO: Test COLOR_WINDOW
    wndclass.lpszClassName = (LPCSTR)impl->class_name;

    RegisterClassEx(&wndclass);

    impl->hwnd = CreateWindowEx(
        WS_EX_LEFT,
        (LPCSTR)impl->class_name,
        title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        (int)width,
        (int)height,
        NULL,
        NULL,
        h_instance,
        NULL
    );

    if (impl->hwnd == NULL) {
        // TODO: We have a problem, manage error
    }

    ShowWindow(impl->hwnd, n_cmdshow);
}

Engine::Window::~Window() {
    if (impl->hwnd != NULL) {
        DestroyWindow(impl->hwnd);
    }
    UnregisterClass((LPCSTR)impl->class_name, impl->h_instance);
    delete impl;
}
