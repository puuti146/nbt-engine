#include "Core.h"
#include "DxLib.h"

bool Core::Main()
{
    ChangeWindowMode(TRUE);

    // ＤＸライブラリ初期化処理
    if (DxLib_Init() == -1)
    {
        // エラーが起きたら直ちに終了
        return true;
    }

    // 点を打つ
    DrawPixel(320, 240, GetColor(255, 255, 255));

    // キー入力待ち
    WaitKey();

    // ＤＸライブラリ使用の終了処理
    DxLib_End();

    return false;
}
