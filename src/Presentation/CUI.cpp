#include <windows.h>
#include <iostream>
#include "CUI.h"

using namespace std;

using namespace FlintEngine;

CUI::CUI()
{
    // 標準入出力をコンソールに再リダイレクト
    FILE* file;
    freopen_s(&file, "CONOUT$", "w", stdout);
    freopen_s(&file, "CONOUT$", "w", stderr);
    freopen_s(&file, "CONIN$",  "r", stdin);

    // C++のストリーム（std::coutなど）を同期させる
    ios_base::sync_with_stdio();

    cout << endl;
}

CUI::~CUI()
{
    HWND hwndConsole = GetConsoleWindow();
    if (hwndConsole)
    {
        PostMessage(hwndConsole, WM_KEYDOWN, VK_RETURN, 0);
    }
}

bool CUI::Start(CUI* out)
{
    // 親プロセスのコンソールに接続を試みる
    if (false == AttachConsole(ATTACH_PARENT_PROCESS))
    {
        return false;
    }

    *out = CUI{};
    return true;
}

void CUI::WriteLine(const char* source) const
{
    cout << source << endl;
}

void CUI::Pause() const
{
    cout << system("pause");
}

//void CUI::WriteLine(const UTF8String& source) const
//{
//    cout << source;
//}
