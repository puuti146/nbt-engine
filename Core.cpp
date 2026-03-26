#include "Core.h"
#include "DxLib.h"

bool Core::Init()
{
    ChangeWindowMode(TRUE);
    SetGraphMode(640, 480, 32);

    if (DxLib_Init() == -1)
    {
        return false;
    }

    SetDrawScreen(DX_SCREEN_BACK);
    return true;
}

bool Core::Update()
{
    if (ScreenFlip() != 0)
    {
        return false;
    }

    if (ClearDrawScreen() != 0)
    {
        return false;
    }

    if (ProcessMessage() != 0)
    {
        return false;
    }

    return true;
}

void Core::Finalize()
{
    DxLib_End();
}
