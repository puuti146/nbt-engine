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

    // エンジンの初期化
    bool Init();

    // 毎フレーム呼ぶ処理（メッセージ処理、画面クリア、裏画面反映をセットで行う）
    // 戻り値が false になったらループを抜ける
    bool Update();

    // 終了処理
    void Finalize();

private:
    Core() = default;
};
