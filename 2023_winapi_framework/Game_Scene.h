#pragma once
#include "Scene.h"
class Game_Scene :
    public Scene
{
    virtual void Init() override;
    virtual void Update() final;
    virtual void Render(HDC _dc) final;
    virtual void Release() final;
public:
    void ChangeBeforeScene();
    void ChangeAftetScene();
};

