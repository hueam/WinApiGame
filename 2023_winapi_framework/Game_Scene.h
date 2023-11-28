#pragma once
#include "Scene.h"
class Game_Scene :
    public Scene
{
    virtual void Init() override;
    void Update() override;
    void Render(HDC _dc) override;
    void Release() override;
};

