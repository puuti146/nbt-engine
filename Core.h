#pragma once

class Core
{
public:
    Core(const Core&) = delete;
    void operator=(const Core&) = delete;

    static Core& GetInstance()
    {
        static Core instance;
        return instance;
    }

    bool Init();
    bool Update();
    void Finalize();

private:
    Core() = default;
};
