#include "Core.h"
#include "InputManager.h"
#include "DxLib.h"

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd
)
{
    hInstance = hInstance;
    hPrevInstance = hPrevInstance;
    lpCmdLine = lpCmdLine;
    nShowCmd = nShowCmd;

    auto& app = Core::GetInstance();

    if (!app.Init())
    {
        return -1;
    }



    while (app.Update())
    {
        DrawPixel(320, 240, GetColor(255, 255, 255));

        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
        {
            break;
        }
    }

    app.Finalize();
    return 0;
}
