#include <windows.h>
#include <optional>
#include "GUI.h"
#include "Domain/Math/Vector2.h"
#include "Domain/UTF8/UTF8.h"

using namespace FlintEngine;

using namespace std;

Window::Window(const HWND handle, const UTF8String taskName, const UTF8String windowName, const UTF8String menuName) 
	: m_handle(handle)
	, m_taskName(taskName)
	, m_windowName(windowName)
	, m_menuName(menuName)
	, m_style(0)
	, m_icon(0)
	, m_smallIcon(0)
	, m_cursor(0)
	, m_position(Vector2Int{})
	, m_size(Vector2Int{})
{
}

void Window::Step()
{
}

static LRESULT CALLBACK WindowProcedure(const HWND window, const UINT message, const WPARAM wParam, const LPARAM lParam)
{
	static HPEN hPen[2];
	LRESULT ret = (LRESULT)0;
	static int width, height;

	switch (message)
	{//メッセージハンドラ
	case WM_CREATE://ウィンドウ生成されたとき(開始時のみ)
		hPen[0] = CreatePen(PS_SOLID, 10, 0x0000FF00);
		hPen[1] = CreatePen(PS_DASH, 1, 0x000000FF);
		break;

	case WM_CLOSE://ウィンドウの✖が押されたとき
		DestroyWindow(window);
		break;

	case WM_DESTROY://ウィンドウ破棄されたとき(終了時のみ)
		DeleteObject(hPen[0]);
		DeleteObject(hPen[1]);
		PostQuitMessage(0);
		break;

	case WM_PAINT://ウィンドウを再表示するとき(最小化最大化サイズ変更すべて)
	{
		//PAINTSTRUCT ps;
		//BeginPaint(window, &ps);
		//HDC hdc = ps.hdc;
		//SelectObject(hdc, hPen[1]);
		//Rectangle(hdc, 0, 0, GE->screenState.WidthDef, GE->screenState.HeightDef);
		//EndPaint(window, &ps);
	}
	break;

	case WM_MOUSEMOVE://ウィンドウ上でマウス移動したとき
	{
		auto mousePositionX = LOWORD(lParam);
		int mPosY = HIWORD(lParam);
		HDC hdc = GetDC(window);
		SelectObject(hdc, hPen[0]);
		Rectangle(hdc, mousePositionX, mPosY, mousePositionX + 30, mPosY + 30);//四角を書く
		//SetPixel(hdc, x + 15, y + 15, 0x000000FF);//赤い点を書く
		//SetPixel(hdc, x + 16, y + 16, 0x000000FF);//赤い点を書く
		//SetPixel(hdc, x + 17, y + 17, 0x000000FF);//赤い点を書く
		ReleaseDC(window, hdc);
	}
	break;
	case WM_KEYDOWN://ウィンドウがアクティブでキー入力を受け付けつけたとき
		if (wParam == VK_ESCAPE)
		{
			DestroyWindow(window);
		}
		if (wParam == 0x57)
		{

		}
		break;
	case WM_SIZE:
		//width = max(min(LOWORD(lParam_), GE->screenState.WidthMax), GE->screenState.WidthMin);
		//height = HIWORD(lParam_);
		break;
	default://それ以外はWindows君に投げつける
		ret = DefWindowProc(window, message, wParam, lParam);
		break;
	}
	return ret;
}

Window::Window(Window&& other) noexcept
	: m_handle(other.m_handle)
	, m_taskName(other.m_taskName)
	, m_windowName(other.m_windowName)
	, m_menuName(other.m_menuName)
	, m_style(other.m_style)
	, m_icon(other.m_icon)
	, m_smallIcon(other.m_smallIcon)
	, m_cursor(other.m_cursor)
	, m_position(other.m_position)
	, m_size(other.m_size)
{
	other.m_handle = nullptr;
}

Window::~Window()
{
	if (m_handle != nullptr)
	{

	}
}

optional<Window> Window::TryCreate(const HINSTANCE instance, const LPRECT rect, const int showCommand)
{
	// NOTE: Registerした名前とCreateWindowする名前は一致させる必要がある
	const auto _className = UTF8String{ "FlintEngine Class" };
	const auto _windowName = UTF8String{ "FlintEngine Window" };
	const auto _menuName = UTF8String{ "FlintEngine Menu" };
	const auto _icon = LoadIcon(instance, IDI_APPLICATION);

	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);

	// NOTE: 実質標準のWin3.0からのフィールド
	wcex.style = (CS_HREDRAW | CS_VREDRAW);

	wcex.lpfnWndProc = (WNDPROC)WindowProcedure;

	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	wcex.hInstance = instance;

	wcex.hIcon = _icon;
	wcex.hCursor = LoadCursor(instance, IDC_ARROW);

	wcex.hbrBackground = CreateSolidBrush(RGB(0xFF, 0xFF, 0x00));

	wcex.lpszMenuName = _menuName;
	wcex.lpszClassName = _className;

	// NOTE: 実質標準のWin4.0からのフィールド
	wcex.hIconSm = _icon;

	if (false == RegisterClassEx(&wcex))
	{
		MessageBox(nullptr, "Failed Subscribe Window", nullptr, MB_OK);
		return nullopt;
	}

	DWORD _style = (WS_CAPTION | WS_SYSMENU | WS_SIZEBOX);

	AdjustWindowRectEx(rect, _style, false, WS_EX_APPWINDOW);
	const HWND _handle = CreateWindowEx(
		WS_EX_APPWINDOW,
		_className,
		_windowName,
		_style,
		rect->left,
		rect->top,
		rect->right,
		rect->bottom,
		nullptr, nullptr, instance, nullptr
	);

	if (nullptr == _handle)
	{
		MessageBox(nullptr, "Failed Create Window", nullptr, MB_OK);
		return nullopt;
	}

	ShowWindow(_handle, showCommand);
	UpdateWindow(_handle);

	return Window{_handle, _className, _windowName, _menuName };
}

int Window::Run()
{
	const auto& _handle = m_handle;

	// NOTE: PeekMessageに失敗したらゼロクリアしないと想定できないデータが入るのでコンストラクタ
	MSG _buffer {};
	do
	{
		if (PeekMessage(&_buffer, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&_buffer);
			DispatchMessage(&_buffer);
			continue;
		}

		if (GetActiveWindow() == _handle)
		{
			Step();
		}
	}
	while (_buffer.message != WM_QUIT);

	return 0;
}
