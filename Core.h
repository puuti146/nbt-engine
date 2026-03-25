#pragma once

class Core
{
public:
    Core(const Core&) = delete;

    static Core& GetInstance() 
    {
        static Core instance;
        return instance;
    }

    bool Main();

private:
    Core() = default;
};

