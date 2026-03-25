#include "Core.h"
#include "DxLib.h"

bool Core::Init()
{
    ChangeWindowMode(TRUE); // ウィンドウモード
    SetGraphMode(640, 480, 32); // 解像度設定

    if (DxLib_Init() == -1)
    {
        return false;
    }

    SetDrawScreen(DX_SCREEN_BACK); // 裏画面描画を有効にする（必須！）
    return true;
}

bool Core::Update()
{
    // 1. 裏画面の内容を本物の画面に反映
    if (ScreenFlip() != 0)
    {
        return false;
    }

    // 2. 画面を真っさらな状態にクリア
    if (ClearDrawScreen() != 0)
    {
        return false;
    }

    // 3. Windowsのメッセージ処理（閉じるボタンなどが押されたかチェック）
    if (ProcessMessage() != 0)
    {
        return false;
    }

    // 4. キー入力状態の更新（後でInputManagerと連携）
    // CheckHitKey(KEY_INPUT_ESCAPE) などで終わるようにしても良い

    return true;
}

void Core::Finalize()
{
    DxLib_End();
}
