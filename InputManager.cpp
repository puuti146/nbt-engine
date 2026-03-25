#include "InputManager.h"
#include "DxLib.h"

bool InputManager::Init()
{
    for (auto& i : NowInput)
    {
        i = 0;
    }

    for (auto& j : PrevInput)
    {
        j = 0;
    }

    return false;
}

void InputManager::Update()
{
    memcpy(PrevInput, NowInput, sizeof(PrevInput));

    GetHitKeyStateAll(NowInput);

    Down.Down = (NowInput[KEY_INPUT_DOWN] == 1) && (PrevInput[KEY_INPUT_DOWN] == 0);
    Left.Down = (NowInput[KEY_INPUT_LEFT] == 1) && (PrevInput[KEY_INPUT_LEFT] == 0);
    Right.Down = (NowInput[KEY_INPUT_RIGHT] == 1) && (PrevInput[KEY_INPUT_RIGHT] == 0);
    Up.Down = (NowInput[KEY_INPUT_UP] == 1) && (PrevInput[KEY_INPUT_UP] == 0);
    Select.Down = (NowInput[KEY_INPUT_Z] == 1) && (PrevInput[KEY_INPUT_Z] == 0);
    Cancel.Down = (NowInput[KEY_INPUT_X] == 1) && (PrevInput[KEY_INPUT_X] == 0);
    Shift.Down = (NowInput[KEY_INPUT_LSHIFT] == 1) && (PrevInput[KEY_INPUT_LSHIFT] == 0);

    Down.Press = (NowInput[KEY_INPUT_DOWN] == 1) && (PrevInput[KEY_INPUT_DOWN] == 1);
    Left.Press = (NowInput[KEY_INPUT_LEFT] == 1) && (PrevInput[KEY_INPUT_LEFT] == 1);
    Right.Press = (NowInput[KEY_INPUT_RIGHT] == 1) && (PrevInput[KEY_INPUT_RIGHT] == 1);
    Up.Press = (NowInput[KEY_INPUT_UP] == 1) && (PrevInput[KEY_INPUT_UP] == 1);
    Select.Press = (NowInput[KEY_INPUT_Z] == 1) && (PrevInput[KEY_INPUT_Z] == 1);
    Cancel.Press = (NowInput[KEY_INPUT_X] == 1) && (PrevInput[KEY_INPUT_X] == 1);
    Shift.Press = (NowInput[KEY_INPUT_LSHIFT] == 1) && (PrevInput[KEY_INPUT_LSHIFT] == 1);

    Down.Up = (NowInput[KEY_INPUT_DOWN] == 0) && (PrevInput[KEY_INPUT_DOWN] == 1);
    Left.Up = (NowInput[KEY_INPUT_LEFT] == 0) && (PrevInput[KEY_INPUT_LEFT] == 1);
    Right.Up = (NowInput[KEY_INPUT_RIGHT] == 0) && (PrevInput[KEY_INPUT_RIGHT] == 1);
    Up.Up = (NowInput[KEY_INPUT_UP] == 0) && (PrevInput[KEY_INPUT_UP] == 1);
    Select.Up = (NowInput[KEY_INPUT_Z] == 0) && (PrevInput[KEY_INPUT_Z] == 1);
    Cancel.Up = (NowInput[KEY_INPUT_X] == 0) && (PrevInput[KEY_INPUT_X] == 1);
    Shift.Up = (NowInput[KEY_INPUT_LSHIFT] == 0) && (PrevInput[KEY_INPUT_LSHIFT] == 1);
}
