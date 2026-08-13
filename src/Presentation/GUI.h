#pragma once

#include <Windows.h>
#include <optional>
#include "Domain/Type.h"
#include "Domain/Math/Vector2.h"
#include "Domain/UTF8/UTF8.h"

namespace FlintEngine
{
	class GUI
	{
	private:
		const HINSTANCE& m_handle;

	public:
		GUI(const HINSTANCE& handle);


	};

	class Window
	{
	private:
		HWND m_handle;

		UTF8String m_taskName;
		UTF8String m_windowName;
		UTF8String m_menuName;

		ui4 m_style;
		
		// NOTE: CbClsExtraは使わないので実装しない
		// static si4 m_classExtraMemory;

		// NOTE: CbWndExtraも同様の理由
		// si4 m_windowExtraMemory;

		HICON m_icon;
		HICON m_smallIcon;
		HCURSOR m_cursor;

		Vector2Int m_position;
		Vector2Int m_size;

		Window(const HWND handle, const UTF8String taskName, const UTF8String windowName, const UTF8String menuName);

		void Step();

	public:
		// NOTE: Windowの多重管理を阻止するためにコピーコンストラクタを禁止する
		Window(const Window&) = delete;
		// NOTE: Moveのみ定義して必ず一つの実体がリソースを管理する
		Window(Window&& other) noexcept;

		~Window();

		// NOTE: コピー代入を禁止する
		Window& operator = (const Window&) = delete;

		static std::optional<Window> TryCreate(const HINSTANCE instance, const LPRECT rect, const int showCommand);

		int Run();
	};
}
