#pragma once
#include "UIObject.h"
class PopUpTexture :
    public UIObject
{
protected:
    PopUpTexture(Vec2 scale, wstring key, wstring textureName);
    ~PopUpTexture();
public:
    void Update() override;
    void Render(HDC _dc) final;
    void EnterCollision() final;
    void ExitCollision() final;
    void Open();
    void Close();
    const bool GetNeedRendering() { return needRendering; }
private:
    bool needRendering;
    bool isEnter;
    Vec2 popupSclae;

};

