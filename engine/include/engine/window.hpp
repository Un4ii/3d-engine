#pragma once

#include <cstdint>

struct HINSTANCE__; // NOLINT
typedef struct HINSTANCE__* HINSTANCE;

namespace Engine {
class Window {
  public:
    Window(HINSTANCE h_instance, int n_cmdshow, const char* title, uint32_t width, uint32_t height);
    ~Window();

    Window(const Window&)            = delete;
    Window(Window&&)                 = delete;
    Window& operator=(const Window&) = delete;
    Window& operator=(Window&&)      = delete;

  private:
    struct Impl;
    Impl* impl;
};
} // namespace Engine
