#pragma once
#include "Object.h"
class TouchTextObject :
    public Object
{
public:
    TouchTextObject(vector<wstring>& texts, bool hint);
    ~TouchTextObject();
public:
    void Update() override;
    void EnterCollision() override;
    void ExitCollision() override;
    void SetHint(bool value) { canHint = value; }
private:
    vector<wstring> textList;
    bool isEnter;
    bool canHint;
    bool isHint;
};

