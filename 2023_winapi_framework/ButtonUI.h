#pragma once
#include "UIObject.h"
class ButtonUI :
    public UIObject
{
public:
    ButtonUI();
    ButtonUI(wstring textureName);
    ~ButtonUI();
public:
    void Update() override;
    virtual void EnterCollision() override;
    virtual void ExitCollision() override;
private:
    Vec2 curScale;
    bool m_bisEnter;
    bool m_bisMouseDown;
};

