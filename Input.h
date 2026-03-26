#pragma once

struct InputData
{
    bool Down;
    bool Press;
    bool Up;
};

class Input
{
public:
    Input(const Input&) = delete;
    void operator=(const Input&) = delete;

    static Input& GetInstance();

    void Update();

    InputData Down;
    InputData Left;
    InputData Right;
    InputData Up;
    InputData Select;
    InputData Cancel;
    InputData Shift;

private:
    Input() = default;

    char NowInput[256];
    char PrevInput[256];
};
