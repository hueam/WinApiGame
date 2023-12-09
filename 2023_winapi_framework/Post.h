#pragma once
#include "Object.h"

class Texture;
class Locker;
class Post :
    public Object
{
public:
    Post(Locker* owner);
    ~Post();
public:
    void Update() final;
    void Render(HDC _dc) final;
    void EnterCollision() final;
    void ExitCollision() final;
private:
    Locker* owner;
    Texture* m_pTex;
    bool isEnter;
};

