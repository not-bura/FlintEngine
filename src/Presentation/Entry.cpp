#include <windows.h>
#include <sal.h>

#include "GUI.h"

using namespace FlintEngine;

int WINAPI WinMain(
    _In_        HINSTANCE   hInstance,
    _In_opt_    HINSTANCE,
    _In_        LPSTR       lpCmdLine,
    _In_        int         nCmdShow
)
{
    GUI _instance{ hInstance };

    auto rect = RECT{ 100, 200, 300, 300 };

    if (auto _window = Window::TryCreate(hInstance, &rect, nCmdShow))
    {
        const auto _result = _window->Run();
        return _result;
    }

    return 1;
}
