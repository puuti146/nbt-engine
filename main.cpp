#include "Core.h"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    auto& app = Core::GetInstance();

    if (!app.Init())
    {
        return -1;
    }

    // メインループ
    while (app.Update())
    {
        // ここにゲームの処理を書く
        DrawPixel(320, 240, GetColor(255, 255, 255));

        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
        {
            break;
        }
    }

    app.Finalize();
    return 0;
}
