#pragma once

struct InputData
{
    bool Down;
    bool Press;
    bool Up;
};

class InputManager
{
public:
    InputManager(const InputManager&) = delete;
    void operator=(const InputManager&) = delete;

    static InputManager& GetInstance()
    {
        static InputManager instance;
        return instance;
    }

    bool Init();

    void Update();

    InputData Down;
    InputData Left;
    InputData Right;
    InputData Up;
    InputData Select;
    InputData Cancel;
    InputData Shift;

private:
    InputManager() = default;

    char NowInput[256];
    char PrevInput[256];
};
